#ifndef ENTITIES_H
#define ENTITIES_H

enum Vulns {none, phishing, ddos, sql_inj};
const char vulns[10][20] = {"phishing", "ddos", "sql_inj"};

struct Server {
	char name[20];
	int x;
	int y;
	int w = 16;
	int h = 16;
	enum Vulns vuln_indices[5];
	int defenseStr;
};

struct Inet {
	char name[20];
	int x;
	int y;
	int w = 16;
	int h = 16;
};

struct Hacker {
	char name[20];
	int x;
	int y;
	int w = 16;
	int h = 16;
	enum Vulns exploit_indices[5];
	int attackStr;
};

#endif
