#include "Tetrimino.h"

class LineBlock : public Tetrimino {
public:
	LineBlock(int size, int x, int y, int speed, int maxX, int maxY, ofImage* image = nullptr, int index = 0, GridT* grid = nullptr) {
		__init__(size, x*size, y*size, speed, maxX, maxY, image, index,grid);
		for (int i = 0; i < 4; i++) {
			Blocks[i] = Block(0,y+(size*i),size);	
		}
		for (Block i : Blocks) {
			if (grid->getItem((i.getX() + __x) / __size, (i.getY() + __y) / __size) != -1) {
				__placementWorked = false;
				break;
			}
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, index);
		}
	}
	void drawItem();
};