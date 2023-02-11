#pragma once
#include <string>
#include <iostream>
enum Occupation { none, warrior, elf, wizard };
enum Attacktype { smite, hit };
class CPlayer
{
public:
	CPlayer();
	virtual ~CPlayer();
	virtual void Attack(Attacktype attackType);
	std::string m_Name;
};