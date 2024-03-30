#include "Plot.h"
#include "../Tools.h"



HousePlot::HousePlot(int x, int y, int w, int h) :Plot(x, y, w, h)
{

}

//改
HousePlot::HousePlot(int x, int y, int w, int h, int prices[3], int sell_prices[3], int pass_prices[3], std::string name, std::string text)
	: Plot(x, y, w, h)
{
	//构造
	this->name_ = name;

	//初始化购买价格, 出售价格, 通过路费
	for (int i = 0; i < 3; i++)
	{
		this->price_[i] = prices[i];
	}
	for (int i = 0; i < 3; i++)
	{
		this->sell_price_[i] = sell_prices[i];
	}
	for (int i = 0; i < 3; i++)
	{
		this->pass_price_[i] = pass_prices[i];
	}

	this->text_ = text;

	// 按钮这里使用默认构造, 具体的属性在Draw里指定
	this->yes_Button_ = new Button;

	this->no_Button_ = new Button;

}

HousePlot::~HousePlot()
{

}

//负责人：
//功能：绘制各个格子的图片
//	绘制矩形 
//  绘制文字	矩形中根据name写出地块名称	（如：“上海”）
//				文字颜色依据owner_ID:红黄蓝绿黑分别表示1234号玩家、无主人。
// 绘制过路费或（无主时）购买金额
// 
//参数:无
void HousePlot::Draw()
{


	//绘制白色格子背景
	setfillcolor(WHITE);
	solidrectangle(xywh_[0], xywh_[1], xywh_[0] + xywh_[2], xywh_[1] + xywh_[3]);


	//输出城市名

	setbkmode(TRANSPARENT);//设置透明模式, 不被背景遮挡

	COLORREF color;//根据id设置颜色
	switch (owner_ID_)
	{
	case 1:
		color = RED;
		break;
	case 2:
		color = RGB(204, 168, 78);
		break;
	case 3:
		color = RGB(71, 134, 200);
		break;
	case 4:
		color = GREEN;
		break;
	default:
		color = BLACK;
		break;
	}


	LPCSTR city_name = name_.c_str();
	settextcolor(color);//根据owner_id设置文字颜色
	outtextxy(xywh_[0] + 13, xywh_[1] + 20, city_name);//需要重新定位文本位置

	//绘制灰色价格矩形
	setfillcolor(color);
	solidrectangle(xywh_[0], xywh_[1], xywh_[0] + 47, xywh_[1] + 13);//52,13也需要重新设计

	//输出价格文本
	settextcolor(WHITE);
	string money = std::to_string(this->price_[level_]);
	LPCSTR price_text = money.c_str();
	outtextxy(xywh_[0] + 15, xywh_[1] + 2, price_text);//需要重新定位文本位置
}


//负责人：
//功能：绘制弹窗
//	绘制矩形 
//  绘制文字	
//	如果已满级，不绘制弹窗。
//	如果无主人，绘制购买弹窗
//  如果有主人且未满级，绘制升级弹窗
//参数:无
//返回值:NULL
void HousePlot::DrawWindow(Player& player)
{
	IMAGE Gwidget;

	loadimage(&Gwidget, "Images/Gameinterface/Widget.png");

	IMAGE dbtn;
	LPCTSTR dbtn_url = "Images/Gameinterface/dbtn.png";

	if (level_ == 2)//如果是2级, 不显示窗口
	{
		return;
	}

	else if (!owner_ID_)//说明没有主人, 绘制购买弹窗
	{
		setfillcolor(WHITE);
		solidrectangle(593, 124, 593 + 207, 131 + 202);
		putimagePNG(550, 110, &Gwidget);

		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		//绘制标题 "购买 城市名"

		std::string title = "购买" + this->name_;
		LPCSTR title_text = title.c_str();
		outtextxy(666, 129, title_text);//需要重新定位文本位置

		//绘制表格表头: 城市等级, 通行费, 购买价格

		outtextxy(603, 154, "城市等级");//需要重新定位文本位置
		outtextxy(677, 154, "通行费");//需要重新定位文本位置
		outtextxy(740, 154, "购买价格");//需要重新定位文本位置


		int buy_price = 0;
		int pass_price = 0;
		char num[20];
		//第一行: 等级1, 通行费数值, 购买费用

		outtextxy(612, 177, "等级1");//需要重新定位文本位置

		pass_price = this->pass_price_[0];
		sprintf(num, "%d", pass_price);
		outtextxy(689, 177, num);//需要重新定位文本位置

		buy_price = this->price_[0];
		sprintf(num, "%d", buy_price);
		outtextxy(755, 177, num);//需要重新定位文本位置


		//第二行: 等级2, 通行费数值, 购买费用

		outtextxy(612, 202, "等级2");//需要重新定位文本位置

		pass_price = this->pass_price_[1];
		sprintf(num, "%d", pass_price);
		outtextxy(689, 202, num);//需要重新定位文本位置

		buy_price = this->price_[1];
		sprintf(num, "%d", buy_price);
		outtextxy(762, 202, num);//需要重新定位文本位置

		//第三行: 等级3, 通行费数值, 购买费用

		outtextxy(612, 225, "等级3");

		pass_price = this->pass_price_[2];
		sprintf(num, "%d", pass_price);
		outtextxy(686, 225, num);//需要重新定位文本位置

		buy_price = this->price_[2];
		sprintf(num, "%d", buy_price);
		outtextxy(759, 225, num);//需要重新定位文本位置

		outtextxy(612, 251, "购买后通行费用");//需要重新定位文本位置

		//购买后通行费用:money

		sprintf(num, "%d", this->pass_price_[0]);
		outtextxy(727, 251, num);

		//显示购买费用
		outtextxy(612, 279, "购买费用");

		sprintf(num, "%d", this->price_[0]);
		outtextxy(617, 299, num);//需要重新定位文本位置

		//调用接口, 绘制,定位按钮
		yes_Button_->button(689, 279, 48, 40, "购买");//需要重新定位按钮位置
		no_Button_->button(744, 279, 48, 40, "取消");//需要重新定位按钮位置
		//loadimage(&dbtn, "Images/Gameinterface/dbtn1.png");
		//putimagePNG(619, 263, &dbtn);
	}
	else if (owner_ID_ == player.ID_ && level_ != 2)//绘制升级弹窗
	{
		setfillcolor(WHITE);
		solidrectangle(593, 124, 593 + 207, 131 + 202);
		putimagePNG(550, 110, &Gwidget);
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		//绘制标题 "购买 城市名"

		std::string title = "升级" + this->name_;
		LPCSTR title_text = title.c_str();
		outtextxy(666, 129, title_text);//需要重新定位文本位置

		//绘制表格表头: 城市等级, 通行费, 购买价格

		outtextxy(603, 154, "城市等级");//需要重新定位文本位置
		outtextxy(677, 154, "通行费");//需要重新定位文本位置
		outtextxy(740, 154, "购买价格");//需要重新定位文本位置


		int buy_price = 0;
		int pass_price = 0;
		char num[20];
		//第一行: 等级1, 通行费数值, 购买费用

		outtextxy(612, 177, "等级1");//需要重新定位文本位置

		pass_price = this->pass_price_[0];
		sprintf(num, "%d", pass_price);
		outtextxy(689, 177, num);//需要重新定位文本位置

		buy_price = this->price_[0];
		sprintf(num, "%d", buy_price);
		outtextxy(755, 177, num);//需要重新定位文本位置


		//第二行: 等级2, 通行费数值, 购买费用

		outtextxy(612, 202, "等级2");//需要重新定位文本位置

		pass_price = this->pass_price_[1];
		sprintf(num, "%d", pass_price);
		outtextxy(689, 202, num);//需要重新定位文本位置

		buy_price = this->price_[1];
		sprintf(num, "%d", buy_price);
		outtextxy(762, 202, num);//需要重新定位文本位置

		//第三行: 等级3, 通行费数值, 购买费用

		outtextxy(612, 225, "等级3");

		pass_price = this->pass_price_[2];
		sprintf(num, "%d", pass_price);
		outtextxy(686, 225, num);//需要重新定位文本位置

		buy_price = this->price_[2];
		sprintf(num, "%d", buy_price);
		outtextxy(759, 225, num);//需要重新定位文本位置

		outtextxy(612, 251, "购买后通行费用");//需要重新定位文本位置

		//购买后通行费用:money

		sprintf(num, "%d", this->pass_price_[level_ + 1]);
		outtextxy(727, 251, num);

		//显示购买费用
		outtextxy(612, 279, "升级费用");

		sprintf(num, "%d", this->price_[level_ + 1]);
		outtextxy(617, 299, num);//需要重新定位文本位置

		//调用接口, 绘制,定位按钮
		yes_Button_->button(689, 279, 48, 40, "升级");//需要重新定位按钮位置
		no_Button_->button(744, 279, 48, 40, "取消");//需要重新定位按钮位置
		putimagePNG(619, 263, &dbtn);
		//loadimage(&dbtn, "Images/Gameinterface/dbtn1.png");
		//putimagePNG(619, 263, &dbtn);
	}

	return;
}



/*
	负责人：
	功能：
			原地获取当前鼠标的信息
			将 msg信息 传入两个按钮的 isArea中
			通过判定结果，执行对应的操作：
				选择购买或升级弹窗，改变level_ owner_、ID_、财富相关的值
				选择取消，直接return
	返回值：NULL
	参数：NULL
*/
void HousePlot::Event(Player& player)
{

	return;
}


/*
	功能：在人物到达此地块后，判断此地块的所有人，如果是无主之地，判断鼠标点击了哪个按钮（购买、X）；
			如果是其他人的地块，地块主人加钱，自己减钱。
		向前随机传送1~12个格子（调用player类的RandomMove（））
	返回值：NULL
	参数：NULL
*/
//判定鼠标目前是否在弹窗上
bool HousePlot::inWindow(const ExMessage& msg, Player& player)//0未点击，1点击了是,2点击退出
{


	//在人物到达此地块后，判断此地块的所有人，
	if (owner_ID_ == 0)
	{
		//	判断鼠标点击了哪个按钮（购买、X）
		//按钮1，购买
		if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
		{
			if (player.cash_ > price_[level_]) {
				player.cash_ -= this->price_[this->level_];//减去相应新等级的卖价
				this->level_++;//升级
				this->owner_ID_ = player.ID_;//更新拥有者ID
				owner = &player;
			}
			else
			{
				//settextstyle(48, 0, "微软雅黑");
				settextcolor(RED);
				outtextxy(10, 10, "资金不够！");
			}
			return true;
		}
		//按钮2，退出
		if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg))
		{
			return true;
		}
		return false;
	}
	else if (owner_ID_ != 0 && owner_ID_ == player.ID_ && level_ != 2)
	{
		//	判断鼠标点击了哪个按钮（购买、X）
		//按钮1，升级
		if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
		{
			if (player.cash_ > price_[level_])
			{
				player.cash_ -= this->price_[this->level_];//减去相应新等级的卖价
				this->level_++;//升级
				//this->owner_ID_ = player.ID_;//更新拥有者ID
				//owner = &player;
			}
			else
			{
				//settextstyle(48, 0, "微软雅黑");
				settextcolor(RED);
				outtextxy(10, 10, "资金不够！");
				cout << "钱不够" << endl;
			}
			return true;
		}
		//按钮2，退出
		if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg)) {
			return true;
		}
		return false;
	}

	//如果是其他人的地块，地块主人加钱，自己减钱。
	else
	{
		owner->UpdateWealth(pass_price_[level_], player);
		/*owner->cash_ += pass_price_[level_];
		player.cash_ -= pass_price_[level_];*/
	}
	return true;

}
