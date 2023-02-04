#include "../include/entity.h"

void move_projectile(struct Projectile* p) {
	if(abs(p->x_dest-p->rect.x) > abs(p->y_dest-p->rect.y)) {
		p->rect.x++;
	} else {
		p->rect.y++;
	}
}

void send_attack(struct EntityNode* attacker, struct EntityNode* defender, struct Projectile* p) {
	p->rect.x = attacker->rect.x + attacker->rect.w;
	p->rect.y = attacker->rect.y;
	p->rect.h = 8;
	p->rect.w = 8;

	p->red = attacker->red;
	p->green = attacker->green;
	p->blue = attacker->blue;

	p->x_dest = defender->rect.x;
	p->y_dest = defender->rect.y;
}

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
