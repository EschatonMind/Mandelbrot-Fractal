#pragma once
#include<iostream>
#include<string>
#include<cstdint>
#include<memory>
#include<math.h>
#include<vector>
#include<assert.h>
#include"Zoom.h"
#include"ZoomList.h"
#include"Mandelbrot.h"
#include"Bitmap.h"
#include"RGB.h"

using namespace std;

namespace Frac {

	class FractalCreator
	{
	private:
		int m_Width;
		int m_Height;
		unique_ptr<int[]> m_Histogram;
		unique_ptr<int[]> m_Fractal;
		Bitmap m_Bitmap;
		ZoomList m_Zoomlist;
		int m_Total{ 0 };

		vector<int> m_Ranges;
		vector<RGB> m_Colors;
		vector<int> m_RangeTotals;

		bool CatchFirstFrac{false};

	private:
		void CalculateIterations();
		void CalculateTotalIterations();
		void CalculateRangeTotals();
		void DrawFractal();
		void WriteBitmap(string name);

	public:
		int GetRange(int iterations)const;

		FractalCreator(int width, int height);
		void AddRange(double endRange, const RGB& rgb);
		void AddZoom(const Zoom& zoom);
		virtual ~FractalCreator();
		void Run(string name);
	};

}

