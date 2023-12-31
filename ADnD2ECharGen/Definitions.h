#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#pragma once
#include "StatRolls.h"
#include <random>

// Defining "Character" and the various attributes this generator will be defining

class Character
	{
	public:
		Character() :CharacterName(), HP(0), AC(10), Str(0), Dex(0), Con(0), Int(0), Wis(0), Cha(0), ClassName(), THAC0M(20), THAC0R(20),
			SavePPDM(0), SaveRSW(0), SavePetPoly(0), SaveBreath(0), SaveSpell(0), ExceptionalStrength(0), IsFighterAvailable(false),
			IsPaladinAvailable(false), IsRangerAvailable(false), IsMageAvailable(false), IsClericAvailable(false),
			IsDruidAvailable(false), IsThiefAvailable(false), IsBardAvailable(false), IsInputValid(false), Input(), CharacterType(0),
			ToHitAdj(10), DmgAdj(10), Carry(0), MaxPress(0), OpenDoor(0), BBLG(0),
			InitiativeAdj(0), MissileAdj(0), ACAdj(0), 
			HPAdj(10), SystemShock(0), Resurrection(0), PoisonSaveAdj(10),
			NumberOfLanguages(-1), MaxSpellLevel(-1), ChanceToLearn(-1), MaxSpellPerLevel(-1),
			MagicDefAdj(10), BonusSpells(false), SpellFail(-1),
			MaxHench(-1), LeadBase(-10), Reaction(-10) {};
		std::string CharacterName;
		int Str;
		int Dex;
		int Con;
		int Int;
		int Wis;
		int Cha;
		// Character Class
		std::string ClassName;
		// To Hit Armor Class 0 (Melee/Ranged)
		int THAC0M;
		int THAC0R;
		//Saving Throws
		int SavePPDM; //Paralyze, Poison, Death Magic
		int SaveRSW; //Rod, Staff, Wand
		int SavePetPoly; //Petrification and Polymorph
		int SaveBreath;
		int SaveSpell;
		int ExceptionalStrength;
		int HP;
		int AC;

		//Strength Characteristics
		int ToHitAdj;
		int DmgAdj;
		int Carry;
		int MaxPress;
		int OpenDoor;
		int BBLG;
		//Dexterity Characteristics
		int InitiativeAdj;
		int MissileAdj;
		int ACAdj;
		//Constitution Characteristics
		int HPAdj;
		int SystemShock;
		int Resurrection;
		int PoisonSaveAdj;
		//Intelligence Characteristics
		int NumberOfLanguages;
		int MaxSpellLevel;
		int ChanceToLearn;
		int MaxSpellPerLevel;
		//Wisdom Characteristics
		int MagicDefAdj;
		bool BonusSpells;
		int SpellFail;
		//Charisma Characteristics
		int MaxHench;
		int LeadBase;
		int Reaction;

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

		//Setting up a variable to classify the 4 Character Class types
		int CharacterType;

		//Defining a function to codify the Character into one of the four types
		void TypeSort() {
			if ((ClassName == "Fighter") || (ClassName == "Ranger") || (ClassName == "Paladin")) {
				CharacterType = 1;
			}

			else if (ClassName == "Mage") {
				CharacterType = 2;
			}

			else if ((ClassName == "Cleric") || (ClassName == "Druid")) {
				CharacterType = 3;
			}

			else if ((ClassName == "Thief") || (ClassName == "Bard")) {
				CharacterType = 4;
			}
		};

		int RollPercent() {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(1, 100);
			return dis(gen);

		};

		void StrengthAdjustments() {
			if (Str == 1) {
				ToHitAdj = -5;
				DmgAdj = -4;
				Carry = 1;
				MaxPress = 3;
				OpenDoor = 1;
				BBLG = 0;
			}

			else if (Str == 2) {
				ToHitAdj = -3;
				DmgAdj = -2;
				Carry = 1;
				MaxPress = 5;
				OpenDoor = 1;
				BBLG = 0;
			}

			else if (Str == 3) {
				ToHitAdj = -3;
				DmgAdj = -2;
				Carry = 5;
				MaxPress = 10;
				OpenDoor = 2;
				BBLG = 0;
			}

			else if ((Str == 4) || (Str == 5)) {
				ToHitAdj = -2;
				DmgAdj = -1;
				Carry = 10;
				MaxPress = 25;
				OpenDoor = 3;
				BBLG = 0;
			}

			else if ((Str == 6) || (Str == 7)) {
				ToHitAdj = -1;
				DmgAdj = 0;
				Carry = 20;
				MaxPress = 55;
				OpenDoor = 4;
				BBLG = 0;
			}

			else if ((Str == 8) || (Str == 9)) {
				ToHitAdj = 0;
				DmgAdj = 0;
				Carry = 35;
				MaxPress = 90;
				OpenDoor = 5;
				BBLG = 1;
			}

			else if ((Str == 10) || (Str == 11)) {
				ToHitAdj = 0;
				DmgAdj = 0;
				Carry = 40;
				MaxPress = 115;
				OpenDoor = 6;
				BBLG = 2;
			}

			else if ((Str == 12) || (Str == 13)) {
				ToHitAdj = 0;
				DmgAdj = 0;
				Carry = 45;
				MaxPress = 140;
				OpenDoor = 7;
				BBLG = 4;
			}

			else if ((Str == 14) || (Str == 15)) {
				ToHitAdj = 0;
				DmgAdj = 0;
				Carry = 55;
				MaxPress = 170;
				OpenDoor = 8;
				BBLG = 7;
			}

			else if (Str == 16) {
				ToHitAdj = 0;
				DmgAdj = 1;
				Carry = 70;
				MaxPress = 195;
				OpenDoor = 9;
				BBLG = 10;
			}

			else if (Str == 17) {
				ToHitAdj = 1;
				DmgAdj = 1;
				Carry = 85;
				MaxPress = 220;
				OpenDoor = 10;
				BBLG = 13;
			}

			else if ((Str == 18) && (ExceptionalStrength == 0)) {
				ToHitAdj = 1;
				DmgAdj = 2;
				Carry = 110;
				MaxPress = 255;
				OpenDoor = 11;
				BBLG = 16;
			}

			else if ((Str == 18) && (ExceptionalStrength >= 1) && (ExceptionalStrength <= 50)) {
				ToHitAdj = 1;
				DmgAdj = 3;
				Carry = 135;
				MaxPress = 280;
				OpenDoor = 12;
				BBLG = 20;
			}

			else if ((Str == 18) && (ExceptionalStrength >= 51) && (ExceptionalStrength <= 75)) {
				ToHitAdj = 2;
				DmgAdj = 3;
				Carry = 160;
				MaxPress = 305;
				OpenDoor = 13;
				BBLG = 25;
			}

			else if ((Str == 18) && (ExceptionalStrength >= 76) && (ExceptionalStrength <= 90)) {
				ToHitAdj = 2;
				DmgAdj = 4;
				Carry = 185;
				MaxPress = 330;
				OpenDoor = 14;
				BBLG = 30;
			}

			else if ((Str == 18) && (ExceptionalStrength >= 91) && (ExceptionalStrength <= 99)) {
				ToHitAdj = 2;
				DmgAdj = 5;
				Carry = 235;
				MaxPress = 380;
				OpenDoor = 15;
				BBLG = 35;
			}

			else if ((Str == 18) && (ExceptionalStrength == 100)) {
				ToHitAdj = 3;
				DmgAdj = 6;
				Carry = 335;
				MaxPress = 480;
				OpenDoor = 16;
				BBLG = 40;
			}
		};

		void SetSaves() {
			if (CharacterType == 1) {
				SavePPDM = 16;
				SaveRSW = 18;
				SavePetPoly = 17;
				SaveBreath = 20;
				SaveSpell = 19;
				HP = 10;
			}

			else if (CharacterType == 2) {
				SavePPDM = 14;
				SaveRSW = 11;
				SavePetPoly = 13;
				SaveBreath = 15;
				SaveSpell = 12;
				HP = 4;
			}

			else if (CharacterType == 3) {
				SavePPDM = 10;
				SaveRSW = 14;
				SavePetPoly = 13;
				SaveBreath = 16;
				SaveSpell = 15;
				HP = 8;
			}

			else if (CharacterType == 4) {
				SavePPDM = 13;
				SaveRSW = 14;
				SavePetPoly = 12;
				SaveBreath = 16;
				SaveSpell = 15;
				HP = 6;
			}
		};

		void DexAdjustments() {
			if (Dex == 1) {
				InitiativeAdj = 6;
				MissileAdj = -6;
				ACAdj = 5;
			}

			else if (Dex == 2) {
				InitiativeAdj = 4;
				MissileAdj = -4;
				ACAdj = 5;
			}

			else if (Dex == 3) {
				InitiativeAdj = 3;
				MissileAdj = -3;
				ACAdj = 4;
			}

			else if (Dex == 4) {
				InitiativeAdj = 2;
				MissileAdj = -2;
				ACAdj = 3;
			}

			else if (Dex == 5) {
				InitiativeAdj = 1;
				MissileAdj = -1;
				ACAdj = 2;
			}

			else if (Dex == 6) {
				InitiativeAdj = 0;
				MissileAdj = 0;
				ACAdj = 1;
			}

			else if (Dex == 15) {
				InitiativeAdj = 0;
				MissileAdj = 0;
				ACAdj = -1;
			}

			else if (Dex == 16) {
				InitiativeAdj = -1;
				MissileAdj = 1;
				ACAdj = -2;
			}

			else if (Dex == 17) {
				InitiativeAdj = -2;
				MissileAdj = 2;
				ACAdj = -3;
			}

			else if (Dex == 18) {
				InitiativeAdj = -2;
				MissileAdj = 2;
				ACAdj = -4;
			}
		};

		void ConstitutionAdjustments() {
			if (Con == 1) {
				HPAdj = -3;
				SystemShock = 25;
				Resurrection = 30;
				PoisonSaveAdj = -2;
			}

			else if (Con == 2) {
				HPAdj = -2;
				SystemShock = 30;
				Resurrection = 35;
				PoisonSaveAdj = -1;
			}

			else if (Con == 3) {
				HPAdj = -2;
				SystemShock = 35;
				Resurrection = 40;
				PoisonSaveAdj = 0;
			}

			else if (Con == 4) {
				HPAdj = -1;
				SystemShock = 40;
				Resurrection = 45;
				PoisonSaveAdj = 0;
			}

			else if (Con == 5) {
				HPAdj = -1;
				SystemShock = 45;
				Resurrection = 50;
				PoisonSaveAdj = 0;
			}

			else if (Con == 6) {
				HPAdj = -1;
				SystemShock = 50;
				Resurrection = 55;
				PoisonSaveAdj = 0;
			}

			else if (Con == 7) {
				HPAdj = 0;
				SystemShock = 55;
				Resurrection = 60;
				PoisonSaveAdj = 0;
			}

			else if (Con == 8) {
				HPAdj = 0;
				SystemShock = 60;
				Resurrection = 65;
				PoisonSaveAdj = 0;
			}

			else if (Con == 9) {
				HPAdj = 0;
				SystemShock = 65;
				Resurrection = 70;
				PoisonSaveAdj = 0;
			}

			else if (Con == 10) {
				HPAdj = 0;
				SystemShock = 70;
				Resurrection = 75;
				PoisonSaveAdj = 0;
			}

			else if (Con == 11) {
				HPAdj = 0;
				SystemShock = 75;
				Resurrection = 80;
				PoisonSaveAdj = 0;
			}

			else if (Con == 12) {
				HPAdj = 0;
				SystemShock = 80;
				Resurrection = 85;
				PoisonSaveAdj = 0;
			}

			else if (Con == 13) {
				HPAdj = 0;
				SystemShock = 85;
				Resurrection = 90;
				PoisonSaveAdj = 0;
			}

			else if (Con == 14) {
				HPAdj = 0;
				SystemShock = 88;
				Resurrection = 92;
				PoisonSaveAdj = 0;
			}

			else if (Con == 15) {
				HPAdj = 1;
				SystemShock = 90;
				Resurrection = 94;
				PoisonSaveAdj = 0;
			}

			else if (Con == 16) {
				HPAdj = 2;
				SystemShock = 95;
				Resurrection = 96;
				PoisonSaveAdj = 0;
			}

			else if ((Con == 17) && (CharacterType != 1)) {
				HPAdj = 2;
				SystemShock = 97;
				Resurrection = 98;
				PoisonSaveAdj = 0;
			}

			else if ((Con == 17) && (CharacterType == 1)) {
				HPAdj = 3;
				SystemShock = 97;
				Resurrection = 98;
				PoisonSaveAdj = 0;
			}

			else if ((Con == 18) && (CharacterType != 1)) {
				HPAdj = 2;
				SystemShock = 99;
				Resurrection = 100;
				PoisonSaveAdj = 0;
			}

			else if ((Con == 18) && (CharacterType == 1)) {
				HPAdj = 4;
				SystemShock = 99;
				Resurrection = 100;
				PoisonSaveAdj = 0;
			}

		};

		void IntelligenceAdj() {

			if (Int == 1) {
				NumberOfLanguages = 0;
				MaxSpellLevel = 0;
				ChanceToLearn = 0;
				MaxSpellPerLevel = 0;
			}

			else if ((Int >= 2) && (Int <= 8)) {
				NumberOfLanguages = 1;
				MaxSpellLevel = 0;
				ChanceToLearn = 0;
				MaxSpellPerLevel = 0;
			}

			else if (Int == 9) {
				NumberOfLanguages = 2;
				MaxSpellLevel = 4;
				ChanceToLearn = 35;
				MaxSpellPerLevel = 6;
			}

			else if (Int == 10) {
				NumberOfLanguages = 2;
				MaxSpellLevel = 5;
				ChanceToLearn = 40;
				MaxSpellPerLevel = 7;
			}

			else if (Int == 11) {
				NumberOfLanguages = 2;
				MaxSpellLevel = 5;
				ChanceToLearn = 45;
				MaxSpellPerLevel = 7;
			}

			else if (Int == 12) {
				NumberOfLanguages = 3;
				MaxSpellLevel = 6;
				ChanceToLearn = 50;
				MaxSpellPerLevel = 7;
			}

			else if (Int == 13) {
				NumberOfLanguages = 3;
				MaxSpellLevel = 6;
				ChanceToLearn = 55;
				MaxSpellPerLevel = 9;
			}

			else if (Int == 14) {
				NumberOfLanguages = 4;
				MaxSpellLevel = 7;
				ChanceToLearn = 60;
				MaxSpellPerLevel = 9;
			}

			else if (Int == 15) {
				NumberOfLanguages = 4;
				MaxSpellLevel = 7;
				ChanceToLearn = 65;
				MaxSpellPerLevel = 11;
			}

			else if (Int == 16) {
				NumberOfLanguages = 5;
				MaxSpellLevel = 8;
				ChanceToLearn = 70;
				MaxSpellPerLevel = 11;
			}

			else if (Int == 17) {
				NumberOfLanguages = 6;
				MaxSpellLevel = 8;
				ChanceToLearn = 75;
				MaxSpellPerLevel = 14;
			}

			else if (Int == 18) {
				NumberOfLanguages = 7;
				MaxSpellLevel = 9;
				ChanceToLearn = 95;
				MaxSpellPerLevel = 18;
			}

		};

		void WisdomAdj() {

			if (Wis == 1) {
				MagicDefAdj = -6;
				BonusSpells = false;
				SpellFail = 80;
			}

			else if (Wis == 2) {
				MagicDefAdj = -4;
				BonusSpells = false;
				SpellFail = 60;
			}

			else if (Wis == 3) {
				MagicDefAdj = -3;
				BonusSpells = false;
				SpellFail = 50;
			}

			else if (Wis == 4) {
				MagicDefAdj = -2;
				BonusSpells = false;
				SpellFail = 45;
			}

			else if (Wis == 5) {
				MagicDefAdj = -1;
				BonusSpells = false;
				SpellFail = 40;
			}

			else if (Wis == 6) {
				MagicDefAdj = -1;
				BonusSpells = false;
				SpellFail = 35;
			}

			else if (Wis == 7) {
				MagicDefAdj = -1;
				BonusSpells = false;
				SpellFail = 30;
			}

			else if (Wis == 8) {
				MagicDefAdj = 0;
				BonusSpells = false;
				SpellFail = 25;
			}

			else if (Wis == 9) {
				MagicDefAdj = 0;
				BonusSpells = false;
				SpellFail = 20;
			}

			else if (Wis == 10) {
				MagicDefAdj = 0;
				BonusSpells = false;
				SpellFail = 15;
			}

			else if (Wis == 11) {
				MagicDefAdj = 0;
				BonusSpells = false;
				SpellFail = 10;
			}

			else if (Wis == 12) {
				MagicDefAdj = 0;
				BonusSpells = false;
				SpellFail = 5;
			}

			else if (Wis == 13) {
				MagicDefAdj = 0;
				BonusSpells = true;
				SpellFail = 0;
			}

			else if (Wis == 14) {
				MagicDefAdj = 0;
				BonusSpells = true;
				SpellFail = 0;
			}

			else if (Wis == 15) {
				MagicDefAdj = 1;
				BonusSpells = true;
				SpellFail = 0;

			}

			else if (Wis == 16) {
				MagicDefAdj = 2;
				BonusSpells = true;
				SpellFail = 0;
			}
			
			else if (Wis == 17) {
				MagicDefAdj = 3;
				BonusSpells = true;
				SpellFail = 0;
			}

			else if (Wis == 18) {
				MagicDefAdj = 4;
				BonusSpells = true;
				SpellFail = 0;
			}

		};

		void CharismaAdj() {


			if (Cha == 1) {
				MaxHench = 0;
				LeadBase = -8;
				Reaction = -7;
			}

			else if (Cha == 2) {
				MaxHench = 1;
				LeadBase = -7;
				Reaction = -6;
			}

			else if (Cha == 3) {
				MaxHench = 1;
				LeadBase = -6;
				Reaction = -5;
			}

			else if (Cha == 4) {
				MaxHench = 1;
				LeadBase = -5;
				Reaction = -4;
			}

			else if (Cha == 5) {
				MaxHench = 2;
				LeadBase = -4;
				Reaction = -3;
			}

			else if (Cha == 6) {
				MaxHench = 2;
				LeadBase = -3;
				Reaction = -2;
			}

			else if (Cha == 7) {
				MaxHench = 3;
				LeadBase = -2;
				Reaction = -1;
			}

			else if (Cha == 8) {
				MaxHench = 3;
				LeadBase = -1;
				Reaction = 0;
			}

			else if ((Cha >= 9) && (Cha <= 11)) {
				MaxHench = 4;
				LeadBase = 0;
				Reaction = 0;
			}

			else if (Cha == 12) {
				MaxHench = 5;
				LeadBase = 0;
				Reaction = 1;
			}

			else if (Cha == 13) {
				MaxHench = 5;
				LeadBase = 0;
				Reaction = 1;
			}

			else if (Cha == 14) {
				MaxHench = 6;
				LeadBase = 1;
				Reaction = 2;
			}

			else if (Cha == 15) {
				MaxHench = 7;
				LeadBase = 3;
				Reaction = 3;
			}

			else if (Cha == 16) {
				MaxHench = 8;
				LeadBase = 4;
				Reaction = 5;
			}

			else if (Cha == 17) {
				MaxHench = 10;
				LeadBase = 6;
				Reaction = 6;
			}

			else if (Cha == 18) {
				MaxHench = 15;
				LeadBase = 8;
				Reaction = 7;
			}

		};

		void Adjustments() {

			THAC0M -= ToHitAdj;
			THAC0R -= MissileAdj;
			AC += ACAdj;
			SavePPDM += PoisonSaveAdj;
			HP += HPAdj;
			SaveSpell -= MagicDefAdj;

		};

	};

#endif
