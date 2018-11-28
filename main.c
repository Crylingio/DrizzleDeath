#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

struct {
	char* name;
	int hp;
	int mp;
	int maxhp;
	int maxmp;
}gob;

enum {
	COLOR_LIGHTBLUE = 9,
	COLOR_LIGHTGREEN,
	COLOR_LIGHTCYAN,
	COLOR_LIGHTRED,
	COLOR_LIGHTMAGENTA,
	COLOR_YELLOW,
	COLOR_WHITE,
	/*
	The different color codes are

	0   BLACK
	1   BLUE
	2   GREEN
	3   CYAN
	4   RED
	5   MAGENTA
	6   BROWN
	7   LIGHTGRAY
	8   DARKGRAY
	9   LIGHTBLUE
	10  LIGHTGREEN
	11  LIGHTCYAN
	12  LIGHTRED
	13  LIGHTMAGENTA
	14  YELLOW
	15  WHITE
	*/

};

void set_console_color(int fg) 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, fg);
}

void gcreate() {
	printf("Goblins, Goblins never change. When atomic fire consumed the goblin lands, those who survived did so in dark underground dungeons."
		"When the goblins left, they set out across ruins of the old goblin lands to build new dungeons, establish new territories, and form tribes."
		"As decades passed, what had been the golbin lands united beneath the flag of the New Goblin Democracy, dedicated to old - goblin values of democracy and the rule of law."
		"As the Democracy grew, so did its needs. Goblin scouts spread east, seeking territory and loot, in the dry and merciless expanse of the badlands."
		"They returned with tales of a goblin city untouched by the orc warheads that had scorched the rest of the goblin world, and a great wall spanning the Goblorado River."
		"The NGD mobilized its army and sent it east to occupy the Moover Dam, and restore it to working condition. But across the Goblorado, another society had arisen under a different flag."
		"A vast army of slaves, forged from the conquest of 76 tribes: Drizzle's Dynasty."
		"Four years have passed since the NGD held the Dam - just barely - against the Dynasty's onslaught. The Dynasty did not retreat."
		"Across the river, it gathers strength. Campfires burned, training drums beat."
		"Through it all, the Las Goblin Straight has stayed open for business under the control of its mysterious overseer, Mr. Dwavmoh', and his army of rehabilitated Tribals and cyblorgins."
		"You are a milkgoblin, hired by the Badlands Express, to deliver milk to the Las Goblin Straight. What seemed like a simple delivery job has taken a turn…"
		"for the worse.");
		getchar();
}

int main()
{
	int test;
	set_console_color(COLOR_WHITE);
	printf("-*- DRIZZLE DUNGEON -*-\n1) Start\n");
	getchar();
	if (getchar() == '1') { //if the rad player inserts a 1 into the console he gets to go to
		gcreate(); //the goblin creation screen
	}
	return 0;
}
