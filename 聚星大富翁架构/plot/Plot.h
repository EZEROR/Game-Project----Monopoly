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
#include<graphics.h>//��
#include <list>
#include"easyX.h"



class Player;

class Plot
{
public:
	// ע��:����Ա�����������ڲ���ʼ��,ֻ��ͨ�����캯���б��ʼ��(�ұ����ʼ��)
	//const PlotKind plot_kind_;// �ؿ�����

	int price_[3]; // ������洢��ͬ�ȼ����еؿ�ļ۸�
	int sell_price_[3]; //�����۸�
	int level_ = 0; // ����Ŀǰ�����ȼ�
	int owner_ID_ = 0;// �ؿ�ӵ����,Ĭ��Ϊ0,������֮��/0 ����//1��ɫ//2��ɫ//3��ɫ//4��ɫ
	std::string name_;//�ؿ�����
	int xywh_[4];// ����������
	std::string text_;// ���ڼ�¼ window�е��ı�//�ڵ�������ʾ������
	Button* yes_Button_ ;// ���ڱ��� window�е�ȷ�ϰ�ť
	Button* no_Button_;// ���ڱ��� window�е�ȡ����ť


	bool flag_window_ = false;
	
	Plot(int x, int y, int w, int h);// ���ݷ������������ʾͼƬ
	~Plot();
	
	virtual void Draw()=0;//���Ƹ���
	virtual void DrawWindow(Player& player)=0; //���Ƶ���

	//bool inArea(const ExMessage& msg);// �ж����Ŀǰ�Ƿ��ڸ�����
	virtual bool inWindow(const ExMessage& msg, Player& player);//�ж����Ŀǰ�Ƿ��ڵ�����

	virtual void Event(Player& player);//��������Ӵ���ʱ,����Ŀǰ������ݣ�Ȼ��

};


//���Ӹ�����
class HousePlot :
	public Plot
{
public:
	Player* owner;
	int pass_price_[3];
	HousePlot(int x, int y, int w, int h);
	//��
	HousePlot(int x, int y, int w, int h, int prices[3], int sell_prices[3], int pass_prices[3], std::string name, std::string text);
	~HousePlot();

	void Draw()override;//���Ƹ��� ��
	void DrawWindow(Player& player)override; //���Ƶ���
	void Event(Player& player)override;//��������Ӵ���ʱ
	bool inWindow(const ExMessage& msg, Player& player);
};

//����������
class PrisonPlot :public Plot
{
public:
	PrisonPlot(int x, int y, int w, int h);
	~PrisonPlot();

	bool inWindow(const ExMessage& msg, Player& player);
	void Draw()override;//���Ƹ���
	void DrawWindow(Player& player)override; //���������¼�����


};
//�����и�����
class AuctionPlot :
	public Plot
{
public:
	int sell_price_[3]; //�����۸�
	std::list<Plot*>* game_map;
	AuctionPlot(int x, int y, int w, int h, std::list<Plot*>& game_map);
	~AuctionPlot();

	void GoAuction(Player& player);//������ ��һ������������ �����ӵ�е�һ������,������������2��3���ķ��Ӽ�ֵ�Ľ�ң����֣�
	void Draw();
	bool inWindow(const ExMessage& msg, Player& player)override;
	//���Ƹ���
	void DrawWindow( Player& player);  //���������¼�����

};
//�����������
class BirthPointPlot :
	public Plot
	{
public:
	BirthPointPlot(int x, int y, int w, int h);
	~BirthPointPlot();

	void Draw()override;//���Ƹ���

	//��
	void DrawWindow(Player& player); //���������¼�����
	bool inWindow(const ExMessage& msg, Player& player)override;
	void Event(Player& player)override;//��������Ӵ���ʱ//�����¼��������ж�����//�����¸��ӵ����İ�ť�ж�����
};


//����¼�������
class RandomPlot :public Plot
{
public:
	int Random = 0;//�����������ֵ��1��Ǯ��2��Ǯ��3�������
	typedef struct RandomEvent {//�ṹ��
		std::string incidence[100];//�ַ�������//��ʾ������¼����硰������Ȼ�ֺ����۳�300Ԫ��/���ƶ�12�񡱣�
		int paid;//����/���ٸ��û��Ĳ�ͬ�����ֽ𼸣�
		int go;//�ƶ�������//��Ϊ0�����ƶ�
	}RandomIncident;

	RandomIncident ran[20] =		//�� ������20������¼�//�ṹ������
	{

	};

	RandomPlot(int x, int y, int w, int h);
	~RandomPlot();

	void Draw()override;//���Ƹ���
	void DrawWindow(Player& player)override;  //���������¼�����	
	bool inWindow(const ExMessage& msg, Player& player) override;
};

//�ɻ�����
class PlanePlot :
public Plot
{
public:
	Player* owner;
	PlanePlot(int x, int y, int w, int h );
	~PlanePlot();

	void Draw()override;//���Ƹ���
	void DrawWindow(Player& player)override; //���Ƶ���
	bool inWindow(const ExMessage& msg, Player& player)override;
};


//���ָ���
class LinerPlot :
	public Plot
{
public:
	LinerPlot(int x, int y, int w, int h);
	~LinerPlot();
	Player* owner;
	void Draw()override;//���Ƹ���
	void DrawWindow(Player& player)override;
	bool inWindow(const ExMessage& msg, Player& player);

};

//�𳵸���
class TrainPlot :
	public Plot
{
public:
	Player* owner;
	TrainPlot(int x, int y, int w, int h);
	~TrainPlot();

	void Draw()override;//���Ƹ���
	void DrawWindow(Player& player)override; //���Ƶ���
	bool inWindow(const ExMessage& msg, Player& player)override;
};

//���������
class GeneratorPlot :
	public Plot
{
public:
	Player* owner;

	GeneratorPlot(int x, int y, int w, int h);
	~GeneratorPlot();	

	void Draw()override;//���Ƹ���
	void DrawWindow(Player& player)override;
	bool inWindow(const ExMessage& msg, Player& player)override;
};

#endif
