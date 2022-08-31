#pragma once
#include <complex>
using namespace std;
namespace Frac {

	class Mandelbrot
	{
	public:
		static const int MAX_ITERATIONS = 1000;

	public:
		Mandelbrot();
		virtual ~Mandelbrot();

		static int GetIterations(double x, double y);
	};

}

