#include <iostream>
#include <vector>
#include "../���Ǵ��̼ܹ�/interface/Interface.h"
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include "Globals.h"


using namespace std;



void Init(); // ��ʼ����Ϸ����+����


int main()
{

	srand((unsigned)time(0));			//�����������
	Init();								// ��ʼ��ͼ��ģʽ

	MainInterface main_interface;		//�������
	RoleInterface role_interface;		//���ƽ�ɫ����


	/*_______�������������������_____*/
	main_interface.Run();
	//==============================//


	getchar();							//��ֹ����

	// �ر�ͼ��ģʽ
	closegraph();
	return 0;

}



void Init()
{
	initgraph(1080, 600, SHOWCONSOLE);
	//ȥ������ı�����ɫ
	setbkmode(TRANSPARENT);
	setbkcolor(RGB(122, 122, 122));
	cleardevice();
}




