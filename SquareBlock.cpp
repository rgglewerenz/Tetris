#include "SquareBlock.h"
void SquareBlock::drawItem() {
	drawBlocks();
}
void SquareBlock::rotate(bool directon) {
	return;
}
void SquareBlock::placeXY(bool self) {
	if (!self)
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
		}
	else {
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index, i.__id__);
		}
	}
}