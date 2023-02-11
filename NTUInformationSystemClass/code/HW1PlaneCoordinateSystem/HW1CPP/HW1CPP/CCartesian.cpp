#include "CCartesian.h"
CCartesian::CCartesian()
{

}

CCartesian::~CCartesian()
{

}

void CCartesian::reflect()
{
	std::cout << "對x軸鏡像後的點座標: " << "(" << lhs << ", " << -rhs << ")\n";
	std::cout << "對y軸鏡像後的點座標: " << "(" << -lhs << ", " << rhs << ")\n";
}
