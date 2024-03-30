#include "Plot.h"
#include "../Tools.h"



HousePlot::HousePlot(int x, int y, int w, int h) :Plot(x, y, w, h)
{

}

//��
HousePlot::HousePlot(int x, int y, int w, int h, int prices[3], int sell_prices[3], int pass_prices[3], std::string name, std::string text)
	: Plot(x, y, w, h)
{
	//����
	this->name_ = name;

	//��ʼ������۸�, ���ۼ۸�, ͨ��·��
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

	// ��ť����ʹ��Ĭ�Ϲ���, �����������Draw��ָ��
	this->yes_Button_ = new Button;

	this->no_Button_ = new Button;

}

HousePlot::~HousePlot()
{

}

//�����ˣ�
//���ܣ����Ƹ������ӵ�ͼƬ
//	���ƾ��� 
//  ��������	�����и���nameд���ؿ�����	���磺���Ϻ�����
//				������ɫ����owner_ID:������̺ڷֱ��ʾ1234����ҡ������ˡ�
// ���ƹ�·�ѻ�����ʱ��������
// 
//����:��
void HousePlot::Draw()
{


	//���ư�ɫ���ӱ���
	setfillcolor(WHITE);
	solidrectangle(xywh_[0], xywh_[1], xywh_[0] + xywh_[2], xywh_[1] + xywh_[3]);


	//���������

	setbkmode(TRANSPARENT);//����͸��ģʽ, ���������ڵ�

	COLORREF color;//����id������ɫ
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
	settextcolor(color);//����owner_id����������ɫ
	outtextxy(xywh_[0] + 13, xywh_[1] + 20, city_name);//��Ҫ���¶�λ�ı�λ��

	//���ƻ�ɫ�۸����
	setfillcolor(color);
	solidrectangle(xywh_[0], xywh_[1], xywh_[0] + 47, xywh_[1] + 13);//52,13Ҳ��Ҫ�������

	//����۸��ı�
	settextcolor(WHITE);
	string money = std::to_string(this->price_[level_]);
	LPCSTR price_text = money.c_str();
	outtextxy(xywh_[0] + 15, xywh_[1] + 2, price_text);//��Ҫ���¶�λ�ı�λ��
}


//�����ˣ�
//���ܣ����Ƶ���
//	���ƾ��� 
//  ��������	
//	����������������Ƶ�����
//	��������ˣ����ƹ��򵯴�
//  �����������δ������������������
//����:��
//����ֵ:NULL
void HousePlot::DrawWindow(Player& player)
{
	IMAGE Gwidget;

	loadimage(&Gwidget, "Images/Gameinterface/Widget.png");

	IMAGE dbtn;
	LPCTSTR dbtn_url = "Images/Gameinterface/dbtn.png";

	if (level_ == 2)//�����2��, ����ʾ����
	{
		return;
	}

	else if (!owner_ID_)//˵��û������, ���ƹ��򵯴�
	{
		setfillcolor(WHITE);
		solidrectangle(593, 124, 593 + 207, 131 + 202);
		putimagePNG(550, 110, &Gwidget);

		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		//���Ʊ��� "���� ������"

		std::string title = "����" + this->name_;
		LPCSTR title_text = title.c_str();
		outtextxy(666, 129, title_text);//��Ҫ���¶�λ�ı�λ��

		//���Ʊ���ͷ: ���еȼ�, ͨ�з�, ����۸�

		outtextxy(603, 154, "���еȼ�");//��Ҫ���¶�λ�ı�λ��
		outtextxy(677, 154, "ͨ�з�");//��Ҫ���¶�λ�ı�λ��
		outtextxy(740, 154, "����۸�");//��Ҫ���¶�λ�ı�λ��


		int buy_price = 0;
		int pass_price = 0;
		char num[20];
		//��һ��: �ȼ�1, ͨ�з���ֵ, �������

		outtextxy(612, 177, "�ȼ�1");//��Ҫ���¶�λ�ı�λ��

		pass_price = this->pass_price_[0];
		sprintf(num, "%d", pass_price);
		outtextxy(689, 177, num);//��Ҫ���¶�λ�ı�λ��

		buy_price = this->price_[0];
		sprintf(num, "%d", buy_price);
		outtextxy(755, 177, num);//��Ҫ���¶�λ�ı�λ��


		//�ڶ���: �ȼ�2, ͨ�з���ֵ, �������

		outtextxy(612, 202, "�ȼ�2");//��Ҫ���¶�λ�ı�λ��

		pass_price = this->pass_price_[1];
		sprintf(num, "%d", pass_price);
		outtextxy(689, 202, num);//��Ҫ���¶�λ�ı�λ��

		buy_price = this->price_[1];
		sprintf(num, "%d", buy_price);
		outtextxy(762, 202, num);//��Ҫ���¶�λ�ı�λ��

		//������: �ȼ�3, ͨ�з���ֵ, �������

		outtextxy(612, 225, "�ȼ�3");

		pass_price = this->pass_price_[2];
		sprintf(num, "%d", pass_price);
		outtextxy(686, 225, num);//��Ҫ���¶�λ�ı�λ��

		buy_price = this->price_[2];
		sprintf(num, "%d", buy_price);
		outtextxy(759, 225, num);//��Ҫ���¶�λ�ı�λ��

		outtextxy(612, 251, "�����ͨ�з���");//��Ҫ���¶�λ�ı�λ��

		//�����ͨ�з���:money

		sprintf(num, "%d", this->pass_price_[0]);
		outtextxy(727, 251, num);

		//��ʾ�������
		outtextxy(612, 279, "�������");

		sprintf(num, "%d", this->price_[0]);
		outtextxy(617, 299, num);//��Ҫ���¶�λ�ı�λ��

		//���ýӿ�, ����,��λ��ť
		yes_Button_->button(689, 279, 48, 40, "����");//��Ҫ���¶�λ��ťλ��
		no_Button_->button(744, 279, 48, 40, "ȡ��");//��Ҫ���¶�λ��ťλ��
		//loadimage(&dbtn, "Images/Gameinterface/dbtn1.png");
		//putimagePNG(619, 263, &dbtn);
	}
	else if (owner_ID_ == player.ID_ && level_ != 2)//������������
	{
		setfillcolor(WHITE);
		solidrectangle(593, 124, 593 + 207, 131 + 202);
		putimagePNG(550, 110, &Gwidget);
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		//���Ʊ��� "���� ������"

		std::string title = "����" + this->name_;
		LPCSTR title_text = title.c_str();
		outtextxy(666, 129, title_text);//��Ҫ���¶�λ�ı�λ��

		//���Ʊ���ͷ: ���еȼ�, ͨ�з�, ����۸�

		outtextxy(603, 154, "���еȼ�");//��Ҫ���¶�λ�ı�λ��
		outtextxy(677, 154, "ͨ�з�");//��Ҫ���¶�λ�ı�λ��
		outtextxy(740, 154, "����۸�");//��Ҫ���¶�λ�ı�λ��


		int buy_price = 0;
		int pass_price = 0;
		char num[20];
		//��һ��: �ȼ�1, ͨ�з���ֵ, �������

		outtextxy(612, 177, "�ȼ�1");//��Ҫ���¶�λ�ı�λ��

		pass_price = this->pass_price_[0];
		sprintf(num, "%d", pass_price);
		outtextxy(689, 177, num);//��Ҫ���¶�λ�ı�λ��

		buy_price = this->price_[0];
		sprintf(num, "%d", buy_price);
		outtextxy(755, 177, num);//��Ҫ���¶�λ�ı�λ��


		//�ڶ���: �ȼ�2, ͨ�з���ֵ, �������

		outtextxy(612, 202, "�ȼ�2");//��Ҫ���¶�λ�ı�λ��

		pass_price = this->pass_price_[1];
		sprintf(num, "%d", pass_price);
		outtextxy(689, 202, num);//��Ҫ���¶�λ�ı�λ��

		buy_price = this->price_[1];
		sprintf(num, "%d", buy_price);
		outtextxy(762, 202, num);//��Ҫ���¶�λ�ı�λ��

		//������: �ȼ�3, ͨ�з���ֵ, �������

		outtextxy(612, 225, "�ȼ�3");

		pass_price = this->pass_price_[2];
		sprintf(num, "%d", pass_price);
		outtextxy(686, 225, num);//��Ҫ���¶�λ�ı�λ��

		buy_price = this->price_[2];
		sprintf(num, "%d", buy_price);
		outtextxy(759, 225, num);//��Ҫ���¶�λ�ı�λ��

		outtextxy(612, 251, "�����ͨ�з���");//��Ҫ���¶�λ�ı�λ��

		//�����ͨ�з���:money

		sprintf(num, "%d", this->pass_price_[level_ + 1]);
		outtextxy(727, 251, num);

		//��ʾ�������
		outtextxy(612, 279, "��������");

		sprintf(num, "%d", this->price_[level_ + 1]);
		outtextxy(617, 299, num);//��Ҫ���¶�λ�ı�λ��

		//���ýӿ�, ����,��λ��ť
		yes_Button_->button(689, 279, 48, 40, "����");//��Ҫ���¶�λ��ťλ��
		no_Button_->button(744, 279, 48, 40, "ȡ��");//��Ҫ���¶�λ��ťλ��
		putimagePNG(619, 263, &dbtn);
		//loadimage(&dbtn, "Images/Gameinterface/dbtn1.png");
		//putimagePNG(619, 263, &dbtn);
	}

	return;
}



/*
	�����ˣ�
	���ܣ�
			ԭ�ػ�ȡ��ǰ������Ϣ
			�� msg��Ϣ ����������ť�� isArea��
			ͨ���ж������ִ�ж�Ӧ�Ĳ�����
				ѡ����������������ı�level_ owner_��ID_���Ƹ���ص�ֵ
				ѡ��ȡ����ֱ��return
	����ֵ��NULL
	������NULL
*/
void HousePlot::Event(Player& player)
{

	return;
}


/*
	���ܣ������ﵽ��˵ؿ���жϴ˵ؿ�������ˣ����������֮�أ��ж���������ĸ���ť������X����
			����������˵ĵؿ飬�ؿ����˼�Ǯ���Լ���Ǯ��
		��ǰ�������1~12�����ӣ�����player���RandomMove������
	����ֵ��NULL
	������NULL
*/
//�ж����Ŀǰ�Ƿ��ڵ�����
bool HousePlot::inWindow(const ExMessage& msg, Player& player)//0δ�����1�������,2����˳�
{


	//�����ﵽ��˵ؿ���жϴ˵ؿ�������ˣ�
	if (owner_ID_ == 0)
	{
		//	�ж���������ĸ���ť������X��
		//��ť1������
		if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
		{
			if (player.cash_ > price_[level_]) {
				player.cash_ -= this->price_[this->level_];//��ȥ��Ӧ�µȼ�������
				this->level_++;//����
				this->owner_ID_ = player.ID_;//����ӵ����ID
				owner = &player;
			}
			else
			{
				//settextstyle(48, 0, "΢���ź�");
				settextcolor(RED);
				outtextxy(10, 10, "�ʽ𲻹���");
			}
			return true;
		}
		//��ť2���˳�
		if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg))
		{
			return true;
		}
		return false;
	}
	else if (owner_ID_ != 0 && owner_ID_ == player.ID_ && level_ != 2)
	{
		//	�ж���������ĸ���ť������X��
		//��ť1������
		if (msg.message == WM_LBUTTONDOWN && yes_Button_->inArea(msg))
		{
			if (player.cash_ > price_[level_])
			{
				player.cash_ -= this->price_[this->level_];//��ȥ��Ӧ�µȼ�������
				this->level_++;//����
				//this->owner_ID_ = player.ID_;//����ӵ����ID
				//owner = &player;
			}
			else
			{
				//settextstyle(48, 0, "΢���ź�");
				settextcolor(RED);
				outtextxy(10, 10, "�ʽ𲻹���");
				cout << "Ǯ����" << endl;
			}
			return true;
		}
		//��ť2���˳�
		if (msg.message == WM_LBUTTONDOWN && no_Button_->inArea(msg)) {
			return true;
		}
		return false;
	}

	//����������˵ĵؿ飬�ؿ����˼�Ǯ���Լ���Ǯ��
	else
	{
		owner->UpdateWealth(pass_price_[level_], player);
		/*owner->cash_ += pass_price_[level_];
		player.cash_ -= pass_price_[level_];*/
	}
	return true;

}
