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
    //����ģ��
    loadimage(&(this->img_[1]), "asserts/����.png ", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[2]), "asserts/����ʦ.png ", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[3]), "asserts/����ѡ��һ.png", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[4]), "asserts/Seele.png ", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[5]), "asserts/Elysia.png", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[6]), "asserts/Kevin.png", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[7]), "asserts/Megaman.png", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[8]), "asserts/Kesulu.png", 47, 52);// ��ʾͼƬ

}

/*
    ���ܣ��������ʾ��ҵĽ�ɫ���ƣ��Ƹ�ֵ���ڹ̶���λ�ã�,�������ʾ�����ͼ����ʼλ�ã�����ö��������ж�չʾ��ͼ����������ҵ�ID
    ������int xywh[4], int cash, std::string name_���ֱ��ʾ��ʾ��λ�ã��Ƹ�������ɫ����
          int x, int y, HeroKind hero_kind_,int id���ֱ��ʾ��ɫ��ͼ��λ�ã���ɫ�����õ�ID
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


    //����ģ��
    loadimage(&(this->img_[1]), "asserts/����.png ", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[2]), "asserts/����ʦ.png ", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[3]), "asserts/����ѡ��һ.png", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[4]), "asserts/Seele.png ", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[5]), "asserts/Elysia.png", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[6]), "asserts/Kevin.png", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[7]), "asserts/Megaman.png", 47, 52);// ��ʾͼƬ
    loadimage(&(this->img_[8]), "asserts/Kesulu.png", 47, 52);// ��ʾͼƬ
}

//�Լ���Ǯ
void Player::UpdateWealth(int cash, Player& p)
{
    if (p.prison_flag_ > 0)
    {
        return;
    }
    this->cash_ += cash;
    p.cash_ -= cash;
}

//�Լ���Ǯ
void Player::UpdateWealth(int cash)
{
    this->cash_ += cash;// �Լ���Ǯ
}


/*
    ������: ����
    ���� :��ʾ�������ģ��,����ÿ�����ڵĵؿ���ʾ
    ���� :NULL
    ����ֵ:NULL
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
    settextstyle(24, 8, "΢���ź�");
    setfillcolor(RGB(rgb_[0], rgb_[1], rgb_[2]));
    fillrectangle(xywh_[0] + 50, xywh_[1] + 10, xywh_[0] + 100, xywh_[1] + 20);
    settextcolor(RGB(233, 223, 157));
    setbkmode(TRANSPARENT);
    outtextxy(xywh_[0] + 60, xywh_[1] + 25, name_);
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%d", this->cash_);
    outtextxy(xywh_[0] + 88, xywh_[1] + xywh_[3] / 2 + 35, buffer);

}

//������: ALIENS
//���� ://
//�ú�����Ҫ���ж���ҵĲƸ�ֵ
/*
        ˵���Ҷ��Ʋ���ʧ�ܵ����:
        �����ҵ��ʲ����ڸ����ֽ�ľ���ֵ, ��������Ʋ�
        һ���Ʋ���������ʧ��

        �߼�����

        if(wealth<0)
        {
            bankrupt_state_ = true;

        ȫ�ֱ���Survive-=1��ʾһ�����ʧ�ܳ���, Ϊ�Ƿ�������̵�
            Survive-=1;
            return false;
        }

        //���û���Ʋ�, Ҳ��û��ʧ��
        return true;
*/
//���� :NULL
//����ֵ:BOOL
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
������: ����
���� :�������ӵĵ�������current_plot_����++��������countÿ�ν����ۼӼ����ܹ�ǰ���˶��٣����ܿ������бȽϣ������ƶ�֮ǰ
      �ж��Ƿ��ڼ��������stop_flag_����0����1֮�����move��������������updateInfor�������ݣ��������ڵĸ�����ʾ�������ShowActor(int x,int y)
      ��ShowInformation()

 �ο������߼�:()
     /oid Move()//�ƶ�
    {
        int move_num = RollDice(); //����ͨ�����������1-6֮���ֵ;
        for (int i = 0; i < move_num; i++) //ע��list�ײ�Ϊ����,��֧���±�ֱ�Ӽ�����
        {
            current_plot_++;
        }
        current_plot_->function();
    }


���� :NULL
����ֵ:NULL
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