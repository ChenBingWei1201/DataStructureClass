#include "CPolar.h"

CPolar::CPolar()
{

}

CPolar::~CPolar()
{

}

void CPolar::reflect()
{
	std::cout << "��L�b�蹳�᪺�I�y��: " << "(" << lhs << ", " << 360 - rhs << "�X)\n";
	std::cout << "���b�蹳�᪺�I�y��: " << "(" << lhs << ", ";
	if (rhs <= 180)
		std::cout << 180 - rhs;
	else
		std::cout << 540 - rhs;
	std::cout << "�X)\n";
}
