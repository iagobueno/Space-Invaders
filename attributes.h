/*library that handles the element's attributes inside the knots
so that other functions do not directly access the structure*/
#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/*inserts the current element's axis*/
void inserts_axis(pair axis, t_list *l);

/*inserts the current element's dimension*/
void inserts_dimension(pair dimension, t_list *l);

/*changes the current element's state*/
void change_state(int state, t_list *l);

/*changes the current element's frame*/
void change_frame(char frame, t_list *l);

/*changes the current element's axis*/
void change_axis(pair axis, t_list *l);

/*it makes *type point the current element's type returning 1 if successful and 0 if not.*/
int current_type(int *type, t_list *l);

/*it makes *axis point the element's current axis, returning 1 if successful and 0 if not.*/
int current_axis(pair *axis, t_list *l);

/*it makes *dimension point the current element's dimension, returning 1 if successful and 0 if not.*/
int current_dimension(pair *dimension, t_list *l);

/*it makes *state point the current element's state, returning 1 if successful and 0 if not.*/
int current_state(int *state, t_list *l);

/*it makes *frame point the current element's frame, returning 1 if successful and 0 if not.*/
int current_frame(char *frame, t_list *l);

#endif
