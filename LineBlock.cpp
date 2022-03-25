#include "LineBlock.h"
void LineBlock::drawItem()
{
	drawBlocks();
}
void LineBlock::rotate(bool direction)
{
	switch (rotation%2) {
	case 0:
		//Working
		if (__x/__size >= 2 && __x/__size < __maxX- 2) {
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
			__xR += 1 * __size;
			__xL -= 2*__size;
			cout << "Xr = " << __xR << endl;
			cout << "XL = " << __xL << endl;
			if (checkOverlap(grid)) {
				Blocks[0].setX(0 * __size);
				Blocks[0].setY(0 * __size);
				Blocks[1].setX(0 * __size);
				Blocks[1].setY(1 * __size);
				Blocks[2].setX(0 * __size);
				Blocks[2].setY(2 * __size);
				Blocks[3].setX(0 * __size);
				Blocks[3].setY(3 * __size);
				for (Block i : Blocks) {
					grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index, i.__id__);
				}
				break;
			}
			for (Block i : Blocks) {
				grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
			}
			rotation++;
			break;
		}
		if(__x / __size < 2) {
			for (Block i : Blocks) {
				grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
			}
			__x += 2 * __size;
			__xR += 2 * __size;
			__xL += 2 * __size;
			Blocks[0].setX(-2 * __size);
			Blocks[0].setY(1 * __size);
			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(1 * __size);
			Blocks[2].setX(0 * __size);
			Blocks[2].setY(1 * __size);
			Blocks[3].setX(1 * __size);
			Blocks[3].setY(1 * __size);
			__xR += 1 * __size;
			__xL -= 2 * __size;
			if (checkOverlap(grid)) {
				__xR -= 1 * __size;
				__xL += 2 * __size;
				Blocks[0].setX(0 * __size);
				Blocks[0].setY(0 * __size);
				Blocks[1].setX(0 * __size);
				Blocks[1].setY(1 * __size);
				Blocks[2].setX(0 * __size);
				Blocks[2].setY(2 * __size);
				Blocks[3].setX(0 * __size);
				Blocks[3].setY(3 * __size);
				for (Block i : Blocks) {
					grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index, i.__id__);
				}
				break;
			}
			for (Block i : Blocks) {
				grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
			}
			rotation++;
			break;
		}
		else {
			for (Block i : Blocks) {
				grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
			}
			__x -= 1 * __size;
			__xR -= 1 * __size;
			__xL -= 1 * __size;
			Blocks[0].setX(-2 * __size);
			Blocks[0].setY(1 * __size);
			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(1 * __size);
			Blocks[2].setX(0 * __size);
			Blocks[2].setY(1 * __size);
			Blocks[3].setX(1 * __size);
			Blocks[3].setY(1 * __size);
			__xR += 1 * __size;
			__xL -= 2 * __size;
			if (checkOverlap(grid)) {
				__xR -= 1 * __size;
				__xL += 2 * __size;
				Blocks[0].setX(0 * __size);
				Blocks[0].setY(0 * __size);
				Blocks[1].setX(0 * __size);
				Blocks[1].setY(1 * __size);
				Blocks[2].setX(0 * __size);
				Blocks[2].setY(2 * __size);
				Blocks[3].setX(0 * __size);
				Blocks[3].setY(3 * __size);
				for (Block i : Blocks) {
					grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index, i.__id__);
				}
				break;
			}
			for (Block i : Blocks) {
				grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
			}
			rotation++;
			break;
		}
		break;
	case 1:
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
		}
		Blocks[0].setX(-1 * __size);
		Blocks[0].setY(0 * __size);
		Blocks[1].setX(-1 * __size);
		Blocks[1].setY(1 * __size);
		Blocks[2].setX(-1 * __size);
		Blocks[2].setY(2 * __size);
		Blocks[3].setX(-1 * __size);
		Blocks[3].setY(3 * __size);
		__xR -= 1 * __size;
		__xL += 2 * __size;
		int lowest_pt = 0;
		for (Block i : Blocks) {
			if (i.getY() > lowest_pt)
				lowest_pt = i.getY();
		}
		if (checkOverlap(grid) || (__y + lowest_pt) / __size >= __maxY - __num__) {
			__y -= 1 * __size;
			if (checkOverlap(grid) || (__y + lowest_pt) / __size >= __maxY - __num__) {
				__y += 1 * __size;
				Blocks[0].setX(-1 * __size);
				Blocks[0].setY(0 * __size);
				Blocks[1].setX(-1 * __size);
				Blocks[1].setY(1 * __size);
				Blocks[2].setX(-1 * __size);
				Blocks[2].setY(2 * __size);
				Blocks[3].setX(-1 * __size);
				Blocks[3].setY(3 * __size);
			}
		}
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index,i.__id__);
		}
		rotation++;
		break;
	}
}