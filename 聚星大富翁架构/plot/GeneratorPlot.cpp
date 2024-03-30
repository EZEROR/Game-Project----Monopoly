#include "Plot.h"


GeneratorPlot::GeneratorPlot(int x, int y, int w, int h) :Plot(x, y, w, h)//std::vector<Player>&player_是为了实现给其他玩家过路费
//GeneratorPlot::GeneratorPlot(int x, int y, int w, int h) : Plot(x, y, w, h)
{
	this->price_[3] = { 250 }; // 数组里存储不同等级城市地块的价格
	this->name_ = "发电站";
	this->xywh_[0] = x;// 方形类坐标
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;
	this->yes_Button_ = new Button();// 用于保存 window中的确认按钮
	this->no_Button_ = new Button();//  用于保存 window中的取消按钮
	this->flag_window_ = true;
}

GeneratorPlot::~GeneratorPlot()
{
	delete yes_Button_;
	delete no_Button_;

}


//绘制格子
void GeneratorPlot::Draw()
{
	IMAGE image;
	if (owner_ID_ == 0) {
		//显示不同图片
		loadimage(&image, _T("asserts/无人发电站(1).jpg"));
	}
	else if (owner_ID_ == 1) {
		loadimage(&image, _T("asserts/红色发电站(1).jpg"));
	}
	else if (owner_ID_ == 2) {
		loadimage(&image, _T("asserts/黄色发电站(1).jpg"));
	}
	else if (owner_ID_ == 3) {
		loadimage(&image, _T("asserts/蓝色发电站(1).jpg"));
	}
	else if (owner_ID_ == 4) {
		loadimage(&image, _T("asserts/绿色发电站(1).jpg"));
	}
	//输出图片
	putimage(xywh_[0], xywh_[1], &image);
}






//绘制弹窗
void GeneratorPlot::DrawWindow(Player& player)
{
	if (!owner_ID_)
	{
		IMAGE img_victory;
		loadimage(&img_victory, "Images/胜利背景.png", 207, 202, true);
		int imgX = 593 + 1;
		int imgY = 124 + 1;

		// 绘制图像
		putimage(imgX, imgY, &img_victory);

		//设置填充颜色
		setfillcolor(WHITE);
		//弹窗//绘制一个矩形//有填充
		//int g_x = 593, g_y = 124, g_w = 207, g_h = 207;
		//fillrectangle(g_x, g_y, g_x + g_w, g_y + g_h);
		//发电站
		//int g_x_t = 634, g_y_t = 127;// , g_w_t = 124, g_h_t = 21;
		//outtextxy(g_x_t, g_y_t, "发电站");
		int g_x_t = 634, g_y_t = 127, g_w_t = 124, g_h_t = 21;
		setfillcolor(RGB(230, 231, 232));
		fillroundrect(g_x_t, g_y_t, g_x_t + g_w_t, g_y_t + g_h_t, 5, 5);
		char g_text[] = "发电站";
		//settextstyle(10,0,"微软雅黑");
		int hSpace = (g_w_t - textwidth(g_text)) / 2;
		int vSpace = (g_h_t - textheight(g_text)) / 2;
		settextcolor(BLACK);
		outtextxy(g_x_t + hSpace, g_y_t + vSpace, g_text);


		settextcolor(BLACK);//设置游戏按钮颜色为白色
		outtextxy(677, 154, "通行费");
		outtextxy(740, 154, "购买价格");
		outtextxy(689, 177, "55");
		outtextxy(755, 177, "250");

		//按钮
		yes_Button_->button(602, 279, 119, 40, "购买250|购买");
		no_Button_->button(744, 279, 48, 40, "拒绝");

	}

	return;

}




/*
	功能：在人物到达此地块后，判断此地块的所有人，如果是无主之地，判断鼠标点击了哪个按钮（购买、X）；
			如果是其他人的地块，地块主人加钱，自己减钱。

	返回值：NULL
	参数：NULL
*/
//判定鼠标目前是否在弹窗上
bool GeneratorPlot::inWindow(const ExMessage& msg, Player& player)//0未点击，1点击了是,2点击退出
{
	//在人物到达此地块后，判断此地块的所有人，
	//如果无主人，绘制购买弹窗
	if (owner_ID_ == 0)
	{
		//	判断鼠标点击了哪个按钮（购买、X）
		//按钮1，购买
		if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
		{
			if (player.cash_ > 250) {
				this->owner_ID_ = player.ID_;//这里代表几号玩家
				owner = &player;
				player.cash_ -= 250;
				this->flag_window_ = false;

			}
			else
			{
				settextstyle(48, 0, "微软雅黑");
				settextcolor(RED);
				outtextxy(10, 10, "资金不够！");
			}

			if (!player.generator_flag_)
			{
				player.generator_flag_ = 1;//无论有无主人，都停留一次
			}

			return true;
		}
		//按钮2，退出
		if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg))
		{
			if (!player.generator_flag_)
			{
				player.generator_flag_ = 1;//无论有无主人，都停留一次
			}
			return true;

		}
		return false;
	}
	//如果是其他人的地块，地块主人加钱，自己减钱。
	else
	{
		owner->UpdateWealth(55, player);
	}


	return true;
}
