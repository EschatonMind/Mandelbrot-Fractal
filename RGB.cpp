#include "RGB.h"
namespace Frac {
	RGB::RGB(double r, double g, double b) : R(r), G(g), B(b) {

	}

	RGB operator-(const RGB& first, const RGB& second) {

		return RGB(first.R - second.R, first.G - second.G, first.B - second.B);
	}

	ostream& operator<<(ostream& out, const RGB& rgb) {

		out << " R: " << rgb.R << ",  G: " << rgb.G << ", B: " << rgb.B << endl;
		return out;
	}
}