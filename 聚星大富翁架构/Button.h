#pragma once
#include <string>
#include <graphics.h>
// ��ť
class Button
{
public:
	int x_, y_;          // ��ť���Ͻ�����
	int width_,height_; // ��ť���
	std::string text;

	Button();
	Button(int x, int y, int w, int h, const char* text);


	void button(int x, int y, int w, int h, const char* text);
	bool inArea(const ExMessage& msg);//�жϰ�ť�Ƿ�������֮�У����ұ����
	bool inArea(int mx, int my);
	
	void button(int x, int y, int w, int h, const char* text, LPCTSTR btn_url, COLORREF color);
	void button(int x, int y, int w, int h, const char* text, LPCTSTR btn_url);
};
		