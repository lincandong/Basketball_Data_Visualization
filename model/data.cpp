#include "data.h"

unordered_map<string, vector<player_avg*>> m_player;
unordered_map<string, vector<team_avg*>> m_team;
vector<vector<player_avg*>> s(5);

bool cmp(player_avg* a, player_avg* b)
{
	return a->pts>b->pts;
}

void player_series(string name, string begin, string end, vector<player_avg*>& players)
{
	players.clear();
	if(m_player.find(name)!=m_player.end())
	{
		vector<player_avg*> v = m_player[name];
		for(auto& value: v)
		{
			if(value->season>=begin && value->season<=end)
			{
				players.push_back(value);
			}
		}
	}
}

void team_series(string name, string begin, string end, vector<team_avg*>& teams)
{
	teams.clear();
	if(m_team.find(name)!=m_team.end())
	{
		vector<team_avg*> v = m_team[name];
		for(auto& value: v)
		{
			if(value->season>=begin && value->season<=end)
			{
				teams.push_back(value);
			}
		}
	}
}

void player_data(string name, string begin, string end, player_avg* p)
{
	int count = 0;
	p->name = name;
	if(m_player.find(name)!=m_player.end())
	{
		vector<player_avg*> v = m_player[name];
		for(auto& value: v)
		{
			if(value->season>=begin && value->season<=end)
			{
				count += 1;
				p->ast += value->ast;
				p->blk += value->blk;
				p->g += value->g;
				p->gs += value->gs;
				p->mp += value->mp;
				p->fg += value->fg;
				p->threep += value->threep;
				p->threepa += value->threepa;
				p->ft += value->ft;
				p->fta += value->fta;
				p->stl += value->stl;
				p->trb += value->trb;
				p->orb += value->orb;
				p->drb += value->drb;
				p->tov += value->tov;
				p->pf += value->pf;
				p->pts += value->pts;
				p->w += value->w;
				p->l += value->l;
				p->fga += value->fga;
				
			}
		}
		p->ast /= count;
		p->blk /= count;
		p->g /= count;
		p->gs /= count;
		p->mp /= count;
		p->fg /= count;
		p->threep /= count;
		p->threepa /= count;
		p->ft /= count;
		p->fta /= count;
		p->stl /= count;
		p->trb /= count;
		p->orb /= count;
		p->drb /= count;
		p->tov /= count;
		p->pf /= count;
		p->pts /= count;
		p->fga /= count;
		p->fgper = p->fg / p->fga * 1.0;
		p->threepper = p->threep / p->threepa * 1.0;
		p->ftper = p->ft / p->fta * 1.0;
	}
}

void team_data(string name, string begin, string end, team_avg* p)
{
	int count = 0;
	p->name = name;
	if(m_team.find(name)!=m_team.end())
	{
		vector<team_avg*> v = m_team[name];
		for(auto& value: v)
		{
			if(value->season>=begin && value->season<=end)
			{
				count += 1;
				p->ast += value->ast;
				p->blk += value->blk;
				p->g += value->g;
				p->fg += value->fg;
				p->threep += value->threep;
				p->threepa += value->threepa;
				p->ft += value->ft;
				p->fta += value->fta;
				p->stl += value->stl;
				p->trb += value->trb;
				p->orb += value->orb;
				p->drb += value->drb;
				p->tov += value->tov;
				p->pf += value->pf;
				p->pts += value->pts;
				p->wg += value->wg;
				p->lg += value->lg;
				p->fga += value->fga;
				
			}
		}
		p->ast /= count;
		p->blk /= count;
		p->g /= count;
		p->fg /= count;
		p->threep /= count;
		p->threepa /= count;
		p->ft /= count;
		p->fta /= count;
		p->stl /= count;
		p->trb /= count;
		p->orb /= count;
		p->drb /= count;
		p->tov /= count;
		p->pf /= count;
		p->pts /= count;
		p->fga /= count;
		p->fgper = p->fg / p->fga * 1.0;
		p->threepper = p->threep / p->threepa * 1.0;
		p->ftper = p->ft / p->fta * 1.0;
	}
}

void order(int year, vector<player_avg*>& players, bool (*cmp)(player_avg*, player_avg*))
{
	players.clear();
	vector<player_avg*> temp = s[year];
	sort(temp.begin(), temp.end(), cmp);
	for(int i=0; i<15; i++)
	{
		players.push_back(temp[i]);
	}
}

int main()
{
	load_player(m_player, s);
	//load_team(m_team);
	vector<player_avg*> v;
	order(0, v, cmp);
	for(auto& value:v)
	{
		cout << value->name << endl;
		cout << value->pts << endl;
	}
	//vector<player_avg*> players;
	//player_avg* p = new player_avg;
	//player_series("丹尼斯-施罗德", "15-16", "17-18", players);
	//player_data("丹尼斯-施罗德", "15-16", "17-18", p);
	//for(auto& t: players)
	//{
	//	cout << t->season << endl;
	//}
	//cout << p->ast << endl;
	//vector<team_avg*> teams;
	//cout << m_team["金州勇士队"][0]->ast << endl;
}
