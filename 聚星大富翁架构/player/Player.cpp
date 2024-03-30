#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../Tools.h"
#include "../Globals.h"

int rnbk = 5;

Player::Player()
{
}
Player::Player(const Player& player):
    cash_(player.cash_), 
    ID_(player.ID_), 
    hero_kind_(player.hero_kind_), 
    current_plot_(player.current_plot_),
    bir_plot_(player.bir_plot_),
    end_plot_(player.end_plot_)
{
    for (int i = 0; i < 4; i++)
    {
        xywh_[i] = player.xywh_[i];
    }
    for (int i = 0; i < 3; i++)
    {
        rgb_[i] = player.rgb_[i];
    }

    strcpy_s(name_, player.name_);
    this->img_.resize(10);
    //人物模型
    loadimage(&(this->img_[1]), "asserts/坤坤.png ", 47, 52);// 显示图片
    loadimage(&(this->img_[2]), "asserts/马老师.png ", 47, 52);// 显示图片
    loadimage(&(this->img_[3]), "asserts/丁真选择一.png", 47, 52);// 显示图片
    loadimage(&(this->img_[4]), "asserts/Seele.png ", 47, 52);// 显示图片
    loadimage(&(this->img_[5]), "asserts/Elysia.png", 47, 52);// 显示图片
    loadimage(&(this->img_[6]), "asserts/Kevin.png", 47, 52);// 显示图片
    loadimage(&(this->img_[7]), "asserts/Megaman.png", 47, 52);// 显示图片
    loadimage(&(this->img_[8]), "asserts/Kesulu.png", 47, 52);// 显示图片

}

/*
    功能：在最初显示玩家的角色名称，财富值（在固定的位置）,在最初显示玩家贴图的起始位置，根据枚举类进行判断展示贴图，并设置玩家的ID
    参数：int xywh[4], int cash, std::string name_，分别表示显示的位置，财富数，角色名称
          int x, int y, HeroKind hero_kind_,int id，分别表示角色贴图的位置，角色，设置的ID
*/
Player::Player(int* xywh, char* name, HeroKind hero_kind_, int id, typename list<Plot*>::iterator bir_plot_
    , typename list<Plot*>::iterator end_plot_, int*rgb)
{
    this->xywh_[0] = xywh[0];
    this->xywh_[1] = xywh[1];
    this->xywh_[2] = xywh[2];
    this->xywh_[3] = xywh[3];

    this->ID_ = id;
    this->hero_kind_ = hero_kind_;
    strcpy_s(this->name_, name);
    this->current_plot_ = bir_plot_;
    this->bir_plot_ = bir_plot_;
    this->end_plot_ = end_plot_;
    this->img_.resize(10);
    this->rgb_[0] = rgb[0];
    this->rgb_[1] = rgb[1];
    this->rgb_[2] = rgb[2];


    //人物模型
    loadimage(&(this->img_[1]), "asserts/坤坤.png ", 47, 52);// 显示图片
    loadimage(&(this->img_[2]), "asserts/马老师.png ", 47, 52);// 显示图片
    loadimage(&(this->img_[3]), "asserts/丁真选择一.png", 47, 52);// 显示图片
    loadimage(&(this->img_[4]), "asserts/Seele.png ", 47, 52);// 显示图片
    loadimage(&(this->img_[5]), "asserts/Elysia.png", 47, 52);// 显示图片
    loadimage(&(this->img_[6]), "asserts/Kevin.png", 47, 52);// 显示图片
    loadimage(&(this->img_[7]), "asserts/Megaman.png", 47, 52);// 显示图片
    loadimage(&(this->img_[8]), "asserts/Kesulu.png", 47, 52);// 显示图片
}

//自己加钱
void Player::UpdateWealth(int cash, Player& p)
{
    if (p.prison_flag_ > 0)
    {
        return;
    }
    this->cash_ += cash;
    p.cash_ -= cash;
}

//自己加钱
void Player::UpdateWealth(int cash)
{
    this->cash_ += cash;// 自己扣钱
}


/*
    负责人: 张三
    功能 :显示玩家人物模型,根据每次所在的地块显示
    参数 :NULL
    返回值:NULL
*/
void Player::ShowActor()
{
    switch (hero_kind_)
    {
    case Kunkun:

        putimagePNG((*this->current_plot_)->xywh_[0], (*this->current_plot_)->xywh_[1], &img_[1]);
        break;
    case Maobaoguo:

        putimagePNG((*this->current_plot_)->xywh_[0], (*this->current_plot_)->xywh_[1], &img_[2]);
        break;
    case  Dingzhen:

        putimagePNG((*this->current_plot_)->xywh_[0], (*this->current_plot_)->xywh_[1], &img_[3]);
        break;
    case Seele:

        putimagePNG((*this->current_plot_)->xywh_[0], (*this->current_plot_)->xywh_[1], &img_[4]);
        break;
    case Elysia:

        putimagePNG((*this->current_plot_)->xywh_[0], (*this->current_plot_)->xywh_[1], &img_[5]);
        break;
    case Kevin:

        putimagePNG((*this->current_plot_)->xywh_[0], (*this->current_plot_)->xywh_[1], &img_[6]);
        break;
    case Megaman:

        putimagePNG((*this->current_plot_)->xywh_[0], (*this->current_plot_)->xywh_[1], &img_[7]);
        break;
    case Kesulu:

        putimagePNG((*this->current_plot_)->xywh_[0], (*this->current_plot_)->xywh_[1], &img_[8]);
        break;
    }
}


void Player::ShowInformation()
{
    settextstyle(24, 8, "微软雅黑");
    setfillcolor(RGB(rgb_[0], rgb_[1], rgb_[2]));
    fillrectangle(xywh_[0] + 50, xywh_[1] + 10, xywh_[0] + 100, xywh_[1] + 20);
    settextcolor(RGB(233, 223, 157));
    setbkmode(TRANSPARENT);
    outtextxy(xywh_[0] + 60, xywh_[1] + 25, name_);
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%d", this->cash_);
    outtextxy(xywh_[0] + 88, xywh_[1] + xywh_[3] / 2 + 35, buffer);

}

//负责人: ALIENS
//功能 ://
//该函数主要会判断玩家的财富值
/*
        说明我对破产和失败的理解:
        如果玩家的资产大于负数现金的绝对值, 代表玩家破产
        一旦破产则代表玩家失败

        逻辑如下

        if(wealth<0)
        {
            bankrupt_state_ = true;

        全局变量Survive-=1表示一名玩家失败出局, 为是否结算做铺垫
            Survive-=1;
            return false;
        }

        //玩家没有破产, 也就没有失败
        return true;
*/
//参数 :NULL
//返回值:BOOL
bool Player::Bankrupt()
{
    if (cash_ <= 0)
    {
        bankrupt_state_ = true;
        for (auto it = bir_plot_; it != end_plot_; it++)
        {
            if ((*it)->owner_ID_ == ID_)
            {
                (*it)->owner_ID_ = 0;
                (*it)->level_ = 0;
            }
        }
        return true;
    }
    return false;
}

/*
负责人: 张三
功能 :根据骰子的点数，将current_plot_进行++操作，将count每次进行累加计算总共前进了多少（和总块数进行比较），在移动之前
      判断是否在监狱，如果stop_flag_大于0，减1之后结束move函数，到最后调用updateInfor更新数据，根据所在的格子显示人物，调用ShowActor(int x,int y)
      与ShowInformation()

 参考代码逻辑:()
     /oid Move()//移动
    {
        int move_num = RollDice(); //此普通函数随机返回1-6之间的值;
        for (int i = 0; i < move_num; i++) //注意list底层为链表,不支持下标直接加数字
        {
            current_plot_++;
        }
        current_plot_->function();
    }


参数 :NULL
返回值:NULL
*/
void Player::Move(int move_num)
{
    if (bankrupt_state_)
    {
        return;
    }
    if (this->prison_flag_ > 0)
    {
        cout << "In Prison:" << prison_flag_ << endl;
        this->prison_flag_--;
        return;
    }
    if (this->generator_flag_ > 0)
    {
        cout << "In generator:" << generator_flag_ << endl;
        this->generator_flag_--;
        return;
    }
    this->count_ += move_num;
    if (count_ > 20)
    {
        count_ -= 20;
        this->cash_ += 200;
    }
    for (int i = 0; i < move_num; i++)
    {
        current_plot_++;
        if (current_plot_ == end_plot_) {
            current_plot_ = bir_plot_;
        }
        //EndBatchDraw();
        this->ShowActor();
        FlushBatchDraw();
        //BeginBatchDraw();
        Sleep(200);
    }
}


void Player::showcolor()
{
    setfillcolor(RGB(rgb_[0], rgb_[1], rgb_[2]));
    fillrectangle(20, 100, 80, 80);
}