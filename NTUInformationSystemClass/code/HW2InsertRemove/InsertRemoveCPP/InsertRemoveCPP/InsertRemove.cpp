// ExpandStackCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstring>
#include "CBaseStack.h"
int main()
{
    int val = 0, maxSize = 20;
    std::string failToPop = "Fail to pop! Because there is no value in the array.\n";
    std::string failToRemove = "Fail to remove! Because there is no value in the array.\n";
    srand(time(NULL));
    CStack<int> baseStack;

    for (int i = 0; i < maxSize; i++)
    {
        val = rand() % 100;
        baseStack.push(val);
        std::cout << std::setw(2) << val << "  ";
        if (i % 10 == 9)
            std::cout << "\n";
    }
  
    for (int i = 0; i < 39; i++) // demarcation
        std::cout << (i == 38 ? "\n" : "/");

    for (int i = 0; i < maxSize; i++)
    {
        if (baseStack.pop(val))
        {
            std::cout << std::setw(2) << val << "  ";
            if (i % 10 == 9)
                std::cout << std::endl;
        }
        else
            std::cout << failToPop;
    }

    char command = '0';
    int pos = 0;
    do {
        std::cout << "Do you want to insert(i) or remove(r) any element?" << "\n";
        std::cout << "If not, press n to exit." << "\n";
        std::cin >> command;
        if (command == 'i')
        {
            std::cout << "Where do you want to insert?" << "\n";
            std::cin >> pos;
            std::cout << "What value do you want to insert?" << "\n";
            std::cin >> val;
            baseStack.insert(pos, val);

            for (int i = 0; i < 39; i++) // demarcation
                std::cout << (i == 38 ? "\n" : "/");
            
            maxSize++;
            for (int i = 0; i < maxSize; i++)
            {
                if ((baseStack.pop(val)) && (pos <= maxSize - 1))
                {
                    std::cout << std::setw(2) << val << "  ";
                    if ((i % 10 == 9) || (i == maxSize - 1))
                        std::cout << std::endl;
                }
                else
                    std::cout << failToPop;
            }
        }
        else if (command == 'r') // remove
        {
            std::cout << "Where do you want to remove?" << "\n";
            std::cin >> pos;
            
            if (baseStack.remove(pos))
            {
                for (int i = 0; i < 39; i++) // demarcation
                    std::cout << (i == 38 ? "\n" : "/");
                
                maxSize--;
                for (int i = 0; i < maxSize; i++)
                {
                    if ((baseStack.pop(val)) && (pos <= maxSize - 1))
                    {
                        std::cout << std::setw(2) << val << "  ";
                        if ((i % 10 == 9) || (i == maxSize - 1))
                            std::cout << std::endl;
                    }
                    else
                        std::cout << failToPop;
                }
            }
            else
                std::cout << failToRemove;
        }
    } while (command != 'n');
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
