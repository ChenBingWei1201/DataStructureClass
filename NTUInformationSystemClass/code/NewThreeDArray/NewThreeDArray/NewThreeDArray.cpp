// NewThreeDArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int i, j, k;
    int n, people, subject;
    float cSum, pSum; // class sum & people sum
    int*** score;
    std::cout << "請輸入班級數: ";
    std::cin >> n;
    std::cout << "請輸入科目數: ";
    std::cin >> subject;
    std::cout << "請輸入學生人數: ";
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
            std::cout << "請輸入編號" << i + 1 << "的學生成績: " << std::endl;
            for (k = 0; k < subject; k++)
            {
                std::cout << "請輸入第" << j + 1 << "科目的成績: ";
                std::cin >> score[i][j][k];
                pSum += score[i][j][k];
            }
            std::cout << "編號" << j + 1 << "學生總平均: " << pSum / subject << std::endl;
        }
        std::cout << "編號" << i + 1 << "班級總平均: " << cSum / n << std::endl;
    }
    
    
    for (i = 0; i < people; i++)
    {
        
        for (j = 0; j < people; j++)
            delete[]score[i][j];
        delete[]score[];
    }
        

    delete[]score; // 升一維

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
