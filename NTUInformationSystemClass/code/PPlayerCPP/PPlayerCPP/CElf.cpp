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
		std::cout << "�ϥX����(�s��g��)" << std::endl;
	else if (attackType == hit)
		std::cout << "�ϥX�@�����(�g��)" << std::endl;
}
