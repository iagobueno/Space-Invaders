/*library that contain all the movements's functions*/
#ifndef MOVEMENTS_H
#define MOVEMENTS_H
#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"set.h"

/*controls the directions of every alien*/
void control_aliens_direction(t_list *aliens, t_game *game);

/*move the aliens*/
void move_aliens(t_list *aliens, t_game *game);

/*move every element of a list*/
void move_elements_list(pair axis, t_list *l;

/*move the ship*/
void joypad(char *state, t_list *ship, t_list *shoot, t_game *game);

/*call the movements function*/
void movements(t_list *ship, t_list *aliens, t_list *shoot, t_list
*lasers, t_list *mae, t_game *game);

#endif
