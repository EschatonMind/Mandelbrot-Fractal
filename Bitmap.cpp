#include "Bitmap.h"
#include"BitmapFileHeader.h"
#include"BitmapInfoHeader.h"
#include<fstream>

using namespace Frac;
using namespace std;

namespace Frac{

	Bitmap::Bitmap(int Width, int Height) : m_Width(Width), m_Height(Height), m_pPixels(new uint8_t[Width*Height*3]{}) {


	}

	bool Bitmap::Write(string filename) {
		BitmapFileHeadr FileHeader;
		BitmapInfoHeadr InfoHeader;

		FileHeader.DataOffset = sizeof(BitmapFileHeadr) + sizeof(BitmapInfoHeadr);
		FileHeader.FileSize = FileHeader.DataOffset + (m_Width * m_Height * 3);
		
		InfoHeader.Width = m_Width;
		InfoHeader.Height = m_Height;

		ofstream File;
		File.open(filename, ios::out | ios::binary);

		if (!File) {
			return false;
		}

		File.write((char*)&FileHeader, sizeof(FileHeader));
		File.write((char*)&InfoHeader, sizeof(InfoHeader));
		File.write((char*)m_pPixels.get(), (m_Width*m_Height*3));

		File.close();

		if (!File) {
			return false;
		}

		return true;
	}

	void Bitmap::SetPixels(int X, int Y, uint8_t Red, uint8_t Green, uint8_t Blue) {

		uint8_t* pPixel = m_pPixels.get();
		
		pPixel += (Y * 3) * m_Width + (X * 3);

		pPixel[0] = Blue;
		pPixel[1] = Green;
		pPixel[2] = Red;
	}

	Bitmap::~Bitmap() {

	}

}