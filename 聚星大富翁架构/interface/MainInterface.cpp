#include "Interface.h"
#include "../Globals.h"
#include <graphics.h>


LPCTSTR mainbk_image_url = "Images/MainInterface.png";
IMAGE mainbk_image;



void MainInterface::Draw()
{
	cleardevice();
	loadimage(&mainbk_image, mainbk_image_url);
	putimage(0, 0, &mainbk_image);

	BeginBatchDraw();


	BeginGameBtn_->button(450, 230, 200, 60, "��ʼ��Ϸ", "Images/bbtn.png");
	ActorChooseBtn_->button(450, 320, 200, 60, "��ɫѡ��", "Images/bbtn.png");
	SetGameBtn_->button(454, 410, 200, 60, "����|����", "Images/bbtn.png");
	ExitGameBtn_->button(450, 500, 200, 60, "�˳���Ϸ", "Images/bbtn.png");
	LoginBtn_->button(940, 40, 100, 40, "��¼", "Images/gbtn.png");
	settextcolor(RGB(20, 20, 20));
	settextstyle(30, 8, "����");
	outtextxy(462, 570, "����01����  �����顪��");

	EndBatchDraw();



}

MainInterface::MainInterface()
{
	BeginGameBtn_ = new Button;
	ActorChooseBtn_ = new Button;
	SetGameBtn_ = new Button;
	ExitGameBtn_ = new Button;
	LoginBtn_ = new Button;//��ʼ��Ϸ����Ϸ���ã���Ϸ�淨��������ܣ��˳�


}





//�ͷŲ���Ҫ���ڴ�
MainInterface::~MainInterface()
{
	delete 	BeginGameBtn_;
	delete ActorChooseBtn_;
	delete SetGameBtn_;
	delete ExitGameBtn_;
	delete LoginBtn_;

}


void MainInterface::Run()
{
	Init();
	Draw();//�滭
	GamesetInterface bgm;
	bgm.BGM();
	ExMessage msg;
	//return��ԭ�������������
	while (1) {
		msg = getmessage();
		if (inArea(msg))
		{
			Init();
			Draw();
		};
		//��������
	}
}




bool MainInterface::inArea(ExMessage& msg)
{




	if (BeginGameBtn_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{

		cleardevice();
		initgraph(800, 450);

		BeginBatchDraw();
		GameInterface game_interface;
		EndBatchDraw();

		game_interface.Run();
		/*place = "Game";*/
					/*
		�滭��Ϸ����+������Ϸ����ѭ��
		*/
		return true;
	}
	if (ActorChooseBtn_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		cleardevice();
		RoleInterface r;
		r.Run();
		return true;
		/*place = "Role";*/
	}
	if (SetGameBtn_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		cleardevice();
		GamesetInterface s;
		s.Run();
		return true;
		/*place = "Gameset";*/
		/*
		�滭��Ϸ���ý���+������Ϸ���ý���ѭ��
		*/
	}
	if (ExitGameBtn_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		exit(0);
	}

	if (LoginBtn_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		/*cleardevice();*/
		//���õ�¼����
	}
	return 0;
}


void MainInterface::Init()
{
	initgraph(1080, 600, SHOWCONSOLE);
	//ȥ������ı�����ɫ
	setbkmode(TRANSPARENT);
	setbkcolor(RGB(122, 122, 122));
	cleardevice();

}