// NewThreeDArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int i, j, k;
    int n, people, subject;
    float cSum, pSum; // class sum & people sum
    int*** score;
    std::cout << "�п�J�Z�ż�: ";
    std::cin >> n;
    std::cout << "�п�J��ؼ�: ";
    std::cin >> subject;
    std::cout << "�п�J�ǥͤH��: ";
    std::cin >> people;
    score = new int** [n];
    for (i = 0; i < n; i++)
    {
        score = new int* [people];
        for (i = 0; i < people; i++)
            score[i] = new int[subject];
    }
    
    for (i = 0; i < n; i++)
    {
        cSum = 0;
        for (j = 0; j < people; j++)
        {
            cSum = 0;
            std::cout << "�п�J�s��" << i + 1 << "���ǥͦ��Z: " << std::endl;
            for (k = 0; k < subject; k++)
            {
                std::cout << "�п�J��" << j + 1 << "��ت����Z: ";
                std::cin >> score[i][j][k];
                pSum += score[i][j][k];
            }
            std::cout << "�s��" << j + 1 << "�ǥ��`����: " << pSum / subject << std::endl;
        }
        std::cout << "�s��" << i + 1 << "�Z���`����: " << cSum / n << std::endl;
    }
    
    
    for (i = 0; i < people; i++)
    {
        
        for (j = 0; j < people; j++)
            delete[]score[i][j];
        delete[]score[];
    }
        

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
