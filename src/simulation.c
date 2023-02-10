#include "../include/simulation.h"

void run_simulation() {
	int quit = 0;
	SDL_Event event;
	time_t tim;
	srand((unsigned) time(&tim));

	const int N_PACKETS = 100;
	int visible_packets = 0;

	struct EntityNode hacker;
	struct EntityNode internet;
	struct EntityNode server;
	struct PacketList packetList;

	SDL_Rect text;
	text.w = 400;
	text.h = 26;
	text.x = 100;
	text.y = 400;

	int money = 100000;
	char str[50];

	initPacketList(&packetList);

	set_entity_col(&hacker, 255, 0, 0, 0);
	set_entity_col(&internet, 0, 0, 255, 0);
	set_entity_col(&server, 0, 255, 0, 0);
	set_entity_loc(&hacker, 100, 100);
	set_entity_loc(&internet, 500, 100);
	set_entity_loc(&server, 1000, 100);
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
		
		// 1% chance of attack being generated
		if(rand()/(float)RAND_MAX > 0.99) {
			sendAttack(&hacker, &server, &packetList);
		}
		handlePackets(&packetList);

		struct Packet* curr = packetList.head;
		while(curr != NULL) {
			//add_entity_to_scene((struct EntityNode*)&curr);
			add_rect_to_scene(&curr->rect, curr->red, curr->green, curr->blue, curr->alpha);
			curr = curr->next;
		}

		sprintf(str, "$%d", money);

		add_text_to_scene(str, &text);

		draw_scene();
	}

	freePacketList(&packetList);
}
