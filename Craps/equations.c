

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

#include "equations.h"

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

int menu_select(void)
{
	int option = 0;
	do
	{
		display_menu();
		option = get_option();
	} while (option < PLAY || option > EXIT);

	return option;
}

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
void display_menu(void)
{
	printf("1. Play Game.\n");
	printf("2. Set Bank Balance.\n");
	printf("3. Game Rules.\n");
	printf("4. Exit.\n");
}

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
int get_option(void)
{
	int option = 0;
	scanf("%d", &option);
	return option;
}

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
void determine_option(int option, double* bank_ptr)
{

	switch (option)
	{
	case PLAY: play_game(bank_ptr);// play game
		break;
	case BALANCE: get_bank_balance(bank_ptr);// prompt for adjusting the balance
		break;
	case GAME_RULES: gamerules(bank_ptr);// show game rules
		break;
	case EXIT: endgame();// exit the game
		break;
	default: // catch all for other values
		break;
	}
}

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
void gamerules(double* bank_ptr)
{
	printf("					CRAPS GAME RULES:\n\n"
		"	A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, \n"
		"	and 6 spots. After the dice have come to rest, the sum of the spots on the two \n"
		"	upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. \n"
		"	If the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e. \n"
		"	the \"house\" wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the \n"
		"	sum becomes the player's \"point.\" To win, you must continue rolling the dice until \n"
		"	you \"make your point.\" The player loses by rolling a 7 before making the point.\n\n\n"

	);
	return_to_menu(bank_ptr);
}

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
int endgame(void)
{
	return 0;
}

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
void return_to_menu(double* bank_ptr)
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
		determine_option(option, bank_ptr);
	}
	else
	{
		endgame();
	}

}

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
void get_bank_balance(double* bank_ptr)
{
	printf("\nThe default bank balance is $100.00\nWhat would you like to change it to.\n");
	double change;
	scanf("%lf", &change);
	*bank_ptr = change;
	printf("Your balance has been changed to $%0.2lf\n\n", *bank_ptr);
	return_to_menu(bank_ptr);
}

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
void play_game(double* bank_ptr)
{
	printf("\n--- Bank balance is $%0.2lf ---\n", *bank_ptr);
	printf("Now rolling both of the dice...\n");
	int dice1, dice2, sum, transfer, answer = 0;
	dice1 = roll_die();
	dice2 = roll_die();
	printf("You rolled a %d and a %d.\n", dice1, dice2);
	sum = calculate_sum_dice(dice1, dice2);
	printf("The sum of your first roll is %d\n", sum);
	transfer = is_win_loss_or_point(sum, bank_ptr);
	if (transfer == 1)
	{
		you_win_the_game(bank_ptr);
	}
	else if (transfer == 0)
	{
		you_lose_the_game(bank_ptr);
	}
	else if (transfer == -1)
	{
		printf("\nDo you want to roll again:\n1.)Yes\n2.)No\n");
		scanf("%d", &answer);
		if (answer == 1)
		{
			continue_the_game(sum, bank_ptr);
		}
		else
		{
			printf("Ending game");
			endgame();
		}
	}
}

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
int roll_die(void)
{
	int die_value = 0;
	die_value = rand() % 6 + 1;
	return die_value;
}

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
int calculate_sum_dice(int dice1, int dice2)
{
	int result;
	result = dice1 + dice2;
	return result;
}

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
int is_win_loss_or_point(int sum, double* bank_ptr)
{
	if (sum == 7 || sum == 11)
	{
		return 1;
	}
	else if (sum == 2 || sum == 3 || sum == 12)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

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
void you_win_the_game(double* bank_ptr)
{
	int chat = 1;
	chatter_messages(chat);
	printf("\nYou Win The Game!!!\n");
	*bank_ptr = 100.00;
	return_to_menu(bank_ptr);
}

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
void you_lose_the_game(double* bank_ptr)
{
	printf("\nYou Lost The Game. Maybe Next Time.\n");
	*bank_ptr = 100.00;
	return_to_menu(bank_ptr);
}

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
void continue_the_game(int point, double* bank_ptr)
{
	int roll_num = 5;
	int dice1, dice2, sum, stopper = 0;
	double save = 0.0;
	
	while (stopper == 0)
	{
		betting(bank_ptr, &save);
		dice1 = roll_die();
		dice2 = roll_die();
		printf("\nYou rolled a %d and a %d.\n", dice1, dice2);
		sum = calculate_sum_dice(dice1, dice2);
		printf("The sum for roll %d is %d\nYou need to get a %d to win.\n", roll_num, sum, point);
		++roll_num;
		if (roll_num == 8 && point != sum)
		{
			chatter_messages(roll_num);
		}

		if (point == sum)
		{
			++stopper;
		}
		else if (sum == 7)
		{
			++stopper;
		}
	}
	if (point == sum)
	{
		you_win_the_game2(bank_ptr, &save);
	}
	if (sum == 7)
	{
		you_lose_the_game2(bank_ptr);
	}
}

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
void betting(double* bank_ptr, double* save_ptr)
{
	int pass = 1;
	double bet = 0.0;
	int chat = 0;
	printf("\nDo you want to bet some money.\n1.)Yes\n2.)No\n");
	scanf("%d", &pass);
	if (pass == 1)
	{
		bet = get_wager_amount(bank_ptr);
		*save_ptr += bet;
		adjust_bank_balance(bank_ptr, bet);
	}
	if (pass == 2)
	{
		printf("You don't want to bet.\n");
		++chat;
		if (chat == 2)
		{
			chatter_messages(chat);
		}
	}
}

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
double get_wager_amount(double* bank_ptr)
{
	double test = 0.0;
	double answer = 0.0;
	do
	{
		printf("\nHow much do you want to bet.\n You have $%0.2lf\n", *bank_ptr);
		scanf("%lf", &answer);
		if (*bank_ptr >= answer)
		{
			test = 1;
		}
		if (*bank_ptr < answer)
		{
			test = 0;
		}
	}
	while (test != 1);
	
	return answer;
}


/*
int check_wager_amount(double* bank_ptr, double bet)
{
	if (*bank_ptr >= bet)
	{
		return 1;
	}
	if (*bank_ptr < bet)
	{
		return 0;
	}
}
*/

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
void adjust_bank_balance(double* bank_ptr, double bet)
{
	*bank_ptr = (*bank_ptr - bet);
}

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
void you_win_the_game2(double* bank_ptr, double* save_ptr)
{
	double win_bet = 0.0;
	win_bet = (2 * *save_ptr);
	printf("\nYou Win The Game!!!\n");
	printf("You bet $%0.2lf. So that means you win $%0.2lf\n", *save_ptr, win_bet);
	*bank_ptr = 100.00;
	return_to_menu(bank_ptr);
}

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
void you_lose_the_game2(double* bank_ptr)
{
	printf("\nYou Lost The Game. Maybe Next Time.\n");
	*bank_ptr = 100.00;
	return_to_menu(bank_ptr);
}

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
void chatter_messages(int tip_off)
{
	if (tip_off == 1)
	{
		printf("\n\n\"WHATTTT! You won already... Well this was short lived.\"\n");
	}
	if (tip_off == 2)
	{
		printf("\n\n\"Oh, Come on this is a game with fake money. You should be betting all your money away.\"\n\n");
	}
	if (tip_off == 8)
	{
		printf("\n\n\"Dang this is taking a lot of rolls isn't it.\"\n");
	}
}