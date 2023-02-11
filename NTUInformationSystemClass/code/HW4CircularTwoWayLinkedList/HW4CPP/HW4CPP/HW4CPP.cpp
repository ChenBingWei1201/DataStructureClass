// HW4CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CCircularDoubleLinkedList.h"
int main()
{
	CCircularDoubleLinkedList<int> linkedList;
	int size = 0;
	if (!linkedList.SetSize(6))
		std::cout << "Fail to set size!\n";
	else
		std::cout << "The size of the circular double linked list: 6\n\n";
	
	// demo add front
	std::cout << "demo add front:\n\n";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "Add Front: " << i + 10 << "\n";
		if (!linkedList.AddFront(i + 10))
			std::cout << "AddFront fail!\n";
		else
			std::cout << "AddFront success!\n";
	}
	linkedList.Show();
	
	// demo add back success and fail
	std::cout << "demo add back:\n\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Add Back: " << i << "\n";
		if (!linkedList.AddBack(i))
			std::cout << "AddBack fail!\n";
		else
			std::cout << "AddBack success!\n";
	}
	linkedList.Show();

	// demo insert success!
	std::cout << "demo insert success!:\n\n";
	std::cout << "After insert 33 at position 3..." << std::endl;
	if (!linkedList.Insert(3, 33))
		std::cout << "Insert fail!\n";
	else
		std::cout << "Insert success!\n";
	linkedList.Show();
	
	// demo insert fail!
	std::cout << "demo insert fail!:\n\n";
	std::cout << "After insert 99 at position 9..." << std::endl;
	if (!linkedList.Insert(9, 99))
		std::cout << "Insert fail!\n";
	else
		std::cout << "Insert success!\n";
	linkedList.Show();
	

	// demo remove fail!
	std::cout << "demo remove fail!:\n\n";
	std::cout << "After remove position 10..." << std::endl;
	if (!linkedList.Remove(10))
		std::cout << "remove fail!\n";
	else
		std::cout << "remove success!\n";
	linkedList.Show();

	// demo remove success!
	std::cout << "demo remove success!:\n\n";
	std::cout << "After remove position "<< 5 << "..." << std::endl;
	if (!linkedList.Remove(5))
		std::cout << "remove fail!\n";
	else
		std::cout << "remove success!\n";
	linkedList.Show();

	// demo circle!
	std::cout << "prove it is exactly a circle!:\n\n";
	for (int i = 0; i < 2; i++)
	{
		std::cout << "After remove position "<< 0 << "..." << std::endl;
		if (!linkedList.Remove(0))
			std::cout << "remove fail!\n";
		else
			std::cout << "remove success!\n";
		linkedList.Show();
	}

	for (int i = 5; i > 1; i--)
	{
		std::cout << "Add Back: " << i << "\n";
		if (!linkedList.AddBack(i))
			std::cout << "AddBack fail!\n";
		else
			std::cout << "AddBack success!\n";
	}
	linkedList.Show();
	
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
