// TwoArrayCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#define PullzeSize 3
int Puzzle[PullzeSize][PullzeSize];
void CreatPuzzle();
void PrintPuzzle();
void MovePuzzle(int num);
int CheckPuzzle();
int main()
{
    int num;
    CreatPuzzle();
    do {
        std::cin >> num;
        MovePuzzle(num);
        system("CLS");
    } while (num != 0);
    if (CheckPuzzle() == 8)
        std::cout << "жие\" << "\n";
    else
        std::cout << "ев▒╤" << "\n";
}

void CreatPuzzle()
{
    int i, j;
    int a, b, c, d, reg;
    srand(time(NULL));

}
void PrintPuzzle()
{

}
void MovePuzzle(int num)
{

}
int CheckPuzzle()
{

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
