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
		std::cout << "�ϥX����(�����y�N)" << std::endl;
	else if (attackType == hit)
		std::cout << "�ϥX�@�����(���y�N)" << std::endl;
}
