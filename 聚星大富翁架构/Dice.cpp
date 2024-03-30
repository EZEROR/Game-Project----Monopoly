#include "Dice.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include "../聚星大富翁架构/Tools.h"

using namespace std;

/*
	初始化 骰子的xywh，以及图片资源 img（6个面，6个图）
*/
Dice::Dice()
{
	for (int i = 0; i < 6; i++)
	{
		string path = "Images/dice/";					//图片存放路径
		path.push_back('0' + i + 1); 					//图片前缀
		path.append(".png");  							//图片格式

		cout << path << " loaded!" << endl;				//测试图片加载

		loadimage(&img_[i], path.c_str(), 100, 100);	
	}
	putimagePNG(x_, y_, &img_[num_ - 1]);
}

Dice::~Dice()
{
}

/*
	画出骰子的图片（putimage img[num-1]）
*/
void Dice::Draw()
{
	putimagePNG(x_, y_, &img_[num_ - 1]);
}

/*
	根据 xywh，判断鼠标是否在骰子的区域内，并且点击
*/
bool Dice::inArea(const ExMessage& msg)
{
	if (msg.x > x_ && msg.x < x_ + width_ && msg.y > y_ && msg.y < y_ + height_)
	{
		if (msg.message == WM_LBUTTONDOWN)		//监测这次和上次鼠标是否按下,要求这次按下,上次没按
		{
			cout << "Dice clicked!" << endl;
			return true;
		}
	}
	return false;
}

/*
	inArea 判定成功后，被调用
	获取一个随机值，并且返回
*/
int Dice::Random()
{
	num_ = rand() % 6 + 1;
	return num_;
}
