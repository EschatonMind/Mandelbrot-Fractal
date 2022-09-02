#pragma once
namespace Frac {

	struct Zoom {
		int X{ 0 };
		int Y{ 0 };
		double Scale{ 0 };

		Zoom(int x, int y, double scale) :X(x), Y(y), Scale(scale) {};
	};

}