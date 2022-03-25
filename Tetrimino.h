#pragma once
#include "ofMain.h"
#include "Block.h"
class Tetrimino
{
public:
	virtual void __init__(int size = 0, int x = 0, int y = 0, int speed = 0, int maxX = 0, int maxY = 0, ofImage* image = nullptr, int index = 0, GridT* grid_pt = nullptr, int num = 0,int xL = 0, int xR = 0)
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
		rotation = 0;
	}
	virtual void moveDown();
	virtual void moveUp();
	virtual void update(int time);
	virtual int getXR();
	virtual int getXL();
	virtual int getY();
	virtual int size();
	virtual void rotate(bool direction);
	virtual void move(bool direction);
	virtual bool checkOverlap(GridT* grid);
	virtual Block getBlock(int index);
	vector<Block> Blocks;
	virtual void drawBlocks();
	virtual void removeBlock(int id);
	ofImage* image__;
	bool __bottom = false;
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
	int rotation;
};

