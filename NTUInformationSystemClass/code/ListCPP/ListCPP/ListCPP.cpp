// ListCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

void PrintList(std::list<int>& l1, std::list<int>& l2);

int main()
{
    std::list<int> list1, list2;
    for (int i = 0; i < 6; i++)
    {
        list1.push_back(i);
        list2.push_front(i);
    }
    PrintList(list1, list2);
    list2.splice(std::find(list1.begin(), list1.end(), 3), list1);
    PrintList(list1, list2);
    list2.splice(list2.end(), list2, list2.begin());
    PrintList(list1, list2);
    list2.sort();
    list1 = list2;
    list2.unique();
    
    PrintList(list1, list2);
    list1.merge(list2);
    PrintList(list1, list2);
    return 0;
}

void PrintList(std::list<int>& l1, std::list<int>& l2)
{
    std::list<int>::iterator it;
    std::cout << "List1: ";
    for (it = l1.begin(); it != l1.end(); it++)
        std::cout << *it << " ";

    std::cout << "\n";

    std::cout << "List2: ";
    for (it = l2.begin(); it != l2.end(); it++)
        std::cout << *it << " ";

    std::cout << "\n";
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

