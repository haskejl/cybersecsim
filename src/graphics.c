#include "../include/graphics.h"

const int SCREEN_HEIGHT = 960;
const int SCREEN_WIDTH = 1280;

const SDL_Color BLACK = {0, 0, 0, 255};
const SDL_Color WHITE = {255, 255, 255, 255};

static SDL_Window* window = NULL;
static SDL_Surface* surface = NULL;
static SDL_Renderer* scene = NULL;
static SDL_Texture* texture = NULL;
static TTF_Font* font = NULL;

void add_rect_to_scene(SDL_Rect* rect) {
	SDL_RenderFillRect(scene, rect);
}

void clear_scene() {
	// Clear the renderer
	SDL_SetRenderDrawColor(scene, 0, 0, 0, 255);
	SDL_RenderClear(scene);
	SDL_SetRenderDrawColor(scene, 255, 255, 255, 255);
}

void draw_scene() {
	SDL_RenderPresent(scene);
}

int init_gfx() {
	printf("Initializing video...\n");
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("ERROR: SDL failed to initialize! %s\n", SDL_GetError());
		return -1;
	}
	printf("Initializing TTF...\n");
	if(TTF_Init() < 0) {
		printf("ERROR: TTF failed to initialize!: %s\n", TTF_GetError());
		return -1;
	}
	window = SDL_CreateWindow("Cybersecurity Simulator", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(window == NULL) {
		printf("ERROR: SDL failed to create window! %s\n", SDL_GetError());
		return -1;
	}

	scene = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if(scene == NULL) {
		printf("ERROR: SDL failed to create renderer! %s\n", SDL_GetError());
		return -1;
	}

	surface = SDL_GetWindowSurface(window);
	if(surface == NULL) {
		printf("ERROR: SDL failed to create surface! %s\n", SDL_GetError());
		return -1;
	}

	font = TTF_OpenFont("./fonts/PlayfairDisplayRegular.ttf", 24);
	if(font == NULL) {
		printf("ERROR: TTF failed to load font!\n");
		return -1;
	}
	return 0;
}

void shutdown_gfx() {
	TTF_Quit();
	SDL_Quit();
}
