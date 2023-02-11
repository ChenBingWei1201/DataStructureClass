#pragma once
#include <string>
enum Occupation{none, warrior, elf, wizard};
enum Attacktype{smite, hit};
class CPlayer
{
public:
	CPlayer();
	~CPlayer();
	void Attack(Attacktype attackType);
	void SetOccupation(Occupation occupation);
	std::string m_Name;
private:
	Occupation m_Occpation;
};

