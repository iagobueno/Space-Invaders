#include"set.h"

/*initialize ncurses library, their functions and the t_game's variables.*/
int initial_set(t_list *ship, t_list *aliens, t_list *shoot, t_list
*lasers, t_list *fortress, t_list *mother, t_game *game)
{
	/*calls basic ncurses functions to set the screen and the keyboard*/

	initscr();              	/* initializes a window */
	wattron(stdscr, A_BOLD);
	start_color();			/* initializes the colors*/
	cbreak();               	/* disables input buffer */
	noecho();               	/* it hides typed characters */
	nodelay(stdscr, TRUE);  	/* it turns off the input delay */
	keypad(stdscr, TRUE);   	/* it ables arrow keys */
	curs_set(FALSE);        	/* it hides the cursor from the screen */

	/*defines screen colors*/
	init_color(COLOR_RED, 1000, 0,0);
	init_pair(1, COLOR_RED, COLOR_BLACK);

	/*checks if the terminal has the appropriate size for executing the game*/
	getmaxyx(stdscr, game->lines, game->columns);
	if(game->lines < LINES || game->columns < COLUMNS){

		erase();
		mvprintw(1,1, "the current window ought have at least a 38x100 dimension");
		mvprintw(2,1, "press any key to continue");
		refresh();
		int x;
		scanf("%d", &x);
		endwin(); 
		return 0;
	}

	game->status=STARTING;
	game->score=0;
	game->total_time=0;
	game->speed_aux=14;

	return 1;
}

/*does the game maintenance routines based on the state it is in*/
void control_game_state(t_list *ship, t_list *aliens, t_list *fortress, t_game *game){

	if(game->status == STARTING){
		set_ship(ship);
		set_alien_list(aliens);
		set_fortress_list(fortress);


		game->round_time=0;
		game->alien_direction=RIGHT;
		game->status=GAMING;

		if(game->speed_aux > 1)
		game->speed_aux-=1;

		game->alien_speed=game->speed_aux;
	}
	else if(game->status==GAMING){
		if(!list_size(aliens))
			game->status=BONUS;

	game->total_time++;
	game->round_time++;
	}
}

/*set the current element*/
void set_element(pair axis, t_list *l){
	change_frame('A', l);
	change_state('A', l);
	inserts_axis(axis, l);

	int type;
	current_type(&type, l);

	pair dimension;
	if(type == SHIP){
		dimension.x=2;
		dimension.y=5;
	}
	else if(type == ALIEN_1){
		dimension.x=3;
		dimension.y=3;
	}
	else if(type == ALIEN_2 || type == ALIEN_3){
		dimension.x=3;
		dimension.y=5;
	}
	else if(type == MOTHER){
		dimension.x=3;
		dimension.y=9;
	}
	else{
		dimension.x=1;
		dimension.y=1;
	}
	inserts_dimension(dimension, l);
}

/*set the ship*/
void set_ship(t_list *ship){

	initializes_current_beginning(ship);

	pair axis;
	axis.x=36;
	axis.y=49;
	set_element(axis, ship);
}

/*set the attributes of every lasers's list element*/
void set_alien_list(t_list *aliens){
	int size;
	size=list_size(aliens);

	initializes_current_beginning(aliens);

	pair axis;
	axis.x=7;
	axis.y=3;

	int i;
	for(i=0;i<size;i++){
		/*there are 11 aliens per line*/
		if(i>0 && i%11==0){
			axis.y=2;
			axis.x+=4;
		}

	set_element(axis,aliens);

	axis.y+=7;
	increases_current(aliens);
	}
}

/*set the attributes of every fortress's list element*/
void set_fortress_list(t_list *fortress)
{
	int i;
	int aux[8] = {13,31,63,81,14,32,64,82};

	pair axis;
	axis.x=33;
	initializes_current_beginning(fortress);
	for(i=0;i<8;i++){
		axis.y=aux[i];
		set_element(axis,fortress);

		if(i==3)
			axis.x--;

		increases_current(fortress);
	}

	int aux2[8] = {18,36,68,86,19,37,69,87};
	axis.x=32;
	for(i=0;i<8;i++){
		axis.y=aux2[i];
		set_element(axis,fortress);

		if(i==3)
		axis.x++;

		increases_current(fortress);
	}

	axis.x=32;
	axis.y=15;
	for(i=0;i<48;i++){
		set_element(axis,fortress);
		if(axis.x == 32){
			if(axis.y == 17)
			axis.y=33;
			else if(axis.y == 35)
			axis.y=65;
			else if(axis.y == 67)
			axis.y=83;
			else
			axis.y++;
		}
		else if(axis.x == 33){
			if(axis.y == 18)
				axis.y=31;
			if(axis.y == 36)
				axis.y=63;
			if(axis.y == 68)
				axis.y=82;
			else
				axis.y++;
			}
		else{
			if(axis.y == 14)
				axis.y=18;
			else if(axis.y == 19)
				axis.y=31;
			else if(axis.y == 32)
				axis.y=36;
			else if(axis.y == 37)
				axis.y=63;
			else if(axis.y == 64)
				axis.y=68;
			else if(axis.y == 69)
				axis.y=81;
			else if(axis.y == 82)
				axis.y=86;
			else
				axis.y++;
		}

		if(i == 11){
			axis.x++;
			axis.y=14;
			}

		if(i == 31){
			axis.x++;
			axis.y=13;
		}

		increases_current(fortress);
	}
}


/*set the attributes of every lasers's list element*/
void set_lasers(int amount, t_list *lasers, t_list *aliens){
	int size;
	size=list_size(aliens);

	initializes_current_end(lasers);

	int i, j;
	for(i=amount;i>0;i--){
		int r;
		r= rand () % size;

		initializes_current_beginning(aliens);
		for(j=0;j<r;j++)
			increases_current(aliens);

		pair aliens_axis, aliens_dimension, axis;
		current_axis(&aliens_axis, aliens);
		current_dimension(&aliens_dimension, aliens);

		axis.x= aliens_axis.x + aliens_dimension.x - 1;
		axis.y= aliens_axis.y + aliens_dimension.y / 2;

		set_element(axis,lasers);

		decreases_current(lasers);
	}
}
