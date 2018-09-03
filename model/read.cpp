<<<<<<< HEAD
#include "data.h"


using namespace rapidjson;

string UTF8ToGBK(const char* strUTF8)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
    wchar_t* wszGBK = new wchar_t[len+1];
    memset(wszGBK, 0, len*2+2);
    MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
    len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
    char* szGBK = new char[len+1];
    memset(szGBK, 0, len+1);
    WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
    string strTemp(szGBK);
    if(wszGBK) delete[] wszGBK;
    if(szGBK) delete[] szGBK;
    return strTemp;
}

void cf_findFileFromDir2(string mainDir, vector<string>& files)
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
				char filename[_MAX_PATH];
				files.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

void load_player(unordered_map<string, vector<player_avg*>>& m, vector<vector<player_avg*>>& s)
{
	vector<string> files;
	cf_findFileFromDir2(".\\players", files);
	char readBuffer[65536];
	for(auto& v : files)
	{
		vector<player_avg*> temp;
		FILE* fp = fopen(v.c_str(), "rb");
		FileReadStream is(fp, readBuffer, sizeof(readBuffer));
		Document d;
		d.ParseStream(is);
		int pos = v.find(".json");
		v.erase(pos, 5);
		for (auto& a : d.GetArray())
		{
			player_avg* p = new player_avg;
			p->name = v;
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
		m[v] = temp;
		fclose(fp);
	}
	//cout << m["丹尼斯-施罗"][2]->pts << endl;
	
}

void load_team(unordered_map<string, vector<team_avg*>>& m)
{
	vector<string> files;
	cf_findFileFromDir2(".\\teams", files);
	char readBuffer[65536];
	for(auto& v : files)
	{
		vector<team_avg*> temp;
		FILE* fp = fopen(v.c_str(), "rb");
		FileReadStream is(fp, readBuffer, sizeof(readBuffer));
		Document d;
		d.ParseStream(is);
		int pos = v.find(".json");
		v.erase(pos, 5);
		if (!d.IsArray())
		{
			cout << v << endl;
			continue;
		}
		for (auto& a : d.GetArray())
		{
			if(a.IsObject())
			{
			team_avg* p = new team_avg;
			p->name = v;
			//p->season = a["season"].GetString();
			p->ast = atof(a["ast"].GetString());
			p->blk = atof(a["blk"].GetString());
			p->g = atof(a["g"].GetString());
			p->fg = atof(a["fg"].GetString());
			p->threep = atof(a["threep"].GetString());
			p->threepa = atof(a["threepa"].GetString());
			p->ft = atof(a["ft"].GetString());
			p->fta = atof(a["fta"].GetString());
			p->stl = atof(a["stl"].GetString());
			p->trb = atof(a["trb"].GetString());
			p->orb = atof(a["orb"].GetString());
			p->drb = atof(a["drb"].GetString());
			p->tov = atof(a["tov"].GetString());
			p->pf = atof(a["pf"].GetString());
			p->pts = atof(a["pts"].GetString());
			p->wg = atof(a["wg"].GetString());
			p->lg = atof(a["lg"].GetString());
			p->fga = atof(a["fga"].GetString());
			p->fgper = p->fg / p->fga * 1.0;
			p->threepper = p->threep / p->threepa * 1.0;
			p->ftper = p->ft / p->fta * 1.0;
			temp.push_back(p);
			}
		}
		m[v] = temp;
		fclose(fp);
	}
	
	
}
=======
#include "data.h"


using namespace rapidjson;

string UTF8ToGBK(const char* strUTF8)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
    wchar_t* wszGBK = new wchar_t[len+1];
    memset(wszGBK, 0, len*2+2);
    MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
    len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
    char* szGBK = new char[len+1];
    memset(szGBK, 0, len+1);
    WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
    string strTemp(szGBK);
    if(wszGBK) delete[] wszGBK;
    if(szGBK) delete[] szGBK;
    return strTemp;
}

void cf_findFileFromDir2(string mainDir, vector<string>& files)
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
				char filename[_MAX_PATH];
				files.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

void load_player(unordered_map<string, vector<player_avg*>>& m, vector<vector<player_avg*>>& s)
{
	vector<string> files;
	cf_findFileFromDir2(".\\players", files);
	char readBuffer[65536];
	for(auto& v : files)
	{
		vector<player_avg*> temp;
		FILE* fp = fopen(v.c_str(), "rb");
		FileReadStream is(fp, readBuffer, sizeof(readBuffer));
		Document d;
		d.ParseStream(is);
		int pos = v.find(".json");
		v.erase(pos, 5);
		for (auto& a : d.GetArray())
		{
			player_avg* p = new player_avg;
			p->name = v;
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
		m[v] = temp;
		fclose(fp);
	}
	//cout << m["丹尼斯-施罗"][2]->pts << endl;
	
}

void load_team(unordered_map<string, vector<team_avg*>>& m)
{
	vector<string> files;
	cf_findFileFromDir2(".\\teams", files);
	char readBuffer[65536];
	for(auto& v : files)
	{
		vector<team_avg*> temp;
		FILE* fp = fopen(v.c_str(), "rb");
		FileReadStream is(fp, readBuffer, sizeof(readBuffer));
		Document d;
		d.ParseStream(is);
		int pos = v.find(".json");
		v.erase(pos, 5);
		if (!d.IsArray())
		{
			cout << v << endl;
			continue;
		}
		for (auto& a : d.GetArray())
		{
			if(a.IsObject())
			{
			team_avg* p = new team_avg;
			p->name = v;
			//p->season = a["season"].GetString();
			p->ast = atof(a["ast"].GetString());
			p->blk = atof(a["blk"].GetString());
			p->g = atof(a["g"].GetString());
			p->fg = atof(a["fg"].GetString());
			p->threep = atof(a["threep"].GetString());
			p->threepa = atof(a["threepa"].GetString());
			p->ft = atof(a["ft"].GetString());
			p->fta = atof(a["fta"].GetString());
			p->stl = atof(a["stl"].GetString());
			p->trb = atof(a["trb"].GetString());
			p->orb = atof(a["orb"].GetString());
			p->drb = atof(a["drb"].GetString());
			p->tov = atof(a["tov"].GetString());
			p->pf = atof(a["pf"].GetString());
			p->pts = atof(a["pts"].GetString());
			p->wg = atof(a["wg"].GetString());
			p->lg = atof(a["lg"].GetString());
			p->fga = atof(a["fga"].GetString());
			p->fgper = p->fg / p->fga * 1.0;
			p->threepper = p->threep / p->threepa * 1.0;
			p->ftper = p->ft / p->fta * 1.0;
			temp.push_back(p);
			}
		}
		m[v] = temp;
		fclose(fp);
	}
	
	
}
>>>>>>> origin/master
