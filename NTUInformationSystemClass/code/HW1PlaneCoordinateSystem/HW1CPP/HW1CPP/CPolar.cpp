#include "CPolar.h"

CPolar::CPolar()
{

}

CPolar::~CPolar()
{

}

void CPolar::reflect()
{
	std::cout << "對L軸鏡像後的點座標: " << "(" << lhs << ", " << 360 - rhs << "°)\n";
	std::cout << "對虛軸鏡像後的點座標: " << "(" << lhs << ", ";
	if (rhs <= 180)
		std::cout << 180 - rhs;
	else
		std::cout << 540 - rhs;
	std::cout << "°)\n";
}
