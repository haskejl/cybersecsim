#include "../include/simulation.h"

void run_simulation() {
	int quit = 0;
	SDL_Event event;
	SDL_Rect test;
	test.x = 10;
	test.y = 0;
	test.w = 100;
	test.h = 100;

	while(quit == 0) {
		// Handle events
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = 1;
					break;
			}
		}
		// Modify the screen
		test.x++;
		if(test.x == 1180) {
			test.x = 0;
			test.y++;
			if(test.y == 860) {
				test.y = 0;
			}
		}
		clear_scene();
		// add objs to renderer;
		add_rect_to_scene(&test);
		draw_scene();
	}
}
