#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#pragma once
#include "StatRolls.h"

// Defining "Character" and the various attributes this generator will be defining

class Character
	{
	public:
		Character() :CharacterName(), Str(0), Dex(0), Con(0), Int(0), Wis(0), Cha(0), ClassName(), THAC0(0), SavePPDM(0),
			SaveRSW(0), SavePetPoly(0), SaveBreath(0), SaveSpell(0), ExceptionalStrength(0), IsFighterAvailable(false),
			IsPaladinAvailable(false), IsRangerAvailable(false), IsMageAvailable(false), IsClericAvailable(false),
			IsDruidAvailable(false), IsThiefAvailable(false), IsBardAvailable(false), IsInputValid(false), Input() {};
		std::string CharacterName;
		int Str;
		int Dex;
		int Con;
		int Int;
		int Wis;
		int Cha;
		// Character Class
		std::string ClassName;
		// To Hit Armor Class 0
		int THAC0;
		//Saving Throws
		int SavePPDM; //Paralyze, Poison, Death Magic
		int SaveRSW; //Rod, Staff, Wand
		int SavePetPoly; //Petrification and Polymorph
		int SaveBreath;
		int SaveSpell;
		int ExceptionalStrength;
		//Defining functions and internal variables needed for Character Generation
		void RollStats() {
			Str = RollVector();
			Dex = RollVector();
			Con = RollVector();
			Int = RollVector();
			Wis = RollVector();
			Cha = RollVector();
			};
		//Variables to set available Character Classes
		bool IsFighterAvailable;
		bool IsPaladinAvailable;
		bool IsRangerAvailable;
		bool IsMageAvailable;
		bool IsClericAvailable;
		bool IsDruidAvailable;
		bool IsThiefAvailable;
		bool IsBardAvailable;
		//Functions to check attributes against Class requirements
		void CheckFighter() {
			if (Str >= 9) {
				IsFighterAvailable = true;
			}
			else
			{
				IsFighterAvailable = false;
			}
		};
		void CheckPaladin() {
			if ((Str >= 12) && (Con >= 9) && (Wis >= 13) && (Cha >= 17)) {
				IsPaladinAvailable = true;
			}
			else {
				IsPaladinAvailable = false;
			}
		};
		void CheckRanger() {
			if ((Str >= 13) && (Dex >= 13) && (Con >= 14) && (Wis >= 14)) {
				IsRangerAvailable = true;
			}
			else {
				IsRangerAvailable = false;
			}
		};
		void CheckMage() {
			if (Int >= 9) {
				IsMageAvailable = true;
			}
			else {
				IsMageAvailable = false;
			}
		};
		void CheckCleric() {
			if (Wis >= 9) {
				IsClericAvailable = true;
			}
			else {
				IsClericAvailable = false;
			}
		};
		void CheckDruid() {
			if ((Wis >= 12) && (Cha >= 15)) {
				IsDruidAvailable = true;
			}
			else {
				IsDruidAvailable = false;
			}
		};
		void CheckThief() {
			if (Dex >= 9) {
				IsThiefAvailable = true;
			}
			else IsThiefAvailable = false;
		};
		void CheckBard() {
			if ((Dex >= 12) && (Int >= 13) && (Cha >= 15)) {
				IsBardAvailable = true;
			}
			else IsBardAvailable = false;
		};
		//Setting up variables for user to choose an available Character Class and to error-check that input
		bool IsInputValid;
		std::string Input;
	};
#endif
