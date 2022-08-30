#include"Bitmap.h"
#include<iostream>
using namespace Frac;
using namespace std;
int main() {
	Bitmap bitmap(800, 600);
	bitmap.Write("Test.bmp");
	cout << "Hello";

	return 0;
}