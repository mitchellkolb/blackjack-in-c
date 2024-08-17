
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


//MAIN CODE
int main()
{
    int option = 0;
    srand(time(NULL));

    option = menu_select();

    double bank_balance = 100.0;
    determine_option(option, &bank_balance);

    return 0;
}

