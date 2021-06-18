Space Invaders in C

##space-invaders

- I rebuilt the japanese shooting video game released in 1978, Space Invaders, as a College project.

#game controls
- arrow keys: move the ship
- space bar: shoot

#about language and stuff

- It was developed in C with a double linked list structure and a ASCII interface for linux console.

##ncurses

- To emulate a window, I used the ncurses library, as requested by my teacher. 
- So, to compile this project you'll need to install the ncurses library.

#installing ncurses

$ sudo apt-get install libncurses5-dev libncursesw5-dev

##compiling

- you have to tell your compiler that it needs ncurses library to compile the game.

- then, use the -lncurses flag.

- the name used as -o parameter ought be "game" cause our script "space_invaders.sh" that optimizes the game
uses this name. 

	$ gcc *.c -o game -lncurses

#executing the game

	$ ./space_invaders.sh

- thank all you guys, have fun!
