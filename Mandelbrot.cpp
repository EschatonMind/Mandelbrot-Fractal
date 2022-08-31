#include "Mandelbrot.h"
namespace Frac {

	Mandelbrot::Mandelbrot() {


	}

	Mandelbrot::~Mandelbrot() {


	}

	int Mandelbrot::GetIterations(double x, double y) {

		complex<double> Z = 0;
		complex<double> C(x, y);

		int Iterations = 0;

		while (Iterations < MAX_ITERATIONS) {

			Z = Z * Z + C;

			if (abs(Z) > 2) {
				break;
			}

			Iterations++;
		}

		return Iterations;
	}

}