#include "Plot.h"
#include<easyx.h>

BirthPointPlot::BirthPointPlot(int x, int y, int w, int h) :Plot(x, y, w, h)
{
	this->name_ = "������";
	this->xywh_[0] = x;
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;


}

BirthPointPlot::~BirthPointPlot()
{

}

//�����ˣ�
//���ܣ����Ƹ������ӵ�ͼƬ
//	���ƾ��� 
//  ��������	�����и���nameд���ؿ�����	
//������NULL
//����ֵ:NULL
void BirthPointPlot::Draw()//����
{
	rectangle(xywh_[0], xywh_[1], xywh_[0] + xywh_[2], xywh_[1] + xywh_[3]);//�ı���Ĵ�С
	setcolor(RGB(215, 215, 215));
	int textWidth4 = textwidth(_T("������"));
	int textHeight4 = textheight(_T("������"));

	int textX4 = xywh_[0] + (xywh_[2] - textWidth4) / 2 + 5;
	int textY4 = xywh_[1] + (xywh_[3] - textHeight4) / 2;
	settextstyle(12, 0, _T("����"));
	outtextxy(textX4, textY4, _T("������"));




	// ����ͼ��
	IMAGE img_birth;
	loadimage(&img_birth, "asserts/birth.png", xywh_[2], xywh_[3], true);


	int imgX = xywh_[0] + 1;
	int imgY = xywh_[1] + 1;

	// ����ͼ��
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