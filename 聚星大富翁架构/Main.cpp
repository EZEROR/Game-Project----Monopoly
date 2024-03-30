#include <iostream>
#include <vector>
#include "../聚星大富翁架构/interface/Interface.h"
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include "Globals.h"


using namespace std;



void Init(); // 初始化游戏数据+画布


int main()
{

	srand((unsigned)time(0));			//生成随机种子
	Init();								// 初始化图形模式

	MainInterface main_interface;		//界面变量
	RoleInterface role_interface;		//绘制角色界面


	/*_______绘制主界面加切屏操作_____*/
	main_interface.Run();
	//==============================//


	getchar();							//防止崩溃

	// 关闭图形模式
	closegraph();
	return 0;

}



void Init()
{
	initgraph(1080, 600, SHOWCONSOLE);
	//去掉字体的背景颜色
	setbkmode(TRANSPARENT);
	setbkcolor(RGB(122, 122, 122));
	cleardevice();
}




