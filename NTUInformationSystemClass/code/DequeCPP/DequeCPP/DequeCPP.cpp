// DequeCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque> // must include deque to do the thing below.
#include <cstring>

int main()
{
    std::deque<std::string> set; // 集合
    set.assign(3, std::string("string")); // (預設空間大小，預設內容)
    set.push_back("the last string"); // 在尾端加
    set.push_front("the first string"); // 在頭端加
    for (int i = 0; i < set.size(); i++)
        std::cout << set[i] << "\n";

    std::cout << "\n";
    set.pop_front();
    set.pop_back();
    for (int i = 1; i < set.size(); i++)
        set[i] = "another " + set[i];
    set.resize(4, std::string("resized string"));
    for (int i = 0; i < set.size(); i++)
        std::cout << set[i] << "\n";

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
