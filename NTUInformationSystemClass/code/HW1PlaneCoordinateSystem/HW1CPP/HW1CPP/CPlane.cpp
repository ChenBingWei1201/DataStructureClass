#include "CPlane.h"
CPlane::CPlane() : lhs(0), rhs(0)
{

}
CPlane::~CPlane()
{

}

void CPlane::getPoint(int lElement, int rElement)
{
	lhs = lElement;
	rhs = rElement;
}

void CPlane::reflect()
{

}




