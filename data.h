#include <string>


struct player_avg {
	float pt;
	float reb;
	float ast;
	float fg;
	float ft;
	float stl;
	float block;
	float foul;
	float to;
};

struct team_avg {
	int win;
	int lose;
	float win_rate;
	float pt;
	float reb;
	float ast;
};

struct ability {
	float attack;
	float defense;
	float shoot;
	float run;
	float point;
	float reb;
};

player_avg player_average(string player_name, time start, time end);
void player_search_games(vector<game>& games, string player_name, time start, time end);
team_avg team_average(string team_name, time start, time end);
void team_search_games(vector<game>& games, string team_name, time start, time end);
void player_get_data(string player_name, string data_name, vector<float>& data, time start, time end);
void team_get_data(string team_name, string data, vector<float>& data, time start, time end);
void ability(string player_name, ability& data, time start, time end);
void player_compare(string p1, string p2, string data, vector<float>& data1, vector<float>& data2, time start, time end);
void team_compare(string t1, string t2, string data, vector<float>& data1, vector<float>& data2, time start, time end);




