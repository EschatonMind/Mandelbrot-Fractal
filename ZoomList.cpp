#include "ZoomList.h"
namespace Frac {

	ZoomList::ZoomList(int width, int height): m_Width(width), m_Height(height){}

	void ZoomList::Add(const Zoom& zoom) {
		Zooms.push_back(zoom);
	}

	pair<double, double> ZoomList::DoZoom(int x, int y) {
		return pair<double, double>(0,0);
	}

}