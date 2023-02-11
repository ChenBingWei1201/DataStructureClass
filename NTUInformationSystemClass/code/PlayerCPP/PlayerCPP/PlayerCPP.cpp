// PlayerCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Cplayer.h"
int main()
{
	CPlayer player;
	int occupation;
	std::cout << "請選擇角色職業" << std::endl;
	std::cout << "1.戰士\t2.精靈\t3.法師\n";
	std::cin >> occupation;
	player.SetOccupation((Occupation)occupation);
	std::cout << "請選擇角色名稱(不超過10中文個字)" << std::endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
