#include "CPlayer.h"
#include <iostream>
CPlayer::CPlayer(): m_Occpation(none), m_Name("")
{

}
CPlayer::~CPlayer()
{

}

void CPlayer::Attack(Attacktype attackType)
{
	std::cout << m_Name;
	switch (m_Occpation)
	{
	case warrior:
		if (attackType == smite)
			std::cout << "�ϥX����(�ۭ���)" << std::endl;
		else if (attackType == hit)
			std::cout << "�ϥX�@�����(����)" << std::endl;
		break;
	case elf:
		if (attackType == smite)
			std::cout << "�ϥX����(�s��g��)" << std::endl;
		else if (attackType == hit)
			std::cout << "�ϥX�@�����(�g��)" << std::endl;
		break;
	case wizard:
		if (attackType == smite)
			std::cout << "�ϥX����(�����y�N)" << std::endl;
		else if (attackType == hit)
			std::cout << "�ϥX�@�����(���y�N)" << std::endl;
		break;
	}
		
}

void CPlayer::SetOccupation(Occupation occupation)
{
	m_Occpation = occupation;
}
