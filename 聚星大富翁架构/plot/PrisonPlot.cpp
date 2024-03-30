#include <graphics.h>
#include <string>
#include "Plot.h"
#include "../Tools.h"

//������:
//����:���������¼�������������		
// 
//������
//����ֵ��
//
void PrisonPlot::DrawWindow(Player& player)
{
	if (!player.prison_flag_)
	{
		IMAGE Gwidget;
		loadimage(&Gwidget, "Images/Gameinterface/Widget.png");
		putimagePNG(550, 110, &Gwidget);
		//���������ɫ
		setfillcolor(WHITE);
		//����//����һ������//�����
		int p_x = 593, p_y = 124, p_w = 207, p_h = 202;
		//fillrectangle(p_x, p_y, p_x + p_w, p_y + p_h);
		//����
		int p_x_t = 634, p_y_t = 127, p_w_t = 124, p_h_t = 21;
		setfillcolor(RGB(230, 231, 232));
		fillroundrect(p_x_t, p_y_t, p_x_t + p_w_t, p_y_t + p_h_t, 5, 5);
		char p_text[] = "����";
		//settextstyle(10,0,"΢���ź�");
		int hSpace = (p_w_t - textwidth(p_text)) / 2;
		int vSpace = (p_h_t - textheight(p_text)) / 2;
		settextcolor(BLACK);
		outtextxy(p_x_t + hSpace, p_y_t + vSpace, p_text);
		//����ͼƬ
		IMAGE image;
		loadimage(&image, _T("asserts/����(1).jpg"));
		putimage(670, 164, &image);//���ͼƬ

		//��ť

		//settextcolor(WHITE);//������Ϸ��ť��ɫΪ��ɫ
		yes_Button_->button(725, 232, 49, 20, "��ǰ���ͣ�150����");
		no_Button_->button(620, 232, 49, 20, "�ܾ�֧��");
		/**/IMAGE image1; IMAGE image2;
		loadimage(&image1, _T("asserts/��ǰ����(1).jpg"));//��ǰ���ͣ�150����
		loadimage(&image2, _T("asserts/�ܾ�֧��(1).jpg"));//�ܾ�֧��
		putimage(725, 232, &image1);//���ͼƬ
		putimage(620, 232, &image2);//���ͼƬ

		//��������
		settextstyle(18, 0, "΢���ź�");
		settextcolor(BLACK);
		outtextxy(620, 275, "���������ֹͣ�ж����غ�");
		outtextxy(620, 298, "�ڼ��Լ������޷���ȡͨ�з�");

		//FlushBatchDraw();
	}

}

/*

*/
PrisonPlot::PrisonPlot(int x, int y, int w, int h) :Plot(x, y, w, h)
{
	this->name_ = "����";
	this->xywh_[0] = x;
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;

	this->yes_Button_ = new Button();//���ڱ��� window�е�ȷ�ϰ�ť
	this->no_Button_ = new Button();// ���ڱ��� window�е�ȡ����ť

	this->flag_window_ = true;

}

PrisonPlot::~PrisonPlot()
{
	delete yes_Button_;
	delete no_Button_;
}


void PrisonPlot::Draw() //����
{
	IMAGE image;

	loadimage(&image, _T("asserts/����(1).jpg"));

	//���ͼƬ
	putimage(xywh_[0], xywh_[1], &image);
}


//�ж����Ŀǰ�Ƿ��ڵ�����
bool PrisonPlot::inWindow(const ExMessage& msg, Player& player)//0δ�����1�������,2����˳�
{
	//ֻ��playerվ�ڵ�ǰ��������Ż�������
	if (!player.prison_flag_)
	{

		//���Ƶ���

			//��ť1����ǰ����
			//��ť2. �ܾ�֧��
		if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
		{
			if (player.cash_ > 150) 
			{
				player.cash_ -= 150;
			}
			else
			{
				settextstyle(48, 0, "΢���ź�");
				settextcolor(RED);
				outtextxy(10, 10, "�ʽ𲻹���");
				//ͣ������
				player.prison_flag_ = 3;
			}
			return true;
		}
		//��ť2���˳�
		if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg))
		{
			//ͣ������
			player.prison_flag_ = 3;
			return true;
		}
		return false;
	}
	return true;
}
