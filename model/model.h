<<<<<<< HEAD
#include "../common/rapidjson/filereadstream.h"
#include "../common/rapidjson/document.h"
#ifndef MODEL_H
#define MODEL_H
#include "..\common\common.h"
#include "..\common\sender.h"
#include "..\common\dataType.h"
#include "..\viewmodel\receiver\receiverFromModel.h"
class model
{
private:    
    senderPropertyChange snd;
    void cf_findFileFromDir2(string mainDir, vector<string>& files);
	void load_player(unordered_map<string, vector<player_avg*>>& m, vector<vector<player_avg*>>& s);
	void load_team(unordered_map<string, team_avg*>& m, vector<team_avg*>& teams);
	unordered_map<string, vector<player_avg*>> m_player;
	unordered_map<string, team_avg*> m_team;
	vector<vector<player_avg*>> v_player;
	vector<team_avg*> v_team;

public:
    model():v_team(vector<team_avg*>(5)){};
    ~model() = default;
    void InitSender(shared_ptr<receiverFromModel> ptr);

	void player_series(string& name, string& begin, string& end, vector<shared_ptr<player_avg>>& players);
	void player_data(string& name, string& begin, string& end, shared_ptr<player_avg> p);
	void team_data(string& name, shared_ptr<team_avg> t);
	void order(int year, vector<shared_ptr<player_avg>>& players, bool (*cmp)(player_avg*, player_avg*));
	void order(vector<shared_ptr<team_avg>>& teams, bool (*cmp)(team_avg*, team_avg*));

};
#endif // !MODEL_H
=======
#include <vector>
#include "rapidjson/filereadstream.h"
#ifndef MODEL_H
#define MODEL_H
#include "..\common\common.h"
#include "..\common\sender.h"
#include "rapidjson/document.h"
#include <iostream>
#include "windows.h"
#include "io.h"
#include "direct.h"
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using namespace std;

class model
{
private:
    void cf_findFileFromDir2(string mainDir, vector<string>& files);
	void load_player(unordered_map<string, vector<player_avg*>>& m, vector<vector<player_avg*>>& s);
	void load_team(unordered_map<string, team_avg*>& m, vector<team_avg*>& teams);
	unordered_map<string, vector<player_avg*>> m_player;
	unordered_map<string, team_avg*> m_team;
	vector<vector<player_avg*>> v_player;
	vector<team_avg*> v_team;
public:
    model():v_team(vector<team_avg*>(5)){};
    ~model();
	void player_series(string& name, string& begin, string& end, vector<player_avg*>& players);
	void player_data(string& name, string& begin, string& end, player_avg* p);
	void team_data(string& name, team_avg* t);
	void order(int year, vector<player_avg*>& players, bool (*cmp)(player_avg*, player_avg*));
	void order(vector<team_avg*>& teams, bool (*cmp)(team_avg*, team_avg*));
};
#endif // MODEL_H
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
