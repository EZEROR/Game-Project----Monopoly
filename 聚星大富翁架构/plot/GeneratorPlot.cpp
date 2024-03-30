#include "Plot.h"


GeneratorPlot::GeneratorPlot(int x, int y, int w, int h) :Plot(x, y, w, h)//std::vector<Player>&player_��Ϊ��ʵ�ָ�������ҹ�·��
//GeneratorPlot::GeneratorPlot(int x, int y, int w, int h) : Plot(x, y, w, h)
{
	this->price_[3] = { 250 }; // ������洢��ͬ�ȼ����еؿ�ļ۸�
	this->name_ = "����վ";
	this->xywh_[0] = x;// ����������
	this->xywh_[1] = y;
	this->xywh_[2] = w;
	this->xywh_[3] = h;
	this->yes_Button_ = new Button();// ���ڱ��� window�е�ȷ�ϰ�ť
	this->no_Button_ = new Button();//  ���ڱ��� window�е�ȡ����ť
	this->flag_window_ = true;
}

GeneratorPlot::~GeneratorPlot()
{
	delete yes_Button_;
	delete no_Button_;

}


//���Ƹ���
void GeneratorPlot::Draw()
{
	IMAGE image;
	if (owner_ID_ == 0) {
		//��ʾ��ͬͼƬ
		loadimage(&image, _T("asserts/���˷���վ(1).jpg"));
	}
	else if (owner_ID_ == 1) {
		loadimage(&image, _T("asserts/��ɫ����վ(1).jpg"));
	}
	else if (owner_ID_ == 2) {
		loadimage(&image, _T("asserts/��ɫ����վ(1).jpg"));
	}
	else if (owner_ID_ == 3) {
		loadimage(&image, _T("asserts/��ɫ����վ(1).jpg"));
	}
	else if (owner_ID_ == 4) {
		loadimage(&image, _T("asserts/��ɫ����վ(1).jpg"));
	}
	//���ͼƬ
	putimage(xywh_[0], xywh_[1], &image);
}






//���Ƶ���
void GeneratorPlot::DrawWindow(Player& player)
{
	if (!owner_ID_)
	{
		IMAGE img_victory;
		loadimage(&img_victory, "Images/ʤ������.png", 207, 202, true);
		int imgX = 593 + 1;
		int imgY = 124 + 1;

		// ����ͼ��
		putimage(imgX, imgY, &img_victory);

		//���������ɫ
		setfillcolor(WHITE);
		//����//����һ������//�����
		//int g_x = 593, g_y = 124, g_w = 207, g_h = 207;
		//fillrectangle(g_x, g_y, g_x + g_w, g_y + g_h);
		//����վ
		//int g_x_t = 634, g_y_t = 127;// , g_w_t = 124, g_h_t = 21;
		//outtextxy(g_x_t, g_y_t, "����վ");
		int g_x_t = 634, g_y_t = 127, g_w_t = 124, g_h_t = 21;
		setfillcolor(RGB(230, 231, 232));
		fillroundrect(g_x_t, g_y_t, g_x_t + g_w_t, g_y_t + g_h_t, 5, 5);
		char g_text[] = "����վ";
		//settextstyle(10,0,"΢���ź�");
		int hSpace = (g_w_t - textwidth(g_text)) / 2;
		int vSpace = (g_h_t - textheight(g_text)) / 2;
		settextcolor(BLACK);
		outtextxy(g_x_t + hSpace, g_y_t + vSpace, g_text);


		settextcolor(BLACK);//������Ϸ��ť��ɫΪ��ɫ
		outtextxy(677, 154, "ͨ�з�");
		outtextxy(740, 154, "����۸�");
		outtextxy(689, 177, "55");
		outtextxy(755, 177, "250");

		//��ť
		yes_Button_->button(602, 279, 119, 40, "����250|����");
		no_Button_->button(744, 279, 48, 40, "�ܾ�");

	}

	return;

}




/*
	���ܣ������ﵽ��˵ؿ���жϴ˵ؿ�������ˣ����������֮�أ��ж���������ĸ���ť������X����
			����������˵ĵؿ飬�ؿ����˼�Ǯ���Լ���Ǯ��

	����ֵ��NULL
	������NULL
*/
//�ж����Ŀǰ�Ƿ��ڵ�����
bool GeneratorPlot::inWindow(const ExMessage& msg, Player& player)//0δ�����1�������,2����˳�
{
	//�����ﵽ��˵ؿ���жϴ˵ؿ�������ˣ�
	//��������ˣ����ƹ��򵯴�
	if (owner_ID_ == 0)
	{
		//	�ж���������ĸ���ť������X��
		//��ť1������
		if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
		{
			if (player.cash_ > 250) {
				this->owner_ID_ = player.ID_;//������������
				owner = &player;
				player.cash_ -= 250;
				this->flag_window_ = false;

			}
			else
			{
				settextstyle(48, 0, "΢���ź�");
				settextcolor(RED);
				outtextxy(10, 10, "�ʽ𲻹���");
			}

			if (!player.generator_flag_)
			{
				player.generator_flag_ = 1;//�����������ˣ���ͣ��һ��
			}

			return true;
		}
		//��ť2���˳�
		if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg))
		{
			if (!player.generator_flag_)
			{
				player.generator_flag_ = 1;//�����������ˣ���ͣ��һ��
			}
			return true;

		}
		return false;
	}
	//����������˵ĵؿ飬�ؿ����˼�Ǯ���Լ���Ǯ��
	else
	{
		owner->UpdateWealth(55, player);
	}


	return true;
}
