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
		std::cout << "使出重擊(旋風斬)" << std::endl;
	else if (attackType == hit)
		std::cout << "使出一般攻擊(斬擊)" << std::endl;
}


