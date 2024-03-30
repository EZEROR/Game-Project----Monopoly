#include "Interface.h"
#include "../player/Player.h" 
#include "../Globals.h"
#include <easyx.h>
#include "../Tools.h"

//IMAGE gbk[3];

GameInterface::GameInterface()
{


    //加载背景
    loadimage(&background_, "./images/b1.jpg", 800, 450);

    loadimage(&gbk[0], "./Images/b1.jpg", 800, 450);
    loadimage(&gbk[1], "./Images/b2.jpg", 800, 450);
    loadimage(&gbk[2], "./Images/f.png", 800, 450);



    //玩家初始化
    int xywh[3][4] = { {100, 0, 60, 40}, { 500, 0, 60, 40 }, {100,330, 60, 40}, };
    int myxywh[4] = { 500,330, 60, 40 };
    int rgb[3][3] = { {252,62,54},{204,168,78},{71,134,200} };
    int myrgb[3] = { 62,149,64 };
    char name[3][10] = { "Kunkun", "Seele", "Kesulu" };
    HeroKind heros[4] = { Kunkun, Seele, Kesulu };

    //Player1 自选角色 ,player2,3,4 默认
    for (int i = 0; i < 3; i++)
    {
        Player player(xywh[i], name[i], heros[i], i + 1, map_.game_map_.begin(), map_.game_map_.end(), rgb[i]);
        players_.push_back(player);
    }

    if (rnbk == 1)
    {
        char myname[10] = "Kunkun";
        HeroKind h = Kunkun;
        Player player(myxywh, myname, h, 4, map_.game_map_.begin(), map_.game_map_.end(), myrgb);
        players_.push_back(player);
    }
    else if (rnbk == 2)
    {
        char myname[10] = "Maobaoguo";
        HeroKind h = Maobaoguo;
        Player player(myxywh, myname, h, 4, map_.game_map_.begin(), map_.game_map_.end(), myrgb);
        players_.push_back(player);
    }
    else if (rnbk == 3)
    {
        char myname[10] = "Dingzhen";
        HeroKind h = Dingzhen;
        Player player(myxywh, myname, h, 4, map_.game_map_.begin(), map_.game_map_.end(), myrgb);
        players_.push_back(player);
    }
    else if (rnbk == 4)
    {
        char myname[10] = "Seele";
        HeroKind h = Seele;
        Player player(myxywh, myname, h, 4, map_.game_map_.begin(), map_.game_map_.end(), myrgb);
        players_.push_back(player);
    }
    else if (rnbk == 5)
    {
        char myname[10] = "Elysia";
        HeroKind h = Elysia;
        Player player(myxywh, myname, h, 4, map_.game_map_.begin(), map_.game_map_.end(), myrgb);
        players_.push_back(player);
    }
    else if (rnbk == 6)
    {
        char myname[10] = "Kevin";
        HeroKind h = Kevin;
        Player player(myxywh, myname, h, 4, map_.game_map_.begin(), map_.game_map_.end(), myrgb);
        players_.push_back(player);
    }
    else if (rnbk == 7)
    {
        char myname[10] = "Megaman";
        HeroKind h = Megaman;
        Player player(myxywh, myname, h, 4, map_.game_map_.begin(), map_.game_map_.end(), myrgb);
        players_.push_back(player);
    }
    else if (rnbk == 8)
    {
        char myname[10] = "Kesulu";
        HeroKind h = Kesulu;
        Player player(myxywh, myname, h, 4, map_.game_map_.begin(), map_.game_map_.end(), myrgb);
        players_.push_back(player);
    }
}

GameInterface::~GameInterface()
{
}



//负责人: ALIENS
//功能 :判断游戏是否胜利:
// 1.除一人以外，所有玩家都破产
// 2.回合数达到20以后，最高的财富拥有者直接获胜。
//实现逻辑:
/*
        (通过int Survive=4来判断是否能胜利,每当玩家破产则Survive - 1)注解

        (每进行一回合都判断每个玩家的拥有财产，如果该玩家的bankrupt_state_=1，则不会再重复判断。例如玩家1破产,则之后的财富判断只会兼顾玩家2，3，4，直接忽略玩家1，)

        (回合数用 int round_记录;)
        当round_==80时，遍历所有玩家的财富值，取最大的玩家获胜。


参数 :NULL
返回值:0为没有人赢,其它数字为获胜者ID
*/

int GameInterface::isWin()
{

    if (survive_ == 1)
    {
        for (auto& player : players_)
        {
            if (!player.bankrupt_state_)
            {
                return player.ID_;
            }
        }
    }

    if (round_ == 90)
    {
        Player* winner = nullptr;
        int max_wealth = 0;
        for (auto& player : players_)
        {
            if (player.cash_ > max_wealth)
            {
                winner = &player;
            }
        }
        return winner->ID_;
    }

    return 0;
}

// 重新更新判定区域
/*
    点击事件
        遍历所有地块类，传入当前的鼠标位置信息 用于帮助对应地块判断是否被触发（调用 地块的 Event 函数，传入 msg）

*/
bool  GameInterface::inArea(const ExMessage& msg)
{
    //诶嘿,不是空的了

    //如果没点骰子, 就只执行点是否点骰子的判定, 如果点了骰子, 就只执行事件确认的判定
    if (!dice_rolled_ && dice_.inArea(msg))
    {
        cout << "Judge succeed!" << endl;
        //骰子获取随机数
        int move_num = dice_.Random();

        dice_.Draw();

        int i = turn_;
        for (; i < 4; i++)
        {
            if (!players_[i].bankrupt_state_)
            {
                players_[turn_].Move(move_num);
                turn_ = i % 4;
                break;
            }    
        }

        
        dice_rolled_ = true;
        return true;
    }

    //触发事件时的确认判断
    else if(dice_rolled_ && map_.inArea(msg, players_[turn_]))
    {
        cout << "Confirmed!" << endl;
        if (players_[turn_].Bankrupt())
        {
            survive_--;
        }

        //增加回合数
        round_++;
        cout << "回合数: " << round_ << endl;
        turn_ = (++turn_) % 4;

        dice_rolled_ = false;
        return true;
    }

    //BeginBatchDraw();

    return false;
}


//负责人: 
//功能 :绘制游戏元素
//      1.游戏界面背景
//      2.四个头像框
//      3.四个财富值
//      4.绘制角色名边框
//        5.遍历所有地块类，并且使用其中的 drow() 来画出地块
//        6.四个在棋盘上的角色（调用player内的函数）
//        7.骰子
//     
//参数 :NULL
//返回值:NULL

/*

*/
void GameInterface::Draw()
{
    /*putimage(0, 0, &background_);*/
    putimage(0, 0, &gbk[nbk]);
    /*
        调用 map，player，dice 的 Draw 画出对应的东西
    */

    //画地图格子
    map_.Draw();

    dice_.Draw();


      //绘制触发事件时的确认框
    if (dice_rolled_)
    {
        cout << "EVENT window drawn." << endl;
        (*players_[turn_].current_plot_)->DrawWindow(players_[turn_]);
    }

    //显示目前轮到的玩家
    settextcolor(RGB(233, 223, 157));
    setbkmode(TRANSPARENT);
    settextstyle(15, 0, _T("宋体"));
    outtextxy(10, 20, "Next Player:");

     settextstyle(20, 0, _T("宋体"));
     outtextxy(15, 40, players_[turn_].name_);



  

    
    //绘制角色信息框弹窗
    RWidget();
    


    for (auto& player : players_)
    {
        //如果只展示存活的角色
        if (!player.bankrupt_state_)
        {
            player.ShowActor();// 展示角色
        }

        player.ShowInformation();// 展示角色信息
    }



    players_[turn_].showcolor();

    //FlushBatchDraw();

}

void GameInterface::Run()
{

    //游戏界面主循环
    Draw();
    BeginBatchDraw();

    while (true)
    {
        FlushBatchDraw();

        //获取键鼠信息
        msg = getmessage();

        //判定鼠标是否操作骰子或事
        if (inArea(msg))
        {
            Draw();
        }

        
        if (isWin())
        {
            //游戏结算界面
            GameoverInterface game_over_interface(players_);
            //GameoverInterface game_over_interface;
            //可能需要传进去的参数有:玩家名, 玩家财富
            game_over_interface.Run();
            return;
        }


        FlushBatchDraw();

    }

    EndBatchDraw();
}


void GameInterface::RWidget()
{

    int r_xy[4][4] = { {100, 0}, {500, 0}, {100, 330}, {500, 330} };//角色狂+财富框坐标

    IMAGE avatar[9];//角色头像


    loadimage(&avatar[1], "Role/Kunkun.png ", 47, 52);// 显示图片
    loadimage(&avatar[2], "Role/Maobaoguo.png ", 47, 52);// 显示图片
    loadimage(&avatar[3], "Role/Dingzhen.png", 47, 52);// 显示图片
    loadimage(&avatar[4], "Role/Seele.png ", 47, 52);// 显示图片
    loadimage(&avatar[5], "Role/Elysia.png", 47, 52);// 显示图片
    loadimage(&avatar[6], "Role/game/Kevin.png", 47, 52);// 显示图片
    loadimage(&avatar[7], "Role/Megaman.png", 47, 52);// 显示图片
    loadimage(&avatar[8], "Role/Kesulu.png", 47, 52);// 显示图片

    for (int i = 0; i < 4; i++)
    {
        if (i == 3)
        {
            putimagePNG(r_xy[i][0] + 5, r_xy[i][1] + 10, &avatar[rnbk]);
        }
        else if (i == 0)
        {
            putimagePNG(r_xy[i][0] + 5, r_xy[i][1] + 10, &avatar[1]);

        }
        else if (i == 1)
        {
            putimagePNG(r_xy[i][0] + 5, r_xy[i][1] + 10, &avatar[4]);
        }

        else if (i == 2)
        {
            putimagePNG(r_xy[i][0] + 5, r_xy[i][1] + 10, &avatar[8]);
        }


    }



    IMAGE Rwidget;
    loadimage(&Rwidget, "Images/Gameinterface/Rolew2.png");

    for (int i = 0; i < 4; i++)
    {
        putimagePNG(r_xy[i][0], r_xy[i][1], &Rwidget);
    }

    IMAGE Money;
    loadimage(&Money, "Images/money.png", 100, 30);// 显示财富框图片
    for (int i = 0; i < 4; i++)
    {
        putimagePNG(r_xy[i][0] + 50, r_xy[i][1] + 50, &Money);
    }

    
}