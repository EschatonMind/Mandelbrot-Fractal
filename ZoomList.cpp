#include "ZoomList.h"
using namespace std;
namespace Frac {

	ZoomList::ZoomList(int width, int height): m_Width(width), m_Height(height){}

	void ZoomList::Add(const Zoom& zoom) {
		Zooms.push_back(zoom);

		m_XCenter += (zoom.X - m_Width / 2) * m_Scale;
		m_YCenter += (zoom.Y - m_Height / 2) * m_Scale;

		m_Scale *= zoom.Scale;
	}

	pair<double, double> ZoomList::DoZoom(int x, int y) {
		double XFractal = (x - m_Width / 2) * m_Scale + m_XCenter;
		double YFractal= (y - m_Height / 2) * m_Scale + m_YCenter;
		return pair<double, double>(XFractal,YFractal);
	}

}