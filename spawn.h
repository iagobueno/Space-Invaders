#ifndef SPAWN_H
#define SPAWN_H
#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"set.h"

/*inserts several elements of the same type in a single list*/
void inserts_elements_list(int type, int amount, t_list *l);

/*spawn the ship*/
void spawn_ship(t_list *ship);

/*spawn the aliens*/
void spawn_aliens(t_list *aliens);

/*spawn the fortress*/
void spawn_fortress(t_list *fortress);

/*spawn the lasers*/
void spawn_lasers(t_list *lasers, t_list *aliens);

/*spawn the mother*/
void spawn_mother(t_list *mother);

/*call all the spawns functions*/
void spawn_elements(t_list *ship, t_list *aliens, t_list *shoot, t_list *lasers, t_list *fortress, t_list *mother, t_game *game);

#endif
