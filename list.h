/*double-linked list of elements*/
#ifndef LIST_H
#define LIST_H
#include<stdio.h>
#include<stdlib.h>

/* several attributes are worked in pairs during the development of the
project. therefore, this structure centralizes the treatment of these attributes */
struct pair {
	int x;
	int y;
};
typedef struct pair pair;

/*structure that contains the attributes of the screen elements*/
struct t_element {
	pair axis;
	pair dimension;
	int state;
	char frame;
	int type;
};
typedef struct t_element t_element;

/*structure of a knot that contains a element*/
struct t_knot {
	t_element element;
	struct t_knot *next;
	struct t_knot *prev;
	};
typedef struct t_knot t_knot;

/*strucuture that links the nodes*/
struct t_list {
	t_knot *first;
	t_knot *current;
	t_knot *last;
	int size;
};
typedef struct t_list t_list;

/*allocates space for the first and last pointers and
tells them where they should point*/
int initializes_list(t_list *l);

/*simply call initializes_list for all the lists that we need*/
int initializes_lists(t_list *l, t_list *m, t_list *n, t_list *o, t_list *p, t_list *q);

/*returns 1 if the list is empty and zero otherwise.*/ 
int empty_list(t_list *l);

/*returns the size of the list*/
int list_size(t_list *l);

/*inserts a new knot at the end of the list*/
int inserts_structure(int type, t_list *l);

/*tells the current pointer to point to the first knot that cointains an element*/
void initializes_current_beginning(t_list *l);

/*tells the current pointer to point to the last knot that cointains an element*/
void initializes_current_end(t_list *l);

/*tells the currrent pointer to point to the next knot*/
void increases_current(t_list *l);

/*tells the currrent pointer to point to the previous knot*/
void decreases_current(t_list *l);

/*removes the knot that the current pointer is pointing*/
int removes_current_knot(t_list *l);

/*destroys every element of the list*/
void destroys_list(t_list *l);

/*simply call destroys_list for all the lists that we need*/
void destroys_lists(t_list *l, t_list *m, t_list *n, t_list *o, t_list *p, t_list *q);

#endif
