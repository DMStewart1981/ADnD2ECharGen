// ADnD2ECharGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
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

    //Code for debugging
    //Generated.Str = 18;

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

    Generated.TypeSort();

    //std::cout << Generated.CharacterType << std::endl;



    if ((Generated.CharacterType == 1) && (Generated.Str == 18)) {
        Generated.ExceptionalStrength = Generated.RollPercent();
    }

    Generated.SetSaves();
    Generated.StrengthAdjustments();
    Generated.DexAdjustments();
    Generated.ConstitutionAdjustments();
    Generated.IntelligenceAdj();
    Generated.WisdomAdj();
    Generated.CharismaAdj();



    std::cout << "Attributes" << std::endl;
    std::cout << "Str " << Generated.Str << " / " << Generated.ExceptionalStrength << std::endl;
    std::cout << "Dex " << Generated.Dex << std::endl;
    std::cout << "Con " << Generated.Con << std::endl;
    std::cout << "Int " << Generated.Int << std::endl;
    std::cout << "Wis " << Generated.Wis << std::endl;
    std::cout << "Cha " << Generated.Cha << std::endl;

    /*Code inserted for testing

    std::cout << "Bend Bars/Lift Gates % = " << Generated.BBLG << std::endl;
    std::cout << "AC Adjustment = " << Generated.ACAdj << std::endl;
    std::cout << "System Shock % = " << Generated.SystemShock << std::endl;
    std::cout << "Number of Languages Known = " << Generated.NumberOfLanguages << std::endl;
    std::cout << "Divine Spell Failure % = " << Generated.SpellFail << std::endl;
    std::cout << "Max Henchmen = " << Generated.MaxHench << std::endl; */

    Generated.Adjustments();

    /* Code inserted for testing
    std::cout << "Base AC = " << Generated.AC << std::endl;
    std::cout << "HP = " << Generated.HP << std::endl;
    std::cout << "THAC0 (Melee) = " << Generated.THAC0M << std::endl;
    std::cout << "THAC0 (Missile) = " << Generated.THAC0R << std::endl;
    std::cout << "Save vs PPDM = " << Generated.SavePPDM << std::endl;
    std::cout << "Save vs Rod/Staff/Wand = " << Generated.SaveRSW << std::endl;
    std::cout << "Save vs Petrify/Polymorph = " << Generated.SavePetPoly << std::endl;
    std::cout << "Save vs Breath Weapon = " << Generated.SaveBreath << std::endl;
    std::cout << "Save vs Spell = " << Generated.SaveSpell << std::endl;
    */

    std::cout << "Character Name:" << std::endl;
    std::cin >> Generated.CharacterName;

    // std::cout << Generated.CharacterName << std::endl; Testing code

    std::ofstream output;
    output.open("Generated.txt");
    output << "Name: " << Generated.CharacterName << " Class: " << Generated.ClassName << "\n";
    output << "STR " << Generated.Str << "/" <<  Generated.ExceptionalStrength << " Damage Adjustment " << Generated.DmgAdj << " Carry " << Generated.Carry << " Max Press " << Generated.MaxPress << " Open Doors " << Generated.OpenDoor << " Bend Bars/Lift Gates " << Generated.BBLG << "\n";
    output << "DEX " << Generated.Dex << " Initiative " << Generated.InitiativeAdj << "\n";
    output << "CON " << Generated.Con << " HP Adjustment " << Generated.HPAdj << " System Shock % " << Generated.SystemShock << " Resurrection Survival % " << Generated.Resurrection << "\n";
    output << "INT " << Generated.Int << " Languages " << Generated.NumberOfLanguages << " Max Spell Level " << Generated.MaxSpellLevel << " Chance To Learn (Arcane) " << Generated.ChanceToLearn << " Max Spells per Level (Arcane) " << Generated.MaxSpellPerLevel << "\n";
    output << "WIS " << Generated.Wis << " Magic Defense Adjustment " << Generated.MagicDefAdj << " Bonus Spells? " << Generated.BonusSpells << " Spell Failure % (Divine) " << Generated.SpellFail << "\n";
    output << "CHA " << Generated.Cha << " Max Henchmen " << Generated.MaxHench << " Leadership " << Generated.LeadBase << " Reaction Adjustment " << Generated.Reaction << "\n";
    output << "THAC0 - Melee " << Generated.THAC0M << " THAC0 - Ranged " << Generated.THAC0R << "\n";
    output << "Base AC " << Generated.AC << " HP " << Generated.HP << "\n";
    output << "Save vs PPDM " << Generated.SavePPDM << " Save vs Rod/Staff/Wand " << Generated.SaveRSW << " Save vs Petrification/Polymorph " << Generated.SavePetPoly << " Save vs Breath Weapon " << Generated.SaveBreath << " Save vs. Spell " << Generated.SaveSpell << "\n";
    output.close();
    

    return 0;
}