#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include"spawn.h"
#include"movements.h"
#include"collisions.h"
#include"print.h"


int main()
{
	t_game game;

	t_list ship, aliens, shoot, lasers, fortress, mothership;

	if(!initial_set(&ship, &aliens, &shoot, &lasers, &fortress, &mothership, &game))
		exit(0);

	while(game.status == STARTING)
	{
		spawn_elements(&ship, &aliens, &shoot, &lasers, &fortress, &mothership, &game);
		control_game_state(&ship, &aliens, &fortress, &game);

		while(game.status == GAMING)
		{
			spawn_elements(&ship, &aliens, &shoot, &lasers, &fortress, &mothership, &game);
			print_screen(&ship, &aliens, &shoot, &lasers, &fortress, &mothership, &game);
			movements(&ship, &aliens, &shoot, &lasers, &mothership, &game);
			collisions(&ship, &aliens, &shoot, &lasers, &fortress, &mothership, &game);
			control_game_state(&ship, &aliens, &fortress, &game);
		}

		if(game.status == BONUS)
		{
			print_screen(&ship, &aliens, &shoot, &lasers, &fortress, &mothership, &game);
			print_bonus(&game);
		}

		if(game.status == GAME_OVER)
		{
			print_screen(&ship, &aliens, &shoot, &lasers, &fortress, &mothership, &game);
			print_game_over(&game);
		}

		destroys_lists(&ship, &aliens, &shoot, &lasers, &fortress, &mothership);
	}

	/*disables ncurses window*/
	endwin();

	return 0;
}
