#include "../include/simulation.h"

void run_simulation() {
	int quit = 0;
	SDL_Event event;
	time_t tim;
	srand((unsigned) time(&tim));

	const int N_PACKETS = 100;
	int visible_packets = 0;
	int next_attack = 10;//(int)(rand()/(float)RAND_MAX * 1000.f + 200.f);

	struct EntityNode hacker;
	struct EntityNode internet;
	struct EntityNode server;
	struct Packet packets[N_PACKETS];

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
		
		// 10% chance of attack being generated
		if(next_attack == 0) {
			send_attack(&hacker, &server, &packets[visible_packets++]);
			next_attack = 10;//(int)(rand()/(float)RAND_MAX * 1000.f + 50.f);
		}
		next_attack--;
		int remove_n_packets = 0;
		for(int i=0; i<visible_packets; i++) {
			// TODO: This is treats them like a stack, need to make these into a linked list
			remove_n_packets += handle_packet(&packets[i]);
			add_entity_to_scene((struct EntityNode*)&packets[i]);
		}
		visible_packets += remove_n_packets;

		draw_scene();
	}
}
