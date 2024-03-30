#pragma once
#include "plot/Plot.h"
#include <list>

class Map {
public:
	std::list<Plot*> game_map_;
	Map();
	~Map();

	void Draw();// 画出地图
	bool inArea(const ExMessage& msg,Player& player);// 判定鼠标点击
};
