// NewTwoArrayCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int i, j;
    int people, subject;
    float sum ;
    int** score;
    std::cout << "�п�J��ؼ�: ";
    std::cin >> subject;
    std::cout << "�п�J�ǥͤH��: ";
    std::cin >> people;
    score = new int* [people];
    for (i = 0; i < people; i++)
        score[i] = new int[subject];
    for (i = 0; i < people; i++)
    {
        sum = 0;
        std::cout << "�п�J�s��" << i + 1 << "���ǥͦ��Z: " << std::endl;
        for (j = 0; j < subject; j++)
        {
            std::cout << "�п�J��" << j + 1 << "��ت����Z: ";
            std::cin >> score[i][j];
            sum += score[i][j];
        }
        std::cout << "�s��" << i + 1 << "�ǥ��`����: " << sum / subject << std::endl;
    }

    for (i = 0; i < people; i++)
        delete[]score[i]; 

    delete[]score; // �ɤ@��
      
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
