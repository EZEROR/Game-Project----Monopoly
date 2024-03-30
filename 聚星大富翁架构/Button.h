#pragma once
#include <string>
#include <graphics.h>
// 按钮
class Button
{
public:
	int x_, y_;          // 按钮左上角坐标
	int width_,height_; // 按钮宽高
	std::string text;

	Button();
	Button(int x, int y, int w, int h, const char* text);


	void button(int x, int y, int w, int h, const char* text);
	bool inArea(const ExMessage& msg);//判断按钮是否在区域之中，并且被点击
	bool inArea(int mx, int my);
	
	void button(int x, int y, int w, int h, const char* text, LPCTSTR btn_url, COLORREF color);
	void button(int x, int y, int w, int h, const char* text, LPCTSTR btn_url);
};
		