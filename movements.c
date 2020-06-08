#include"movements.h"

/*controls the directions of every alien*/
void control_aliens_direction(t_list *aliens, t_game *game){
	if(game->alien_direction == BOTTOM_LEFT){
		game->alien_speed-=1;
		if(game->alien_speed<=0)
			game->alien_speed=1;

		game->alien_direction=LEFT;
	}
	else if(game->alien_direction == BOTTOM_RIGHT){
		game->alien_speed-=1;
		if(game->alien_speed<=0)
			game->alien_speed=1;

		game->alien_direction=RIGHT;
	}
	else{
		initializes_current_beginning(aliens);

		int size;
		size=list_size(aliens);

		int i;
		for(i=0;i<size;i++){
			pair dimension, axis;
			current_dimension(&dimension, aliens);
			current_axis(&axis, aliens);

			if(axis.y + dimension.y >= 99){
				game->alien_direction=BOTTOM_LEFT;
				return;
			}

			if(axis.y == 1){
			game->alien_direction=BOTTOM_RIGHT;
			return;
			}

			increases_current(aliens);
		}
	}
}

/*move the aliens*/
void move_aliens(t_list *aliens, t_game *game){
	control_aliens_direction(aliens, game);

	/*based in alien direction, defines the axis that will
	be passed to move all the elements*/
	pair axis;
	if(game->alien_direction==RIGHT){
		axis.x=0;
		axis.y=1;
	}
	else if(game->alien_direction==LEFT){
		axis.x=0;
		axis.y=-1;
	}
	else{
		axis.x=1;
		axis.y=0;
	}

	move_elements_list(axis, aliens);
}

/*move every element of a list*/
void move_elements_list(pair axis, t_list *l){
	int size;
	size=list_size(l);

	initializes_current_beginning(l);

	int i;
	for(i=0;i<size;i++){
		change_axis(axis, l);
		increases_current(l);
	}
}

/*move the ship*/
void joypad(char *state, t_list *ship, t_list *shoot, t_game *game){
	int key;
	key = getch();

	initializes_current_beginning(ship);

	pair axis;
	current_axis(&axis, ship);
	if(key == KEY_LEFT && axis.y > 1 ){
		axis.x=0;
		axis.y=-1;
		move_elements_list(axis, ship);
	}
	else if(key == KEY_RIGHT && axis.y < 95){
		axis.x=0;
		axis.y=1;
		move_elements_list(axis, ship);
	}
	else if(key == ' '){
		int size;
		size=list_size(shoot);
		if(size < 3){
			inserts_structure(SHOOT, shoot);
			initializes_current_beginning(shoot);

			pair axis;
			current_axis(&axis, ship);
			axis.y+=2;
			set_element(axis,shoot);
		}
		return;
	}
	else if(key == 'q')
		*state = STOP;
	else
		return;
}

/*call the movements function*/
void movements(t_list *ship, t_list *aliens, t_list *shoot, t_list
*lasers, t_list *mother, t_game *game){
	joypad(&game->status, ship, shoot, game);

	if(game->alien_speed != 0 && game->total_time % game->alien_speed == 0)
		move_aliens(aliens, game);

	pair axis;
	axis.x=-1;
	axis.y=0;
	move_elements_list(axis, shoot);

	if(game->total_time != 0 && game->total_time % 4 == 0){
		axis.x=1;
		axis.y=0;
		move_elements_list(axis, lasers);
	}

	if(game->total_time!=0 && game->total_time%2==0){
		axis.x=0;
		axis.y=1;
		move_elements_list(axis, mother);
	}
}
