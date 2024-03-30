#pragma once
#include <cstdio>
#include <string>

#include <conio.h>
#include <graphics.h>
#include <iostream>

#include "../Globals.h"
#include "../Dice.h"
#include "../Button.h"
#include "../Map.h"
#include "../Tools.h"

class Interface
{
protected:
	ExMessage msg = { 0 };
public:
	virtual void Run() = 0;
	virtual void Draw() = 0;
};


// 主界面
class MainInterface :public Interface
{
private:
	Button* BeginGameBtn_ = nullptr;
	Button* ActorChooseBtn_ = nullptr;
	Button* SetGameBtn_ = nullptr;
	Button* ExitGameBtn_ = nullptr;
	Button* LoginBtn_ = nullptr;	//开始游戏，游戏设置，游戏玩法，人物介绍，退出
public:
	MainInterface();
	~MainInterface();
	void Init();
	bool inArea(ExMessage& msg);	// 判定区域
	void Draw()override; // 重新绘制
	void Run()override;

};

// 游戏界面
class GameInterface :public Interface
{
private:
	Map map_;								// 格子怎么显示

	Dice dice_;								// 骰子
	bool dice_rolled_ = false;				//避免不文明游玩(乐)
	std::vector<Player> players_;			// n个玩家, 最终采用不删除的方案

	int round_ = 0;                        //总回合数
	int turn_ = 0;						//用于记录轮到谁了


	int survive_ = 4;                    //存活人数
	IMAGE background_;
	IMAGE gbk[3];

public:
	GameInterface();
	~GameInterface();

	bool inArea(const ExMessage& msg); //我觉得这个函数意义不够明显,所以改成了下面那个
	void Draw(); // 重新绘制
	void Run();
	void RWidget();
	int isWin();// 是否胜利

};


class RoleInterface :public Interface
{
private:
	Button* SetUp_;//向上按钮
	Button* SetDown_;//向下按钮 
	Button* CloseBtn_;
	Button* Confirm_;//确定按钮
public:
	RoleInterface();
	~RoleInterface();
	IMAGE imgs[9];// 保存所有8个角色的图片
	IMAGE aimgs[9];// 保存所有角色属性图片
	bool inArea(const ExMessage& msg);
	void Draw();// 绘制
	void Run();

};

//游戏结算界面	
class GameoverInterface :public Interface
{
private:
	Button* playerbk_;
	Button* playernames_[4];
	Button* playergold_[4];
	std::vector<Player> players_;

public:
	GameoverInterface(std::vector<Player>&);
	~GameoverInterface();

	void Draw();//绘制
	void Run();
	bool inArea(const ExMessage& msg);
};


// 游戏设置界面
class GamesetInterface :public Interface
{
private:
	IMAGE img_[3];

public:
	GamesetInterface();
	~GamesetInterface();

	//void Volume();// 音量控制
	static void BGM();//播放背景音乐以及开关‘

	bool inArea(const ExMessage& msg);
	void Draw();// 绘制
	void Run();

};