#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../plot/Plot.h"
#include "../Dice.h"
#include "../Globals.h"
#include <list>
#include <easyx.h>

//������������ģ��
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
	typename list<Plot*>::iterator current_plot_;//ָ��ǰ�ؿ��ָ��
	typename list<Plot*>::iterator bir_plot_;//ָ��ǰ�ؿ��ָ��
	typename list<Plot*>::iterator end_plot_;//ָ��ǰ�ؿ��ָ��

	HeroKind hero_kind_;// ��������
	int cash_ = 1500;// �ֽ𣬾���Ĭ��ֵ
	char name_[10];// �������ƣ�
	int ID_; // �Լ���ID,������������һ�����
	int prison_flag_ = 0; // ����0��ʾ�����ж�
	int generator_flag_ = 0; // ����0��ʾ�����ж�
	bool bankrupt_state_ = false;// ����Ʋ���1��û�Ʋ���0
	int count_;// ����һ��ǰ���˶��ٸ���
	int xywh_[4];// ��ʾ��ɫ��Ϣ��λ��
	int rgb_[3];
	vector <IMAGE> img_;
	bool Bankrupt(); // �ж��Ʋ�
	void UpdateWealth(int cash, Player& p);// ���²Ƹ���Ϣ
	void UpdateWealth(int cash);
	Player();// ���캯�� 
	explicit Player(const Player&);// ���ƹ��캯�� 
	Player(int* xywh, char* name, HeroKind hero_kind_, int id, typename list<Plot*>::iterator bir_plot_
		, typename list<Plot*>::iterator end_plot_, int*rgb);
	void ShowActor();// ��ʾ����
	void ShowInformation(); //��ʾ��ɫ��Ϣ
	void Move(int move_num); // �ƶ�
	void showcolor();
};


#endif
