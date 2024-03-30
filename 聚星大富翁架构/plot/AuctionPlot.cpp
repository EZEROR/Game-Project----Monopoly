#include "Plot.h"
#include<iostream>
#include "../Tools.h"

using namespace std;
//拍卖行格子类

	/*
		负责人：
		功能：遍历所有城市，找到用户拥有的城市，点击拍卖，即卖掉。卖掉后随机获得2、3倍的房子价值的现金。再调用
		参数：无
		返回值：无

	*/
AuctionPlot::AuctionPlot(int x, int y, int w, int h, std::list<Plot*>& game_map) :Plot(x, y, w, h) {
	// 实例化按钮并设置其位置和标签
	this->name_ = "拍卖行";
	this->xywh_[0] = x;
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;
	this->yes_Button_ = new Button(619, 293, 44, 20, "拍卖"); // 根据需要调整坐标和尺寸
	this->no_Button_ = new Button(733, 293, 44, 20, "放弃");   // 根据需要调整坐标和尺寸
	this->game_map = &game_map;

}
AuctionPlot::~AuctionPlot()
{
	delete yes_Button_;
	delete no_Button_;
}

//链表中 第一个被搜索到的 该玩家拥有的一座城市,卖掉后随机获得2、3倍的房子价值的金币（文字）
void AuctionPlot::GoAuction(Player& player)
{
	// 遍历 Map 类对象的 game_map_ 成员变量找到第一个属于玩家拥有的一座城市的地块
	int i = (*game_map).size();
	for (auto it = (*game_map).begin(); it != (*game_map).end(); ++it) {
		// 遍历地块列表，找到属于玩家拥有的一座城市的地块

		if ((*it)->owner_ID_ == player.ID_) {
			int moneyMultiplier = (rand() % 2 == 0) ? 2 : 3; // 随机生成2或3
			int moneyToAdd = (*it)->sell_price_[(*it)->level_] * moneyMultiplier; // 计算金币数目
			player.cash_ += moneyToAdd;
			break;
		}
		if (!i)
		{
			break;
		}
	}

}



//负责人:
//功能:当玩家踩到这个格子时，绘制特殊事件（拍卖）弹窗
//	   在页面右侧绘制一个矩形，即弹窗本体
// 	   矩形中绘制：
//							拍卖！（绘制文字）
// 
//		退出（绘制按钮）					拍卖（绘制按钮）
//		输入你自己所拥有的一座城市的名字,拍卖。卖掉后随机获得2、3倍的房子价值的金币n（文字）。
//		再调用//Player类的函数：UpdateWealth(n);// 根据事件更新资金 		
//参数：无
//返回值：无
//
void AuctionPlot::DrawWindow(Player& player)  //绘制特殊事件弹窗
{
	IMAGE img_victory;
	loadimage(&img_victory, "Images/胜利背景.png", 207, 202, true);
	int imgX = 593 + 1;
	int imgY = 124 + 1;

	// 绘制图像
	putimage(imgX, imgY, &img_victory);

	setfillcolor(WHITE);
	//fillrectangle(593, 124, 593 + 207, 124 + 202);//文本框的大小

	//int offsetX=200, offsetY=200; //记录x，y的偏移量

	//rectangle(634, 127, 634 + 124, 127 + 21);//城市拍卖文本框的大小

	int textWidth = textwidth(_T("城市拍卖"));
	int textHeight = textheight(_T("城市拍卖"));

	int textX = 634 + (124 - textWidth) / 2;
	int textY = 127 + (21 - textHeight) / 2;

	settextcolor(BLACK);
	settextstyle(15, 0, _T("宋体"));
	outtextxy(textX, textY, _T("城市拍卖"));

	//rectangle(619, 172, 619 + 155, 172 + 84);//城市文本框的大小


	//int cityNameWidth6 = textwidth("广州");
	//int cityNameHeight6 = textheight("广州");
	//int cityNameX = 619 + (155 - cityNameWidth6) / 2;
	//int cityNameY = 172 + (84 - cityNameHeight6) / 2 - 30;

	//settextstyle(17, 0, _T("黑体"));
	//outtextxy(cityNameX, cityNameY, "广州");

	//std::string auctionValueText = "拍卖价值："; // 加入一行文字，代表拍卖价值

	//// 计算拍卖价值文字的宽度和高度
	//int auctionValueTextWidth = textwidth(auctionValueText.c_str());
	//int auctionValueTextHeight = textheight(auctionValueText.c_str());

	//int auctionValueTextX = 619 + (155 - auctionValueTextWidth) / 2 - 20;
	//int auctionValueTextY = cityNameY + cityNameHeight6 + 40;

	//settextstyle(15, 0, _T("宋体"));
	//outtextxy(auctionValueTextX, auctionValueTextY, auctionValueText.c_str());



	std::string plotName = ""; // 从地块对象获取名称
	int moneyToAdd = 0; // 初始化moneyToAdd变量
	for (auto at = (*game_map).begin(); at != (*game_map).end(); ++at) {


		// 遍历地块列表，找到属于玩家拥有的一座城市的地块
		if (HousePlot* houseplot = dynamic_cast<HousePlot*>(*at)) {
			if (houseplot->owner_ID_ == player.ID_) {
				plotName = houseplot->name_;
				int moneyMultiplier = (rand() % 2 == 0) ? 2 : 3; // 随机生成2或3
				moneyToAdd = (*at)->sell_price_[(*at)->level_] * moneyMultiplier; // 计算金币数目  200
				break;
			}
		}
	}
	int cityNameWidth6 = textwidth(plotName.c_str());
	int cityNameHeight6 = textheight(plotName.c_str());
	int cityNameX = 625 + (143 - cityNameWidth6) / 2;
	int cityNameY = 192 + (28 - cityNameHeight6) / 2 - 30;
	settextstyle(13, 0, _T("黑体"));
	outtextxy(cityNameX, cityNameY, plotName.c_str());

	std::string auctionValueText = "拍卖价值："; // 加入一行文字，代表拍卖价值
	int auctionValueTextWidth = textwidth(auctionValueText.c_str());
	int auctionValueTextHeight = textheight(auctionValueText.c_str());

	int auctionValueTextX = 625 + (143 - auctionValueTextWidth) / 2 - 20;
	int auctionValueTextY = 220 + (29 - cityNameHeight6) / 2;
	settextstyle(13, 0, _T("宋体"));

	outtextxy(auctionValueTextX, auctionValueTextY, auctionValueText.c_str());
	outtextxy(auctionValueTextX + 80, auctionValueTextY, std::to_string(moneyToAdd).c_str());

	yes_Button_ = new Button(619, 293, 44, 20, "拍卖"); // 根据需要调整坐标和尺寸
	no_Button_ = new Button(733, 293, 44, 20, "放弃");   // 根据需要调整坐标和尺寸

	//fillrectangle(593, 124, 593 + 207, 124 + 202);//文本框的大小



}



//负责人：
//功能：绘制各个格子的图片
//	绘制矩形 
//  绘制文字	矩形中根据name写出地块名称	
//参数：NULL
//返回值:NULL
void AuctionPlot::Draw()//绘制地块
{
	rectangle(xywh_[0], xywh_[1], xywh_[0] + xywh_[2], xywh_[1] + xywh_[3]);//文本框的大小
	setcolor(RGB(215, 215, 215));
	int textWidth3 = textwidth(_T(name_.c_str()));
	int textHeight3 = textheight(_T(name_.c_str()));

	int textX3 = xywh_[0] + (xywh_[2] - textWidth3) / 2;
	int textY3 = xywh_[1] + (xywh_[3] - textHeight3) / 2;
	settextstyle(12, 0, _T("宋体"));
	outtextxy(textX3, textY3, _T(name_.c_str()));

	// 加载图像
	IMAGE img_auction;
	loadimage(&img_auction, "asserts/auction.png", xywh_[2], xywh_[3], true);


	int imgX = xywh_[0] + 1;
	int imgY = xywh_[1] + 1;

	// 绘制图像
	putimage(imgX, imgY, &img_auction);

	//FlushBatchDraw();
}

bool AuctionPlot::inWindow(const ExMessage& msg, Player& player)
{
	// 从 MOUSEMSG 对象中提取需要的信息，赋值给 ExMessage 对象
	if (msg.message == WM_LBUTTONDOWN) {
		if (yes_Button_->inArea(msg)) {
			cout << "1" << endl;
			GoAuction(player); // 玩家进入拍卖，调用GoAuction()函数
			return true;
		}
		else if (no_Button_->inArea(msg))
		{
			cout << "2" << endl;
			return true;
		}
	}

	return false;
}

//负责人:
//功能:当玩家踩到这个格子时，绘制特殊事件（拍卖）弹窗
/* 	while (1)
	{
		peekmessage(&msg);接收消息
		if (msg.message == WM_LBUTTONDOWN)//鼠标左键按下
		{
			if(Button::inArea(int m.x, int m.y, int x, int y, int w, int h) //判断鼠标的点击是否在“拍卖”按钮区域之中
					//x y w h为“拍卖”按钮区域相关
					//如果是 则 玩家进入拍卖。 调用GoAuction()函数
			{
				GoAuction()；
				break;
			}
			if(Button::inArea(int m.x, int m.y, int x, int y, int w, int h) //判断鼠标的点击是否在“ 退出”按钮区域之中
					//x y w h为“ 退出”按钮区域相关
					//如果是 则不做任何处理
			{
				break;
			}
		}
	}
*/
//参数：无
//返回值：无
//void AuctionPlot::Event(std::list<Plot*>& game_map, Player& player, const ExMessage& msg) // 当特殊格子触发时的特殊事件弹窗判断区域
//{
//	bool continueLoop = true; // 设置一个标志变量来控制循环
//	while (continueLoop)
//	{
//		// 从 MOUSEMSG 对象中提取需要的信息，赋值给 ExMessage 对象
//		if (msg.message == WM_LBUTTONDOWN) {
//			if (yes_Button_->inArea(msg)) {
//				cout << "1" << endl;
//				GoAuction(game_map, player); // 玩家进入拍卖，调用GoAuction()函数
//				continueLoop = false;
//				//break;
//			}
//			else if (no_Button_->inArea(msg))
//			{
//				cout << "2" << endl;
//				continueLoop = false; // 标志变量设为false，跳出循环
//				//break;
//			}
//
//		}
//
//	}
//}


//MOUSEMSG msg = GetMouseMsg();
//	if (Button::inArea(msg.x>899 && msg.x< 899 + 44 && msg.y>368 && msg.y< 368+20 && msg.uMsg == WM_LBUTTONDOWN)) // 判断鼠标的点击是否在“拍卖”按钮区域之中
//	{
//		GoAuction(); // 玩家进入拍卖，调用GoAuction()函数
//		break;
//	}
//	if (Button::inArea(msg.x > 1013 && msg.x < 1013 + 44 && msg.y>368 && msg.y < 368 + 20 && msg.uMsg == WM_LBUTTONDOWN)) // 判断鼠标的点击是否在“退出”按钮区域之中
//	{
//		break; // 不做任何处理
//	}


//	if (msg.x > 899 && msg.x < 899 + 44 && msg.y>368 && msg.y < 368 + 20 && msg.message == WM_LBUTTONDOWN)
//	{
//		cout << "1" << endl;
//		GoAuction(); // 玩家进入拍卖，调用GoAuction()函数
//		//break;
//		//return true;
//	}
//	else if (msg.x > 1013 && msg.x < 1013 + 44 && msg.y>368 && msg.y < 368 + 20 && msg.message == WM_LBUTTONDOWN) {
//		cout << "2" << endl;
//		//break;
//	}
//
//
//	//return false;
//}
//	


	//rectangle(899, 368, 899 + 44, 368 + 20);//拍卖按钮大小
	//
	//int textWidth1 = textwidth(_T("拍卖"));
	//int textHeight1 = textheight(_T("拍卖"));

	//int textX1 = 899 + (44 - textWidth1) / 2;
	//int textY1 = 368 + (20 - textHeight1) / 2;

	//settextstyle(12, 0, _T("宋体"));
	//outtextxy(textX1, textY1, _T("拍卖"));

	//rectangle(1013, 368, 1013 + 44,  368 + 20);//放弃按钮大小

	//int textWidth2 = textwidth(_T("放弃"));
	//int textHeight2 = textheight(_T("放弃"));

	//int textX2 = 1013 + (44 - textWidth2) / 2;
	//int textY2 = 368 + (20 - textHeight2) / 2;

	//settextstyle(12, 0, _T("宋体"));
	//outtextxy(textX2, textY2, _T("放弃"));