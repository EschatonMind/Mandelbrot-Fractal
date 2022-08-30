#pragma once
#include<string>
#include<cstdint>
#include<memory>
using namespace std;

namespace Frac {

	class Bitmap
	{

	private:

		int m_Width{ 0 };
		int m_Height{ 0 };
		unique_ptr<uint8_t[]> m_pPixels{ nullptr };
	
	public:

		Bitmap(int Width, int Height);
		void SetPixels(int X, int Y, uint8_t Red, uint8_t Green, uint8_t Blue);
		bool Write(string filename);
		virtual~Bitmap();

	};

}
