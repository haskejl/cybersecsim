#include "../include/entity.h"

int handle_packet(struct Packet* p) {
	if(SDL_HasIntersection(&p->rect, &p->dest->rect)) {
		if(p->type == malicious_traffic && p->dest == p->src) {
			return -1;
		} else {
			p->origin = p->dest;
			p->dest = p->src;
		}
	}
	move_packet(p);
	return 0;
}

void move_packet(struct Packet* p) {
	if(abs(p->dest->rect.x-p->rect.x) > abs(p->dest->rect.y-p->rect.y)) {
		p->rect.x += (p->dest->rect.x > p->rect.x) - (p->rect.x > p->dest->rect.x);
	} else {
		p->rect.y += (p->dest->rect.y > p->rect.y) - (p->rect.y > p->dest->rect.y);
	}
}

void send_attack(struct EntityNode* attacker, struct EntityNode* defender, struct Packet* p) {
	p->rect.x = attacker->rect.x + attacker->rect.w;
	p->rect.y = attacker->rect.y + 4;
	p->rect.h = 8;
	p->rect.w = 8;

	set_entity_col((struct EntityNode*)p, attacker->red, attacker->green, attacker->blue, attacker->alpha);

	p->src = attacker;
	p->origin = attacker;
	p->dest = defender;
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
