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
typedef struct t_knot t_nodo;

/*strucuture that links the nodes*/
struct t_list {
	t_knot *first;
	t_knot *current;
	t_knot *last;
	int size;
};
typedef struct t_list t_list;

int initializes_list(t_list *l);

int initialize_lists(t_list *l, t_list *m, t_list *n, t_list *o, t_list *p, t_list *q);

int empty_list(t_list *l);

int list_size(t_list *l);

int insere_estrutura_list(int tipo, t_list *l);

void initializes_current_beginning(t_list *l);

void initializes_current_beginning(t_list *l);

void increases_current(t_list *l);

void decreases_current(t_list *l);

int remove_current_item(t_list *l);

void destroy_list(t_list *l);

void destroy_lists(t_list *l, t_list *m, t_list *n, t_list *o, t_list *p, t_list *q);

#endif
