#include "Interface.h"


using namespace std;

#include <mmsystem.h>//多媒体设备接口


#pragma comment(lib,"winmm.lib")


int tag = 2;//判断界面为哪个
bool musicSwitch = true;//音乐开启或关闭
int mci = 5;//判断哪首歌曲
int nbk = 2;

LPCTSTR bbtn_url = "Images/bbtn.png";
IMAGE bbtn;

LPCTSTR gsbk_url = "Images/gsbk.png";
IMAGE gsbk;

LPCTSTR gs2bk_url = "Images/gs2bk.png";
IMAGE gs2bk;


LPCTSTR gscbtn_url = "Images/hk2btn.png";
IMAGE gscbtn;

LPCTSTR music_url = "Images/music.png";
IMAGE music;

IMAGE gamebk[3];

IMAGE Rule;
int rule = 0;

////////////////////////////////////////
LPCTSTR set_selet = "Images/set_selet.png";
IMAGE set;
////////////////////////////////////////
LPCTSTR set_bk = "Images/set_bk2.png";
IMAGE setbk;
GamesetInterface::GamesetInterface()
{
	//_button_change_bgm = new Button(1,2,3,4,"啦啦啦");// 需要填入 xywh，显示的字
	//_button_change_bgm_mode = new Button(1,2,3,4,"啦啦啦");// 需要填入 xywh，显示的字
}

GamesetInterface::~GamesetInterface()
{

}

//// 音量控制
///*
//	负责人：
//	功能：监控鼠标的操作，鼠标左键按下音乐音量的滑动条可以进行调节声音的大小 /按下音乐开关的按钮就可以控制音乐播放还是关闭
//			每次点击之后都要重新绘画界面进行设置的更新
//			当键盘点击esc的时候，退出设置模式
//	参数：void
//	返回值：void
//
//
//*/
//void GamesetInterface::Volume()
//{
//
//
//}




/*
	负责人：
	功能：画一个矩形的音量设置图标,字体显示音乐音量
		  画一个矩形的音乐开关图标，字体显示音乐开关，根据musicSwitch控制音乐打开还是关闭
	参数：void
	返回值：void
*/
void GamesetInterface::BGM() //播放背景音乐以及开关
{
	mciSendString("open ./Music/基尼太没.mp3 alias mci[0]", 0, 0, 0);
	mciSendString("open ./Music/komorebi.mp3 alias mci[1]", 0, 0, 0);
	mciSendString("open ./Music/玫瑰少年.mp3 alias mci[2]", 0, 0, 0);
	mciSendString("open ./Music/星茶会.mp3 alias mci[3]", 0, 0, 0);
	mciSendString("open ./Music/Reunion.mp3 alias mci[4]", 0, 0, 0);
	mciSendString("open ./Music/Liyueday.mp3 alias mci[5]", 0, 0, 0);
	mciSendString("open ./Music/Regression.mp3 alias mci[6]", 0, 0, 0);


	string musicplay = "play mci[" + to_string(char(mci)) + "] repeat";
	LPCSTR musicplay0 = musicplay.c_str();
	string musicclose = "close mci[" + to_string(char(mci)) + "]";
	LPCSTR musicclose0 = musicclose.c_str();
	if (musicSwitch == true)
	{
		mciSendString(musicplay0, 0, 0, 0);
	}
	else
	{
		mciSendString(musicclose0, 0, 0, 0);
	}
}

/*
	把界面画出来
	tag == 0 画背景图选择界面
	tag == 1 画bgm选择界面
*/
void GamesetInterface::Draw()
{
	BeginBatchDraw();
	////////////////////////////////////////
	if (tag == 2)
	{///
		setbkmode(TRANSPARENT);
		rule = 0;
		////
		fillcircle(749, 20, 12);
		fillrectangle(300, 113, 520, 188);
		fillrectangle(300, 273, 520, 349);
		loadimage(&set, set_selet);
		loadimage(&setbk, set_bk);
		putimage(0, 0, &setbk);
		putimage(300, 113, &set);
		putimage(300, 273, &set);
		settextcolor(RGB(200, 230, 230));
		outtextxy(300 + 50, 113 + 30, _T("介绍及背景选择"));
		outtextxy(300 + 100, 273 + 30, _T("BGM"));
	}
	////////////////////////////////////////
	if (tag == 0)
	{
		setfillcolor(WHITE);
		setlinecolor(WHITE);
		loadimage(&gsbk, gsbk_url);
		//loadimage(&gscbtn, gscbtn_url);
		loadimage(&gs2bk, gs2bk_url);
		loadimage(&music, music_url);
		putimage(0, 0, &gsbk);
		fillcircle(749, 20, 12);
		fillrectangle(72, 57, 728, 359);
		fillrectangle(24, 170, 48, 230);
		fillrectangle(752, 170, 776, 230);
		/*fillrectangle(370, 390, 460, 420);*/
		setbkmode(WHITE);
		settextcolor(BLACK);
		outtextxy(745, 14, _T("X"));

		//确定按钮


		//outtextxy(400, 395, _T("确定"));
		outtextxy(760, 190, _T(">"));
		outtextxy(36, 190, _T("<"));

		/*loadimage(&img[0], "./Images/111.png", 656, 302);
		loadimage(&img[1], "./Images/222.png", 656, 302);
		loadimage(&img[2], "./Images/333.png", 656, 302);*/
		loadimage(&gamebk[0], "./Images/b1.jpg", 656, 302);
		loadimage(&gamebk[1], "./Images/b2.jpg", 656, 302);
		loadimage(&gamebk[2], "./Images/f.png", 656, 302);


		loadimage(&Rule, "Images/Rules.png", 656, 302);

		if (!rule)
		{
			putimage(72, 57, 656, 302, &Rule, 0, 0);
		}
		if (rule >= 1)

		{
			putimage(72, 57, 656, 302, &gamebk[nbk], 0, 0);
		}
		//putimagePNG(305, 385, &gscbtn);
	}
	else if (tag == 1)
	{///
		setbkmode(TRANSPARENT);
		//
		loadimage(&gs2bk, gs2bk_url);
		loadimage(&music, music_url);
		//
		putimage(0, 0, &gs2bk);
		setfillcolor(WHITE);
		setlinecolor(WHITE);
		fillcircle(749, 20, 12);
		/*fillrectangle(270, 100, 700, 350);*/
		putimage(350, 100, &music);
		fillrectangle(120, 100, 240, 150);
		fillrectangle(120, 300, 240, 350);

		settextcolor(RGB(200, 230, 230));
		loadimage(&bbtn, bbtn_url);
		putimagePNG(-50, 85, &bbtn);
		outtextxy(745, 14, _T("X"));

		outtextxy(140, 115, _T("切换BGM"));
		if (musicSwitch == true)
		{
			putimagePNG(-50, 285, &bbtn);
			outtextxy(140, 315, _T("关闭BGM"));
		}
		else
		{
			putimagePNG(-50, 285, &bbtn);
			outtextxy(140, 315, _T("开启BGM"));
		}
	}
	EndBatchDraw();
}

bool GamesetInterface::inArea(const ExMessage& msg)
{
	bool inArea_judge = true;
	/////
	if (tag == 2)
	{
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (((msg.x - 749) * (msg.x - 749) + (msg.y - 20) * (msg.y - 20)) <= (12.5) * (12.5))//关掉页面
			{
				inArea_judge = false;
				cleardevice();
				tag = 2;
				MainInterface M;
				M.Run();
			}
			else if (msg.x >= 300 && msg.x <= 522 && msg.y >= 113 && msg.y <= 190)
			{

				cleardevice();
				tag = 0;
				Draw();
			}
			else if (msg.x >= 300 && msg.x <= 522 && msg.y >= 273 && msg.y <= 348)
			{
				cleardevice();
				tag = 1;
				Draw();
			}
			break;
		default:
			break;
		}
	}
	//__——————————————————
	else if (tag == 0)
	{
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (((msg.x - 749) * (msg.x - 749) + (msg.y - 20) * (msg.y - 20)) <= (12.5) * (12.5))//关掉页面
			{
				inArea_judge = false;
				cleardevice();
				tag = 2;
				MainInterface M;
				M.Run();
			}
			else if (msg.x >= 24 && msg.x <= 48 && msg.y >= 170 && msg.y <= 230)
			{
				if (nbk == 0)
				{
					nbk = 2;

				}
				else
				{
					nbk--;

				}
				rule++;
				Draw();
			}
			else if (msg.x >= 752 && msg.x <= 776 && msg.y >= 170 && msg.y <= 230)
			{
				if (nbk == 2)
				{
					nbk = 0;
				}
				else
				{
					nbk++;
				}
				rule++;
				Draw();
			}
			/*else if (msg.x >= 370 && msg.x <= 460 && msg.y >= 390 && msg.y <= 420)
			{
				cleardevice();
				tag = 1;
				Draw();
			}*/
			break;
		default:
			break;
		}
	}
	else if (tag == 1)
	{
		string musicplay = "play mci[" + to_string(char(mci)) + "] repeat";
		LPCSTR musicplay0 = musicplay.c_str();
		string musicclose = "close mci[" + to_string(char(mci)) + "]";
		LPCSTR musicclose0 = musicclose.c_str();
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (((msg.x - 749) * (msg.x - 749) + (msg.y - 20) * (msg.y - 20)) <= (12.5) * (12.5))//关掉页面
			{
				inArea_judge = false;
				cleardevice();
				tag = 2;
				MainInterface M;
				M.Run();
			}
			else if (msg.x >= 120 && msg.x <= 240 && msg.y >= 100 && msg.y <= 150)//改变BGM
			{
				if (mci == 6)
				{
					mciSendString(musicclose0, 0, 0, 0);
					mci = 0;
					BGM();
				}
				else
				{
					mciSendString(musicclose0, 0, 0, 0);
					mci++;
					BGM();
				}
			}
			else if (msg.x >= 120 && msg.x <= 240 && msg.y >= 300 && msg.y <= 350)//开关BGM
			{
				musicSwitch = !musicSwitch;
				BGM();
				cleardevice();
				Draw();
			}
			break;
		default:
			break;
		}
	}
	return false;
}



/*
	如果 tag == 2 直接teturn
*/
void GamesetInterface::Run()
{
	initgraph(800, 450, EX_SHOWCONSOLE);
	setbkcolor(0xAAAAAA);
	cleardevice();
	Draw();
	BGM();
	ExMessage msg;
	bool inArea_judge = true;
	while (inArea_judge)
	{
		msg = getmessage(EX_MOUSE | EX_KEY);
		inArea(msg);
	}
	getchar();
}


