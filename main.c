#include "stdafx.h"
#include "Windows.h"
#include <conio.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <random>

using namespace std;

struct goblin {
	int hp; //goblins hit points
	int sp; //goblins mana reserves
	int maxHP; //maximum hitpoints
	int maxSP; //maximum mana thingies
	//Each of these stats start at 0 and only go up to 10.
	int str = 1; //goblin's strength
	int end = 1; //endurance
	int dex = 1; //dexterity
	int wis = 1; //wisdom
	int chr = 1; //charisma		

} gob;


enum {
	COLOR_LIGHTBLUE = 9,
	COLOR_LIGHTGREEN,
	COLOR_LIGHTCYAN,
	COLOR_LIGHTRED,
	COLOR_LIGHTMAGENTA,
	COLOR_YELLOW,
	COLOR_WHITE,
};

void wait_enter(void) //Method of wait_enter, call it to create a Press Enter to continue screen.
{
	
	//cin.ignore();
	cout << "Press ENTER to continue...";
	cin.ignore();
}

void set_console_color(int fg)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, fg);
}

int waitForKey()
{
	return _getch() - 48;
}

struct Perk {

};


void perks() {
	int perkin;
	system("cls");
	cout << "-*- Perks -*-" << endl;
	perkin = waitForKey();
}

void stat_alloc() {
	int statin; //local variable
	string stat;
	bool stat_finished = true;
	while (stat_finished == true) {
		system("cls");
		cout << "-*- Stat Allocation -*-\n\n1) Strength: " << gob.str << "\n\n2) Endurance: " << gob.end << "\n\n3) Dexterity: " << gob.dex << "\n\n4) Wisdom: " << gob.wis << "\n\n5) Charisma: " << gob.chr << endl;
		cout << "\nYou have 1 Point to Allocate." << endl;
		statin = waitForKey(); //Takes input. 1 = Strength, 2 = Endurance, 3 = Dexterity, 4 = Wisdom, 5 = Charisma
		if (statin >= 1 && statin <= 5) {
			switch (statin) {
			case 1: //Strength
				if (!(gob.str >= 10)) //Checks to make sure it cannot go above 10
					gob.str++; //Puts the point in
				stat = "Strength"; //Sets the string at the end so it says "You put a point into x"
				break;
			case 2: //Endurance
				if (!(gob.end >= 10))
					gob.end++;
				stat = "Endurance";
				break;
			case 3: //Dexterity
				if (!(gob.dex >= 10))
					gob.dex++;
				stat = "Dexterity";
				break;
			case 4: //Wisdom
				if (!(gob.wis >= 10))
					gob.wis++;
				stat = "Wisdom";
				break;
			case 5: //Charisma
				if (!(gob.chr >= 10))
					gob.chr++;
				stat = "Charisma";
				break;
				
			}
			system("cls");
			cout << "-*- Stat Allocated! -*-\n\nYou put a point into " << stat << "!" << endl;
			wait_enter();
			stat_finished = false;
			perks();
		}
	}

}

enum {
	CARD_ENCOUNTER,
	CARD_TRAP,
	CARD_MERCHANT,
	CARD_LOOT,
	CARD_SHRINE,
};

void tile_gen() {
	static int inp;
	static int i;
	static int chance_picked;
	static int cards_chance[] = { 30, 20, 20, 20, 10 };
	int deck[] = { 0, 0, 0, 0, 0 };
	static int dumb_yeen;
	dumb_yeen = rand() % 10 + 7;
	cout << "Tiles: " << dumb_yeen << endl;
	for (i = 0; i < dumb_yeen; i++) {
		chance_picked = rand() % 101;
		if (chance_picked <= cards_chance[0]) {
			//cout << "Picked an Encounter card! Current: " << cards_chance[0] << endl;
			cards_chance[0] -= 20;
			cards_chance[1] += 5; cards_chance[2] += 5; cards_chance[3] += 5; cards_chance[4] += 5;
			deck[0] += 1;
		}
			else if (chance_picked >= cards_chance[0] && chance_picked <= cards_chance[0] + cards_chance[1]) {
				//cout << "Picked a Trap card! Current: " << cards_chance[1] << endl;
				cards_chance[1] -= 30;
				cards_chance[0] += 15; cards_chance[2] += 5; cards_chance[3] += 5; cards_chance[4] += 5;
				deck[1] += 1;
		}
			else if (chance_picked >= cards_chance[0] + cards_chance[1] 
				&& chance_picked <= cards_chance[0] + cards_chance[1] + cards_chance[2]) {
				//cout << "Picked a Merchant card! Current: " << cards_chance[2] << endl;
			cards_chance[2] -= 40;
			cards_chance[0] += 10; cards_chance[1] += 10; cards_chance[3] += 10; cards_chance[4] += 10;
			deck[2] += 1;
		}
			else if (chance_picked >= cards_chance[0] + cards_chance[1] + cards_chance[2]
				&& chance_picked <= cards_chance[0] + cards_chance[1] + cards_chance[2] + cards_chance[3]) {
				//cout << "Picked a Loot card! Current: " << cards_chance[3] << endl;
				cards_chance[3] -= 20;
				cards_chance[0] += 5; cards_chance[1] += 5; cards_chance[2] += 5; cards_chance[4] += 5;
				deck[3] += 1;
		}
			else if (chance_picked >= cards_chance[0] + cards_chance[1] + cards_chance[2] + cards_chance[3]
				&& chance_picked <= cards_chance[0] + cards_chance[1] + cards_chance[2] + cards_chance[3] + cards_chance[4]) {
				//cout << "Picked a Shrine card! Current: " << cards_chance[4] << endl;
				cards_chance[4] -= 20;
				cards_chance[0] += 5; cards_chance[1] += 5; cards_chance[2] += 5; cards_chance[3] += 5;
				deck[4] += 1;
			}

	}
	cout << "Current Deck: \n\n" << deck[0] << " Encounter(s) \n\n" << deck[1] << " Trap(s)\n\n" << deck[2] << " Merchant(s)\n\n" << deck[3] << " Loot Card(s)\n\n" << deck[4] << " Shrine(s)" << endl;
	inp = waitForKey();
	system("cls");
	tile_gen();
}




int main()
{
	srand(time(0));
	int in; //dumb local variable
	set_console_color(COLOR_WHITE); //dumb sets the color to white
	cout << "-*- DRIZZLE DUNGEON -*-\n\n1) Start" << endl; //print
	in = waitForKey();
	switch (in) {
	case 1:
		tile_gen();
	break;
	}
    return 0;
}

