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
			std::cout << "使出重擊(旋風斬)" << std::endl;
		else if (attackType == hit)
			std::cout << "使出一般攻擊(斬擊)" << std::endl;
		break;
	case elf:
		if (attackType == smite)
			std::cout << "使出重擊(連續射擊)" << std::endl;
		else if (attackType == hit)
			std::cout << "使出一般攻擊(射擊)" << std::endl;
		break;
	case wizard:
		if (attackType == smite)
			std::cout << "使出重擊(豪火球術)" << std::endl;
		else if (attackType == hit)
			std::cout << "使出一般攻擊(火球術)" << std::endl;
		break;
	}
		
}

void CPlayer::SetOccupation(Occupation occupation)
{
	m_Occpation = occupation;
}
