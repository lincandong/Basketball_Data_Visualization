#ifndef DATATYPE_H
#define DATATYPE_H
#include "common.h"

struct player_avg {
	string name;
	string season;
    string tm;
    float g;
    float gs;
    float mp;
    float fgper;
    float fg;
    float fga;
    float threepper;
    float threep;
    float threepa;
    float ftper;
    float ft;
    float fta;
    float ts;
    float trb;
    float orb;
    float drb;
    float ast;
    float stl;
    float blk;
    float tov;
    float pf;
    float pts;
    float w;
    float l;

    player_avg() {}
    player_avg(player_avg *ptr)
    {
        memcpy(this, ptr, sizeof(player_avg));
    }
};

struct team_avg {
	string name;
	string season;
	float g;
    float wg;
    float lg;
    float fgper;
    float fg;
    float fga;
    float threepper;
    float threep;
    float threepa;
    float ftper;
    float ft;
    float fta;
    float ts;
    float trb;
    float orb;
    float drb;
    float ast;
    float stl;
    float blk;
    float tov;
    float pf;
    float pts;

};

struct ability {
	float attack;
	float defense;
	float shoot;
	float run;
	float point;
	float reb;
};
#endif // !DATATYPE_H
