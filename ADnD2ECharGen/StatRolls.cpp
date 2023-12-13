#include <iostream>
#include <random>
#include "StatRolls.h"

// Function to generate a random dice roll
int rollDice() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(2, 6);
    return dis(gen);
}

//Initializes an array to hold attributes and rolls attributes to fill that array

std::array<int, 6> StatList() {
    int STR = RollVector();
    int DEX = RollVector();
    int CON = RollVector();
    int INT = RollVector();
    int WIS = RollVector();
    int CHA = RollVector();

    std::array<int, 6> Stats;
    Stats[0] = STR;
    Stats[1] = DEX;
    Stats[2] = CON;
    Stats[3] = INT;
    Stats[4] = WIS;
    Stats[5] = CHA;

    return Stats;
}

int RollVector() {
    // Create 4 dice rolls
    int roll1 = rollDice();
    int roll2 = rollDice();
    int roll3 = rollDice();
    int roll4 = rollDice();
    int StatVector[4];

    // Output results to Vector
    StatVector[0] = roll1;
    StatVector[1] = roll2;
    StatVector[2] = roll3;
    StatVector[3] = roll4;

    //Bubble Sort algorithm to order from greatest to least

    int i;
    int j;
    int temp;
    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (StatVector[j] > StatVector[i])
            {
                temp = StatVector[i];
                StatVector[i] = StatVector[j];
                StatVector[j] = temp;
            }
        }
    }

    //Commented out code was used for testing to ensure the rolling and sorting operations were performing as expected 

    /*std::cout << StatVector[0] << std::endl;
    std::cout << StatVector[1] << std::endl;
    std::cout << StatVector[2] << std::endl;
    std::cout << StatVector[3] << std::endl;*/

    //std::cout << StatVector[0] + StatVector[1] + StatVector[2] << std::endl;

    //Sums three highest rolls and returns them into the variable calling the function

    return StatVector[0] + StatVector[1]+StatVector[2];
}