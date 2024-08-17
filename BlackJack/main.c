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

//GLobal Variables that are needed to transend functions:



int main(void)
{
	int option = 0;
	srand(time(NULL));
	
	option = menu_select();
	determine_option(option);

	return 0;
}//End of main() and of the the program!