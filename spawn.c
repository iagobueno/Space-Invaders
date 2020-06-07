#include"spawn.h"

/*inserts several elements of the same type in a single list*/
void inserts_elements_list(int type, int amount, t_list *l){
	int i;

	for(i=0;i<amount;i++)
	inserts_structure(type, l);
}

/*spawn the ship*/
	void spawn_ship(t_list *ship){
	inserts_structure(SHIP, ship);
}

/*spawn the aliens*/
void spawn_aliens(t_list *aliens){
	inserts_elements_list(ALIEN_1, 11, aliens);
	inserts_elements_list(ALIEN_2, 22, aliens);
	inserts_elements_list(ALIEN_3, 22, aliens);
}

/*spawn the fortress*/
void spawn_fortress(t_list *fortress){
	inserts_elements_list(FORTRESS_1, 8, fortress);
	inserts_elements_list(FORTRESS_2, 8, fortress);
	inserts_elements_list(FORTRESS_3, 48, fortress);
}

/*spawn the lasers*/
void spawn_lasers(t_list *lasers, t_list *aliens){
	int amount, size;
	size=list_size(aliens);

	srand(time(NULL));
	amount = (rand () % size/3)/3 + 1;

	inserts_elements_list(LASER,amount,lasers);
	set_lasers(amount, lasers, aliens);
}

/*spawn the mother*/
void spawn_mother(t_list *mother){
	if(mother->size<1){
		inserts_elements_list(MOTHER, 1, mother);
		initializes_current_beginning(mother);

		pair axis;
		axis.x=3;
		axis.y=-9;
		set_element(axis,mother);
	}
}

/*call all the spawns functions*/
void spawn_elements(t_list *ship, t_list *aliens, t_list *shoot, t_list *lasers, t_list *fortress, t_list *mother, t_game *game){
	if(game->status == STARTING){
		initializes_lists(ship, aliens, shoot, lasers, fortress, mother);
		spawn_ship(ship);
		spawn_aliens(aliens);
		spawn_fortress(fortress);
	}
	else{
		if(game->total_time % 40 == 0)
			spawn_lasers(lasers, aliens);
		if(game->total_time % 280 == 0)
			spawn_mother(mother);
	}
}
