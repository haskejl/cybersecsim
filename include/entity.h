#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL_rect.h>

struct EntityNode {
	SDL_Rect rect;
	int red;
	int green;
	int blue;
	int alpha;
};

void set_entity_col(struct EntityNode* en, const int r, const int g, const int b, const int a);
void set_entity_loc(struct EntityNode* en, const int x, const int y);
void set_entity_size(struct EntityNode* en, const int w, const int h);

#endif
