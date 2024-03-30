#include "Plot.h"
#include<easyx.h>

BirthPointPlot::BirthPointPlot(int x, int y, int w, int h) :Plot(x, y, w, h)
{
	this->name_ = "出生点";
	this->xywh_[0] = x;
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;


}

BirthPointPlot::~BirthPointPlot()
{

}

//负责人：
//功能：绘制各个格子的图片
//	绘制矩形 
//  绘制文字	矩形中根据name写出地块名称	
//参数：NULL
//返回值:NULL
void BirthPointPlot::Draw()//绘制
{
	rectangle(xywh_[0], xywh_[1], xywh_[0] + xywh_[2], xywh_[1] + xywh_[3]);//文本框的大小
	setcolor(RGB(215, 215, 215));
	int textWidth4 = textwidth(_T("出生点"));
	int textHeight4 = textheight(_T("出生点"));

	int textX4 = xywh_[0] + (xywh_[2] - textWidth4) / 2 + 5;
	int textY4 = xywh_[1] + (xywh_[3] - textHeight4) / 2;
	settextstyle(12, 0, _T("宋体"));
	outtextxy(textX4, textY4, _T("出生点"));




	// 加载图像
	IMAGE img_birth;
	loadimage(&img_birth, "asserts/birth.png", xywh_[2], xywh_[3], true);


	int imgX = xywh_[0] + 1;
	int imgY = xywh_[1] + 1;

	// 绘制图像
	putimage(imgX, imgY, &img_birth);

}

void BirthPointPlot::DrawWindow(Player& player) {

}

bool BirthPointPlot::inWindow(const ExMessage& msg, Player& player)
{
	return true;
}



void BirthPointPlot::Event(Player& player) 
{

}