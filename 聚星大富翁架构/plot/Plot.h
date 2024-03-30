#ifndef _PLOT_H_
#define _PLOT_H_

#include <graphics.h>
#include <string>
#include<vector>
#include <random>
#include<iostream>
using namespace std;

#include "../Button.h"
#include "../player/Player.h"
#include<graphics.h>//改
#include <list>
#include"easyX.h"



class Player;

class Plot
{
public:
	// 注意:常成员变量不能在内部初始化,只能通过构造函数列表初始化(且必须初始化)
	//const PlotKind plot_kind_;// 地块种类

	int price_[3]; // 数组里存储不同等级城市地块的价格
	int sell_price_[3]; //售卖价格
	int level_ = 0; // 城市目前所处等级
	int owner_ID_ = 0;// 地块拥有者,默认为0,即无主之地/0 无人//1红色//2黄色//3青色//4蓝色
	std::string name_;//地块名字
	int xywh_[4];// 方形类坐标
	std::string text_;// 用于记录 window中的文本//在弹窗中显示的文字
	Button* yes_Button_ ;// 用于保存 window中的确认按钮
	Button* no_Button_;// 用于保存 window中的取消按钮


	bool flag_window_ = false;
	
	Plot(int x, int y, int w, int h);// 根据方形类的坐标显示图片
	~Plot();
	
	virtual void Draw()=0;//绘制格子
	virtual void DrawWindow(Player& player)=0; //绘制弹窗

	//bool inArea(const ExMessage& msg);// 判定鼠标目前是否在格子上
	virtual bool inWindow(const ExMessage& msg, Player& player);//判定鼠标目前是否在弹窗上

	virtual void Event(Player& player);//当特殊格子触发时,接受目前鼠标数据，然后

};


//房子格子类
class HousePlot :
	public Plot
{
public:
	Player* owner;
	int pass_price_[3];
	HousePlot(int x, int y, int w, int h);
	//改
	HousePlot(int x, int y, int w, int h, int prices[3], int sell_prices[3], int pass_prices[3], std::string name, std::string text);
	~HousePlot();

	void Draw()override;//绘制格子 改
	void DrawWindow(Player& player)override; //绘制弹窗
	void Event(Player& player)override;//当特殊格子触发时
	bool inWindow(const ExMessage& msg, Player& player);
};

//监狱格子类
class PrisonPlot :public Plot
{
public:
	PrisonPlot(int x, int y, int w, int h);
	~PrisonPlot();

	bool inWindow(const ExMessage& msg, Player& player);
	void Draw()override;//绘制格子
	void DrawWindow(Player& player)override; //绘制特殊事件弹窗


};
//拍卖行格子类
class AuctionPlot :
	public Plot
{
public:
	int sell_price_[3]; //售卖价格
	std::list<Plot*>* game_map;
	AuctionPlot(int x, int y, int w, int h, std::list<Plot*>& game_map);
	~AuctionPlot();

	void GoAuction(Player& player);//链表中 第一个被搜索到的 该玩家拥有的一座城市,卖掉后随机获得2、3倍的房子价值的金币（文字）
	void Draw();
	bool inWindow(const ExMessage& msg, Player& player)override;
	//绘制格子
	void DrawWindow( Player& player);  //绘制特殊事件弹窗

};
//出生点格子类
class BirthPointPlot :
	public Plot
	{
public:
	BirthPointPlot(int x, int y, int w, int h);
	~BirthPointPlot();

	void Draw()override;//绘制格子

	//改
	void DrawWindow(Player& player); //绘制特殊事件弹窗
	bool inWindow(const ExMessage& msg, Player& player)override;
	void Event(Player& player)override;//当特殊格子触发时//特殊事件弹窗的判断区域//即更新格子弹窗的按钮判断区域
};


//随机事件格子类
class RandomPlot :public Plot
{
public:
	int Random = 0;//随机出来的数值：1加钱，2扣钱，3随机传送
	typedef struct RandomEvent {//结构体
		std::string incidence[100];//字符串数组//表示随机的事件（如“遇上自然灾害，扣除300元”/“移动12格”）
		int paid;//增加/减少该用户的不同数量现金几￥
		int go;//移动格子数//可为0，不移动
	}RandomIncident;

	RandomIncident ran[20] =		//如 这里是20个随机事件//结构体数组
	{

	};

	RandomPlot(int x, int y, int w, int h);
	~RandomPlot();

	void Draw()override;//绘制格子
	void DrawWindow(Player& player)override;  //绘制特殊事件弹窗	
	bool inWindow(const ExMessage& msg, Player& player) override;
};

//飞机格子
class PlanePlot :
public Plot
{
public:
	Player* owner;
	PlanePlot(int x, int y, int w, int h );
	~PlanePlot();

	void Draw()override;//绘制格子
	void DrawWindow(Player& player)override; //绘制弹窗
	bool inWindow(const ExMessage& msg, Player& player)override;
};


//邮轮格子
class LinerPlot :
	public Plot
{
public:
	LinerPlot(int x, int y, int w, int h);
	~LinerPlot();
	Player* owner;
	void Draw()override;//绘制格子
	void DrawWindow(Player& player)override;
	bool inWindow(const ExMessage& msg, Player& player);

};

//火车格子
class TrainPlot :
	public Plot
{
public:
	Player* owner;
	TrainPlot(int x, int y, int w, int h);
	~TrainPlot();

	void Draw()override;//绘制格子
	void DrawWindow(Player& player)override; //绘制弹窗
	bool inWindow(const ExMessage& msg, Player& player)override;
};

//发电机格子
class GeneratorPlot :
	public Plot
{
public:
	Player* owner;

	GeneratorPlot(int x, int y, int w, int h);
	~GeneratorPlot();	

	void Draw()override;//绘制格子
	void DrawWindow(Player& player)override;
	bool inWindow(const ExMessage& msg, Player& player)override;
};

#endif
