#pragma once
class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	std::string m_Name;
	void Attack(AttackType attackType);
};

