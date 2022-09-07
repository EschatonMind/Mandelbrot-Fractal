#include"FractalCreator.h"

using namespace std;
using namespace Frac;

int main() {

	FractalCreator frac1(800, 600);

	frac1.AddRange(0.0, RGB(0, 0, 0));
	frac1.AddRange(0.3, RGB(70, 50, 10));
	frac1.AddRange(0.5, RGB(80, 100, 70));
	frac1.AddRange(1.0, RGB(200, 150, 255));

	cout << frac1.GetRange(999) << endl;
	frac1.AddZoom(Zoom(500, 500, 0.5));
	frac1.AddZoom(Zoom(500, 500, 0.2));
	frac1.Run("Test.bmp");

	cout << "finished" << endl;

	return 0;
}