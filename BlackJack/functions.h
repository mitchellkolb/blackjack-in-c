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


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time ()
#include <math.h>

#define GAME_RULES 1
#define BALANCE 2
#define PLAY 3
#define EXIT 4

//Main menu functions
void display_menu(void);
int get_option(void);
int menu_select(void);
void determine_option(int option);

//Going from 1-4 menu options 
int gamerules(void);
void main_bank_balance(void);
void play_game(void);
int endgame(void);
int return_to_menu(void);

//Player functions
void player_2(void);
void player_3(void);
void player_4(void);
void player_5(void);

//WHEN TWO PEOPLE ARE PLAYING
//player 1 functions
void play_game(void);
void main_bank_balance(void);
void start_game_1_plyr1(void);
int wdywtb(void);
int whole_player_turn(void);
int dice_roll_under_16(void);
void next_ifs_1_plyr1(void);
int won_2x(int player_bank_1);
void endturn(void);
void next_ifs_2(void);
void roll_again(void);
void compare(void);
void do_you_endgame(void);

//player 2 functions 
void start_game_1_plyr2(void);
int wdywtb_2(void);
int whole_player_turn_2(void);
int dice_roll_under_16_2(void);
void next_ifs_1_plyr2(void);
void next_ifs_2_2(void);
void roll_again_2(void);
void compare_2(void);
int final_results(void);