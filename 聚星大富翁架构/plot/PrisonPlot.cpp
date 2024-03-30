#include <graphics.h>
#include <string>
#include "Plot.h"
#include "../Tools.h"

//负责人:
//功能:绘制特殊事件（监狱）弹窗		
// 
//参数：
//返回值：
//
void PrisonPlot::DrawWindow(Player& player)
{
	if (!player.prison_flag_)
	{
		IMAGE Gwidget;
		loadimage(&Gwidget, "Images/Gameinterface/Widget.png");
		putimagePNG(550, 110, &Gwidget);
		//设置填充颜色
		setfillcolor(WHITE);
		//弹窗//绘制一个矩形//有填充
		int p_x = 593, p_y = 124, p_w = 207, p_h = 202;
		//fillrectangle(p_x, p_y, p_x + p_w, p_y + p_h);
		//监狱
		int p_x_t = 634, p_y_t = 127, p_w_t = 124, p_h_t = 21;
		setfillcolor(RGB(230, 231, 232));
		fillroundrect(p_x_t, p_y_t, p_x_t + p_w_t, p_y_t + p_h_t, 5, 5);
		char p_text[] = "监狱";
		//settextstyle(10,0,"微软雅黑");
		int hSpace = (p_w_t - textwidth(p_text)) / 2;
		int vSpace = (p_h_t - textheight(p_text)) / 2;
		settextcolor(BLACK);
		outtextxy(p_x_t + hSpace, p_y_t + vSpace, p_text);
		//监狱图片
		IMAGE image;
		loadimage(&image, _T("asserts/监狱(1).jpg"));
		putimage(670, 164, &image);//输出图片

		//按钮

		//settextcolor(WHITE);//设置游戏按钮颜色为白色
		yes_Button_->button(725, 232, 49, 20, "提前保释（150￥）");
		no_Button_->button(620, 232, 49, 20, "拒绝支付");
		/**/IMAGE image1; IMAGE image2;
		loadimage(&image1, _T("asserts/提前保释(1).jpg"));//提前保释（150￥）
		loadimage(&image2, _T("asserts/拒绝支付(1).jpg"));//拒绝支付
		putimage(725, 232, &image1);//输出图片
		putimage(620, 232, &image2);//输出图片

		//释义文字
		settextstyle(18, 0, "微软雅黑");
		settextcolor(BLACK);
		outtextxy(620, 275, "进入监狱后将停止行动三回合");
		outtextxy(620, 298, "期间自己房产无法收取通行费");

		//FlushBatchDraw();
	}

}

/*

*/
PrisonPlot::PrisonPlot(int x, int y, int w, int h) :Plot(x, y, w, h)
{
	this->name_ = "监狱";
	this->xywh_[0] = x;
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;

	this->yes_Button_ = new Button();//用于保存 window中的确认按钮
	this->no_Button_ = new Button();// 用于保存 window中的取消按钮

	this->flag_window_ = true;

}

PrisonPlot::~PrisonPlot()
{
	delete yes_Button_;
	delete no_Button_;
}


void PrisonPlot::Draw() //绘制
{
	IMAGE image;

	loadimage(&image, _T("asserts/监狱(1).jpg"));

	//输出图片
	putimage(xywh_[0], xywh_[1], &image);
}


//判定鼠标目前是否在弹窗上
bool PrisonPlot::inWindow(const ExMessage& msg, Player& player)//0未点击，1点击了是,2点击退出
{
	//只有player站在当前方格上面才会点击弹窗
	if (!player.prison_flag_)
	{

		//绘制弹窗

			//按钮1，提前保释
			//按钮2. 拒绝支付
		if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
		{
			if (player.cash_ > 150) 
			{
				player.cash_ -= 150;
			}
			else
			{
				settextstyle(48, 0, "微软雅黑");
				settextcolor(RED);
				outtextxy(10, 10, "资金不够！");
				//停留三次
				player.prison_flag_ = 3;
			}
			return true;
		}
		//按钮2，退出
		if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg))
		{
			//停留三次
			player.prison_flag_ = 3;
			return true;
		}
		return false;
	}
	return true;
}
