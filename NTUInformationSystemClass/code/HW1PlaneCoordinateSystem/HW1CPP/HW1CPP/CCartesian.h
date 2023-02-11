#pragma once
#include "CPlane.h"
class CCartesian : public CPlane
{
	public:
		CCartesian();
		~CCartesian();
		void reflect();
};

