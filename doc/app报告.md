
#课题：篮球数据可视化应用（俱乐部数据以及球员个人数据的收集与可视化分析）


#课题要求：
	1.以MVVM模式完成一个自选主题的应用开发
	2.使用cpp系列工具链进行开发

#模块功能阐述：
	本模块负责将view，model，view model三个模块综合起来：初始化各个模块、将通知发送器与接收器绑定、将view中的数据与view model绑定、将view中的命令与view model中的命令绑定。
	由于mvvm模式下各模块均不耦合，因此绑定都是通过各模块提供的接口实现的。



#源码解读：
    int main(int argc, char *argv[])
    {
        
        //初始化QT模块
        QApplication app(argc, argv);
        
        //初始化三个模块（vm中内置model）
        view v;
        viewModel vm;

        //绑定属性改变通知
        vm.m.InitSender(vm.getModelReceiver());
        
        //绑定通知发送器与接收器
        vm.setScc(v.getCommandReceiver());
        vm.setSpc(v.getPropertyReceiver());

        //绑定数据
        v.setPlayer(vm.getPlayer());
        v.setPlayerRank(vm.getPlayerRank());
        v.setTeam(vm.getTeam());
        v.setTeamRank(vm.getTeamRank());
        
        //绑定命令
        v.setPlayerDataCommand(vm.getPlayerDataCmd());
        v.setPlayerRankCommand(vm.getPlayerRankCmd());
        v.setTeamDataCommand(vm.getTeamDataCmd());
        v.setTeamRankCommand(vm.getTeamRankCmd());

        //显示界面
        v.show();

        return app.exec();
    }

#工具链使用：
    Jenkins作为一个持续集成工具，提供了许多功能插件，我们通过这些功能插件和终端插件在Jenkins上集成自动构建、测试、发布项目的功能，以实现自动部署持续集成，同时将项目成果存储在github上，方便团队协作，并使用git作为版本控制工具以方便开发。
 
    利用Jenkins自动构建并发布在github上。

