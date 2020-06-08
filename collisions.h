#ifndef COLLISIONS_H
#define COLLISIONS_H
#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"set.h"

/*remove every dying element*/
void removes_exploding_elements(t_list *l, t_game *game);

/*treat collisions between elements*/
void elements_collisions(t_list *l, t_game *game);

/*treat collisions between elements and the edges*/
void edges_collisions(t_list *l, t_game *game);

/*checks collisions between elements*/
void check_elements_collisions(int amount, t_list *l, t_list *m, t_game *game);

/*checks collisions between elements and the edges*/
void check_edges_collisions(int edge, int n, t_list *l, t_game *game);

/*call every collision function*/
void collisions(t_list *ship, t_list *aliens, t_list *shoot, t_list
*lasers, t_list *fortress, t_list *mother, t_game *game);

#endif
