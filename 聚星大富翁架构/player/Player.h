#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../plot/Plot.h"
#include "../Dice.h"
#include "../Globals.h"
#include <list>
#include <easyx.h>

//声明所有人物模型
enum HeroKind
{
	Kunkun = 1,
	Maobaoguo,
	Dingzhen,
	Seele,
	Elysia,
	Kevin,
	Megaman,
	Kesulu

};

class Plot;

class Player {
public:
	typename list<Plot*>::iterator current_plot_;//指向当前地块的指针
	typename list<Plot*>::iterator bir_plot_;//指向当前地块的指针
	typename list<Plot*>::iterator end_plot_;//指向当前地块的指针

	HeroKind hero_kind_;// 代表人物
	int cash_ = 1500;// 现金，具有默认值
	char name_[10];// 人物名称；
	int ID_; // 自己的ID,用来表明是哪一个玩家
	int prison_flag_ = 0; // 大于0表示不能行动
	int generator_flag_ = 0; // 大于0表示不能行动
	bool bankrupt_state_ = false;// 如果破产则1，没破产则0
	int count_;// 计算一共前进了多少格子
	int xywh_[4];// 显示角色信息的位置
	int rgb_[3];
	vector <IMAGE> img_;
	bool Bankrupt(); // 判断破产
	void UpdateWealth(int cash, Player& p);// 更新财富信息
	void UpdateWealth(int cash);
	Player();// 构造函数 
	explicit Player(const Player&);// 复制构造函数 
	Player(int* xywh, char* name, HeroKind hero_kind_, int id, typename list<Plot*>::iterator bir_plot_
		, typename list<Plot*>::iterator end_plot_, int*rgb);
	void ShowActor();// 显示人物
	void ShowInformation(); //显示角色信息
	void Move(int move_num); // 移动
	void showcolor();
};


#endif
