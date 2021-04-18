/*
		This application should allow a user to play MadLibs from the comfort and convenience from their own computer!
		It features theme selection as well for endless fun.

		I'm also very proud to point out that my code is "secure" and does not depend on disabling
		failsafes to use depreciated functions.

		On the other hand however, I cannot in good conscience say that my code is completely "secure" as I am an
		ameteur, and this assumes at least just number inputs, not null inputs and character inputs in wrong places.
*/
#include <stdio.h>
#include <string.h>
#include <windows.h>	//wanted to add a fancy animation to boot; this will allow use of sleep() but makes non-portable beyond windows

int			selection = 0;			//Used to navigate menus
int			sleep_delay = 300;		//In milliseconds, delay welcome print lines
int			c;						//Used to fix tutorial skipping first fgets()
int const	WRD_LENGTH = 20;		//Maximum word length

struct wordinput { char word[20]; };					//Created structure for words, technically could be numbers but in literal, not int
struct wordinput response[20];							//Response array of words, so now I don't have that hot mess of 20 predefined char arrays
char cache[1700];
char* p = cache;

//Bool to have tutorial auto skip if user has encountered it.
_Bool	tutorial_pass = 0; //0 == not yet, 1 == skipped

// Placeholder for filename, NULL as temp input
FILE* filename = NULL;

void	tutorial(), vacation_theme(), credits(); //To predefine functions before they are called and defaulted to int
int		menu_load(), theme(), cleanup(), save(), save_prompt(); // Predefine functions as int return to avoid assumptions
static int input_check();						// Predefine functions to avoid assumptions
char	*mystrcat(char* dest, char* src);		// Again, predefine
int main(void) // The main event
{

	menu_load();	//Loads menu for the first time
	while (selection == 0)
	{
		printf(" Type number to select option: ");	//Ask user to make a choice after menu has been loaded
		scanf_s("%d", &selection);
		if (selection < 0 || selection > 4)			//Error Checking for menu selection, as well as resetting selection
		{
			printf("Error: Invalid selection!\n");
			selection = 0;
		}
		if (selection == 1)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //Not sure how to clear terminal yet so just using this as a "brute force"
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

int menu_load(void) // The opener
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

int theme(void) // The introduction
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

void tutorial(void) // The guide
{
	selection = 0;
	printf("\n\n");
	printf("\n	Welcome to Mad Libs!");
	printf("\n	Would you like to learn how to play?");
	printf("\n	1) Yes! How does this work?");
	printf("\n	2) Nope, I got it from here. Thanks!");
	
	while (selection == 0)
	{
		printf("\n\n Type number to select option: ");	//This has been recycled from the main menu
		scanf_s("%d", &selection);

		if (selection < 0 || selection > 2)
		{
			printf(" Error: Invalid selection!\n");
			selection = 0;
		}

		if (selection == 1)
		{
			printf("\n\n	The game works by asking the player to fill in the blank");
			printf("\n	with a corresponding phrase of your choice, and after all");
			printf("\n	blanks are filled, the game will output your words in a");
			printf("\n	wacky story to enjoy!\n\n");
			printf("\n Press Any Key to Continue...");
			getch();

			tutorial_pass = 1;	//User has completed tutorial, avoid asking again
			return;
		}

		if (selection == 2);
		{
			printf("\n	Alright well excuuuuuse me then.\n");
			tutorial_pass = 1;	//User rejected tutorial, same as completing
			printf("\n Press Any Key to Continue...");
			getch();
			return;
		}
	}
}

void vacation_theme(void) // The showstopper
{

	if (tutorial_pass == 0) //Check if user has completed tutorial, if not then skip
		tutorial();

	while ((c = getchar()) != '\n' && c != EOF); //fix to avoid having tutorial skip first fgets()

	printf("\n I need an Adjective:\n  ");
	fgets(response[1].word, WRD_LENGTH, stdin);

	printf("\n\n I need another Adjective:\n  ");
	fgets(response[2].word, WRD_LENGTH, stdin);

	printf("\n\n I need a noun: \n  ");
	fgets(response[3].word, WRD_LENGTH, stdin);

	printf("\n\n I need another noun: \n  ");
	fgets(response[4].word, WRD_LENGTH, stdin);

	printf("\n\n I need a plural noun: \n  ");
	fgets(response[5].word, WRD_LENGTH, stdin);

	printf("\n\n I need a game: \n  ");
	fgets(response[6].word, WRD_LENGTH, stdin);

	printf("\n\n I need a plural noun: \n  ");
	fgets(response[7].word, WRD_LENGTH, stdin);

	printf("\n\n I need a verb ending in *ing*: \n  ");
	fgets(response[8].word, WRD_LENGTH, stdin);

	printf("\n\n I need another verb ending in *ing*: \n  ");
	fgets(response[9].word, WRD_LENGTH, stdin);

	printf("\n\n I need a plural noun: \n  ");
	fgets(response[10].word, WRD_LENGTH, stdin);

	printf("\n\n I need a verb ending in *ing*: \n  ");
	fgets(response[11].word, WRD_LENGTH, stdin);

	printf("\n\n I need a noun: \n  ");
	fgets(response[12].word, WRD_LENGTH, stdin);

	printf("\n\n I need a plant: \n  ");
	fgets(response[13].word, WRD_LENGTH, stdin);

	printf("\n\n I need a part of the body: \n  ");
	fgets(response[14].word, WRD_LENGTH, stdin);

	printf("\n\n I need a place: \n  ");
	fgets(response[15].word, WRD_LENGTH, stdin);

	printf("\n\n I need a verb ending in *ing*: \n  ");
	fgets(response[16].word, WRD_LENGTH, stdin);

	printf("\n\n I need an adjective: \n  ");
	fgets(response[17].word, WRD_LENGTH, stdin);

	printf("\n\n I need a number: \n  ");
	fgets(response[18].word, WRD_LENGTH, stdin);

	printf("\n\n And finally, I need a plural noun: \n  ");
	fgets(response[19].word, WRD_LENGTH, stdin);
	
	printf("\n Here we go!");

	cleanup(); // Calling cleanup function to remove \n characters from fgets input

	/*
	Print out all the answers! Now with \n character removal from fgets for cleaner output with cleanup() function.
	*/

	printf("\n");
	printf("\n A vacation is when you take a trip to some %s place with your %s family.",	response[1].word, response[2].word);
	printf("\n Usually you go to some place that is near a/an %s or up on a/an %s",			response[3].word, response[4].word);
	printf("\n A good vacation place is one where you can ride %s or play %s or go",		response[5].word, response[6].word);
	printf("\n hunting for %s. I like to spend my time %s or %s",		  response[7].word, response[8].word, response[9].word);
	printf("\n When parents go on a vacation, they spend their time eating three");
	printf("\n %s a day, and fathers play golf, and mothers sit around %s.",				response[10].word, response[11].word);
	printf("\n Last summer, my little brother fell in a/an %s and got poison %s",			response[12].word, response[13].word);
	printf("\n all over his %s. My family is going to (the) %s and I will practice",		response[14].word, response[15].word);
	printf("\n %s. Parents need more vacations than kids because parents are always very",	response[16].word);
	printf("\n %s and because they have to work %s hours every day all year making enough", response[17].word, response[18].word);
	printf("\n %s to pay for the vacation!",												response[19].word);


	//allow the user to read at their own pace before kicking out back to the main menu
	printf("\n\n\n Press Any Key to Continue...");
	getch();

	// Prints to cache for saving. It gets especially ugly 
	cache[0] = '\0';
	mystrcat(cache, "Made with Mad Libs!\n\n");
	mystrcat(cache, "A vacation is when you take a trip to some");
	mystrcat(cache, response[1].word);
	mystrcat(cache, " place with your ");
	mystrcat(cache, response[2].word);
	mystrcat(cache, " family.\nUsually you go to some place that is near a/an ");
	mystrcat(cache, response[3].word);
	mystrcat(cache, " or up on a/an ");
	mystrcat(cache, response[4].word);
	mystrcat(cache, ".\nA good vacation place is one where you can ride ");
	mystrcat(cache, response[5].word);
	mystrcat(cache, " or play ");
	mystrcat(cache, response[6].word);
	mystrcat(cache, " or go hunting for ");
	mystrcat(cache, response[7].word);
	mystrcat(cache, ".\n I like to spend my time ");
	mystrcat(cache, response[8].word);
	mystrcat(cache, " or ");
	mystrcat(cache, response[9].word);
	mystrcat(cache, ". When parents go on a vacation, they spend their time eating three ");
	mystrcat(cache, response[10].word);
	mystrcat(cache, " a day, and fathers play golf, \nand mothers sit around ");
	mystrcat(cache, response[11].word);
	mystrcat(cache, ". Last summer, my little brother fell in a/an ");
	mystrcat(cache, response[12].word);
	mystrcat(cache, " and got poison ");
	mystrcat(cache, response[13].word);
	mystrcat(cache, " all over his ");
	mystrcat(cache, response[14].word);
	mystrcat(cache, ". My family is going to (the)\n");
	mystrcat(cache, response[15].word);
	mystrcat(cache, " and I will practice ");
	mystrcat(cache, response[16].word);
	mystrcat(cache, ". Parents need more vacations than kids because parents are always very \n");
	mystrcat(cache, response[17].word);
	mystrcat(cache, " and because they have to work ");
	mystrcat(cache, response[18].word);
	mystrcat(cache, " hours every day all year making enough ");
	mystrcat(cache, response[19].word);
	mystrcat(cache, " to pay for the vacation!");
	
	//Asks user if they want to save the output
	save_prompt();
	return;
}

void credits(void) // The nomad
{
	printf("\n Made with blood, sweat, tears, and spite by Raymond Tu\n\n");
	printf(" Press Any Key to Continue...");
	getch();
	return;
}

int cleanup(void) // Used to cleanup input responses at end for nicer looking paragraph
{
	int i; //counter i
	for (i = 0; i < 20; i++)
	{
		response[i].word[strcspn(response[i].word, "\n")] = 0;
	}
	return 0;
}

int save_prompt(void)
{
	/*
	* Pretty much same as menu() but this time for yes/no input.
	*/
	printf("\n Would you like to save this?");
	printf("\n 1 = Yes		2 = No");
	selection = 0;
	while (selection == 0)
	{
		printf("\n\n Type number to select option: ");	//Ask user to make a choice after menu has been loaded
		scanf_s("%d", &selection);
		if (selection < 0 || selection > 2)			//Error Checking for menu selection, as well as resetting selection
		{
			printf("Error: Invalid selection!\n");
			selection = 0;
		}
		if (selection == 1)
		{
			save();
			return 0;
		}
		if (selection == 2)
		{
			return 0;
		}
	}
}

int save(void)
{
	/*
	* This function was found online in conjunction for the line input check down below, with a little bit more for opening and writing the contents of cache into a file named by a user.
	*/

	// 0 is OK
	// 1 is No Input
	// 2 is Too Long of an input
	int rc;
	_Bool status = 0;
	char buff[20];

	while (status == 0)
	{
		while ((c = getchar()) != '\n' && c != EOF); //Clearing the previous getchar(); to avoid skipping input

		rc = input_check("Enter filename ending in .txt> ", buff, sizeof(buff));
		if (rc == 1)
		{
			printf("\nNo input\n");
			save();
		}

		if (rc == 2) // Checks for too long of an input
		{
			printf("Input is too long [%s]\n", buff);
			save();
		}
		if (rc == 0)
		{
			printf("OK [%s]\n", buff);					// OK to use filename

			fopen_s(&filename, buff, "w");				// Opens/creates filename in write mode
			fwrite(cache, sizeof(cache), 1, filename);	// Writes contents of cache to filename set by user
			int fclose(FILE * filename);				// Close file

			memset(cache, 0, sizeof(cache));			// Clears out Cache for reuse in next game
			status = 1;
			return 0;
		}
	}
}

static int input_check(char* prmpt, char* buff, size_t sz) 
{
	/*
	* This code was found online to check for a line input, making sure that the user does not input null nor too long of a file
	*/
	int ch, extra;

	// Get line with buffer overrun protection.
	if (prmpt != NULL) {
		printf("%s", prmpt);
		fflush(stdout);
	}
	if (fgets(buff, sz, stdin) == NULL)
		return 1;

	// If it was too long, there'll be no newline. In that case, we flush
	// to end of line so that excess doesn't affect the next call.
	if (buff[strlen(buff) - 1] != '\n') {
		extra = 0;
		while (((ch = getchar()) != '\n') && (ch != EOF))
			extra = 1;
		return (extra == 1) ? 2 : 0;
	}

	// Otherwise remove newline and give string back to caller.
	buff[strlen(buff) - 1] = '\0';
	return 0;
}

char* mystrcat(char* dest, char* src)
{	
	/*
	* So this is a custom strcat as read online, because strcat is "unsafe" and does not offer good performance for larger character arrays
	*/
	while (*dest) dest++;
	while (*dest++ = *src++);
	return --dest;
}