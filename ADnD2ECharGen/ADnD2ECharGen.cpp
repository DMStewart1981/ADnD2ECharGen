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

    Generated.CheckFighter();
    Generated.CheckPaladin();
    Generated.CheckRanger();
    Generated.CheckMage();
    Generated.CheckCleric();
    Generated.CheckDruid();
    Generated.CheckThief();
    Generated.CheckBard();

    //Code inserted for testing

/*  std::cout << "Is Fighter Available = " << Generated.IsFighterAvailable << std::endl;
    std::cout << "Is Paladin Available = " << Generated.IsPaladinAvailable << std::endl;
    std::cout << "Is Ranger Available = " << Generated.IsRangerAvailable << std::endl;
    std::cout << "Is Mage Available = " << Generated.IsMageAvailable << std::endl;
    std::cout << "Is Cleric Available = " << Generated.IsClericAvailable << std::endl;
    std::cout << "Is Druid Available = " << Generated.IsDruidAvailable << std::endl;
    std::cout << "Is Thief Available = " << Generated.IsThiefAvailable << std::endl;
    std::cout << "Is Bard Available = " << Generated.IsBardAvailable << std::endl;  */



    std::cout << "Available Classes:" << std::endl;

    if (Generated.IsFighterAvailable == true) {
        std::cout << "Fighter" << std::endl;
    };

    if (Generated.IsPaladinAvailable == true) {
        std::cout << "Paladin" << std::endl;
    };

    if (Generated.IsRangerAvailable == true) {
        std::cout << "Ranger" << std::endl;
    };

    if (Generated.IsMageAvailable == true) {
        std::cout << "Mage" << std::endl;
    };

    if (Generated.IsClericAvailable == true) {
        std::cout << "Cleric" << std::endl;
    };

    if (Generated.IsDruidAvailable == true) {
        std::cout << "Druid" << std::endl;
    };

    if (Generated.IsThiefAvailable == true) {
        std::cout << "Thief" << std::endl;
    };

    if (Generated.IsBardAvailable == true) {
        std::cout << "Bard" << std::endl;
    };

    std::cout << "Choose from available Classes" << std::endl;


















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
