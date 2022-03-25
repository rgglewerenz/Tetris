#pragma once
#include "ofMain.h"
#include "GridT.h"
class Block
{
public:
	Block(int x = 0, int y = 0, int size = 0,int id = 0) {
		__x__ = x;
		__y__ = y;
		__size__ = size;
		__id__ = id;
	}
	void DrawBlock();
	void updateBlock();
	double getX();
	double getY();
	int getSize();
	void setX(double x);
	void setY(double y);
	int __id__;
	bool checkIntercect(Block* otherBlock);
	bool Equal(GridT* otherBlock, int size, int index, int x, int y);
private:
	int __size__;
	double __x__;
	double __y__;
};
