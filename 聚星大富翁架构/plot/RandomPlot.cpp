#include <easyx.h>
#include <string>
#include "Plot.h"


//负责人：
//功能：绘制各个格子的图片
//	绘制矩形 
//  绘制文字	矩形中根据name写出地块名称	
//参数：NULL
//返回值:NULL
void RandomPlot::Draw()
{
	IMAGE image;
	loadimage(&image, "asserts/RandomPlot.png");
	putimage(xywh_[0], xywh_[1], &image);
}

//负责人:
//功能:绘制特殊事件（随机事件）弹窗//每次到本格子，随机显示不同事件	
/*
	绘制矩形
	根据0~19的随机数显示随机事件
	随机事件！ （文字）
	显示随机事件,与增减金额n￥
	再调用//Player类的函数：RandomMove（go）函数
	//UpdateWealth(n);// 根据事件更新资金 */
	//参数：无
	//返回值：无
	//
void RandomPlot::DrawWindow(Player& player)
{
	IMAGE image;
	if (Random == 3) {
		loadimage(&image, "asserts/RamdomPlot_cs.png");
	}
	else if (Random == 1) {
		loadimage(&image, "asserts/RamdomPlot_send_money.png");
	}
	else if (Random == 2)
	{
		loadimage(&image, "asserts/RamdomPlot_deduct_money.png");
	}
	putimage(593, 99, &image);
	FlushBatchDraw();
} //绘制特殊事件弹窗	

bool RandomPlot::inWindow(const ExMessage& msg, Player& player)
{
	//遇上自然灾害，扣除300元” / “移动12格

	//随机数
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 3);
	Random = dist(gen);
	//画弹窗
	DrawWindow(player);

	if (Random == 1) {
		player.UpdateWealth(300);
	}
	else if (Random == 2) {
		player.UpdateWealth(-300);
	}
	if (Random == 3) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(1, 22);
		int randomNum = dist(gen);
		cout << randomNum << endl;
		//未写：人物行走路程增加
		//未写人物到达下一个格子
		player.Move(randomNum);
		//移动有大问题
		/*(*player.bir_plot_)->DrawWindow(player);
		(*player.bir_plot_)->inWindow(msg,player);*/
	}
	Random = 0;
	//Event(player);
	Sleep(2000);
	return true;
}

RandomPlot::RandomPlot(int x, int y, int w, int h) :Plot(x, y, w, h)
{
	this->price_[3] = { 250 }; // 数组里存储不同等级城市地块的价格
	this->name_ = "随机格子";
	this->xywh_[0] = x;// 方形类坐标
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;
	this->yes_Button_ = new Button();// 用于保存 window中的确认按钮
	this->no_Button_ = new Button(0, 0, 800, 450, "");//  用于保存 window中的取消按钮
	this->flag_window_ = true;

}

RandomPlot::~RandomPlot()
{
}



