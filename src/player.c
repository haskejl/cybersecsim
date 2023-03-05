#include "../include/player.h"

void inline initPlayer(struct Player *p, const float initialFunds, const char name[20]) {
	for(int i=0; i<20; i++) {
		p->name[i] = name[i];
	}
	p->money = initialFunds;
}
