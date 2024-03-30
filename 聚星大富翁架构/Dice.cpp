#include "Dice.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include "../���Ǵ��̼ܹ�/Tools.h"

using namespace std;

/*
	��ʼ�� ���ӵ�xywh���Լ�ͼƬ��Դ img��6���棬6��ͼ��
*/
Dice::Dice()
{
	for (int i = 0; i < 6; i++)
	{
		string path = "Images/dice/";					//ͼƬ���·��
		path.push_back('0' + i + 1); 					//ͼƬǰ׺
		path.append(".png");  							//ͼƬ��ʽ

		cout << path << " loaded!" << endl;				//����ͼƬ����

		loadimage(&img_[i], path.c_str(), 100, 100);	
	}
	putimagePNG(x_, y_, &img_[num_ - 1]);
}

Dice::~Dice()
{
}

/*
	�������ӵ�ͼƬ��putimage img[num-1]��
*/
void Dice::Draw()
{
	putimagePNG(x_, y_, &img_[num_ - 1]);
}

/*
	���� xywh���ж�����Ƿ������ӵ������ڣ����ҵ��
*/
bool Dice::inArea(const ExMessage& msg)
{
	if (msg.x > x_ && msg.x < x_ + width_ && msg.y > y_ && msg.y < y_ + height_)
	{
		if (msg.message == WM_LBUTTONDOWN)		//�����κ��ϴ�����Ƿ���,Ҫ����ΰ���,�ϴ�û��
		{
			cout << "Dice clicked!" << endl;
			return true;
		}
	}
	return false;
}

/*
	inArea �ж��ɹ��󣬱�����
	��ȡһ�����ֵ�����ҷ���
*/
int Dice::Random()
{
	num_ = rand() % 6 + 1;
	return num_;
}
