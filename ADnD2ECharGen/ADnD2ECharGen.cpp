// ADnD2ECharGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Definitions.h"

int main() {
 
    /*auto Stats = StatList();

    std::cout << "STR = " << Stats[0] << std::endl;
    std::cout << "DEX = " << Stats[1] << std::endl;
    std::cout << "CON = " << Stats[2] << std::endl;
    std::cout << "INT = " << Stats[3] << std::endl;
    std::cout << "WIS = " << Stats[4] << std::endl;
    std::cout << "CHA = " << Stats[5] << std::endl;*/

    Character Generated;
    Generated.RollStats();
    std::cout << "STR = " << Generated.Str << std::endl;
    std::cout << "DEX = " << Generated.Dex << std::endl;
    std::cout << "CON = " << Generated.Con << std::endl;
    std::cout << "INT = " << Generated.Int << std::endl;
    std::cout << "WIS = " << Generated.Wis << std::endl;
    std::cout << "CHA = " << Generated.Cha << std::endl;




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
