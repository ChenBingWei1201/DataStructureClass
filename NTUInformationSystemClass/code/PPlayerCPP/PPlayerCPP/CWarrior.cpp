#include "CWarrior.h"

CWarrior::CWarrior()
{
}
CWarrior::~CWarrior()
{
}

void CWarrior::Attack(Attacktype attackType)
{
	CPlayer::Attack(attackType);
	if (attackType == smite)
		std::cout << "�ϥX����(�ۭ���)" << std::endl;
	else if (attackType == hit)
		std::cout << "�ϥX�@�����(����)" << std::endl;
}


