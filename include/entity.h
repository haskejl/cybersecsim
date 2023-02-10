#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL_rect.h>

enum PacketType {
	normal_traffic, malicious_traffic
};

struct EntityNode {
	SDL_Rect rect;
	int red;
	int green;
	int blue;
	int alpha;
};

struct Packet {
	SDL_Rect rect;
	int red;
	int green;
	int blue;
	int alpha;
	struct EntityNode* src;
	struct EntityNode* origin;
	struct EntityNode* dest;
	enum PacketType type;
	int n_records;
	struct Packet* next;
};

struct PacketList {
	struct Packet* head;
	struct Packet* tail;
	struct Packet* freeHead;
	struct Packet* memStart;
};

void freePacketList(struct PacketList* pl);
void handlePackets(struct PacketList* pl);
void initPacketList(struct PacketList* pl);
void sendAttack(struct EntityNode* attacker, struct EntityNode* defender, struct PacketList* pl);

void set_entity_col(struct EntityNode* en, const int r, const int g, const int b, const int a);
void set_entity_loc(struct EntityNode* en, const int x, const int y);
void set_entity_size(struct EntityNode* en, const int w, const int h);

#endif
