#pragma once
#include "Tetrimino.h"
class TBlock :public Tetrimino
{
public:
	TBlock(int size, int x, int y, int speed, int maxX, int maxY, ofImage* image = nullptr, int index = 0, GridT* grid = nullptr, int num = 0) {
		__init__(size, x * size, y * size, speed, maxX, maxY, image, index, grid, num, x * size , (x * size) + size);
		__y += __size;
		Blocks.push_back(Block(0, y + size*-1, size, 0));
		Blocks.push_back(Block(0, y + size*1, size, 0));
		Blocks.push_back(Block(0, y + size*0, size, 0));
		Blocks.push_back(Block(__size, y, size, 0));
		for (Block i : Blocks) {
			if (grid->getItem((i.getX() + __x) / __size, (i.getY() + __y) / __size) != -1) {
				__placementWorked = false;
				break;
			}
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, index, i.__id__);
		}
	}
	void placeXY(bool self);
	virtual void rotate(bool direction);
	void drawItem();
};

