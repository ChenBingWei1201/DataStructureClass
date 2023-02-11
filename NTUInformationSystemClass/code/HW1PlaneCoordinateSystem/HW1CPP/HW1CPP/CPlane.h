#pragma once
#include <iostream>
enum PlaneType {cartesian = 1 , polar};
class CPlane
{
	public:
		CPlane();
		virtual~CPlane();
		void getPoint(int , int);
		virtual void reflect();
	protected:
		int lhs, rhs;
};









