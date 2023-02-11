// HW3CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include "CCircularQueue.h"
int main()
{
	int qSize = 0, value = 0;
	CCircularQueue<int> queue;
	srand(time(NULL));
	std::cout << "Please determine the size of a queue: ";
	std::cin >> qSize;
	queue.setSize(qSize);

	int command = 0, pushSize = 0, popSize = 0; // command, push size, pop size
	std::string query = "Do you want to push back(1), push front(2),  pop back(3), or pop front(4) any element?\n";
	do {
		std::cout << "\n" << query;
		std::cout << "If not, press 0 to exit." << "\n";
		std::cin >> command;
		switch (command)
		{
			case PushBack:
				std::cout << "Please determine the size to \"push back\" : ";
				std::cin >> pushSize;
				std::cout << "\nthe values you \"push back\" into the array: \n";
				for (int i = 0; i < pushSize; i++)
				{
					value = rand() % 100;
					if (queue.pushBack(value)) 
						std::cout << std::setw(2) << value << "  ";
					else
						std::cout << "Fail to \"push back\"! ";
				}
				std::cout << "\n";
				break;
			case PushFront:
				std::cout << "Please determine the size to \"push front\": ";
				std::cin >> pushSize;
				std::cout << "\nthe values you \"push front\" into the array: \n";
				for (int i = 0; i < pushSize; i++)
				{
					value = rand() % 100;
					if (queue.pushFront(value))
						std::cout << std::setw(2) << value << "  ";
					else
						std::cout << "Fail to \"push front\"! ";
				}
				std::cout << "\n";
				break;
			case PopBack:
				std::cout << "Please determine the size to \"pop back\": ";
				std::cin >> popSize;
				std::cout << "\nthe values you \"pop back\" out the array: \n";
				for (int i = 0; i < popSize; i++)
				{
					if (queue.popBack(value))
						std::cout << std::setw(2) << value << "  ";
					else
						std::cout << "Fail to \"pop back\"! ";
				}
				std::cout << "\n";
				break;
			case PopFront:
				std::cout << "Please determine the size to \"pop front\": ";
				std::cin >> popSize;
				std::cout << "\nthe values you \"pop front\" out the array: \n";
				for (int i = 0; i < popSize; i++)
				{
					if (queue.popFront(value)) 
						std::cout << std::setw(2) << value << "  ";
					else
						std::cout << "Fail to \"pop front\"! ";
				}
				std::cout << "\n";
				break;
		}
	} while (command != 0);
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
