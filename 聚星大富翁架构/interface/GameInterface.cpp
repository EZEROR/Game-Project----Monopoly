#include "Interface.h"
#include "../player/Player.h" 
#include "../Globals.h"
#include <easyx.h>
#include "../Tools.h"

//IMAGE gbk[3];

GameInterface::GameInterface()
{


    //���ر���
    loadimage(&background_, "./images/b1.jpg", 800, 450);

    loadimage(&gbk[0], "./Images/b1.jpg", 800, 450);
    loadimage(&gbk[1], "./Images/b2.jpg", 800, 450);
    loadimage(&gbk[2], "./Images/f.png", 800, 450);



    //��ҳ�ʼ��
    int xywh[3][4] = { {100, 0, 60, 40}, { 500, 0, 60, 40 }, {100,330, 60, 40}, };
    int myxywh[4] = { 500,330, 60, 40 };
    int rgb[3][3] = { {252,62,54},{204,168,78},{71,134,200} };
    int myrgb[3] = { 62,149,64 };
    char name[3][10] = { "Kunkun", "Seele", "Kesulu" };
    HeroKind heros[4] = { Kunkun, Seele, Kesulu };

    //Player1 ��ѡ��ɫ ,player2,3,4 Ĭ��
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



//������: ALIENS
//���� :�ж���Ϸ�Ƿ�ʤ��:
// 1.��һ�����⣬������Ҷ��Ʋ�
// 2.�غ����ﵽ20�Ժ���ߵĲƸ�ӵ����ֱ�ӻ�ʤ��
//ʵ���߼�:
/*
        (ͨ��int Survive=4���ж��Ƿ���ʤ��,ÿ������Ʋ���Survive - 1)ע��

        (ÿ����һ�غ϶��ж�ÿ����ҵ�ӵ�вƲ����������ҵ�bankrupt_state_=1���򲻻����ظ��жϡ��������1�Ʋ�,��֮��ĲƸ��ж�ֻ�������2��3��4��ֱ�Ӻ������1��)

        (�غ����� int round_��¼;)
        ��round_==80ʱ������������ҵĲƸ�ֵ��ȡ������һ�ʤ��


���� :NULL
����ֵ:0Ϊû����Ӯ,��������Ϊ��ʤ��ID
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

// ���¸����ж�����
/*
    ����¼�
        �������еؿ��࣬���뵱ǰ�����λ����Ϣ ���ڰ�����Ӧ�ؿ��ж��Ƿ񱻴��������� �ؿ�� Event ���������� msg��

*/
bool  GameInterface::inArea(const ExMessage& msg)
{
    //����,���ǿյ���

    //���û������, ��ִֻ�е��Ƿ�����ӵ��ж�, �����������, ��ִֻ���¼�ȷ�ϵ��ж�
    if (!dice_rolled_ && dice_.inArea(msg))
    {
        cout << "Judge succeed!" << endl;
        //���ӻ�ȡ�����
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

    //�����¼�ʱ��ȷ���ж�
    else if(dice_rolled_ && map_.inArea(msg, players_[turn_]))
    {
        cout << "Confirmed!" << endl;
        if (players_[turn_].Bankrupt())
        {
            survive_--;
        }

        //���ӻغ���
        round_++;
        cout << "�غ���: " << round_ << endl;
        turn_ = (++turn_) % 4;

        dice_rolled_ = false;
        return true;
    }

    //BeginBatchDraw();

    return false;
}


//������: 
//���� :������ϷԪ��
//      1.��Ϸ���汳��
//      2.�ĸ�ͷ���
//      3.�ĸ��Ƹ�ֵ
//      4.���ƽ�ɫ���߿�
//        5.�������еؿ��࣬����ʹ�����е� drow() �������ؿ�
//        6.�ĸ��������ϵĽ�ɫ������player�ڵĺ�����
//        7.����
//     
//���� :NULL
//����ֵ:NULL

/*

*/
void GameInterface::Draw()
{
    /*putimage(0, 0, &background_);*/
    putimage(0, 0, &gbk[nbk]);
    /*
        ���� map��player��dice �� Draw ������Ӧ�Ķ���
    */

    //����ͼ����
    map_.Draw();

    dice_.Draw();


      //���ƴ����¼�ʱ��ȷ�Ͽ�
    if (dice_rolled_)
    {
        cout << "EVENT window drawn." << endl;
        (*players_[turn_].current_plot_)->DrawWindow(players_[turn_]);
    }

    //��ʾĿǰ�ֵ������
    settextcolor(RGB(233, 223, 157));
    setbkmode(TRANSPARENT);
    settextstyle(15, 0, _T("����"));
    outtextxy(10, 20, "Next Player:");

     settextstyle(20, 0, _T("����"));
     outtextxy(15, 40, players_[turn_].name_);



  

    
    //���ƽ�ɫ��Ϣ�򵯴�
    RWidget();
    


    for (auto& player : players_)
    {
        //���ֻչʾ���Ľ�ɫ
        if (!player.bankrupt_state_)
        {
            player.ShowActor();// չʾ��ɫ
        }

        player.ShowInformation();// չʾ��ɫ��Ϣ
    }



    players_[turn_].showcolor();

    //FlushBatchDraw();

}

void GameInterface::Run()
{

    //��Ϸ������ѭ��
    Draw();
    BeginBatchDraw();

    while (true)
    {
        FlushBatchDraw();

        //��ȡ������Ϣ
        msg = getmessage();

        //�ж�����Ƿ�������ӻ���
        if (inArea(msg))
        {
            Draw();
        }

        
        if (isWin())
        {
            //��Ϸ�������
            GameoverInterface game_over_interface(players_);
            //GameoverInterface game_over_interface;
            //������Ҫ����ȥ�Ĳ�����:�����, ��ҲƸ�
            game_over_interface.Run();
            return;
        }


        FlushBatchDraw();

    }

    EndBatchDraw();
}


void GameInterface::RWidget()
{

    int r_xy[4][4] = { {100, 0}, {500, 0}, {100, 330}, {500, 330} };//��ɫ��+�Ƹ�������

    IMAGE avatar[9];//��ɫͷ��


    loadimage(&avatar[1], "Role/Kunkun.png ", 47, 52);// ��ʾͼƬ
    loadimage(&avatar[2], "Role/Maobaoguo.png ", 47, 52);// ��ʾͼƬ
    loadimage(&avatar[3], "Role/Dingzhen.png", 47, 52);// ��ʾͼƬ
    loadimage(&avatar[4], "Role/Seele.png ", 47, 52);// ��ʾͼƬ
    loadimage(&avatar[5], "Role/Elysia.png", 47, 52);// ��ʾͼƬ
    loadimage(&avatar[6], "Role/game/Kevin.png", 47, 52);// ��ʾͼƬ
    loadimage(&avatar[7], "Role/Megaman.png", 47, 52);// ��ʾͼƬ
    loadimage(&avatar[8], "Role/Kesulu.png", 47, 52);// ��ʾͼƬ

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
    loadimage(&Money, "Images/money.png", 100, 30);// ��ʾ�Ƹ���ͼƬ
    for (int i = 0; i < 4; i++)
    {
        putimagePNG(r_xy[i][0] + 50, r_xy[i][1] + 50, &Money);
    }

    
}