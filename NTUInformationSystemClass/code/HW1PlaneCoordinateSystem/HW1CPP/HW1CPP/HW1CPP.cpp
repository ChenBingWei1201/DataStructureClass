// HW1CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CCartesian.h"
#include "CPolar.h"

int main()
{
    CPlane *plane = NULL;
    int type = 0, lhs = 0, rhs = 0;

    std::cout << "請問你要使用哪種座標系統?" << "\n";
    std::cout << "1.直角座標系(輸入1)" << "\t" << "2.極座標系(輸入2)" << "\n";
    std::cin >> type; // type of coordinate system  = cartesian or ploar 
    
    switch (type)
    {
        case cartesian :
            plane = new CCartesian;
            break;
        case polar:
            plane = new CPolar;
            break;
    }

    std::cout << "請輸入欲鏡像的點座標(皆為整數): " << "\n";
    std::cin >> lhs >> rhs; // left hand side & right hand side 
    plane->getPoint(lhs, rhs); // get the point user gave
    std::cout << "原座標(" << lhs << ", " << rhs << ")在對兩軸分別鏡像後的座標分別為: \n";
    plane->reflect(); // show the points after reflected with respect to two axis respectively
    delete plane;
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
