#pragma once
#include "CPlayer.h"
class CElf : public CPlayer
{
public:
	CElf();
	~CElf();
	void Attack(Attacktype attackType);
};

