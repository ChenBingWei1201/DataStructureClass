#include "CWizard.h"

CWizard::CWizard()
{
}

CWizard::~CWizard()
{
}

void CWizard::Attack(Attacktype attackType)
{
	CPlayer::Attack(attackType);
	if (attackType == smite)
		std::cout << "使出重擊(豪火球術)" << std::endl;
	else if (attackType == hit)
		std::cout << "使出一般攻擊(火球術)" << std::endl;
}
