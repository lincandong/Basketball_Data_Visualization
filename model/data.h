#include <string>
#include <vector>
#include "rapidjson/filereadstream.h"
#include "rapidjson/document.h"
#include <iostream>
#include "windows.h"
#include "io.h"
#include "direct.h"
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using namespace std;

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

string UTF8ToGBK(const char* strUTF8);
void cf_findFileFromDir2(string mainDir, vector<string>& files);
void load_player(unordered_map<string, vector<player_avg*>>& m, vector<vector<player_avg*>>& s);
void load_team(unordered_map<string, vector<team_avg*>>& m);

void player_series(string& name, string& begin, string& end, vector<player_avg*>& players);
void player_data(string& name, string& begin, string& end, player_avg* p);
void team_data(string name, string begin, string end, team_avg* p);
void team_series(string name, string begin, string end, vector<team_avg*>& teams);
void order(int year, vector<player_avg*>& players, bool (*cmp)(player_avg*, player_avg*));


