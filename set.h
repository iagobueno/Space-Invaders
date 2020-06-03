#ifndef SET_H
#define SET_H
#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"attributes.h"
#define STARTING 'A'
#define GAMING 'B'
#define GAMEOVER 'C'
#define BONUS 'E'
#define LINES 38
#define COLUMNS 110
#define UPPER 28
#define BOTTOM 29
#define RIGHT 30
#define LEFT 31
#define BOTTOM_LEFT 32
#define BOTTOM_RIGHT 33
#define FORTRESS_1 10
#define FORTRESS_2 11
#define FORTRESS_3 12
#define EDGE 0
#define SHIP 1
#define SHOOT 2
#define ALIEN_1 -1
#define ALIEN_2 -2
#define ALIEN_3 -3
#define LASER -4
#define MOTHER -5

/*structure that contains all the variables related to the game maintenance routines*/
struct t_game
{
	char status;
	int score;
	int lines;
	int columns;
	int time;
	int time_aux;
	int alien_speed;
	int speed_aux;
	int alien_direction;
};
typedef struct t_game t_game;

/*initialize ncurses library, their functions and the t_game's variables.*/
int initial_set(t_list *ship, t_list *aliens, t_list *shoot, t_list
*lasers, t_list *fortress, t_list *mother, t_game *game;

/*does the game maintenance routines based on the state it is in*/
void control_game_state(t_list *ship, t_list *aliens, t_list *fortress, t_game *game);

/*set the current element*/
void set_element(pair axis, t_list *l);

/*set the ship*/
void set_ship(t_list *ship);

/*set the attributes of every lasers's list element*/
void set_alien_list(t_list *aliens);

/*set the attributes of every fortress's list element*/
void set_fortress_list(t_list *fortress);

/*set the attributes of every lasers's list element*/
void set_lasers(int amount, t_list *lasers, t_list *aliens);

#endif
