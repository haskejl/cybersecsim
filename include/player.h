#ifndef PLAYER_H
#define PLAYER_H

struct Player {
	float money;
	char name[20];
};

void inline initPlayer(struct Player *p, const float initialFunds, const char name[20]);

#endif
