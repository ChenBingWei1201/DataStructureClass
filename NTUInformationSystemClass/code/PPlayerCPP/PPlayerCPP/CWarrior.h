#pragma once
#include "CPlayer.h"
class CWarrior : public CPlayer
{
public:
	CWarrior();
	~CWarrior();
	void Attack(Attacktype attackType);
};

