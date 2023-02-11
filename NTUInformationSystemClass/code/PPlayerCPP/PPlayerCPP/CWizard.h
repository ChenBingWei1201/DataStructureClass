#pragma once
#include "CPlayer.h"
class CWizard : public CPlayer
{
public:
	CWizard();
	~CWizard();
	void Attack(Attacktype attackType);
};

