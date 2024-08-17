
/*
Programmer: Mitchell Kolb
Class: CptS 121, Spring 2020; Lab Section ##
Programming Assingment: #5
Date: 3/13/2020
Description:  This program plays a text based game of Yahtzee

             ***ADDITION***
*/

//LIBRARIES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time ()

//DEFFINITIONS FOR VALUES
#define GAME_RULES 1
#define PLAY 2
#define EXIT 3

//FUNCTION DELCARATIONS FOR PA

//Main menu functions

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
int menu_select(void);

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
void display_menu(void);

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
int get_option(void);

/*************************************************************
* Function:void determine_option(int option)
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description: Matches the option picked by the user to send
the user down the right path based on what they picked.
* Input parameters:option
* Returns: nothing
* Preconditions: that option is a int
* Postconditions:none
*************************************************************/
void determine_option(int option);

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
void gamerules(void);

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
int endgame(void);

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
void return_to_menu(void);

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
void play_game(void);

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
int roll_die(void);

/*************************************************************
* Function:int 
* Date Created: 3/13/2020
* Date Last Modified: NA
* Description:
* Input parameters: 
* Returns: 
* Preconditions: 
* Postconditions: 
*************************************************************/
void single_round(int scoreboard_p1[],int scoreboard_p2[]);


void print_scoreboard(int scoreboard_p1[],int scoreboard_p2[]);

//char perform_character_encoding(char plaintext_character, int offset);


