/*
	Programmer: Mitchell Kolb
	Class: CptS 121, Fall 2019; Lab Section 20
	Programming Assingment: PA4
	Date: 10/6/2019
	Description:This is PA4: It's an assingment where I'm going to make a game called Blackjack.
				Five total players each bet the amount they have avaliable in the bank and then
				they all roll the dice and try and get as close to 21 as possible. The closest to
				21 without going over wins 2x's their bet. 
*/

#include "functions.h"


//Global Variables
int default_bank = 0, die_value_total = 0, bet = 0;
int total_bet = 0, total = 0, total_bet_2 = 0, total_2 = 0;
int player_bank_1 = 0, player_bank_2 = 0, player_bank_3 = 0, player_bank_4 = 0, player_bank_5 = 0;
int player_dice_value_1 = 0, player_dice_value_2 = 0, player_dice_value_3 = 0, player_dice_value_4 = 0, player_dice_value_5 = 0;



/*************************************************************
* Function: 
* Date Created: 10/6/2019
* Date Last Modified: 10/6/2019
* Description: This function 
* Input parameters: 
* Returns: 
* Preconditions: 
* Postconditions: 
*************************************************************/

int menu_select(void)
{
	int option = 0;

	// Below is an input-validation loop.
	do
	{
		display_menu();
		option = get_option();
	} while (option < GAME_RULES || option > EXIT);

	return option;
}

void display_menu(void)
{
	printf("1. Game Rules.\n");
	printf("2. Set Bank Balance.\n");
	printf("3. Play Game.\n");
	printf("4. Exit.\n");
}

int get_option(void)
{
	int option = 0;

	scanf("%d", &option);

	return option;
}

void determine_option(int option)
{
	switch (option)
	{
	case GAME_RULES: gamerules();// show game rules
		break;
	case BALANCE: main_bank_balance();// prompt for balance
		break;
	case PLAY: play_game();// play game
		break;
	case EXIT: endgame();// exit the game
		break;
	default: // catch all for other values
		break;
	}
}

int gamerules(void)
{
	printf("					BLACKJACK GAME RULES:\n\n"
		"		   When starting the game up you will be prompted to choose how many players \n"
		"		you want to be in your game. Since this is a multiplayer game you are required \n"
		"		to pick between 2 - 5 people.\n\n"
		"		   When the game starts player 1 will be asked if they want to roll a dice and \n"
		"		recieve a number between 1 - 6. The player will continue to be asked to roll \n "
		"		until they reach a total of 16. Once they reach that number the player can \n"
		"		choose to stop and keep their number and let the next player start their turn.\n"
		"		The players main goal is to keep rolling the dice and try to get as close to 21 \n"
		"		as they can without rolling over 21. If the player goes over 21 they end their \n"
		"		turn and the next player starts their turn. The game is played until one player\n"
		"		decides to stop.\n\n"
		"					BETTING and the BANK\n\n"
		"		   In the main menu the player can set the original balance of bank that the\n"
		"		players will be able to bet in the game. Once the game starts each player will\n"
		"		be able to bet any amount of money they have avaliable in their account. The\n"
		"		players have the choice to bet at the start of every dice roll they have.\n  "
		"		Every bet the player makes accumulates. Each player that scores a 21 will earn\n"
		"		double the amount of money they bet. If no player scores 21, then the player \n"
		"		closest without going over earns 1.5 times the money he/she bet. If multiple \n"
		"		players earn the same high score for the game, and it is not 21, then the players\n"
		"		get the money they bet back. All other players lose their bet.\n\n"

	);
	return_to_menu();
}
void main_bank_balance(void)
{
	printf("\n\nWhat amount of money do you want every player to start out with in the bank?\n  "
		"$");
	scanf("%d", &default_bank);
	return_to_menu();
}
void play_game(void)
{
	int many_people = 0;
	printf("\nHow many people are playing the game?  (2, 3, 4, 5)\n");
	scanf("%d", &many_people);
	if (many_people == 2)
	{
		start_game_1_plyr1();
	}
	else if (many_people == 3)
	{
		printf("you picked 3");
	}
	else if (many_people == 4)
	{
		printf("you picked 4");
	}
	else if (many_people == 5)
	{
		printf("you picked 5");
	}
	else
	{
		printf("You didn't pick the right option. :( ");
		endgame();
	}

}
int endgame(void)
{
	return 0;
}

int return_to_menu(void)
{
	int menu_choice, menu_final;
	printf("Do you want to return to the main menu? (Enter an integer) \n"
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

/*


*/

void start_game_1_plyr1(void)
{
	player_bank_1 = default_bank;
	player_bank_2 = default_bank;
	printf("\n***Player 1 Your Turn Starts Now***\n");
	player_bank_1 = wdywtb();
	whole_player_turn();

}

int wdywtb(void) // wdywtb = What Do You Want To Bet 
{
	printf("\nHow much money do you want to bet: $");
	scanf("%d", &bet);
	while (bet > player_bank_1)
	{
		printf("\nYou can't bet that much. Enter an amount you can afford. ");
		printf("\nHow much money do you want to bet: $");
		scanf("%d", &bet);
	}
	total_bet = (bet + total_bet);
	total = (player_bank_1 - bet);
	printf("\nYou have $%d left in your account", total);
	printf("\nThe total amount you have bet so far is $%d", total_bet);
	return total;
}

int whole_player_turn(void)
{
	int roll = 0;
	dice_roll_under_16();
	next_ifs_1_plyr1();

}

int dice_roll_under_16(void)
{
	int die_value = 0;
	printf("\n\n***Now Rolling Dice***\n");
	while (die_value_total <= 16)
	{
		die_value = rand() % 6 + 1;
		printf("%d\n", die_value);
		die_value_total = (die_value_total + die_value);
	}
	printf("Your current total is %d\n", die_value_total);
	//die_value_total = 21;
	//return die_value;
}

void next_ifs_1_plyr1()
{
	if (die_value_total == 21)
	{
		printf("\nCongrats you got exactly 21. You get 2X your bet.\n");
		player_bank_1 = won_2x(bet);
		printf("\n     $%d\n", player_bank_1);
		endturn();
		do_you_endgame();

	}
	else if (die_value_total < 21)
	{
		next_ifs_2();
	}
	else
	{
		printf("You messed up real bad. You should never see this message.");
		endgame();
	}
}

int won_2x(int a)
{
	int plyr_bank = 0;
	plyr_bank = (a * 2);
	return plyr_bank;
}

void endturn(void)
{
	//printf("\nThis function ends the turn of the player and restarts the whole turn process for the next player\n");
}

void next_ifs_2()
{
	int choice_if_2 = 0;
	printf("\nYou are under 21, do you want to roll again or end your turn?"
		"\n1.) Roll Again"
		"\n2.) End Turn\n");
	scanf("\n%d", &choice_if_2);

	if (choice_if_2 == 1)
	{
		player_bank_1 = wdywtb();
		roll_again();
	}
	else
	{
		player_dice_value_1 = die_value_total;
		do_you_endgame();
	}
}

void roll_again()
{
	int die_value_2 = 0;
	die_value_2 = rand() % 6 + 1;
	printf("\n\nYour roll is %d\n", die_value_2);
	die_value_total = (die_value_total + die_value_2);
	printf("Your total is %d\n", die_value_total);
	//die_value_total = 21;
	compare();
}




void compare()
{
	if (die_value_total < 21)
	{
		next_ifs_2();
	}
	else if (die_value_total == 21)
	{
		printf("\nCongrats you got exactly 21. You get 2X your bet.\n");
		player_bank_1 = won_2x(total_bet);
		printf("\n     $%d\n", player_bank_1);
		do_you_endgame();

	}
	else if (die_value_total > 21)
	{
		printf("\nBust");
		do_you_endgame();
	}
	else
	{
		printf("You messed up real bad. You should never see this message.");
		endgame();
	}
}

void do_you_endgame()
{
	int do_endgame = 0;
	printf("\nYour turn has ended. Do you want to:"
		"\n1.) Move On To Next Player."
		"\n2.) End Game.\n");
	scanf("%d", &do_endgame);
	if (do_endgame == 1)
	{
		player_2();
	}
	else
	{

	}
}


//NEXT PLAYER 


void player_2()
{
	int total = 0;
	start_game_1_plyr2();
}

void start_game_1_plyr2()
{

	printf("\n***Player 2 Your Turn Starts Now***\n");
	player_bank_2 = wdywtb_2();
	whole_player_turn_2();

}

int wdywtb_2(void) // wdywtb = What Do You Want To Bet 
{
	printf("\nHow much money do you want to bet: $");
	scanf("%d", &bet);
	while (bet > player_bank_2)
	{
		printf("\nYou can't bet that much. Enter an amount you can afford. ");
		printf("\nHow much money do you want to bet: $");
		scanf("%d", &bet);
	}
	total_bet_2 = (bet + total_bet_2);
	total_2 = (player_bank_2 - bet);
	printf("\nYou have $%d left in your account", total_2);
	printf("\nThe total amount you have bet so far is $%d", total_bet_2);
	return total_2;
}

int whole_player_turn_2(void)
{
	int roll = 0;
	dice_roll_under_16_2();
	next_ifs_1_plyr2();

}

int dice_roll_under_16_2(void)
{
	int die_value = 0, die_value_total = 0;
	printf("\n\n***Now Rolling Dice***\n");
	while (die_value_total < 16)
	{
		die_value = rand() % 6 + 1;
		printf("%d\n", die_value);
		die_value_total = (die_value_total + die_value);
	}
	printf("Your current total is %d\n", die_value_total);
	//die_value_total = 21;
	//return die_value;
}

void next_ifs_1_plyr2()
{
	if (die_value_total < 21)
	{
		next_ifs_2_2();
	}
	else if (die_value_total == 21)
	{
		printf("\nCongrats you got exactly 21. You get 2X your bet.\n");
		player_bank_2 = won_2x(total_bet_2);
		printf("\n     $%d\n", player_bank_2);
		endturn();
		final_results();

	}
	else
	{
		printf("You lllmessed up real bad. You should never see this message.");
		endgame();
	}
}

void next_ifs_2_2()
{
	int choice_if_2 = 0;
	printf("\nYou are under 21, do you want to roll again or end your turn?"
		"\n1.) Roll Again"
		"\n2.) End Turn\n");
	scanf("\n%d", &choice_if_2);

	if (choice_if_2 == 1)
	{
		player_bank_2 = wdywtb_2();
		roll_again_2();
	}
	else
	{
		player_dice_value_2 = die_value_total;
		final_results();
	}
}

void roll_again_2()
{
	int die_value_2 = 0;
	die_value_2 = rand() % 6 + 1;
	printf("\n\nYour roll is %d\n", die_value_2);
	die_value_total = (die_value_total + die_value_2);
	printf("Your total is %d\n", die_value_total);
	//die_value_total = 21;
	compare_2();
}

void compare_2()
{
	if (die_value_total < 21)
	{
		next_ifs_2_2();
	}
	else if (die_value_total == 21)
	{
		printf("\nCongrats you got exactly 21. You get 2X your bet.\n");
		player_bank_2 = won_2x(total_bet_2);
		printf("\n     $%d\n", player_bank_2);
		player_dice_value_2 = 0;
		final_results();

	}
	else if (die_value_total > 21)
	{
		printf("\nBust, you really just have the worst luck.");
		player_dice_value_2 = 0;
		final_results();
	}
	else
	{
		printf("You messed up real bad. You should never see this message.");
		endgame();
	}
}

int final_results(void)
{
	printf("\n\n__________________________________________________________\n");
	if (player_dice_value_1 > player_dice_value_2)
	{
		int player1_payout = 0;
		player1_payout = (total_bet * 1.5);
		printf("\nThe Results are in!"
			"\nPlayer 1 had the higher score so they win 1.5x's what they bet: "
			"\n			You win $%d", player1_payout);
	}
	else if (player_dice_value_2 > player_dice_value_1)
	{
		int player2_payout = 0;
		player2_payout = (total_bet_2 * 1.5);
		printf("\nThe Results are in!"
			"\nPlayer 2 had the higher score so they win 1.5x's what they bet: "
			"\n			You win $%d", player2_payout);
	}
	else if (player_dice_value_1 == player_dice_value_2)
	{
		printf("The Results are in!"
			"\n You both had the same total roll so you both receive"
			"\n			A Crisp High Five... "
			"\n		...in others words you get nothing");
	}
	else
	{
		return 0;
	}
	return 0;
}
