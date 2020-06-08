#include"set.h"

/*remove every dying element*/
void removes_exploding_elements(t_list *l, t_game *game){
	if(game->alien_speed != 0 && game->total_time % game->alien_speed == 0){
		initializes_current_beginning(l);
		int control, i, state, size;
		size=list_size(l);

		for(i = 0;i < size;i++){
			control=0;
			
			current_state(&state, l);
			if(state == 'D'){
				removes_current_knot(l);
				control=1;
			}

			if(!control)
				increases_current(l);
			if(control)
				break;
			size=list_size(l);
		}
	}
}

/*treat collisions between elements*/
void elements_collisions(t_list *l, t_game *game){
	int type;
	current_type(&type, l);

	if(type == SHIP){
		change_frame('D',l);
		game->status=GAME_OVER;
	}
	else if(type == ALIEN_1){
		game->score+=30;
		change_state('D',l);
		change_frame('D',l);
	}
	else if(type == ALIEN_2){
		game->score+=20;
		change_state('D',l);
		change_frame('D',l);
	}
	else if(type == ALIEN_3){
		game->score+=10;
		change_state('D',l);
		change_frame('D',l);
	}
	else if(type == MOTHER){
		game->score+=200;
		change_state('D',l);
		change_frame('D',l);
	}
	else
		removes_current_knot(l);
}

/*treat collisions between elements and the edges*/
void edges_collisions(t_list *l, t_game *game){
	int type;
	current_type(&type, l);
	if(type == ALIEN_1 || type == ALIEN_2 || type == ALIEN_3)
		game->status=GAME_OVER;
	else
		removes_current_knot(l);
}

/*checks collisions between elements*/
void check_elements_collisions(int amount, t_list *l, t_list *m, t_game *game){
	int i, j, size_l, size_m;
	initializes_current_beginning(l);
	size_l=list_size(l);

	for(i = 0;i < size_l;i++){
		int control;

		/*getting first axis and dimension*/
		pair axis_1, dim_1;
		current_axis(&axis_1, l);
		current_dimension(&dim_1, l);

		size_m=list_size(m);
		initializes_current_beginning(m);
		for(j=0;j < size_m;j++){
			control=0;
			int state;
			current_state(&state, m);
			if(state == 'D'){

				/*gettint second axis and dimension*/
				pair axis_2, dim_2;
				current_axis(&axis_2, l);
				current_dimension(&dim_2, l);

				/*the code below basically says: if collides, treat collision*/

				/*collision calculation for x*/
				if(axis_1.x + dim_1.x - 1 >= axis_2.x && axis_1.x <= axis_2.x + dim_2.x - 1){


					/*collision calculation for y*/
					if(axis_1.y + dim_1.y - 1 >= axis_2.y && axis_1.y <= axis_2.y + dim_2.y - 1){
						elements_collisions(l, game);
						if(amount == 2)
							elements_collisions(m, game);
						control=1;
					}
				}
			}
			increases_current(m);
			if(control)
				break;
		}

		if(!control)
			increases_current(l);
		size_l=list_size(l);
	}
}

/*checks collisions between elements and the edges*/
void check_edges_collisions(int edge, int n, t_list *l, t_game *game){
	int i, size;
	initializes_current_beginning(l);
	size=list_size(l);

	//MUDAR AQUI
	for(i=0;i < size;i++){
		int control;
		pair axis;
		control=0;
		current_axis(&axis, l);
		if(edge == RIGHT){
			if(axis.y > n){
				removes_current_knot(l);
				control=1;
			}
		}
		else{
			if(edge == BOTTOM){
				if(axis.x > n){
					edges_collisions(l, game);
					control=1;
				}
			}
			else{
				if(axis.x < n){
					removes_current_knot(l);
					control=1;
				}
			}
		}
		if(!control)
			increases_current(l);
		size=list_size(l);
	}
}

/*call every collision function*/
void collisions(t_list *ship, t_list *aliens, t_list *shoot, t_list
*lasers, t_list *fortress, t_list *mother, t_game *game){
	check_elements_collisions(2, shoot, aliens, game);
	check_elements_collisions(2, shoot, fortress, game);
	check_elements_collisions(2, shoot, mother, game);
	check_elements_collisions(2, lasers, fortress, game);
	check_elements_collisions(1, fortress, aliens, game);
	check_elements_collisions(1, ship, aliens, game);
	check_elements_collisions(1, ship, lasers, game);
	check_edges_collisions(UPPER, 1, shoot, game);
	check_edges_collisions(BOTTOM, 37, lasers, game);
	check_edges_collisions(RIGHT, 99, mother, game);
	check_edges_collisions(BOTTOM, 35, aliens, game);
	removes_exploding_elements(aliens, game);
	removes_exploding_elements(mother, game);
}

