#include "Interface.h"
#include "../player/Player.h"
#include <iostream>
#include <graphics.h>
#include "../Tools.h"



LPCTSTR role_image_url = "Role/Kevin.png";
IMAGE role_image;

LPCTSTR rolebk_image_url = "Role/Solitude.png";
IMAGE rolebk_image;
int role_n = 6;//切换人物用的整数（人物编号）

LPCTSTR role_widget_url = "Role/Widget.png";
IMAGE role_widget;

LPCTSTR role_attribute_url = "Role/Chart/KWchart.png";
IMAGE role_attribute;

IMAGE rtext;//标题文字
ExMessage msg = { 0 };




void RoleInterface::Draw()
{

	/*
		   画出当前界面的按钮
		*/
	loadimage(&rolebk_image, rolebk_image_url);
	putimage(0, 0, &rolebk_image);
	SetUp_->button(180, 60, 200, 60, "↑", "Images/hkbtn.png", RGB(0, 0, 0));
	SetDown_->button(180, 500, 200, 60, "↓", "Images/hkbtn.png", RGB(0, 0, 0));
	CloseBtn_->button(940, 40, 100, 40, "X", "Images/hkbtn.png", RGB(0, 0, 0));
	Confirm_->button(700, 450, 200, 120, "", "Images/hk2btn.png", RGB(0, 0, 0));

	loadimage(&imgs[6], "Role/Kevin.png");
	putimage(105, 135, &imgs[6]);//放置初始图片

	//放置角色属性窗口
	loadimage(&role_widget, role_widget_url);
	putimagePNG(582, 135, &role_widget);

	loadimage(&role_attribute, role_attribute_url);
	putimagePNG(687, 240, &role_attribute);

	//放置标题
	loadimage(&rtext, "Role/Text.png");
	putimagePNG(387, 40, &rtext);
	/*
	   对所有按钮 判定 鼠标是否点击
	*/

	EndBatchDraw();



}
bool RoleInterface::inArea(const ExMessage& msg)
{




	FlushBatchDraw();

	if (SetUp_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		role_n++;
		/*std::cout << role_n<<"here1" << std::endl;*/
		/*this->Draw();*/
		role_n = role_n % 9;
		if (role_n == 0)
			role_n++;
		/*std::cout << role_n << "here2" << std::endl;*/
		Resize(&role_image, 340, 340);
		putimage(105, 135, &imgs[role_n]);
		putimagePNG(582, 135, &role_widget);
		putimagePNG(687, 240, &aimgs[role_n]);
		/*std::cout << role_n << "here1" << std::endl;*/

	}

	if (SetDown_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		/*std::cout << role_n << "here4" << std::endl;*/
		role_n--;
		/*std::cout << role_n << "here3" << std::endl;*/
	/*this->Draw();*/
		if (role_n == 0)
		{
			role_n = 8;
			role_n = role_n % 9;
		}
		/*std::cout << role_n<<"here2"<<std::endl;*/



		Resize(&role_image, 352, 353);
		putimage(105, 135, &imgs[role_n]);
		putimagePNG(582, 135, &role_widget);
		putimagePNG(687, 240, &aimgs[role_n]);

	}
	if (CloseBtn_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		cleardevice();
		/*		MainInterface M;
				M.Run();*/
		return true;

	}

	if (Confirm_->inArea(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		rnbk = role_n;
		cleardevice();
		return true;
		//确定当前角色模型;
	}
	return 0;

}



RoleInterface::RoleInterface()
{
	BeginBatchDraw();


	SetDown_ = new Button;
	SetUp_ = new Button;
	CloseBtn_ = new Button;
	Confirm_ = new Button;

	loadimage(&imgs[1], "Role/Kunkun.png");
	loadimage(&imgs[2], "Role/Mabaoguo.png");
	loadimage(&imgs[3], "Role/Dingzhen.png");
	loadimage(&imgs[4], "Role/Seele.png");
	loadimage(&imgs[5], "Role/Elysia.png");
	loadimage(&imgs[6], "Role/Kevin.png");
	loadimage(&imgs[7], "Role/Megaman.png");
	loadimage(&imgs[8], "Role/Kesulu.png");


	loadimage(&aimgs[1], "Role/Chart/Cxkchart.png");
	loadimage(&aimgs[2], "Role/Chart/Mchart.png");
	loadimage(&aimgs[3], "Role/Chart/Dchart.png");
	loadimage(&aimgs[4], "Role/Chart/Schart.png");
	loadimage(&aimgs[5], "Role/Chart/Echart.png");
	loadimage(&aimgs[6], "Role/Chart/KWchart.png");
	loadimage(&aimgs[7], "Role/Chart/Mechart.png");
	loadimage(&aimgs[8], "Role/Chart/Kchart.png");



}
RoleInterface::~RoleInterface()
{
	delete SetUp_;
	delete SetDown_;
	delete CloseBtn_;
	delete Confirm_;
	SetUp_ = nullptr;
	SetDown_ = nullptr;
	CloseBtn_ = nullptr;
	Confirm_ = nullptr;
}

void RoleInterface::Run()
{
	Draw();
	while (1)
	{
		msg = getmessage();
		if (inArea(msg))
		{
			//MainInterface M;
			//M.Run();
			return;
		}

	}

}