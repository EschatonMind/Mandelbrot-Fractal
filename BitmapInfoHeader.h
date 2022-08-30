#pragma once
#include<cstdint>
using namespace std;
#pragma pack(2)
namespace Frac{

struct BitmapInfoHeadr {

	int32_t HeadrSize{ 40 };
	int32_t Width;
	int32_t Height;
	int16_t Planes{ 1 };
	int16_t BitesPerPixel{ 24 };
	int32_t Compression{ 0 };
	int32_t DataSize{ 0 };
	int32_t HorizontalResolution{ 2400 };
	int32_t VerticalResolution{ 2400 };
	int32_t Colors{ 0 };
	int32_t ImportantColors{ 0 };
};

}
