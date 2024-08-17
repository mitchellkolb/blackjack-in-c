

/*
Programmer: Mitchell Kolb
Class: CptS 121, Spring 2020; Lab Section ##
Programming Assingment: #4
Date: 2/28/2020
Description: This program plays the game craps that the PA4 assignment page reuqests.

                          ***NOTES*** Mr. O'Fallon gave us explicit insturctions that the function prototypes that are
			 on the PA4 assingment page are for people who need help setting up the program and that if we 
			 come up with better ways to create this game without them we are we can. Along with that the
			 points accociated to the function prototypes are not indicative of the point you would lose if
			 you were not going to include them. That being said I inlcuded many of the functions he wants,
			 most by their exact name. But I have changed the return type and arguments for practically all
			 of them becuase I wanted this to be code that I developed and not just copying the layout of
			 the assingment page. You will also notice that I have commented out the check_wager_amount
			 function. That is not because I forgot it but because I found a smoother way of validating 
			 wether the currently inputted betting amount is avalible by putting it into a do while loop.
			 Besides that everything should work perfectly fine in this program. Thanks for reading this blurb
			 of text.

*/

//LIBRARIES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time ()

//DEFFINITIONS FOR VALUES
#define PLAY 1
#define BALANCE 2
#define GAME_RULES 3
#define EXIT 4

//FUNCTION DELCARATIONS FOR PA4
//Main menu functions


/*************************************************************
* Function: int menu_select(void)
* Date Created: 3/2/2020
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
* Date Created: 3/2/2020
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
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description: gets the menu option from the user
* Input parameters:none
* Returns:option
* Preconditions:that menu is displaying
* Postconditions:the input is a number
*************************************************************/
int get_option(void);

/*************************************************************
* Function:void determine_option(int option, double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description: Matches the option picked by the user to send
the user down the right path based on what they picked. Bank_ptr
is initalized so it can be messed with throughout the game.
* Input parameters:option, bank_ptr
* Returns: nothing
* Preconditions: that option is a int
* Postconditions:none
*************************************************************/
void determine_option(int option, double* bank_ptr);

/*************************************************************
* Function:void gamerules(double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:Printf's the game rules
* Input parameters:bank_ptr
* Returns:nothing
* Preconditions:none
* Postconditions:none
*************************************************************/
void gamerules(double* bank_ptr);

/*************************************************************
* Function:int endgame(void)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:ends the game
* Input parameters:none
* Returns: 0
* Preconditions:none
* Postconditions:none
*************************************************************/
int endgame(void);

/*************************************************************
* Function:void return_to_menu(double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description: Returns the game to the menu to restart the
game if the user lost or won or was in the other categories.
* Input parameters:bank_ptr
* Returns:nothing
* Preconditions:none
* Postconditions:none
*************************************************************/
void return_to_menu(double* bank_ptr);

/*************************************************************
* Function:void get_bank_balance(double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:Displays the balance and will begin the procces to change it.
* Input parameters:bank_ptr
* Returns:nothing
* Preconditions:none
* Postconditions:none
*************************************************************/
void get_bank_balance(double* bank_ptr);

/*************************************************************
* Function:void play_game(double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:This function is the main selection map of the 1st
round of dice rolling.
* Input parameters:bank_ptr
* Returns:void
* Preconditions:void
* Postconditions:void
*************************************************************/
void play_game(double* bank_ptr);

/*************************************************************
* Function:int roll_die(void)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:creates a random number and sends it out to be used.
* Input parameters:void
* Returns:the dice roll value
* Preconditions:the function returns the number to be assinged to a variable
* Postconditions: the function returns the number to be assinged to a variable
*************************************************************/
int roll_die(void);

/*************************************************************
* Function:int calculate_sum_dice(int dice1, int dice2)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:adds up the two dice and returns the value.
* Input parameters:dice1 and dice2
* Returns:the sum
* Preconditions:that dice1 and dice 2 are the same type and a good value.
* Postconditions:that the function returns the number to be assinged to a variable
*************************************************************/
int calculate_sum_dice(int dice1, int dice2);

/*************************************************************
* Function:int is_win_loss_or_point(int sum, double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:determines wether the first round of dice rolling
is a win, lost, or to continue.
* Input parameters:sum, bank_ptr
* Returns:1,0,-1
* Preconditions:that sum is an int
* Postconditions:none
*************************************************************/
int is_win_loss_or_point(int sum, double* bank_ptr);

/*************************************************************
* Function:void you_win_the_game(double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description: Shows that the user has won the game on the first round
* Input parameters:bank_ptr
* Returns:nothing
* Preconditions:none
* Postconditions:none
*************************************************************/
void you_win_the_game(double* bank_ptr);

/*************************************************************
* Function:void you_lose_the_game(double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:Shows that the user has lost the game on the first round.
* Input parameters:bank_ptr
* Returns:nothing
* Preconditions:none
* Postconditions:none
*************************************************************/
void you_lose_the_game(double* bank_ptr);

/*************************************************************
* Function:void continue_the_game(int point, double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:This function is the main selection map of the 2nd
round of dice rolling.
* Input parameters:point and bank_ptr
* Returns:nothing
* Preconditions:that stopper is initalized correctly
* Postconditions:none
*************************************************************/
void continue_the_game(int sum, double* bank_ptr);

/*************************************************************
* Function:void betting(double* bank_ptr, double* save_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:Is the main function for the operation of betting.
* Input parameters:bank_ptr and save_ptr
* Returns:void
* Preconditions: that bank_ptr is inistalized correctly
* Postconditions:that pass diverts the user to the correct place
*************************************************************/
void betting(double* bank_ptr, double* save_ptr);

/*************************************************************
* Function:double get_wager_amount(double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:gets the users bet and continues the betting system
* Input parameters: bank_ptr
* Returns:answer
* Preconditions:none
* Postconditions:none
*************************************************************/
double get_wager_amount(double* bank_ptr);


//int check_wager_amount(double* bank_ptr, double bet);

/*************************************************************
* Function:void adjust_bank_balance(double* bank_ptr, double bet)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description: adjusts the bank balance to the new value.
* Input parameters:bank_ptr and bet
* Returns:void
* Preconditions: that bet is the correct type of value
* Postconditions: none
*************************************************************/
void adjust_bank_balance(double* bank_ptr, double bet);

/*************************************************************
* Function:void you_win_the_game2(double* bank_ptr, double* save_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:Displays to the user that they have won in the rounds after
the first. It also determines and displays the bets and the result.
* Input parameters:bank_ptr and save_ptr
* Returns:void
* Preconditions: that the betting has been done correctly
* Postconditions:the game will be sent off to the begining again
*************************************************************/
void you_win_the_game2(double* bank_ptr, double* save_ptr);

/*************************************************************
* Function:void you_lose_the_game2(double* bank_ptr)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:Displays to the user that they have lost in the rounds after
the first.
* Input parameters:bank_ptr and save_ptr
* Returns:void
* Preconditions: that the betting has been done correctly
* Postconditions:the game will be sent off to the begining again
*************************************************************/
void you_lose_the_game2(double* bank_ptr);

/*************************************************************
* Function:void chatter_messages(int tip_off)
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:This fucntion will send off chatter messages if the values
match correctly and it calls for it.
* Input parameters:tip_off
* Returns:nothing
* Preconditions:none
* Postconditions:none
*************************************************************/
void chatter_messages(int tip_off);


/*************************************************************
* Function:
* Date Created: 3/2/2020
* Date Last Modified: NA
* Description:
* Input parameters:
* Returns:
* Preconditions: 
* Postconditions: 
*************************************************************/