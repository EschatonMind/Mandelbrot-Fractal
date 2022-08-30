#include"Bitmap.h"
#include<iostream>
using namespace Frac;
using namespace std;
int main() {
	int const  WIDTH = 1920;
	int const  HEIGHT = 1080;

	Bitmap bitmap(WIDTH, HEIGHT);

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			bitmap.SetPixels(x, y, 255, 120, 50);

		}
	}

	bitmap.Write("Test.bmp");

	cout << "Hello";

	return 0;
}