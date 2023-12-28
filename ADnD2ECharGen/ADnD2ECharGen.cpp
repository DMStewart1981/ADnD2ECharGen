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
    do {
        Generated.RollStats();
        std::cout << "STR = " << Generated.Str << std::endl;
        std::cout << "DEX = " << Generated.Dex << std::endl;
        std::cout << "CON = " << Generated.Con << std::endl;
        std::cout << "INT = " << Generated.Int << std::endl;
        std::cout << "WIS = " << Generated.Wis << std::endl;
        std::cout << "CHA = " << Generated.Cha << std::endl;
    } while ((Generated.Str < 9) && (Generated.Dex < 9) && (Generated.Int < 9) && (Generated.Wis < 9));

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
    }

    if (Generated.IsPaladinAvailable == true) {
        std::cout << "Paladin" << std::endl;
    }

    if (Generated.IsRangerAvailable == true) {
        std::cout << "Ranger" << std::endl;
    }

    if (Generated.IsMageAvailable == true) {
        std::cout << "Mage" << std::endl;
    }

    if (Generated.IsClericAvailable == true) {
        std::cout << "Cleric" << std::endl;
    }

    if (Generated.IsDruidAvailable == true) {
        std::cout << "Druid" << std::endl;
    }

    if (Generated.IsThiefAvailable == true) {
        std::cout << "Thief" << std::endl;
    }

    if (Generated.IsBardAvailable == true) {
        std::cout << "Bard" << std::endl;
    }

    std::cout << "Choose from available Classes" << std::endl;

    do {

        std::cin >> Generated.Input;

        /* Testing code
        std::cout << "Input = " << Generated.Input << std::endl; */

        if (Generated.IsFighterAvailable == true && Generated.Input == "Fighter") {
            Generated.IsInputValid = true;
        }

        else if (Generated.IsRangerAvailable == true && Generated.Input == "Ranger") {
            Generated.IsInputValid = true;
        }

        else if (Generated.IsPaladinAvailable == true && Generated.Input == "Paladin") {
            Generated.IsInputValid = true;
        }

        else if (Generated.IsMageAvailable == true && Generated.Input == "Mage") {
            Generated.IsInputValid = true;
        }

        else if (Generated.IsClericAvailable == true && Generated.Input == "Cleric") {
            Generated.IsInputValid = true;
        }

        else if (Generated.IsDruidAvailable == true && Generated.Input == "Druid") {
            Generated.IsInputValid = true;
        }

        else if (Generated.IsThiefAvailable == true && Generated.Input == "Thief") {
            Generated.IsInputValid = true;
        }

        else if (Generated.IsBardAvailable == true && Generated.Input == "Bard") {
            Generated.IsInputValid = true;
        }

        else {
            std::cout << "Please choose an available Character Class.  Available Character Classes are:" << std::endl;
            std::cout << "Available Classes:" << std::endl;

            if (Generated.IsFighterAvailable == true) {
                std::cout << "Fighter" << std::endl;
            }

            if (Generated.IsPaladinAvailable == true) {
                std::cout << "Paladin" << std::endl;
            }

            if (Generated.IsRangerAvailable == true) {
                std::cout << "Ranger" << std::endl;
            }

            if (Generated.IsMageAvailable == true) {
                std::cout << "Mage" << std::endl;
            }

            if (Generated.IsClericAvailable == true) {
                std::cout << "Cleric" << std::endl;
            }

            if (Generated.IsDruidAvailable == true) {
                std::cout << "Druid" << std::endl;
            }

            if (Generated.IsThiefAvailable == true) {
                std::cout << "Thief" << std::endl;
            }

            if (Generated.IsBardAvailable == true) {
                std::cout << "Bard" << std::endl;
            }

        }

    }
    while (Generated.IsInputValid == false);

    Generated.ClassName = Generated.Input;

    /* Code inserted to check variable assignment
    std::cout << "Class chosen is " << Generated.ClassName << std::endl;*/










    return 0;
}