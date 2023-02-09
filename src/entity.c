#include "../include/entity.h"

void handlePackets(struct PacketList* pl) {
	if(pl->head != NULL) {
		struct Packet* p = pl->head;
		struct Packet* prev = NULL;
		while(p != NULL) {
			// Check for intersection
			if(SDL_HasIntersection(&p->rect, &p->dest->rect)) {
				if(p->type == malicious_traffic && p->dest == p->src) {
					//remove the packet
					if(p == pl->head) {
						p->next = pl->freeHead;
						pl->freeHead = p;
						pl->head = NULL;
					} else {
						prev->next = p->next;
						p->next = pl->freeHead;
						pl->freeHead = p;
					}
				} else {
					p->origin = p->dest;
					p->dest = p->src;
				}
			}
			// Move the packets
			if(abs(p->dest->rect.x-p->rect.x) > abs(p->dest->rect.y-p->rect.y)) {
				p->rect.x += (p->dest->rect.x > p->rect.x) - (p->rect.x > p->dest->rect.x);
			} else {
				p->rect.y += (p->dest->rect.y > p->rect.y) - (p->rect.y > p->dest->rect.y);
			}

			// get ready for next packets
			prev = p;
			p = p->next;
		}
	} 
}

void initPacketList(struct PacketList *pl) {
	pl->head = NULL;
	pl->tail = NULL;
	pl->freeHead = pl->memStart = calloc(100, sizeof(struct Packet));
	if(pl->memStart == NULL) {
		printf("Something went wrong initializing the PacketList\n");
	}
	
	for(int i=0; i<99; i++) {
		pl->freeHead[i].next = &pl->freeHead[i+1];
		pl->freeHead[i].rect.h = 8;
		pl->freeHead[i].rect.w = 8;
	}
	pl->freeHead[99].rect.h = 8;
	pl->freeHead[99].rect.w = 8;
}

void sendAttack(struct EntityNode* attacker, struct EntityNode* defender, struct PacketList* pl) {
	if(pl->freeHead == NULL) {
		printf("Failed to add more packets, out of packets\n");
	} else {
		struct Packet* toAdd = pl->freeHead;
		pl->freeHead = pl->freeHead->next;

		toAdd->rect.x = attacker->rect.x + attacker->rect.w;
		toAdd->rect.y = attacker->rect.y + 4;
		toAdd->next = NULL;
		toAdd->src = attacker;
		toAdd->origin = attacker;
		toAdd->dest = defender;

		if(pl->tail == NULL) {
			pl->head = pl->tail = toAdd;
		} else {
			pl->tail->next = toAdd;
			pl->tail = toAdd;
		}

		set_entity_col((struct EntityNode*)toAdd, attacker->red, attacker->green, attacker->blue, attacker->alpha);

	}
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
