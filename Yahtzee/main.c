

/*
Programmer: Mitchell Kolb
Class: CptS 121, Spring 2020; Lab Section ##
Programming Assingment: #5
Date: 3/13/2020
Description:  This program plays a text based game of Yahtzee

             ***ADDITION***
*/


#include "Equations.h"


//MAIN CODE
int main()
{
    int option = 0;
    srand(time(NULL));

    option = menu_select();

    determine_option(option);

    return 0;
}


