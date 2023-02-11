// CircularQueueCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "CCircularQueue.h"
int main()
{
	int size = 0, value = 0;
	CCircularQueue<int> queue;
	srand(time(NULL));
	std::cout << "Please enter the size of array: ";
	std::cin >> size;
	queue.setSize(size);
	for (int i = 0; i < size; i++)
	{
		value = rand() % 100;
		if (queue.push(value))
			std::cout << std::setw(2) << value << " ";
		else
			std::cout << "fail to push!";
	}

	std::cout << "\n" << "\\\\\\\\\\\\\\\\" << "\n";

	for (int i = 0; i < size; i++)
	{
		if (queue.pop(value))
			std::cout << std::setw(2) << value << " ";
		else
			std::cout << "fail to pop!";
	}
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
