#include "Button.h"
#include <easyx.h>
#include <stdio.h>
#include "Tools.h"
using namespace std;

Button::Button()
{

}

Button::Button(int x, int y, int width, int height, const char* text):
	x_(x), y_(y), width_(width), height_(height)
{
	//���ư�ť
	setfillcolor(RGB(230, 231, 232));
	fillroundrect(x, y, x + width, y + height, 5, 5);
	//���ư�ť�ı�
	textwidth(10);
	int hSpace = (width - textwidth(text)) / 2;
	int vSpace = (height - textheight(text)) / 2;
	settextcolor(BLACK);//������Ϸ��ť��ɫΪ��ɫ
	outtextxy(x + hSpace, y + vSpace, text);
}


bool Button::inArea(const ExMessage& msg) //�жϰ�ť�Ƿ���ָ���ľ�������֮��
{
	if (msg.x > x_ && msg.x < x_ + width_ && msg.y>y_ && msg.y < y_ + height_ && msg.message == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}


bool Button::inArea(int mx, int my) //�жϰ�ť�Ƿ���ָ���ľ�������֮��
{
	if (mx > x_ && mx < x_ + width_ && my>y_ && my < y_ + height_)
	{
		return true;
	}


	return false;
}

//������ͨ��ť
void Button::button(int x, int y, int w, int h, const char* text) //������ڰ�ť�������Ұ�ť�������ִ�����º�����
{
	//�������滭��ǰ��ť����ֵ�����͸���������Ķ���
	this->x_ = x;
	this->y_ = y;
	this->width_ = w;
	this->height_ = h;

	//���ư�ť
	setfillcolor(RGB(230, 231, 232));
	fillroundrect(x, y, x + w, y + h, 5, 5);
	//���ư�ť�ı�
	textwidth(10);
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	settextcolor(BLACK);//������Ϸ��ť��ɫΪ��ɫ
	outtextxy(x + hSpace, y + vSpace, text);

}


//������ɫ��ť��ֻ����ɫ��
void Button::button(int x, int y, int w, int h, const char* text, LPCTSTR btn_url)
{
	//�������滭��ǰ��ť����ֵ�����͸���������Ķ���


	//���ư�ť
	//setfillcolor(RGB(230, 231, 232));
	//fillroundrect(x, y, x + w, y + h, 5, 5);
	//���ư�ť�ı�
	textwidth(10);
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	//LPCTSTR bbtn_url = "Images/bbtn.png";
	IMAGE btn;//��ťͼƬ
	settextstyle(24, 8, "����");
	loadimage(&btn, btn_url);
	/*putimage(x + hSpace - 120, y + vSpace - 30, &btn); */
	putimagePNG(x + hSpace - 120, y + vSpace - 30, &btn);
	settextcolor(RGB(200, 200, 200));//������Ϸ��ť��ɫΪ��ɫ
	outtextxy(x + hSpace, y + vSpace, text);
	this->x_ = x;
	this->y_ = y;
	this->width_ = w;
	this->height_ = h;
}



void Button::button(int x, int y, int w, int h, const char* text, LPCTSTR btn_url, COLORREF color)
{
	//�������滭��ǰ��ť����ֵ�����͸���������Ķ���


	//���ư�ť
	//setfillcolor(RGB(230, 231, 232));
	//fillroundrect(x, y, x + w, y + h, 5, 5);
	//���ư�ť�ı�
	textwidth(10);
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	//LPCTSTR bbtn_url = "Images/bbtn.png";
	IMAGE btn;//��ťͼƬ
	settextstyle(24, 8, "����");
	loadimage(&btn, btn_url);
	/*putimage(x + hSpace - 120, y + vSpace - 30, &btn); */
	putimagePNG(x + hSpace - 120, y + vSpace - 30, &btn);
	settextcolor(color);//������Ϸ��ť��ɫ
	outtextxy(x + hSpace, y + vSpace, text);
	this->x_ = x;
	this->y_ = y;
	this->width_ = w;
	this->height_ = h;
}




