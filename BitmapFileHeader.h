#pragma once
#include<cstdint>
using namespace std;
#pragma pack(2)
namespace Frac {

	struct BitmapFileHeadr {
		char headr[2]{ 'B','M' };
		int32_t FileSize;
		int32_t Reserved{ 0 };
		int32_t DataOffset;
	};

}
