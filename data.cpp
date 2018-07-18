#include "data.h"

void player_search_games(vector<game>& games, string player_name, time start, time end)
{
	for(start:end)
	{
		games + temp;
	}
}

player_avg player_average(string player_name, time start, time end)
{
	vector<game> games;
	player_search_games(games, player_name, start, end);
	player_avg p;
	for (games)
	{
		p.ast = ;
	}
	return p;
}

void team_search_games(vector<game>& games, string team_name, time start, time end)
{
	vector<game> temp = all_team_search(team_name);
	for(start:end)
	{
		games + temp;
	}
}

team_avg team_average(string team_name, time start, time end)
{
	vector<game> games;
	team_search_games(games, team_name, start, end);
	team_avg p;
	for (games)
	{
		p.ast = ;
	}
	return p;
}

void player_get_data(string player_name, string data_name, vector<float>& data, time start, time end)
{
	player_avg p;
	for (t in start:end)
	{
		p = player_average(player_name, t, t);
		data.push_back(p.data_name);
	}
}

void team_get_data(string team_name, string data, vector<float>& data, time start, time end)
{
	team_avg p;
	for (t in start:end)
	{
		p = team_average(team_name, t, t);
		data.push_back(p.data_name);
	}
}

void ability(string player_name, ability& data, time start, time end)
{
	player_avg p = player_average(player_name, start, end);
	data.attack = w1 * p.ast + w2 * 
}

void player_compare(string p1, string p2, string data, vector<float>& data1, vector<float>& data2, time start, time end)
{
	player_get_data(p2, data, data2, start, end);
	player_get_data(p1, data, data1, start, end);
}

void team_compare(string t1, string t2, string data, vector<float>& data1, vector<float>& data2, time start, time end)
{
	team_get_data(p2, data, data2, start, end);
	team_get_data(t1, data, data1, start, end);
}
