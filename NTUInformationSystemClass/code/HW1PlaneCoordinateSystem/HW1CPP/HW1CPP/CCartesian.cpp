#include "CCartesian.h"
CCartesian::CCartesian()
{

}

CCartesian::~CCartesian()
{

}

void CCartesian::reflect()
{
	std::cout << "��x�b�蹳�᪺�I�y��: " << "(" << lhs << ", " << -rhs << ")\n";
	std::cout << "��y�b�蹳�᪺�I�y��: " << "(" << -lhs << ", " << rhs << ")\n";
}
