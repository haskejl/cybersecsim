#include "../include/simulation.h"

void run_simulation() {
	int quit = 0;
	SDL_Event event;

	while(quit == 0) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = 1;
					break;
			}
		}
		draw_screen();
	}
}
