#模块功能阐述：
本模块负责承接view模块以及model模块。一方面，model中的数据/算法返回值不一定可直接为view使用，所以view model（简称vm）需要设置一些数据变量将model中的数据转化成view可用的格式。这些变量将与view进行绑定，而且由于view与vm不互知，vm需要向view暴露绑定的变量。并且当model中的数据发生更新时，vm需要设置一个通知接收器，以便接收来自model的关于数据更新的通知，进而更新在vm中的相关变量。同时，当vm接收到此类通知时，需要通过一个通知发送器对view发送通知，告诉view数据更新了，应该相应地更新数据在界面上的显示。另一方面，当view需要某个数据时（已在vm中有相应的绑定数据），view是通过执行命令来让vm更新绑定的数据，进而实现view中数据的更新。而这些命令都需要在vm中实例化，并且也需要向view暴露命令。同时，当命令执行完后，vm需要通过另一个通知发送器告诉view请求的数据已经可用，可以更新界面显示了。并且vm中的两个通知发送器都需要绑定对应的接收器。



#补充说明：
1.由于在mvvm模式下，数据、命令、接收器与发送器之间的绑定都是通过绑定指针来实现的，所以为了方便管理，都统一使用智能指针。
2.本工程中，由于业务流程，model中的数据是固定的不会发生变化，因此去除了vm中的属性改变通知发送器以及view中的属性改变通知接收器。同时，在vm中设置一些临时变量。每当view请求数据时，vm执行命令将数据存在临时变量中，当vm向view发送命令完成通知时，vm再将临时变量的值赋给绑定的数据，进而实现view中数据的更新。


#源码解读：
    ViewModel主体部分：
    class viewModel
    {
    private:
        //绑定的数据
        shared_ptr<vector<shared_ptr<player_avg>>> PlayerRank;
        shared_ptr<vector<shared_ptr<player_avg>>> PlayerData;
        shared_ptr<vector<shared_ptr<team_avg>>> TeamData;
        shared_ptr<vector<shared_ptr<team_avg>>> TeamRank;

        //临时变量
        shared_ptr<vector<shared_ptr<player_avg>>> tmpPlayer;
        shared_ptr<team_avg> tmpTeam;

        //接收器，负责接收model部分的属性改变通知
        shared_ptr<receiverFromModel> receiveModel;

    public:
        //暴露绑定的数据
        shared_ptr<vector<shared_ptr<player_avg>>> getPlayer();
        shared_ptr<vector<shared_ptr<player_avg>>> getPlayerRank();
        shared_ptr<vector<shared_ptr<team_avg>>> getTeam();
        shared_ptr<vector<shared_ptr<team_avg>>> getTeamRank();

        
    //暴露接收器与发送器
        shared_ptr<receiverFromModel> getModelReceiver();
        void setSpc(shared_ptr<propertyReceiver> ptr);
        void setScc(shared_ptr<commandReceiver> ptr);

        //计算临时数据的算法
        void RequestPlayerData(shared_ptr<dataParameter> ptr);
        void RequestPlayerRank(shared_ptr<rankParameter> ptr);
        void RequestTeamData(shared_ptr<dataParameter> ptr);
        void RequestTeamRank(shared_ptr<rankParameter> ptr);
        //将临时数据更新到绑定数据上
        void UpdatePlayerData();
        void UpdatePlayerRank();
        void UpdateTeamData();
        void UpdateTeamRank();

        //命令部分
        //实例化的命令
        shared_ptr<playerDataCommand> PlayerDataCmd;
        shared_ptr<playerRankCommand> PlayerRankCmd;
        shared_ptr<teamDataCommand> TeamDataCmd;
        shared_ptr<teamRankCommand> TeamRankCmd;
        //向view暴露命令
        shared_ptr<command> getPlayerDataCmd();
        shared_ptr<command> getPlayerRankCmd();
        shared_ptr<command> getTeamDataCmd();
        shared_ptr<command> getTeamRankCmd();
        
        //其他成员
        //内含的model部分
        model m;
        //属性改变通知发送器
        senderPropertyChange spc;
        //命令完成通知发送器
        senderCommandComplete scc;
        viewModel();
    };

        命令部分：
    class command
    {
    protected:
    //命令的参数 
    std::shared_ptr<parameters> parameter;

    public:
    command();
    //暴露设置参数的接口
        void setParameter(std::shared_ptr<parameters> para);
    //执行命令（虚函数） 
    virtual void action() = 0;
    };
        


        参数部分：
    class parameters {};

    class dataParameter : public parameters
    {
    public:
        std::string name;   // 球队/球员名字
        std::string option; // 球队/球员哪项数据的历史
        std::string begin;
        std::string end;
        dataParameter(std::string name, std::string option, std::string begin, std::string end) : name(name), option(option), begin(begin), end(end) {}
    };  // 绑定一个vector，存储球队/球员的该项数据的历史记录

    class rankParameter : public parameters
    {
    public:
        std::string option;  // 用来排序的选项，按照爬取的名字来看
        int season; // 赛季
        
        rankParameter(std::string option, int season): option(option), season(season) {}

    };  // 绑定一个大小为15的vector，存储前15名球队/球员的该项数据

