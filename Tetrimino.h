#pragma once
#include "ofMain.h"
#include "Block.h"
class Tetrimino
{
public:
	void __init__(int size = 0, int x = 0, int y = 0, int speed = 0, int maxX = 0, int maxY = 0, ofImage* image = nullptr, int index = 0, GridT* grid_pt = nullptr)
	{
		__size = size;
		__x = x;
		__y = y;
		__maxX = maxX / size;
		__maxY = maxY / size;
		__speed = speed;
		image__ = image;
		__index = index;
		grid = grid_pt;
	}
	void moveDown();
	void moveUp();
	void update();
	int getX();
	int getY();
	int size();
	void move(bool direction);
	bool checkOverlap(GridT* grid);
	Block getBlock(int index);
	Block Blocks[4];
	void drawBlocks();
	ofImage* image__;
	double __speed;
	int __size;
	int __x;
	int __y;
	int __maxX;
	int __maxY;
	int __index;
	bool __live = true;
	bool __placementWorked = true;
	GridT* grid;
};

