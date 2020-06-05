/*library that is responsible for prints every element of the game*/
#ifndef PRINT_H
#define PRINT_H
#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"set.h"

/*print the game's edge*/
void print_edges(int lines, int columns);

/*print the control's varibles of the game*/
void print_game_variables(t_list *aliens, t_game *game);

/*returns the current elememnt's sprite*/
char *sprites(t_list *l);

/*change the current element's frame*/
void swap_frame(t_list *l);

/*prints a element*/
void print_element(t_list *l);

/*prints every elements of a list*/
void print_list(t_list *l, t_game *game);

/*calls the other print functions*/
void print_screen(t_list *ship, t_list *aliens, t_list *shoot,
t_list *lasers, t_list *fortress, t_list *mother, t_game *game);

/*prints the bonus gained at the end of the current wave*/
void print_bonus(t_game *game);

/*prints the game over message*/
void print_game_over(t_game *game);

#endif
