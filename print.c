#include"print.h"

/*print the game's edge*/
void print_edges(int lines, int columns){
	int i;
	/*first and last lines*/
	for(i = 0;i <= columns;i++){
		move(0, i);
		addch('#');
		move(lines, i);
		addch('#');
	}
	/*first, middle and last columns*/
	for(i =0 ;i <= lines;i++){
		move(i, 0);
		addch('#');
		move(i, columns);
		addch('#');
		move(i, 100);
		addch('#');
	}
}

/*print the control's varibles of the game*/
void print_game_variables(t_list *aliens, t_game *game){
	int speed;
	speed=(500/game->alien_speed);

	mvprintw(2, 102, "score:");
	mvprintw(3, 102, "%.6d", game->score);
	mvprintw(8, 102, "speed:");
	mvprintw(9, 102, "%d", speed);
	mvprintw(14, 102, "tempo:");
	mvprintw(15, 102, "%d", game->total_time/30);
}

/*returns the current elememnt's sprite*/
char *sprites(t_list *l){
	char *sprite;

	int type;
	current_type(&type, l);
	char frame;
	current_frame(&frame, l);

	if(type==SHIP){
		if(frame=='A' || frame == 'B')
			sprite=" /A\\ MMMMM";
		else
			sprite=".' '.- \" -";
		}

	else if(type==ALIEN_1){
		if(frame=='A')
			sprite=" A A*A/ \\";
		else if(frame=='B')
			sprite=" A A*A( )";
		else
			sprite="'.' . . .";
	}

	else if(type==ALIEN_2){
		if(frame=='A')
			sprite="(( )) .U.  { } ";
		else if(frame=='B')
			sprite="\\\\ // .V.  { } ";
		else
			sprite="'. .'  .  '   '";
	}

	else if(type==ALIEN_3){
		if(frame=='A')
			sprite="(( ))\"o\"o\"// \\\\";
		else if(frame=='B')
			sprite="\\\\ //\"\\\"/\"(( ))";
		else
			sprite="'. .'  .  '   '";
	}


	else if(type==SHOOT)
		sprite="^";
	else if(type==LASER)
		sprite="?";
	else if(type==FORTRESS_1)
		sprite="J";
	else if(type==FORTRESS_2)
		sprite="L";
	else if(type==FORTRESS_3)
		sprite="I";
	else if(type==MOTHER){
		if(frame=='A')
			sprite=" JIZIZIL AoAoAoAoA'I''I''I'";
		else if(frame=='B')
			sprite=" JIZIZIL oAoAoAoAA I  I  I ";
		else
			sprite="'   .   '  ' . '  . ' . ' .";
	}
	return sprite;
}

/*change the current element's frame*/
void swap_frame(t_list *l){
	char frame;
	current_frame(&frame, l);

	if(frame == 'A')
		change_frame('B', l);
	else if(frame == 'B')
		change_frame('A', l);
	else
		return;
}

/*prints a element*/
void print_element(t_list *l){
	char *sprite;
	sprite=sprites(l);

	pair dimension;
	current_dimension(&dimension, l);

	int i, j, k;
	k=0;
	for(i=0;i<dimension.x;i++){
		for(j=0;j<dimension.y;j++,k++){
			pair axis;
			current_axis(&axis, l);
			axis.x+=i;
			axis.y+=j;

			if(axis.x >= 0 && axis.x <= 38) {
				if(axis.y >= 0 && axis.y <= 100){
					move(axis.x,axis.y);
					addch(sprite[k]);
				}
			}
		}
	}
}

/*prints every elements of a list*/
void print_list(t_list *l, t_game *game){
	int i, size;
	size=list_size(l);
	initializes_current_beginning(l);

	for(i=0;i<size;i++){
		print_element(l);
		if(game->total_time%12==0)
			swap_frame(l);
		increases_current(l);
	}
}

/*calls the other print functions*/
void print_screen(t_list *ship, t_list *aliens, t_list *shoot,
t_list *lasers, t_list *fortress, t_list *mother, t_game *game){
	erase();
	print_list(fortress, game);
	print_list(ship, game);
	print_list(aliens, game);
	attron(COLOR_PAIR(1));
	print_list(shoot, game);
	print_list(lasers, game);
	print_list(mother, game);
	print_game_variables(aliens, game);
	print_edges(LINES, COLUMNS);
	refresh();
	usleep(30000);
}

/*prints the bonus gained at the end of the current wave*/
void print_bonus(t_game *game){
	int bonus;
	bonus= 1000 - (game->round_time/30 * 10);
	game->status='A'; //MUDAR ISSO

	mvprintw(30, 102, "BONUS!:");
	mvprintw(31, 102, "%d", bonus);

	game->score+=bonus;
	refresh();
	sleep(2);
}

/*prints the game over message*/
void print_game_over(t_game *game){
	sleep(3);
	erase();
	mvprintw(19, 46, "GAME OVER");
	mvprintw(20, 44, "score: %.6d", game->score);
	refresh();
	sleep(3);
	game->status='D'; //MUDAR ISSO
}

