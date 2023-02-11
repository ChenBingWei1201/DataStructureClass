// HW5CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include "CBinarySearchTree.h"
int main()
{
	std::string success = "Success to remove number ";
	std::string fail = "Fail to remove because there is no number ";
	int a[] = { 41, 67, 34, 0, 69, 24, 78, 58, 62, 64,\
		5, 45, 81, 27, 61, 91, 95, 42, 27, 36,\
		91, 4, 2, 53, 92, 82, 21, 16, 18, 95,\
		47, 26, 71, 38, 69, 12, 67, 99, 35, 94,\
		3, 11, 22, 33, 73, 64, 41, 11, 53, 68 };

	// demo: insertion
	CBinarySearchTree<int> bst;
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		std::cout << "Insert: " << a[i] << std::endl;
		if (!bst.Insert(a[i]))
			std::cout << "Insert fail: " << a[i] << std::endl;
	}
	bst.LevelOrder(bst.m_Root);
	std::cout << std::endl;

	// demo: remove inexist number
	std::cout << "After remove 1:" << std::endl;
	if (bst.Remove(1))
		std::cout << success << 1 << " in the tree!\n";
	else
		std::cout << fail << 1 << " in the tree!\n";
	bst.LevelOrder(bst.m_Root);
	std::cout << "\n";

	// demo: remove the node with only one son
	std::cout << "After remove 2:" << std::endl;
	if (bst.Remove(2))
		std::cout << success << 2 << " in the tree!\n";
	else
		std::cout << fail << 2 << " in the tree!\n";
	bst.LevelOrder(bst.m_Root);
	std::cout << std::endl;

	// demo: remove the node with two sons
	std::cout << "After remove 16:" << std::endl;
	if (bst.Remove(16))
		std::cout << success << 16 << " in the tree!\n";
	else
		std::cout << fail << 16 << " in the tree!\n";
	bst.LevelOrder(bst.m_Root);
	std::cout << std::endl;

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
