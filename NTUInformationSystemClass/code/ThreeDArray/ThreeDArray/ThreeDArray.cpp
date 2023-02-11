// ThreeDArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#define X 5
#define Y 4
#define Z 3

void CreateMatrix(int a[Y][X]);
void PrintMatrix(int a[Y][X]);
int main()
{
    int i, j;
    int matrix[Z][Y][X];
    std::cout << "Matrix A" << "\n";
    CreateMatrix(matrix[0]);
    PrintMatrix(matrix[0]);

    std::cout << "Matrix B" << "\n";
    CreateMatrix(matrix[1]);
    PrintMatrix(matrix[1]);

    std::cout << "Matrix C" << "\n";
    for (j = 0; j < Y; j++)
        for (i = 0; i < X; i++)
            matrix[2][j][i] = matrix[0][j][i] + matrix[1][j][i];

}

void CreateMatrix(int a[Y][X])
{

}

void AddMatrix(int a[Y][X])
{

}

void PrintMatrix(int a[Y][X])
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
