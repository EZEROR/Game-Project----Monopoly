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


// ������
class MainInterface :public Interface
{
private:
	Button* BeginGameBtn_ = nullptr;
	Button* ActorChooseBtn_ = nullptr;
	Button* SetGameBtn_ = nullptr;
	Button* ExitGameBtn_ = nullptr;
	Button* LoginBtn_ = nullptr;	//��ʼ��Ϸ����Ϸ���ã���Ϸ�淨��������ܣ��˳�
public:
	MainInterface();
	~MainInterface();
	void Init();
	bool inArea(ExMessage& msg);	// �ж�����
	void Draw()override; // ���»���
	void Run()override;

};

// ��Ϸ����
class GameInterface :public Interface
{
private:
	Map map_;								// ������ô��ʾ

	Dice dice_;								// ����
	bool dice_rolled_ = false;				//���ⲻ��������(��)
	std::vector<Player> players_;			// n�����, ���ղ��ò�ɾ���ķ���

	int round_ = 0;                        //�ܻغ���
	int turn_ = 0;						//���ڼ�¼�ֵ�˭��


	int survive_ = 4;                    //�������
	IMAGE background_;
	IMAGE gbk[3];

public:
	GameInterface();
	~GameInterface();

	bool inArea(const ExMessage& msg); //�Ҿ�������������岻������,���Ըĳ��������Ǹ�
	void Draw(); // ���»���
	void Run();
	void RWidget();
	int isWin();// �Ƿ�ʤ��

};


class RoleInterface :public Interface
{
private:
	Button* SetUp_;//���ϰ�ť
	Button* SetDown_;//���°�ť 
	Button* CloseBtn_;
	Button* Confirm_;//ȷ����ť
public:
	RoleInterface();
	~RoleInterface();
	IMAGE imgs[9];// ��������8����ɫ��ͼƬ
	IMAGE aimgs[9];// �������н�ɫ����ͼƬ
	bool inArea(const ExMessage& msg);
	void Draw();// ����
	void Run();

};

//��Ϸ�������	
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

	void Draw();//����
	void Run();
	bool inArea(const ExMessage& msg);
};


// ��Ϸ���ý���
class GamesetInterface :public Interface
{
private:
	IMAGE img_[3];

public:
	GamesetInterface();
	~GamesetInterface();

	//void Volume();// ��������
	static void BGM();//���ű��������Լ����ء�

	bool inArea(const ExMessage& msg);
	void Draw();// ����
	void Run();

};