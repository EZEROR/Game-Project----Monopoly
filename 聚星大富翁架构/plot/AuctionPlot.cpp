#include "Plot.h"
#include<iostream>
#include "../Tools.h"

using namespace std;
//�����и�����

	/*
		�����ˣ�
		���ܣ��������г��У��ҵ��û�ӵ�еĳ��У������������������������������2��3���ķ��Ӽ�ֵ���ֽ��ٵ���
		��������
		����ֵ����

	*/
AuctionPlot::AuctionPlot(int x, int y, int w, int h, std::list<Plot*>& game_map) :Plot(x, y, w, h) {
	// ʵ������ť��������λ�úͱ�ǩ
	this->name_ = "������";
	this->xywh_[0] = x;
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;
	this->yes_Button_ = new Button(619, 293, 44, 20, "����"); // ������Ҫ��������ͳߴ�
	this->no_Button_ = new Button(733, 293, 44, 20, "����");   // ������Ҫ��������ͳߴ�
	this->game_map = &game_map;

}
AuctionPlot::~AuctionPlot()
{
	delete yes_Button_;
	delete no_Button_;
}

//������ ��һ������������ �����ӵ�е�һ������,������������2��3���ķ��Ӽ�ֵ�Ľ�ң����֣�
void AuctionPlot::GoAuction(Player& player)
{
	// ���� Map ������ game_map_ ��Ա�����ҵ���һ���������ӵ�е�һ�����еĵؿ�
	int i = (*game_map).size();
	for (auto it = (*game_map).begin(); it != (*game_map).end(); ++it) {
		// �����ؿ��б��ҵ��������ӵ�е�һ�����еĵؿ�

		if ((*it)->owner_ID_ == player.ID_) {
			int moneyMultiplier = (rand() % 2 == 0) ? 2 : 3; // �������2��3
			int moneyToAdd = (*it)->sell_price_[(*it)->level_] * moneyMultiplier; // ��������Ŀ
			player.cash_ += moneyToAdd;
			break;
		}
		if (!i)
		{
			break;
		}
	}

}



//������:
//����:����Ҳȵ��������ʱ�����������¼�������������
//	   ��ҳ���Ҳ����һ�����Σ�����������
// 	   �����л��ƣ�
//							���������������֣�
// 
//		�˳������ư�ť��					���������ư�ť��
//		�������Լ���ӵ�е�һ�����е�����,������������������2��3���ķ��Ӽ�ֵ�Ľ��n�����֣���
//		�ٵ���//Player��ĺ�����UpdateWealth(n);// �����¼������ʽ� 		
//��������
//����ֵ����
//
void AuctionPlot::DrawWindow(Player& player)  //���������¼�����
{
	IMAGE img_victory;
	loadimage(&img_victory, "Images/ʤ������.png", 207, 202, true);
	int imgX = 593 + 1;
	int imgY = 124 + 1;

	// ����ͼ��
	putimage(imgX, imgY, &img_victory);

	setfillcolor(WHITE);
	//fillrectangle(593, 124, 593 + 207, 124 + 202);//�ı���Ĵ�С

	//int offsetX=200, offsetY=200; //��¼x��y��ƫ����

	//rectangle(634, 127, 634 + 124, 127 + 21);//���������ı���Ĵ�С

	int textWidth = textwidth(_T("��������"));
	int textHeight = textheight(_T("��������"));

	int textX = 634 + (124 - textWidth) / 2;
	int textY = 127 + (21 - textHeight) / 2;

	settextcolor(BLACK);
	settextstyle(15, 0, _T("����"));
	outtextxy(textX, textY, _T("��������"));

	//rectangle(619, 172, 619 + 155, 172 + 84);//�����ı���Ĵ�С


	//int cityNameWidth6 = textwidth("����");
	//int cityNameHeight6 = textheight("����");
	//int cityNameX = 619 + (155 - cityNameWidth6) / 2;
	//int cityNameY = 172 + (84 - cityNameHeight6) / 2 - 30;

	//settextstyle(17, 0, _T("����"));
	//outtextxy(cityNameX, cityNameY, "����");

	//std::string auctionValueText = "������ֵ��"; // ����һ�����֣�����������ֵ

	//// ����������ֵ���ֵĿ�Ⱥ͸߶�
	//int auctionValueTextWidth = textwidth(auctionValueText.c_str());
	//int auctionValueTextHeight = textheight(auctionValueText.c_str());

	//int auctionValueTextX = 619 + (155 - auctionValueTextWidth) / 2 - 20;
	//int auctionValueTextY = cityNameY + cityNameHeight6 + 40;

	//settextstyle(15, 0, _T("����"));
	//outtextxy(auctionValueTextX, auctionValueTextY, auctionValueText.c_str());



	std::string plotName = ""; // �ӵؿ�����ȡ����
	int moneyToAdd = 0; // ��ʼ��moneyToAdd����
	for (auto at = (*game_map).begin(); at != (*game_map).end(); ++at) {


		// �����ؿ��б��ҵ��������ӵ�е�һ�����еĵؿ�
		if (HousePlot* houseplot = dynamic_cast<HousePlot*>(*at)) {
			if (houseplot->owner_ID_ == player.ID_) {
				plotName = houseplot->name_;
				int moneyMultiplier = (rand() % 2 == 0) ? 2 : 3; // �������2��3
				moneyToAdd = (*at)->sell_price_[(*at)->level_] * moneyMultiplier; // ��������Ŀ  200
				break;
			}
		}
	}
	int cityNameWidth6 = textwidth(plotName.c_str());
	int cityNameHeight6 = textheight(plotName.c_str());
	int cityNameX = 625 + (143 - cityNameWidth6) / 2;
	int cityNameY = 192 + (28 - cityNameHeight6) / 2 - 30;
	settextstyle(13, 0, _T("����"));
	outtextxy(cityNameX, cityNameY, plotName.c_str());

	std::string auctionValueText = "������ֵ��"; // ����һ�����֣�����������ֵ
	int auctionValueTextWidth = textwidth(auctionValueText.c_str());
	int auctionValueTextHeight = textheight(auctionValueText.c_str());

	int auctionValueTextX = 625 + (143 - auctionValueTextWidth) / 2 - 20;
	int auctionValueTextY = 220 + (29 - cityNameHeight6) / 2;
	settextstyle(13, 0, _T("����"));

	outtextxy(auctionValueTextX, auctionValueTextY, auctionValueText.c_str());
	outtextxy(auctionValueTextX + 80, auctionValueTextY, std::to_string(moneyToAdd).c_str());

	yes_Button_ = new Button(619, 293, 44, 20, "����"); // ������Ҫ��������ͳߴ�
	no_Button_ = new Button(733, 293, 44, 20, "����");   // ������Ҫ��������ͳߴ�

	//fillrectangle(593, 124, 593 + 207, 124 + 202);//�ı���Ĵ�С



}



//�����ˣ�
//���ܣ����Ƹ������ӵ�ͼƬ
//	���ƾ��� 
//  ��������	�����и���nameд���ؿ�����	
//������NULL
//����ֵ:NULL
void AuctionPlot::Draw()//���Ƶؿ�
{
	rectangle(xywh_[0], xywh_[1], xywh_[0] + xywh_[2], xywh_[1] + xywh_[3]);//�ı���Ĵ�С
	setcolor(RGB(215, 215, 215));
	int textWidth3 = textwidth(_T(name_.c_str()));
	int textHeight3 = textheight(_T(name_.c_str()));

	int textX3 = xywh_[0] + (xywh_[2] - textWidth3) / 2;
	int textY3 = xywh_[1] + (xywh_[3] - textHeight3) / 2;
	settextstyle(12, 0, _T("����"));
	outtextxy(textX3, textY3, _T(name_.c_str()));

	// ����ͼ��
	IMAGE img_auction;
	loadimage(&img_auction, "asserts/auction.png", xywh_[2], xywh_[3], true);


	int imgX = xywh_[0] + 1;
	int imgY = xywh_[1] + 1;

	// ����ͼ��
	putimage(imgX, imgY, &img_auction);

	//FlushBatchDraw();
}

bool AuctionPlot::inWindow(const ExMessage& msg, Player& player)
{
	// �� MOUSEMSG ��������ȡ��Ҫ����Ϣ����ֵ�� ExMessage ����
	if (msg.message == WM_LBUTTONDOWN) {
		if (yes_Button_->inArea(msg)) {
			cout << "1" << endl;
			GoAuction(player); // ��ҽ�������������GoAuction()����
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

//������:
//����:����Ҳȵ��������ʱ�����������¼�������������
/* 	while (1)
	{
		peekmessage(&msg);������Ϣ
		if (msg.message == WM_LBUTTONDOWN)//����������
		{
			if(Button::inArea(int m.x, int m.y, int x, int y, int w, int h) //�ж����ĵ���Ƿ��ڡ���������ť����֮��
					//x y w hΪ����������ť�������
					//����� �� ��ҽ��������� ����GoAuction()����
			{
				GoAuction()��
				break;
			}
			if(Button::inArea(int m.x, int m.y, int x, int y, int w, int h) //�ж����ĵ���Ƿ��ڡ� �˳�����ť����֮��
					//x y w hΪ�� �˳�����ť�������
					//����� �����κδ���
			{
				break;
			}
		}
	}
*/
//��������
//����ֵ����
//void AuctionPlot::Event(std::list<Plot*>& game_map, Player& player, const ExMessage& msg) // ��������Ӵ���ʱ�������¼������ж�����
//{
//	bool continueLoop = true; // ����һ����־����������ѭ��
//	while (continueLoop)
//	{
//		// �� MOUSEMSG ��������ȡ��Ҫ����Ϣ����ֵ�� ExMessage ����
//		if (msg.message == WM_LBUTTONDOWN) {
//			if (yes_Button_->inArea(msg)) {
//				cout << "1" << endl;
//				GoAuction(game_map, player); // ��ҽ�������������GoAuction()����
//				continueLoop = false;
//				//break;
//			}
//			else if (no_Button_->inArea(msg))
//			{
//				cout << "2" << endl;
//				continueLoop = false; // ��־������Ϊfalse������ѭ��
//				//break;
//			}
//
//		}
//
//	}
//}


//MOUSEMSG msg = GetMouseMsg();
//	if (Button::inArea(msg.x>899 && msg.x< 899 + 44 && msg.y>368 && msg.y< 368+20 && msg.uMsg == WM_LBUTTONDOWN)) // �ж����ĵ���Ƿ��ڡ���������ť����֮��
//	{
//		GoAuction(); // ��ҽ�������������GoAuction()����
//		break;
//	}
//	if (Button::inArea(msg.x > 1013 && msg.x < 1013 + 44 && msg.y>368 && msg.y < 368 + 20 && msg.uMsg == WM_LBUTTONDOWN)) // �ж����ĵ���Ƿ��ڡ��˳�����ť����֮��
//	{
//		break; // �����κδ���
//	}


//	if (msg.x > 899 && msg.x < 899 + 44 && msg.y>368 && msg.y < 368 + 20 && msg.message == WM_LBUTTONDOWN)
//	{
//		cout << "1" << endl;
//		GoAuction(); // ��ҽ�������������GoAuction()����
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


	//rectangle(899, 368, 899 + 44, 368 + 20);//������ť��С
	//
	//int textWidth1 = textwidth(_T("����"));
	//int textHeight1 = textheight(_T("����"));

	//int textX1 = 899 + (44 - textWidth1) / 2;
	//int textY1 = 368 + (20 - textHeight1) / 2;

	//settextstyle(12, 0, _T("����"));
	//outtextxy(textX1, textY1, _T("����"));

	//rectangle(1013, 368, 1013 + 44,  368 + 20);//������ť��С

	//int textWidth2 = textwidth(_T("����"));
	//int textHeight2 = textheight(_T("����"));

	//int textX2 = 1013 + (44 - textWidth2) / 2;
	//int textY2 = 368 + (20 - textHeight2) / 2;

	//settextstyle(12, 0, _T("����"));
	//outtextxy(textX2, textY2, _T("����"));