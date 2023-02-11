// TemplateCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iomanip>
#include <iostream>
template<class T>
T Max(T a, T b);

// std::cout << 
int main()
{
    int arraySize = 10;
    int* piArray = new int[arraySize];
    std::cout << "Int Data Array: " << std::endl;
    srand((unsigned)time(NULL));
    for (int i = 0; i < arraySize; i++)
    {
        piArray[i] = rand();
        std::cout << piArray[i] << "\t";
    }
    std::cout << "\n";
    int imax = piArray[0];
    for (int i = 0; i < arraySize; i++)
    {
        imax = Max<int>(imax, piArray[i]);
    }
    std::cout << imax << "\n";

    float* pfArray = new float[arraySize];
    std::cout << "Float Data Array: " << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        pfArray[i] = (float)rand()/RAND_MAX;
        std::cout << std::setprecision(2) << std::setw(6) <<pfArray[i] << "\t";
    }
    std::cout << "\n";
    float fmax = pfArray[0];
    for (int i = 0; i < arraySize; i++)
    {
        fmax = Max<float>(fmax, pfArray[i]);
    }
    std::cout << fmax << "\n";

}

template<class T>
T Max(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
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
