#pragma once
#include "plot/Plot.h"
#include <list>

class Map {
public:
	std::list<Plot*> game_map_;
	Map();
	~Map();

	void Draw();// ������ͼ
	bool inArea(const ExMessage& msg,Player& player);// �ж������
};
