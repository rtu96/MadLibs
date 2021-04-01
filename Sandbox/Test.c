#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Test.h"

int const	WRD_LENGTH = 20;		//Maximum word length

struct wordinput { char word[20]; };
struct wordinput response[19];

int main(void)
{
	printf("\n I need an Adjective:\n");
	fgets(response[1].word, WRD_LENGTH, stdin);

	printf("\n\n I need another Adjective:\n");
	fgets(response[2].word, WRD_LENGTH, stdin);

	printf("\n\n I need a noun: \n");
	fgets(response[3].word, WRD_LENGTH, stdin);

	printf("\n\n I need another noun: \n");
	fgets(response[4].word, WRD_LENGTH, stdin);

	cleanup();
	printf("\n");
	printf("\n A vacation is when you take a trip to some %s", response[1]);
	printf(" place with your %s family.", response[2]);
	printf("\n Usually you go to some place that is near a/an %s", response[3]);
	printf(" or up on a/an %s", response[4]);

	printf("\n\n\nPress Any Key to Continue...");
	
	getch();

	return 0;
}

int cleanup(void)
{
	int i;
	for ( i = 0 ; i < 19; i++)
	{
		response[i].word[strcspn(response[i].word, "\n")] = 0;
	}
	return 0;
}