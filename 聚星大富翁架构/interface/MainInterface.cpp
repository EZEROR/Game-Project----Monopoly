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


	BeginGameBtn_->button(450, 230, 200, 60, "开始游戏", "Images/bbtn.png");
	ActorChooseBtn_->button(450, 320, 200, 60, "角色选择", "Images/bbtn.png");
	SetGameBtn_->button(454, 410, 200, 60, "设置|介绍", "Images/bbtn.png");
	ExitGameBtn_->button(450, 500, 200, 60, "退出游戏", "Images/bbtn.png");
	LoginBtn_->button(940, 40, 100, 40, "登录", "Images/gbtn.png");
	settextcolor(RGB(20, 20, 20));
	settextstyle(30, 8, "楷体");
	outtextxy(462, 570, "——01星球  聚星组——");

	EndBatchDraw();



}

MainInterface::MainInterface()
{
	BeginGameBtn_ = new Button;
	ActorChooseBtn_ = new Button;
	SetGameBtn_ = new Button;
	ExitGameBtn_ = new Button;
	LoginBtn_ = new Button;//开始游戏，游戏设置，游戏玩法，人物介绍，退出


}





//释放不必要的内存
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
	Draw();//绘画
	GamesetInterface bgm;
	bgm.BGM();
	ExMessage msg;
	//return回原来的主界面继续
	while (1) {
		msg = getmessage();
		if (inArea(msg))
		{
			Init();
			Draw();
		};
		//更新区域
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
		绘画游戏界面+进入游戏界面循环
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
		绘画游戏设置界面+进入游戏设置界面循环
		*/
	}
	if (ExitGameBtn_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		exit(0);
	}

	if (LoginBtn_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		/*cleardevice();*/
		//调用登录界面
	}
	return 0;
}


void MainInterface::Init()
{
	initgraph(1080, 600, SHOWCONSOLE);
	//去掉字体的背景颜色
	setbkmode(TRANSPARENT);
	setbkcolor(RGB(122, 122, 122));
	cleardevice();

}