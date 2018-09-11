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
	//notify when data is got or work is finished
    senderPropertyChange snd;
    //find files from a directory
    void cf_findFileFromDir2(string mainDir, vector<string>& files);
    // load players from files
	void load_player(unordered_map<string, vector<player_avg*>>& m, vector<vector<player_avg*>>& s);
	//load teams from files
	void load_team(unordered_map<string, team_avg*>& m, vector<team_avg*>& teams);
	//map name with data
	unordered_map<string, vector<player_avg*>> m_player;
	unordered_map<string, team_avg*> m_team;
	//store all data in a vector
	vector<vector<player_avg*>> v_player;
	vector<team_avg*> v_team;
	// change format between UTF and string
    std::string UTF8_To_string(const std::string & str);
    std::string string_To_UTF8(const std::string & str);

public:
	model();
    ~model() = default;
    void InitSender(shared_ptr<receiverFromModel> ptr);

	//load one player's data of many years 
	void player_series(string& name, string& begin, string& end, vector<shared_ptr<player_avg>>& players);
	//load one player's statistical data(avg etc.)
	void player_data(string& name, string& begin, string& end, shared_ptr<player_avg> p);
	//load a team's statistical data
    shared_ptr<team_avg> team_data(string& name);
	//load the player rank of a specified entry in one year(top 15) 
	void order(int year, vector<shared_ptr<player_avg>>& players, bool (*cmp)(player_avg*, player_avg*));
    //load the team rank in 17-18 season
	void order(vector<shared_ptr<team_avg>>& teams, bool (*cmp)(team_avg*, team_avg*));

};
#endif // !MODEL_H
