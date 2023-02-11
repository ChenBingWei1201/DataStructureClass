// VectorCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
int main()
{
    std::vector<std::string> sentence;
    sentence.reserve(5);
    sentence.push_back("Hello, ");
    sentence.push_back("how");
    sentence.push_back("are");
    sentence.push_back("you");
    sentence.push_back("?");

    for (int i = 0; i < sentence.size(); i++)
        std::cout << sentence[i] << " ";
    std::cout << "\n";
    std::cout << sentence.max_size() << "\n";
    std::cout << sentence.size() << "\n";
    std::cout << sentence.capacity() << "\n";
    std::swap(sentence[1], sentence[3]);
    sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");
    sentence.back() = "!";

    for (int i = 0; i < sentence.size(); i++)
        std::cout << sentence[i] << " ";
    std::cout << "\n";
    std::cout << sentence.max_size() << "\n";
    std::cout << sentence.size() << "\n";
    std::cout << sentence.capacity() << "\n";
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
