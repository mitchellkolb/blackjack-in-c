

/*
Programmer: Mitchell Kolb
Class: CptS 121, Spring 2020; Lab Section ##
Programming Assingment: #5
Date: 3/13/2020
Description: This program plays a text based game of Yahtzee

             ***ADDITION***
*/

#include "Equations.h"


/*************************************************************
* Function: int menu_select(void)
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description: Has an input validation loop to display and
get the option for the menu.
* Input parameters: void
* Returns: option
* Preconditions: none
* Postconditions: none
*************************************************************/

int menu_select(void)
{
	int option = 0;
	do
	{
		display_menu();
		option = get_option();
	} while (option < GAME_RULES || option > EXIT);

	return option;
}

/*************************************************************
* Function: void display_menu(void)
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description: Just a simple printf group that is the menu
* Input parameters: none
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/
void display_menu(void)
{
	printf("1. Game Rules.\n");
	printf("2. Play Game.\n");
	printf("3. Exit.\n");
}

/*************************************************************
* Function:int get_option(void)
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description: gets the menu option from the user
* Input parameters:none
* Returns:option
* Preconditions:that menu is displaying
* Postconditions:the input is a number
*************************************************************/
int get_option(void)
{
	int option = 0;
	scanf("%d", &option);
	return option;
}

/*************************************************************
* Function:void determine_option(int option)
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description: Matches the option picked by the user to send
the user down the right path based on what they picked. Bank_ptr
is initalized so it can be messed with throughout the game.
* Input parameters:option
* Returns: nothing
* Preconditions: that option is a int
* Postconditions:none
*************************************************************/
void determine_option(int option)
{

	switch (option)
	{
	case GAME_RULES: gamerules();// show game rules
		break;
	case PLAY: play_game();// play game
		break;
	case EXIT: endgame();// exit the game
		break;
	default: // catch all for other values
		break;
	}
}

/*************************************************************
* Function:void gamerules()
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description:Printf's the game rules
* Input parameters:none
* Returns:nothing
* Preconditions:none
* Postconditions:none
*************************************************************/
void gamerules(void)
{
	printf("					YAHTZEE GAME RULES:\n\n"
		"	The scorecard used for Yahtzee is composed of two sections. A upper section and a lower \n"
		"	section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the \n"
		"	sections. The upper section consists of boxes that are scored by summing the value of the \n"
		"	dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's \n"
		"	box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not \n"
		"	be changed and the combination is no longer in play for future rounds. If the sum of the \n"
		"	scores in the upper section is greater than or equal to 63, then 35 more points are added to \n"
		"	the players overall score as a bonus. The lower section contains a number of poker like \n"
		"	combinations. See the table provided below:\n\n\n"

	);
	return_to_menu();
}

/*************************************************************
* Function:int endgame(void)
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description:ends the game
* Input parameters:none
* Returns: 0
* Preconditions:none
* Postconditions:none
*************************************************************/
int endgame(void)
{
	printf("Goodbye.\n");
	return 0;
}

/*************************************************************
* Function:void return_to_menu()
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description: Returns the game to the menu to restart the
game if the user lost or won or was in the other categories.
* Input parameters:none
* Returns:nothing
* Preconditions:none
* Postconditions:none
*************************************************************/
void return_to_menu(void)
{
	int menu_choice;
	printf("\nDo you want to return to the main menu? (Enter an integer) \n"
		"1.) Yes\n"
		"2.) No\n");
	scanf("%d", &menu_choice);
	printf("\n%d\n", menu_choice);
	if (menu_choice == 1)
	{
		int option = 0;
		option = menu_select();
		determine_option(option);
	}
	else
	{
		endgame();
	}

}

/*************************************************************
* Function:void play_game()
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description:This function is the main selection map of the 1st
round of dice rolling.
* Input parameters:none
* Returns:void
* Preconditions:void
* Postconditions:void
*************************************************************/
void play_game(void)
{
	system("cls");
	//printf("Play Game.\n");
	
	int scoreboard_p1[13];
	int scoreboard_p2[13];
	
	for (int i = 13; i < 14; ++i)
	{
		single_round(scoreboard_p1, scoreboard_p2);
	}
	//Before return to menu I need to print scores and delcare winner
	return_to_menu();
}

/*************************************************************
* Function:int roll_die(void)
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description:creates a random number and sends it out to be used.
* Input parameters:void
* Returns:the dice roll value
* Preconditions:the function returns the number to be assinged to a variable
* Postconditions: the function returns the number to be assinged to a variable
*************************************************************/
int roll_die(void)
{
	int die_value = 0;
	die_value = rand() % 6 + 1;
	return die_value;
}

/*************************************************************
* Function: void single_round(void)
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description: Loops the code that executes a single round of yahtzee
* Input parameters:void
* Returns:void
* Preconditions:The loop must be verified
* Postconditions: The function must be called
*************************************************************/

void single_round(int scoreboard_p1[],int scoreboard_p2[])
{
	printf("\nsingle_round\n");
	printf("\nP1 value of spot 3 is %d", scoreboard_p1[2]);
	scoreboard_p1[2] = 3;
	printf("\nP1 value of spot 3 is %d", scoreboard_p1[2]);
    int round_number = 1;
    while (round_number < 3)
    {
        print_scoreboard(scoreboard_p1, scoreboard_p2);
    }


}

void print_scoreboard(int scoreboard_p1[],int scoreboard_p2[])
{
    printf("hello");
    printf("\nP1 value of spot 3 is %d", scoreboard_p1[2]);
    scoreboard_p1[2] = 4;
    printf("\nP1 value of spot 3 is %d", scoreboard_p1[2]);
}
/*
int offset = 0;
char plaintext_character;
char encoded_character;
printf("\n#3) Character Encoding:\n");
printf("Please enter offset which is an integer:\n");
scanf("%d", &offset);
printf("Please enter plaintext_character which is a character:\n");
scanf(" %c", &plaintext_character);
encoded_character = perform_character_encoding(plaintext_character, offset);
printf("\nencoded_character = offset + (plaintext_character - 'a') + 'A'");
printf("\n       %c          =   %d    + (         %c          -  %c ) +  %c\n", encoded_character, offset, plaintext_character, 'a', 'A');

char perform_character_encoding(char plaintext_character, int offset)
{
	double result;
	result = offset + (plaintext_character - 'a') + 'A';
	return result;
}
*/
