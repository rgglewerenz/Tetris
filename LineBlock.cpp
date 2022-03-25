#include "LineBlock.h"
void LineBlock::drawItem()
{
	drawBlocks();
}
void LineBlock::rotate(bool direction)
{
	switch (rotation) {
	case 0:
		if (__x/__size > 2) {
			for (Block i : Blocks) {
				grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
			}
			Blocks[0].setX(-2*__size);
			Blocks[0].setY(1 * __size);
			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(1 * __size);
			Blocks[2].setX(0 * __size);
			Blocks[2].setY(1 * __size);
			Blocks[3].setX(1 * __size);
			Blocks[3].setY(1 * __size);
			__xR -= 2*__size;
			__xL += __size;
			for (Block i : Blocks) {
				grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
			}
		}
		else {
			__x = 2 * __size;
			Blocks[0].setX(-2 * __size);
			Blocks[0].setY(2 * __size);
			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(2 * __size);
			Blocks[2].setX(0 * __size);
			Blocks[2].setY(2 * __size);
			Blocks[3].setX(1 * __size);
			Blocks[3].setY(2 * __size);
			__xR -= 2 * __size;
			__xL += __size;
		}
		break;
	}
}