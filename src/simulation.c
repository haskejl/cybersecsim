#include "../include/simulation.h"

void run_simulation() {
	int quit = 0;
	SDL_Event event;
	time_t tim;
	srand((unsigned) time(&tim));
	struct EntityNode hacker;
	struct EntityNode internet;
	struct EntityNode server;

	set_entity_col(&hacker, 255, 0, 0, 0);
	set_entity_col(&internet, 0, 0, 255, 0);
	set_entity_col(&server, 0, 255, 0, 0);
	set_entity_loc(&hacker, 100, 100);
	set_entity_loc(&internet, 200, 100);
	set_entity_loc(&server, 300, 100);
	set_entity_size(&hacker, 16, 16);
	set_entity_size(&internet, 16, 16);
	set_entity_size(&server, 16, 16);

	// Initialize

	while(quit == 0) {
		// Handle events
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					quit = 1;
					break;
			}
		}
		clear_scene();
		// add objs to renderer;
		add_entity_to_scene(&hacker);
		add_entity_to_scene(&internet);
		add_entity_to_scene(&server);
		draw_scene();
	}
}
