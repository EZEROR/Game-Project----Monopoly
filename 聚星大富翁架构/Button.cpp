#include "Button.h"
#include <easyx.h>
#include <stdio.h>
#include "Tools.h"
using namespace std;

Button::Button()
{

}

Button::Button(int x, int y, int width, int height, const char* text):
	x_(x), y_(y), width_(width), height_(height)
{
	//绘制按钮
	setfillcolor(RGB(230, 231, 232));
	fillroundrect(x, y, x + width, y + height, 5, 5);
	//绘制按钮文本
	textwidth(10);
	int hSpace = (width - textwidth(text)) / 2;
	int vSpace = (height - textheight(text)) / 2;
	settextcolor(BLACK);//设置游戏按钮颜色为黑色
	outtextxy(x + hSpace, y + vSpace, text);
}


bool Button::inArea(const ExMessage& msg) //判断按钮是否在指定的矩形区域之中
{
	if (msg.x > x_ && msg.x < x_ + width_ && msg.y>y_ && msg.y < y_ + height_ && msg.message == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}


bool Button::inArea(int mx, int my) //判断按钮是否在指定的矩形区域之中
{
	if (mx > x_ && mx < x_ + width_ && my>y_ && my < y_ + height_)
	{
		return true;
	}


	return false;
}

//绘制普通按钮
void Button::button(int x, int y, int w, int h, const char* text) //当鼠标在按钮区域中且按钮被点击，执行以下函数。
{
	//把用来绘画当前按钮的数值，传送给构造出来的对象
	this->x_ = x;
	this->y_ = y;
	this->width_ = w;
	this->height_ = h;

	//绘制按钮
	setfillcolor(RGB(230, 231, 232));
	fillroundrect(x, y, x + w, y + h, 5, 5);
	//绘制按钮文本
	textwidth(10);
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	settextcolor(BLACK);//设置游戏按钮颜色为黑色
	outtextxy(x + hSpace, y + vSpace, text);

}


//绘制棕色按钮（只有棕色）
void Button::button(int x, int y, int w, int h, const char* text, LPCTSTR btn_url)
{
	//把用来绘画当前按钮的数值，传送给构造出来的对象


	//绘制按钮
	//setfillcolor(RGB(230, 231, 232));
	//fillroundrect(x, y, x + w, y + h, 5, 5);
	//绘制按钮文本
	textwidth(10);
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	//LPCTSTR bbtn_url = "Images/bbtn.png";
	IMAGE btn;//按钮图片
	settextstyle(24, 8, "楷体");
	loadimage(&btn, btn_url);
	/*putimage(x + hSpace - 120, y + vSpace - 30, &btn); */
	putimagePNG(x + hSpace - 120, y + vSpace - 30, &btn);
	settextcolor(RGB(200, 200, 200));//设置游戏按钮颜色为黑色
	outtextxy(x + hSpace, y + vSpace, text);
	this->x_ = x;
	this->y_ = y;
	this->width_ = w;
	this->height_ = h;
}



void Button::button(int x, int y, int w, int h, const char* text, LPCTSTR btn_url, COLORREF color)
{
	//把用来绘画当前按钮的数值，传送给构造出来的对象


	//绘制按钮
	//setfillcolor(RGB(230, 231, 232));
	//fillroundrect(x, y, x + w, y + h, 5, 5);
	//绘制按钮文本
	textwidth(10);
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	//LPCTSTR bbtn_url = "Images/bbtn.png";
	IMAGE btn;//按钮图片
	settextstyle(24, 8, "楷体");
	loadimage(&btn, btn_url);
	/*putimage(x + hSpace - 120, y + vSpace - 30, &btn); */
	putimagePNG(x + hSpace - 120, y + vSpace - 30, &btn);
	settextcolor(color);//设置游戏按钮颜色
	outtextxy(x + hSpace, y + vSpace, text);
	this->x_ = x;
	this->y_ = y;
	this->width_ = w;
	this->height_ = h;
}




