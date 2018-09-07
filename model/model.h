#ifndef MODEL_H
#define MODEL_H
#include "../common/rapidjson/filereadstream.h"
#include "../common/rapidjson/document.h"
#include "../common/common.h"
#include "../common/sender.h"
#include "../common/dataType.h"
#include "../viewmodel/receiver/receiverFromModel.h"
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
	model();
    ~model() = default;
    void InitSender(shared_ptr<receiverFromModel> ptr);

	void player_series(string& name, string& begin, string& end, vector<shared_ptr<player_avg>>& players);
	void player_data(string& name, string& begin, string& end, shared_ptr<player_avg> p);
	void team_data(string& name, shared_ptr<team_avg> t);
	void order(int year, vector<shared_ptr<player_avg>>& players, bool (*cmp)(player_avg*, player_avg*));
	void order(vector<shared_ptr<team_avg>>& teams, bool (*cmp)(team_avg*, team_avg*));

};
#endif // !MODEL_H
