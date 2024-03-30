#include "Interface.h"

using namespace std;


GameoverInterface::GameoverInterface(vector<Player>& players):players_(players)
{

	playerbk_ = new Button;

	for (int i = 0; i < 4; i++)
	{
		playernames_[i] = new Button;
		playergold_[i] = new Button;
	}
}
GameoverInterface::~GameoverInterface()
{
	delete playerbk_;
	
	for (int i = 0; i < 4; i++)
	{
		delete playernames_[i];
		delete playergold_[i];
	}

}

bool GameoverInterface::inArea(const ExMessage& msg)
{

	switch (msg.message)
	{
	case WM_LBUTTONDOWN:
		if (((msg.x - 546) * (msg.x - 546) + (msg.y - 46) * (msg.y - 46)) <= (12.5) * (12.5))
		{

			cleardevice();
			return true;
		}
	}
	return false;
}


void GameoverInterface::Draw()
{

	setbkmode(TRANSPARENT);
	setlinecolor(BLACK);
	IMAGE imgbk;
	IMAGE imga;
	IMAGE img_[9];
	IMAGE wimg;
	IMAGE bbimg;
	IMAGE imgck;
	loadimage(&imgbk, "Images/胜利背景.png", 300, 379);
	loadimage(&img_[1], "asserts/坤坤.png ", 47, 52);// 显示图片
	loadimage(&img_[2], "asserts/马老师.png ", 47, 52);// 显示图片
	loadimage(&img_[3], "asserts/丁真选择一.png", 47, 52);// 显示图片
	loadimage(&img_[4], "asserts/Seele.png ", 47, 52);// 显示图片
	loadimage(&img_[5], "asserts/Elysia.png", 47, 52);// 显示图片
	loadimage(&img_[6], "asserts/Kevin.png", 47, 52);// 显示图片
	loadimage(&img_[7], "asserts/Megaman.png", 47, 52);// 显示图片
	loadimage(&img_[8], "asserts/Kesulu.png", 47, 52);// 显示图片

	loadimage(&imga, "Images/财富框.png", 70, 20);
	loadimage(&wimg, "Images/wimgs.png");
	loadimage(&imgck, "Images/s.png", 800, 450);
	putimagePNG(0, 0, &imgck);
	putimagePNG(246, 46, &imgbk);
	//退出按钮
	fillcircle(546, 46, 12);


	int circle_y[4] = { 105,190,280,365 };
	int circle_img_y[4] = { 85,170,257,345 };
	int circle_img_x[4] = { 261,264,258,264 };
	int name_button_y[4] = { 155,240,330,410 };
	int name_button_png_y[4] = { 120,205,285,370 };
	int name_y[4] = { 135,220,310,390 };
	int gold_y[4] = { 120,205,290,375 };

 	for (int i = 0; i < 4; i++)
	{
		fillcircle(283, circle_y[i], 20);//圆状态
		if (i == 0)
		{
			putimage(circle_img_x[i], circle_img_y[i], &img_[1]);
		}
		else if (i == 1)
		{
			putimage(circle_img_x[i], circle_img_y[i], &img_[4]);
		}
		else if (i == 2)
		{
			putimage(circle_img_x[i], circle_img_y[i], &img_[8]);
		}
		else if (i == 3)
		{
			putimage(circle_img_x[i], circle_img_y[i], &img_[rnbk]);
		}

		playernames_[i]->button(335, name_button_y[i], 70, 20, "", "Images/sbbtn.png");
		putimagePNG(350, name_button_png_y[i], &wimg);
		outtextxy(250, name_y[i], players_[i].name_);	//分别输入四个角色的名字
		outtextxy(410, gold_y[i], std::to_string(players_[i].cash_).c_str()); //分别输入四个角色的财富
	}


	settextcolor(BLACK);
	outtextxy(542, 38, _T("X"));
	settextstyle(30, 20, _T("Consolas"));
	outtextxy(320, 50, _T("游戏结束"));

}

void GameoverInterface::Run()
{
	bool inArea_bk = true;
	initgraph(800, 450, EX_SHOWCONSOLE);
	setbkcolor(0xAAAAAA);
	cleardevice();

	Draw();

	FlushBatchDraw();

	ExMessage msg;
	while (inArea_bk == true)
	{
		msg = getmessage(EX_KEY | EX_MOUSE);
		if (inArea(msg))
		{
			break;
		}
	}

}

