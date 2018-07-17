# CppSummerProject
A simple cpp project for summer school in ZJU
##主题：
__篮球数据可视化：俱乐部数据以及球员个人数据的收集与可视化分析。__
#工作流程：
   设计俱乐部类与球员类
#   1.爬取数据
		*非动态爬取，一次性爬取并存入本地文件中
		*用一个数据管理器管理所有数据，并提供接口，供界面管理器调用并获得所需数据
		*编写初始化函数：
			1) 存储所有的比赛（到一个容器里）
			2) 将比赛关联到俱乐部与球员

#	2.设计UI界面
##		a、菜单以及子菜单的设计
			（1）菜单及子菜单内容根据菜单树设置，可视化数据使用多个图表显示在一个窗口或标签卡对应的多个窗口。
			（2）菜单位于窗口最上方，主菜单横向排列，子菜单为下拉菜单。
			（3）点击菜单，出现下一级子菜单，点击最子级的菜单，重绘主窗口并调用相应的绘制函数：
				a)球员介绍：头像、名字，点击球员调用球员数据绘制函数（绘制所有数据）。
				b)球队介绍：图标、名字，点击球队调用球队数据绘制函数（绘制所有数据）。
				c)球员排名：根据菜单绘制对应数据的图表。
				d)球队排名和战绩排名：根据菜单绘制对应数据的图表。

##		b、菜单内容：该菜单可视化
###			（1）哪些数据
				a)球员排行：投篮、三分、罚球、篮板、助攻、抢断、盖帽、失误、犯规、得分。
				b)球队排行：投篮、三分、罚球（细分为命中率、命中和出手），篮板（细分为总篮板、进攻和防守）、助攻、抢断、盖帽、失误、犯规、得分，战绩（细分为胜、负、胜率、胜场差、联盟、主场、客场、得分、失分、净胜）。
				c)球员介绍：头像、名字等基本信息。
				d)球队介绍：图标、名字等基本信息。
			
###			（2）以什么形式
				1)排行数据柱状图
				2)球员或球队数据趋势图（折线图），能力数据六芒星图（只取主要的数据类型）。
				3)多个球员或球队进行比较的趋势图（折线图）。

##		c、绘制一个菜单树
			战绩排行：
				|-东部赛区
				|-西部赛区
				（可跳转到球队数据页面）
			数据： 
				|-东部赛区
				|-西部赛区
					|-西南赛区
						|-休斯顿火箭
							|-球队
								{
									战绩
									{
										时间轴控制的
											>总胜率、总胜场、总负场（饼状图或一条数轴）
											>对每个其他队的胜率、胜场、负场(折线图(value VS time))
									}
								}
							|-球员
								{
									基本信息
									{
										名字、头像、简介
									}
									详细信息
									{
										综合能力（五芒星）
											拖动时间轴
										单项数据（avg）
											按整年的记录或赛季的记录，以折线图形式表现
									}
								}
					|-太平洋赛区
				……

#	3.实现界面（熟悉qt）：
		i. 将窗口约分成基本单元（设计类与继承），实现基本面板的代码
		ii. 利用基本单元实现完整的各个窗口函数。建立各面板之间的跳转关系
	
		Basic ideas:
			//
			class panel
			{
			public:
				…
				panel& parent; //父panel的引用，以便从子panel返回父panel
				void Init(); //根据一个树型结构建立各panel之间的关系
				vector<panel> panels; //包含所有子panels(行为是折叠与展开)
				vector<panel> siblings; //可切换到的其他panel(行为是切换)
				panel& Jump(int x, int y); //接收鼠标点击的坐标，确定选中的是哪个sibling以及是否发生跳转行为。若无跳转，返回自己。
				void Activate(int x, int y); //根据鼠标点击坐标，激活需要展开的子panel. If set, make it unset.
				void Display(); //供顶层窗口使用，绘制panel本身以及所有激活了的子panels
			}

#	4.顶层窗口
		*顶层窗口：监视I/O行为
			1) 监视鼠标与键盘行为，使用状态机的设计，鼠标点击则跳转到下一状态。当前状态的菜单会被显示
			2) 两类panel：
				i.会引起切换的panel
				ii.只引起子panel折叠与展开的panel

				Basic ideas:
					panel thisPanel, nextPanel;
					int x, y;
					thisPanel = topMenu;
					whille(not exit)
					{
						x = getMouseX();
						y = getMouseY();
						nextPanel = thisPanel(x, y);
						if(nextPanel != thisPanel) thisPanel = nextPanel;
						else thisPanel.Activate(x, y);
						thisPanel.Display();
					}

#	5.数据分析
##		实现：
			确定并编写基本的统计函数（以球员/俱乐部ID、container的引用作为参数）
			基于设计，调用各统计分析函数，再做数据处理
##		内容：
###		一、单主体分析
			1.球员基本统计
				1）单项数据统计（average）:（根据球员和相关比赛）
					得分
					篮板
					助攻
					...
				float average(string playerName, string start, string end)
				{
					vector<game> games;	
					int ID = searchID(playerName);
					searchGames(ID, start, end, games);
				}
				void searchGames(int playerID, string start, string end, vector<game>& games)
				{

				}
				int searchID(string playerName)
				{
					...
					return ID;
				}

			2.球队基本统计
				1）sum/average统计:（根据球队和相关比赛）
					胜场
					胜率
					得分
					...

			3.球员总结统计
				1）短期（近期）统计
					赛季统计
					个人生涯统计（三者均属于定期统计）
				2）趋势统计：
					定期统计按时间顺序多次调用
					增加趋势指标（增长率，峰值等）
					void getData(..., vector<float>& data)
					{

					}
				3）球员能力：
					分别调用得分、篮板、助攻的基本统计，加权平均，得到球员能力值
					void analyze(..., struct 六芒星& data){ }

			4.球队总结统计
				1）短期（近期）统计
					赛季统计
					队史统计（三者均属于定期统计）：
					根据球员和指定日期内的比赛，调用sum（max）函数
				2）趋势统计：
					定期统计按时间顺序多次调用
					增加趋势指标（增长率，峰值等）

###		二、多主体分析
			1.球员对比分析
				两人，时间轴
				void calculateDifference(..., vector<float>& data);
			2.球队组合分析
				类似球员

###		三、其他分析
			比赛结果预测：
				胜率函数（根据球队能力）
				模拟比赛结果

#工具：
	爬取数据（py脚本）
	UI（QT）

#目录树
	|-view
		|- new button
			|- .cpp & .h
		|- new slider
			|- .cpp & .h
		...
	|-viewModel
	|-model
	|-app
	|-command
		|- base
			|- base command .cpp & .h
			|- base parameter .cpp & .h
		|-a command
			|- .cpp & .h (inherit any new parameter from base parameter)
		...
	|-notification
		|-base
			|- receiver .cpp & .h
			|- sender .cpp & .h
		|- inheritent
			|- view receiver : public receiver
			|- vm receiver : public receiver