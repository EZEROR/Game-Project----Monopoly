#include <easyx.h>
#include <string>
#include "Plot.h"


//�����ˣ�
//���ܣ����Ƹ������ӵ�ͼƬ
//	���ƾ��� 
//  ��������	�����и���nameд���ؿ�����	
//������NULL
//����ֵ:NULL
void RandomPlot::Draw()
{
	IMAGE image;
	loadimage(&image, "asserts/RandomPlot.png");
	putimage(xywh_[0], xywh_[1], &image);
}

//������:
//����:���������¼�������¼�������//ÿ�ε������ӣ������ʾ��ͬ�¼�	
/*
	���ƾ���
	����0~19���������ʾ����¼�
	����¼��� �����֣�
	��ʾ����¼�,���������n��
	�ٵ���//Player��ĺ�����RandomMove��go������
	//UpdateWealth(n);// �����¼������ʽ� */
	//��������
	//����ֵ����
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
} //���������¼�����	

bool RandomPlot::inWindow(const ExMessage& msg, Player& player)
{
	//������Ȼ�ֺ����۳�300Ԫ�� / ���ƶ�12��

	//�����
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 3);
	Random = dist(gen);
	//������
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
		//δд����������·������
		//δд���ﵽ����һ������
		player.Move(randomNum);
		//�ƶ��д�����
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
	this->price_[3] = { 250 }; // ������洢��ͬ�ȼ����еؿ�ļ۸�
	this->name_ = "�������";
	this->xywh_[0] = x;// ����������
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;
	this->yes_Button_ = new Button();// ���ڱ��� window�е�ȷ�ϰ�ť
	this->no_Button_ = new Button(0, 0, 800, 450, "");//  ���ڱ��� window�е�ȡ����ť
	this->flag_window_ = true;

}

RandomPlot::~RandomPlot()
{
}



