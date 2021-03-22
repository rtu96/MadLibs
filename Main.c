/*
		This application should allow a user to play MadLibs from the comfort and convenience from their own computer!
		It features theme selection as well for endless fun.

		I'm also very proud to point out that my code is "secure" and does not depend on disabling
		failsafes to avoid depreciated functions.
*/
#include <stdio.h>
#include <Windows.h>	//wanted to add a fancy animation to boot; this will allow use of sleep() but makes non-portable beyond windows

int			selection = 0;			//Used to navigate menus
int			sleep_delay = 300;		//In milliseconds, delay welcome print lines
int			c;						//Used to fix tutorial skipping first fgets()
int const	WRD_LENGTH = 20;		//Maximum word length

//Init all char arrays for use later. Couldn't figure out how to have flexible input lengths.
char	wrd1[20];
char	wrd2[20];
char	wrd3[20];
char	wrd4[20];
char	wrd5[20];
char	wrd6[20];	
char	wrd7[20];
char	wrd8[20];
char	wrd9[20];
char	wrd10[20];
char	wrd11[20];
char	wrd12[20];
char	wrd13[20];
char	wrd14[20];
char	wrd15[20];
char	wrd16[20];
char	wrd17[20];
char	wrd18[20];
char	wrd19[20];

//Bool to have tutorial auto skip if user has encountered it.
_Bool	tutorial_pass = 0; //0 == not yet, 1 == skipped

void	tutorial(), vacation_theme(); //To predefine functions before they are called and defaulted to int

int main(void)
{

	menu_load();	//Loads menu for the first time
	while (selection == 0)
	{
		printf("Type number to select option: ");	//Ask user to make a choice after menu has been loaded
		scanf_s("%d", &selection);
		if (selection < 0 || selection > 5)			//Error Checking for menu selection, as well as resetting selection
		{
			printf("Error: Invalid selection!\n");
			selection = 0;
		}
		if (selection == 1)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //Not sure how to clear terminal yet so just using this as a "brute force"
			theme();
			selection = 0;
			menu_load();
		}
		if (selection == 2)
		{
			tutorial();
			menu_load();
			selection = 0;
		}
		if (selection == 3)
		{
			credits();
			selection = 0;
		}
		if (selection == 4)
			return 0;
	}
	return 0;
}

int menu_load(void)
{
	/*
	This section is just some fancy printing of the Mad Libs boot up. Totally extra, I know
	but I wanted that old school boot up feel. You can almost hear a boot chime.
	sleep_delay is not a constant so when the user returns to the main menu
	for whatever reason, everything prints faster the second time around,
	emulating that the program has finished loading to ram.
	*/
	int time;
	for (time = 1; time <= 16; time++)	// A for loop to print each line one at a time
	{
		Sleep(sleep_delay);				//for some reason, I thought it'd be easier to have one delay repeat and have many if statements (it's the same)
		if (time == 1)					//if statement to check which line it's on
			printf("\n");				//print the line
		if (time == 2)
			printf(" #     #    #    ######     #       ### ######   #####	\n");
		if (time == 3)
			printf(" ##   ##   # #   #     #    #        #  #     # #     # \n");
		if (time == 4)
			printf(" # # # #  #   #  #     #    #        #  #     # #       \n");
		if (time == 5)
			printf(" #  #  # #     # #     #    #        #  ######   #####  \n");
		if (time == 6)
			printf(" #     # ####### #     #    #        #  #     #       # \n");
		if (time == 7)
			printf(" #     # #     # #     #    #        #  #     # #     # \n");
		if (time == 8)
			printf(" #     # #     # ######     ####### ### ######   #####  \n");
		if (time == 9)
		{
			printf("\n");
			Sleep(sleep_delay * 2);
		}
		if (time == 10)
		{
			printf("\n\n");
			printf("		MAIN MENU	\n");
		}
		if (time == 11)
		{
			printf("\n\n");
			printf("	1) Start Game\n");
		}
		if (time == 12)
			printf("	2) Tutorial\n");
		if (time == 13)
			printf("	3) Credits\n");
		if (time == 14)
			printf("	4) Quit\n\n");
		if (time == 16)
			sleep_delay = 0;		//Application has "finished loading" and future loads after are snappy
	}
	return 0;
}

int theme(void)
{
	selection = 0; //Reset selection to 0 for reuse

	//Print theme menu
	printf("\n		Select a Theme");
	printf("\n\n");
	printf("	1) Vacations\n");						//calls for vacations_theme 
	printf("	2) More themes coming soon!\n");
	printf("	3) More themes coming soon!\n");
	printf("	4) Main Menu\n");

	//Create while loop for menu selection
	while (selection == 0)
	{
		printf("Type number to select option: ");	//This has been recycled from the main menu
		scanf_s("%d", &selection);
		if (selection < 0 || selection > 4)
		{
			printf("Error: Invalid selection!\n");
			selection = 0;
		}
		if (selection == 1)
		{
			vacation_theme();
			selection = 0;
			return 0;
		}
		if (selection == 2 || selection == 3)
		{
			printf("\nGood things come to those who wait!\n");
			selection = 0;
		}
		if (selection == 4)
			return 0;
	}
	return 0;
}

void tutorial(void)
{
	selection = 0;
	printf("\n\n");
	printf("\n	Welcome to Mad Libs!");
	printf("\n	Would you like to learn how to play?");
	printf("\n	1) Yes! How does this work?");
	printf("\n	2) Nope, I got it from here. Thanks!");
	
	while (selection == 0)
	{
		printf("\n\nType number to select option: ");	//This has been recycled from the main menu
		scanf_s("%d", &selection);

		if (selection < 0 || selection > 2)
		{
			printf("Error: Invalid selection!\n");
			selection = 0;
		}

		if (selection == 1)
		{
			printf("\n\n	The game works by asking the player to fill in the blank");
			printf("\n	with a corresponding phrase of your choice, and after all");
			printf("\n	blanks are filled, the game will output your words in a");
			printf("\n	wacky story to enjoy!\n\n");
			printf("\nPress Any Key to Continue...");
			getch();

			tutorial_pass = 1;	//User has completed tutorial, avoid asking again
			return;
		}

		if (selection == 2);
		{
			printf("\n	Alright well excuuuuuse me then.\n");
			tutorial_pass = 1;	//User rejected tutorial, same as completing
			printf("\nPress Any Key to Continue...");
			getch();
			return;
		}
	}
}

void vacation_theme(void)
{

	if (tutorial_pass == 0) //Check if user has completed tutorial, if not then skip
		tutorial();

	while ((c = getchar()) != '\n' && c != EOF); //fix to avoid having tutorial skip first fgets()

	printf("\n I need an Adjective:\n");
	fgets(&wrd1, WRD_LENGTH, stdin);

	printf("\n\n I need another Adjective:\n");
	fgets(&wrd2, WRD_LENGTH, stdin);

	printf("\n\n I need a noun: \n");
	fgets(&wrd3, WRD_LENGTH, stdin);

	printf("\n\n I need another noun: \n");
	fgets(&wrd4, WRD_LENGTH, stdin);

	printf("\n\n I need a plural noun: \n");
	fgets(&wrd5, WRD_LENGTH, stdin);

	printf("\n\n I need a game: \n");
	fgets(&wrd6, WRD_LENGTH, stdin);

	printf("\n\n I need a plural noun: \n");
	fgets(&wrd7, WRD_LENGTH, stdin);

	printf("\n\n I need a verb ending in *ing*: \n");
	fgets(&wrd8, WRD_LENGTH, stdin);

	printf("\n\n I need another verb ending in *ing*: \n");
	fgets(&wrd9, WRD_LENGTH, stdin);

	printf("\n\n I need a plural noun: \n");
	fgets(&wrd10, WRD_LENGTH, stdin);

	printf("\n\n I need a verb ending in *ing*: \n");
	fgets(&wrd11, WRD_LENGTH, stdin);

	printf("\n\n I need a noun: \n");
	fgets(&wrd12, WRD_LENGTH, stdin);

	printf("\n\n I need a plant: \n");
	fgets(&wrd13, WRD_LENGTH, stdin);

	printf("\n\n I need a part of the body: \n");
	fgets(&wrd14, WRD_LENGTH, stdin);

	printf("\n\n I need a place: \n");
	fgets(&wrd15, WRD_LENGTH, stdin);

	printf("\n\n I need a verb ending in *ing*: \n");
	fgets(&wrd16, WRD_LENGTH, stdin);

	printf("\n\n I need an adjective: \n");
	fgets(&wrd17, WRD_LENGTH, stdin);

	printf("\n\n I need a number: \n");
	fgets(&wrd18, WRD_LENGTH, stdin);

	printf("\n\n And finally, I need a plural noun: \n");
	fgets(&wrd19, WRD_LENGTH, stdin);
	
	printf("\n Here we go!");

	/*
	Print out all the answers! Unfortunately I can't figure out to delimit the \n in
	all answers, so the paragraph prints out a new line and it looks pretty ugly in the
	console. I've done my best to mitigate that here but it still looks pretty bad.
	*/

	printf("\n");
	printf("\n A vacation is when you take a trip to some %s",				&wrd1);
	printf(" place with your %s family.",									&wrd2);
	printf("\n Usually you go to some place that is near a/an %s",			&wrd3);
	printf(" or up on a/an %s",												&wrd4);
	printf(" A good vacation place is one where you can ride %s",			&wrd5);
	printf(" or play %s or go hunting for ",								&wrd6);
	printf("%s",															&wrd7);
	printf(" I like to spend my time %s",									&wrd8);
	printf(" or %s",														&wrd9);
	printf(" When parents go on a vacation, they spend their time eating");
	printf("\n three %s a day, and fathers play golf, and mothers",			&wrd10);
	printf(" sit around %s Last summer, my little brother",					&wrd11);
	printf(" fell in a/an %s and got poison",								&wrd12);
	printf(" %s",															&wrd13);
	printf(" all over his %s ",												&wrd14);
	printf(" My family is going to go to (the) %s and I will practice",		&wrd15);
	printf(" %s Parents",													&wrd16);
	printf(" need more vacations than kids because parents are always very");
	printf(" %s and because they have to work",								&wrd17);
	printf(" %s",															&wrd18);
	printf(" hours every day all year making enough %s",					&wrd19);
	printf(" to pay for the vacation");

	//allow the user to read at their own pace before kicking out back to the main menu
	printf("\n\n\nPress Any Key to Continue...");
	getch();
	return;
}

int credits(void)
{
	printf("\nMade with love by Raymond Tu\n\n");
	printf("Press Any Key to Continue...");
	getch();
}