#pragma once
#include<vector>
#include<utility>
#include"Zoom.h"

using namespace std;

namespace Frac {

	class ZoomList
	{

	private:
		int m_XCenter{ 0 };
		int m_YCenter{ 0 };
		double m_Scale{ 1.0 };

		int m_Width{ 0 };
		int m_Height{ 0 };
		vector<Zoom> Zooms;

	public:
		ZoomList(int width, int height);
		void Add(const Zoom& zoom);
		pair<double, double> DoZoom(int x, int y);

	};

}

