#include"list.h"

/*allocates space for the first and last pointers and
tells them where they should point*/
int initializes_list(t_list *l){
	t_knot *first_p = (t_knot*)malloc(sizeof(t_knot));
	if(first_p == NULL)
		return 0;

	t_knot *last_p = (t_knot*)malloc(sizeof(t_knot));
	if(last_p == NULL)
		return 0;

	first_p->next=last_p;
	first_p->prev=NULL;

	last_p->next=NULL;
	last_p->prev=first_p;

	l->first=first_p;
	l->last=last_p;
	l->current=NULL;
	l->size=0;
	return 1;
}

/*simply call initializes_list for all the lists that we need*/
int initializes_lists(t_list *l, t_list *m, t_list *n, t_list *o, t_list *p, t_list *q){
	if(!initializes_list(l)) return 0;
	if(!initializes_list(m)) return 0;
	if(!initializes_list(n)) return 0;
	if(!initializes_list(o)) return 0;
	if(!initializes_list(p)) return 0;
	if(!initializes_list(q)) return 0;
	return 1;
}

/*returns 1 if the list is empty and zero otherwise.*/
int empty_list(t_list *l){
	if(l->size == 0)
		return 1;

	return 0;
}

/*returns the size of the list*/
int list_size(t_list *l){
	return l->size;
}

/*inserts a new knot at the end of the list*/
int inserts_structure(int type, t_list *l){
	t_knot *new = (t_knot*)malloc(sizeof(t_knot));
	if(new == NULL)
		return 0;

	new->next=l->last;
	new->prev=l->last->prev;
	new->element.type=type;

	l->last->prev->next=new;
	l->last->prev=new;
	l->size++;
	return 1;
}

/*tells the current pointer to point to the first knot that cointains an element*/
void initializes_current_beginning(t_list *l){
	if(!empty_list(l))
		l->current=l->first->next;
}

/*tells the current pointer to point to the last knot that cointains an element*/
void initializes_current_end(t_list *l)
{
	if(!empty_list(l))
		l->current=l->last->prev;
}

/*tells the currrent pointer to point to the next knot*/
void increases_current(t_list *l){
	if(!empty_list(l)){
		if(l->current==NULL){
			l->current=l->first->next;
			return ;
		}

		l->current=l->current->next;
		}
}

/*tells the currrent pointer to point to the previous knot*/
void decreases_current(t_list *l){
	if(!empty_list(l)){

		/*if the current pointer is nulliefied, it will points to the last knot that
		 cointains an element*/
		if(l->current==NULL){
			l->current=l->last->prev;
			return;
		}

	l->current=l->current->prev;
	}
}

int removes_current_knot(t_list *l){
	if(l->current==NULL)
		return 0;

	/*links the pointers adjacent to the current pointer*/
	l->current->prev->next=l->current->next;
	l->current->next->prev=l->current->prev;

	/*save the current pointer*/
	t_knot *aux=l->current->next;

	/*nullifies the current's pointers*/
	l->current->prev=NULL;
	l->current->next=NULL;

	free(l->current);
	l->current= aux;
	l->size--;
	aux=NULL;

	return 1;
}

/*destroyss every element of the list*/
void destroys_list(t_list *l){

	/*points the current pointer to the first pointer*/
	l->current=l->first;

	/*then, points the first pointer to the next, nullifies the current's pointers,
	 and point the current pointer to the first pointer again*/
	while(l->current!=NULL){
		l->first=l->first->next;
		l->current->prev=NULL;
		l->current->next=NULL;
		free(l->current);
		l->current=l->first;
	}
}

/*simply call destroyss_list for all the lists that we need*/
void destroys_lists(t_list *l, t_list *m, t_list *n, t_list *o, t_list *p, t_list *q){
	destroys_list(l);
	destroys_list(m);
	destroys_list(n);
	destroys_list(o);
	destroys_list(p);
	destroys_list(q);
}

