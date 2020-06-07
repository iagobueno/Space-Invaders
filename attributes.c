#include"attributes.h"

/*inserts the current element's axis*/
void inserts_axis(pair axis, t_list *l){
	l->current->element.axis.x=axis.x;
	l->current->element.axis.y=axis.y;
}

/*inserts the current element's dimension*/
void inserts_dimension(pair dimension, t_list *l){
	l->current->element.dimension.x=dimension.x;
	l->current->element.dimension.y=dimension.y;
}

/*changes the current element's state*/
void change_state(int state, t_list *l){
	l->current->element.state=state;
}

/*changes the current element's frame*/
void change_frame(char frame, t_list *l){
	l->current->element.frame=frame;
}

/*changes the current element's axis*/
void change_axis(pair axis, t_list *l){
	l->current->element.axis.x+=axis.x;
	l->current->element.axis.y+=axis.y;
}

/*it makes *type point the current element's type returning 1 if successful and 0 if not.*/
int current_type(int *type, t_list *l){
	if(l->current==NULL)
		return 0;
	*type=l->current->element.type;
	return 1;
}

/*it makes *axis point the element's current axis, returning 1 if successful and 0 if not.*/
int current_axis(pair *axis, t_list *l){
	if(l->current==NULL)
		return 0;
	*axis=l->current->element.axis;
	return 1;
}

/*it makes *dimension point the current element's dimension, returning 1 if successful and 0 if not.*/
int current_dimension(pair *dimension, t_list *l){
	if(l->current==NULL)
		return 0;
	*dimension=l->current->element.dimension;
	return 1;
}

/*it makes *state point the current element's state, returning 1 if successful and 0 if not.*/
int current_state(int *state, t_list *l){
	if(l->current==NULL)
		return 0;
	*state=l->current->element.state;
	return 1;
}

/*it makes *frame point the current element's frame, returning 1 if successful and 0 if not.*/
int current_frame(char *frame, t_list *l){
	if(l->current==NULL)
		return 0;
	*frame=l->current->element.frame;
	return 1;
}
