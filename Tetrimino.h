#pragma once
#include "ofMain.h"
#include "Block.h"
class Tetrimino
{
public:
	void __init__(int size = 0, int x = 0, int y = 0, int speed = 0, int maxX = 0, int maxY = 0, ofImage* image = nullptr, int index = 0, GridT* grid_pt = nullptr, int num = 0,int xL = 0, int xR = 0)
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
		__num__ = num;
		__xR = xR;
		__xL = xL;
	}
	void moveDown();
	void moveUp();
	void update();
	int getXR();
	int getXL();
	int getY();
	int size();
	void move(bool direction);
	bool checkOverlap(GridT* grid);
	Block getBlock(int index);
	vector<Block> Blocks;
	void drawBlocks();
	void removeBlock(int id);
	ofImage* image__;

	double __speed;
	int __size;
	int __x;
	int __xL;
	int __xR;
	int __y;
	int __maxX;
	int __maxY;
	int __index;
	bool __live = true;
	bool __placementWorked = true;
	GridT* grid;
	int __num__;
};

