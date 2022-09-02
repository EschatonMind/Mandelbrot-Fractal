#include"Bitmap.h"
#include"Mandelbrot.h"
#include"ZoomList.h"
#include<iostream>
#include<memory>
#include<math.h>
using namespace Frac;
using namespace std;
int main() {
	int const  WIDTH = 1920;
	int const  HEIGHT = 1080;

	Bitmap bitmap(WIDTH, HEIGHT);

	double Min = 999999;
	double Max = -999999;

	unique_ptr<int[]> Histogram(new int[Mandelbrot::MAX_ITERATIONS] {0});
	unique_ptr<int[]> Fractal(new int[WIDTH*HEIGHT] {0});

	for (int y = 0; y < HEIGHT; y++) {

		for (int x = 0; x < WIDTH; x++) {
			double XFractal = (x - WIDTH / 2) * (2.0 / WIDTH);
			double YFractal = (y - HEIGHT / 2) * (2.0 / HEIGHT);

			int Iterations = Mandelbrot::GetIterations(XFractal, YFractal);

			Fractal[y * WIDTH + x] = Iterations;

			if(Iterations!=Mandelbrot::MAX_ITERATIONS){ Histogram[Iterations]++; }
			
		}
	}

	int Total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		Total += Histogram[i];
	}


	for (int y = 0; y < HEIGHT; y++) {

		for (int x = 0; x < WIDTH; x++) {

			uint8_t Red{0};
			uint8_t Green{0};
			uint8_t Blue{0};

			int Iterations = Fractal[y * WIDTH + x];

			if (Iterations != Mandelbrot::MAX_ITERATIONS) {
				double Hue = 0;

				for (int i = 0; i <= Iterations; i++) {
					Hue += ((double)Histogram[i] / Total);
				}

				Red = pow(255, Hue);
				Green = pow(255, Hue);
				Blue = pow(255, Hue);

			}
			
			bitmap.SetPixels(x, y, Red, Green, Blue);
		}
	}

	cout << Min << ", " << Max << flush << endl;

	bitmap.Write("Test.bmp");

	cout << "Finish";

	return 0;
}