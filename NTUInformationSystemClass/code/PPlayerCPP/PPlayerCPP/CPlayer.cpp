#include "CPlayer.h"
CPlayer::CPlayer():m_Name("")
{

}
CPlayer::~CPlayer()
{

}

void CPlayer::Attack(Attacktype attackType)
{
	std::cout << m_Name;
}
