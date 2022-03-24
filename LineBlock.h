#include "Tetrimino.h"

class LineBlock : public Tetrimino {
public:
	LineBlock(int size, int x, int y, int speed, int maxX, int maxY, ofImage* image = nullptr, int index = 0, GridT* grid = nullptr) {
		__init__(size, x, y, speed, maxX, maxY, image, index,grid);
		for (int i = 0; i < 4; i++) {
			Blocks[i] = Block(x*size,y+(size*i),size);	
		}
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, index);
		}
	}
	void drawItem();
};