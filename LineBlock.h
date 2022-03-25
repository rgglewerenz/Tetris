#include "Tetrimino.h"

class LineBlock : public Tetrimino {
public:
	LineBlock(int size, int x, int y, int speed, int maxX, int maxY, ofImage* image = nullptr, int index = 0, GridT* grid = nullptr, int num = 0) {
		__init__(size, x*size, y*size, speed, maxX, maxY, image, index,grid,num,x*size,x*size);
		for (int i = 0; i < 4; i++) {
			Blocks.push_back(Block(0,y+(size*i),size,i));	
		}
		for (Block i : Blocks) {
			if (grid->getItem((i.getX() + __x) / __size, (i.getY() + __y) / __size) != -1) {
				__placementWorked = false;
				break;
			}
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, index,i.__id__);
		}
	}
	void drawItem();
};