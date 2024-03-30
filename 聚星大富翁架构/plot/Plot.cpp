#include "Plot.h"


/*
	对常量赋值
	根据 plot_kind 获取名称，保存至 name
	对所有其他变量进行初始化

	初始化 yesButton 和 noButton

*/
Plot::Plot(int x, int y, int w, int h) :xywh_{ x,y,w,h }
{
	yes_Button_ = new Button(x, y, w, h, "确认");
	no_Button_ = new Button(x, y, w, h, "取消");
}

Plot::~Plot()
{
}

/*
	利用 xywh_ 在对应位置，画出对应大小的地块
		绘制矩形
		绘制文字	矩形中根据name写出地块名称	（如：“上海”）
*/
//void Plot::Draw()
//{
//
//}

void Plot::Draw()
{
}

///*
//	画出长方形对话框
//	确认 与 取消按钮
//	提示文本
//*/
//void Plot::DrawWindow()
//{
//
//
//}

/*
	判定 输入进来的 msg 是否在当前 plot 的范围内（默认触发了左键down）
*/
//bool Plot::inArea(const ExMessage& msg)
//{
//	return false;
//}

/*
	判定 输入进来的 msg 是否在当前 window中的 button 的范围内（默认触发了左键down）
		分别判定 yes，nobutton 的 inarea 是否被触发
*/

bool Plot::inWindow(const ExMessage& msg, Player& player)
{
	if ((*player.current_plot_)->level_ == 2 || (*player.current_plot_)->owner_ID_ != player.ID_ && (*player.current_plot_)->owner_ID_)
	{
		cout << "No window to show." << endl;
		return true;
	}



	if (yes_Button_->inArea(msg)) {
		/*
			执行对应操作
		*/
		cout << "YES button clicked." << endl;
		Event(player);
		return true;
	}
	/*
		同理 no_button
	*/
	else if(no_Button_->inArea(msg))
	{
		cout << "NO button clicked." << endl;
		return true;
	}
	return false;

}

void Plot::Event(Player& player)
{
}

