#include"Bitmap.h"
#include"Mandelbrot.h"
#include<iostream>
using namespace Frac;
using namespace std;
int main() {
	int const  WIDTH = 1920;
	int const  HEIGHT = 1080;

	Bitmap bitmap(WIDTH, HEIGHT);

	double Min = 999999;
	double Max = -999999;

	for (int y = 0; y < HEIGHT; y++) {

		for (int x = 0; x < WIDTH; x++) {
			double XFractal = (x - WIDTH / 2) * (2.0 / WIDTH);
			double YFractal = (y - HEIGHT / 2) * (2.0 / HEIGHT);

			int Iterations = Mandelbrot::GetIterations(XFractal, YFractal);

			uint8_t Red = (uint8_t)(256 * (double)Iterations / Mandelbrot::MAX_ITERATIONS);
			
			bitmap.SetPixels(x, y, Red, Red, Red);			
			if (YFractal < Min) Min = YFractal;
			if (YFractal > Max) Max = YFractal;
		}
	}

	cout << Min << ", " << Max << flush << endl;

	bitmap.Write("Test.bmp");

	cout << "Finish";

	return 0;
}