#include "CElf.h"

CElf::CElf()
{
}

CElf::~CElf()
{
}

void CElf::Attack(Attacktype attackType)
{
	CPlayer::Attack(attackType);
	if (attackType == smite)
		std::cout << "使出重擊(連續射擊)" << std::endl;
	else if (attackType == hit)
		std::cout << "使出一般攻擊(射擊)" << std::endl;
}
