#include "model.h"

model::model()
{
    v_player.resize(5);
    load_player(m_player, v_player);
    load_team(m_team, v_team);
}
void model::InitSender(shared_ptr<receiverFromModel> ptr)
{
    snd.add(ptr);
}
///
std::string model::UTF8_To_string(const std::string & str)
{
int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴
memset(pwBuf, 0, nwLen * 2 + 2);

MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

char * pBuf = new char[nLen + 1];
memset(pBuf, 0, nLen + 1);

WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

std::string retStr = pBuf;

delete []pBuf;
delete []pwBuf;

pBuf = NULL;
pwBuf = NULL;

return retStr;
}
std::string model::string_To_UTF8(const std::string & str)
{
int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴
ZeroMemory(pwBuf, nwLen * 2 + 2);

::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

char * pBuf = new char[nLen + 1];
ZeroMemory(pBuf, nLen + 1);

::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

std::string retStr(pBuf);

delete []pwBuf;
delete []pBuf;

pwBuf = NULL;
pBuf  = NULL;

return retStr;
}
///
void model::cf_findFileFromDir2(string mainDir, vector<string>& files)
{
	files.clear();
	const char *dir = mainDir.c_str();
	_chdir(dir);
	long hFile;
	_finddata_t fileinfo;
 
	if ((hFile = _findfirst("*.*", &fileinfo)) != -1)
	{
		do
		{
			if (!(fileinfo.attrib & _A_SUBDIR))
            {
                files.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

void model::load_player(unordered_map<string, vector<player_avg*>>& m, vector<vector<player_avg*>>& s)
{
	vector<string> files2;
	cf_findFileFromDir2("../NBA/data/players", files2);
	char readBuffer[65536];
	for(auto& v : files2)
    {
		vector<player_avg*> temp;
		FILE* fp = fopen(v.c_str(), "rb");
		rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
		rapidjson::Document d;
		d.ParseStream(is);
		int pos = v.find(".json");
		v.erase(pos, 5);
        if (d.IsArray())
            for (auto& a : d.GetArray())
            {
                player_avg* p = new player_avg;
                p->name = string_To_UTF8(v);
                p->season = a["season"][0].GetString();
                p->tm = a["tm"][0].GetString();
                p->ast = atof(a["ast"][0].GetString());
                p->blk = atof(a["blk"][0].GetString());
                p->g = atof(a["g"][0].GetString());
                p->gs = atof(a["gs"][0].GetString());
                p->mp = atof(a["mp"][0].GetString());
                p->fg = atof(a["fg"][0].GetString());
                p->threep = atof(a["threep"][0].GetString());
                p->threepa = atof(a["threepa"][0].GetString());
                p->ft = atof(a["ft"][0].GetString());
                p->fta = atof(a["fta"][0].GetString());
                p->stl = atof(a["stl"][0].GetString());
                p->trb = atof(a["trb"][0].GetString());
                p->orb = atof(a["orb"][0].GetString());
                p->drb = atof(a["drb"][0].GetString());
                p->tov = atof(a["tov"][0].GetString());
                p->pf = atof(a["pf"][0].GetString());
                p->pts = atof(a["pts"][0].GetString());
                p->w = atof(a["w"][0].GetString());
                p->l = atof(a["l"][0].GetString());
                p->fga = atof(a["fga"][0].GetString());
                p->fgper = p->fg / p->fga * 1.0;
                p->threepper = p->threep / p->threepa * 1.0;
                p->ftper = p->ft / p->fta * 1.0;
                temp.push_back(p);
                if(p->season == "17-18")
                    s[0].push_back(p);
                if(p->season == "16-17")
                    s[1].push_back(p);
                if(p->season == "15-16")
                    s[2].push_back(p);
                if(p->season == "14-15")
                    s[3].push_back(p);
                if(p->season == "13-14")
                    s[4].push_back(p);
            }
        m[string_To_UTF8(v)] = temp;
		fclose(fp);
	}
	//cout << m["�ղ���-ղķ˹"][2]->pts << endl;
	
}

void model::load_team(unordered_map<string, team_avg*>& m, vector<team_avg*>& v_team)
{
	vector<string> files;
    cf_findFileFromDir2("../teams/17-18season", files);
	char readBuffer[65536];
    //cout << "team" << endl;
	for(auto& v : files)
    {
		FILE* fp = fopen(v.c_str(), "rb");
		rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
		rapidjson::Document d;
		d.ParseStream(is);
		int pos = v.find(".json");
		v.erase(pos, 5);
		if (!d.IsArray())
		{
			cout << v << endl;
			continue;
		}
		//if (!d.IsArray())
		//cout << "no " << endl;
		team_avg* p = new team_avg;
		for (auto& a : d.GetArray())
		{
			if(a.HasMember("pts"))
			{
            p->name = string_To_UTF8(v);
			//p->season = a["season"].GetString();
			p->ast = atof(a["ast"][0].GetString());
			p->blk = atof(a["blk"][0].GetString());
			p->g = atof(a["g"][0].GetString());
			p->fg = atof(a["fg"][0].GetString());
			p->threep = atof(a["threep"][0].GetString());
			p->threepa = atof(a["threepa"][0].GetString());
			p->ft = atof(a["ft"][0].GetString());
			p->fta = atof(a["fta"][0].GetString());
			p->stl = atof(a["stl"][0].GetString());
			p->trb = atof(a["trb"][0].GetString());
			p->orb = atof(a["orb"][0].GetString());
			p->drb = atof(a["drb"][0].GetString());
			p->tov = atof(a["tov"][0].GetString());
			p->pf = atof(a["pf"][0].GetString());
			p->pts = atof(a["pts"][0].GetString());
			p->wg = atof(a["wg"][0].GetString());
			p->lg = atof(a["lg"][0].GetString());
			p->fga = atof(a["fga"][0].GetString());
			p->fgper = p->fg / p->fga * 1.0;
			p->threepper = p->threep / p->threepa * 1.0;
            p->ftper = p->ft / p->fta * 1.0;
            v_team.push_back(p);
            m[string_To_UTF8(v)] = p;
			}
            if (a.HasMember("name"))
            {
                p->players.push_back(a["name"][0].GetString());
            }


		}
		fclose(fp);
	}
	
	//cout << m["���������������"]->pts << endl;
}


void model::player_series(string& name, string& begin, string& end, vector<shared_ptr<player_avg>>& players)
{
	players.clear();
	if(m_player.find(name)!=m_player.end())
	{
		vector<player_avg*> v = m_player[name];
		for(auto& value: v)
		{
			if(value->season>=begin && value->season<=end)
			{
				players.push_back(make_shared<player_avg>(value));
			}
		}
	}
	snd.notify("player has been set");
}

void model::player_data(string& name, string& begin, string& end, shared_ptr<player_avg> p)
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
	snd.notify("player has been set");
}

shared_ptr<team_avg> model::team_data(string& name)
{
    string str = name;
    str.append("队");
    shared_ptr<team_avg> t = make_shared<team_avg>(m_team[str]);
	snd.notify("team has been set");
    return t;
}

void model::order(int year, vector<shared_ptr<player_avg>>& players, bool (*cmp)(player_avg*, player_avg*))
{
	players.clear();
    vector<player_avg*> temp = v_player[2017 - year];
    shared_ptr<player_avg> p;
	sort(temp.begin(), temp.end(), cmp);
	for(int i=0; i<15; i++)
    {
        p = make_shared<player_avg>(temp[i]);
		players.push_back(p);
	}
	snd.notify("player rank has been set");
}

void model::order(vector<shared_ptr<team_avg>>& teams, bool (*cmp)(team_avg*, team_avg*))
{
    teams.clear();
    vector<team_avg*> temp = v_team;
    shared_ptr<team_avg> p;
	sort(temp.begin(), temp.end(), cmp);
	for(int i=0; i<15; i++)
    {
        p = make_shared<team_avg>(temp[i]);
        teams.push_back(p);
	}
	snd.notify("team rank has been set");
}

