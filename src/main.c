#include <SDL2/SDL.h>
#include <stdio.h>

#include "../include/graphics.h"
#include "../include/simulation.h"

int main(int argc, char* args[]) {
	if(init_gfx() != 0) {
		return -1;
	}

	run_simulation();
	
	shutdown_gfx();
}
