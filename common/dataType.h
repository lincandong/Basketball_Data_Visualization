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

    player_avg() {
        name = season = tm = "";
        g = gs = mp = fgper = fg = fga = threepper = threep = threepa
                = ftper = ft = fta = ts = trb = orb = drb = ast = stl
                = blk = tov = pf = pts = w = l = 0.0;
    }
    player_avg(player_avg *ptr)
    {
        name = ptr->name;
        season = ptr->season;
        tm = ptr->tm;
        g = ptr->g;
        gs = ptr->gs;
        mp = ptr->mp;
        fgper = ptr->fgper;
        fg = ptr->fg;
        fga = ptr->fga;
        threepper = ptr->threepper;
        threep = ptr->threep;
        threepa = ptr->threepa;
        ftper = ptr->ftper;
        ft = ptr->ft;
        fta = ptr->fta;
        ts = ptr->ts;
        trb = ptr->trb;
        orb = ptr->orb;
        drb = ptr->drb;
        ast = ptr->ast;
        stl = ptr->stl;
        blk = ptr->blk;
        tov = ptr->tov;
        pf = ptr->pf;
        pts = ptr->pts;
        w = ptr->w;
        l = ptr->l;
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
    vector<string> players;

    team_avg() {
        name = season = "";
        g = wg = lg = fgper = fg = fga = threepper = threep = threepa
                = ftper = ft = fta = ts = trb = orb = drb = ast = stl
                = blk = tov = pf = pts = 0.0;
    }
    team_avg(team_avg *ptr)
    {
        name = ptr->name;
        season = ptr->season;
        g = ptr->g;
        wg = ptr->wg;
        lg = ptr->lg;
        fgper = ptr->fgper;
        fg = ptr->fg;
        fga = ptr->fga;
        threepper = ptr->threepper;
        threep = ptr->threep;
        threepa = ptr->threepa;
        ftper = ptr->ftper;
        ft = ptr->ft;
        fta = ptr->fta;
        ts = ptr->ts;
        trb = ptr->trb;
        orb = ptr->orb;
        drb = ptr->drb;
        ast = ptr->ast;
        stl = ptr->stl;
        blk = ptr->blk;
        tov = ptr->tov;
        pf = ptr->pf;
        pts = ptr->pts;
        for (vector<string>::iterator it = ptr->players.begin(); it != ptr->players.end(); it++)
            players.push_back(*it);
    }
};

struct ability
{
	float offense;
	float defense;
	float control;
	float reb;
	float efficiency;
	ability(player_avg* p)
	{
		offense = p->pts + p->ast + p->orb;
		defense = p->blk + p->stl + p->drb;
		control = p->stl - p->tov;
		reb = p->trb;
		efficiency = p->pts + p->trb + p->ast + p->stl + p->blk - p->fga + p->fg - p->fta + p->ft;
	}
};
#endif // !DATATYPE_H
