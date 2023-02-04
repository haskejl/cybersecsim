#include "../include/entity.h"

void set_entity_col(struct EntityNode *en, const int r, const int g, const int b, const int a) {
	en->red = r;
	en->green = g;
	en->blue = b;
	en->alpha = a;
}

void set_entity_loc(struct EntityNode* en, const int x, const int y) {
	en->rect.x = x;
	en->rect.y = y;
}

void set_entity_size(struct EntityNode *en, const int w, const int h) {
	en->rect.w = w;
	en->rect.h = h;
}
