#pragma once
#include<iostream>
using namespace std;
namespace Frac {

	class RGB
	{
	public:
		double R;
		double G;
		double B;

		RGB(double r, double g, double b);
	};

	RGB operator -(const RGB& first, const RGB& second);

	ostream& operator<<(ostream& out, const RGB& rgb);
}
