#include "TBlock.h"
void TBlock::drawItem() {
	drawBlocks();
}
void TBlock::rotate(bool directon) {
	switch (rotation % 4)
	{
	case 0:
	{
		if (__xR / __size < __maxX && __xL / __size > 1) {
			placeXY(false);
			__xL -= __size;
			Blocks[0].setX(0);
			Blocks[0].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(1 * __size);
			Blocks[2].setY(0);

			Blocks[3].setX(0);
			Blocks[3].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(1 * __size);

					Blocks[2].setX(0);
					Blocks[2].setY(1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(2 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(2 * __size);
						__y += __size;
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
		else if (__xR / __size < __maxX && !(__xL / __size > 1)) {
			placeXY(false);
			__x += __size;
			__xR += __size;
			__xL += __size;
			__xL -= __size;
			Blocks[0].setX(0);
			Blocks[0].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(1 * __size);
			Blocks[2].setY(0);

			Blocks[3].setX(0);
			Blocks[3].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(1 * __size);

					Blocks[2].setX(0);
					Blocks[2].setY(1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(2 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(2 * __size);
						__y += __size;
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
		else {
			placeXY(false);
			__x -= __size;
			__xR -= __size;
			__xL -= __size;
			__xL -= __size;
			Blocks[0].setX(0);
			Blocks[0].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(1 * __size);
			Blocks[2].setY(0);

			Blocks[3].setX(0);
			Blocks[3].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(1 * __size);

					Blocks[2].setX(0);
					Blocks[2].setY(1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(2 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(2 * __size);
						__y += __size;
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
	}
	case 1:
	{
		if (__xR / __size < __maxX && __xL / __size > 1) {
			placeXY(false);
			__xR -= __size;
			Blocks[0].setX(0);
			Blocks[0].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(1 * __size);

			Blocks[2].setX(0);
			Blocks[2].setY(1 * __size);

			Blocks[3].setX(0);
			Blocks[3].setY(2 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(1 * __size);

					Blocks[2].setX(0);
					Blocks[2].setY(1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(2 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(2 * __size);
						__y += __size;
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
		else if (__xR / __size < __maxX && !(__xL / __size > 1)) {
			placeXY(false);
			__x += __size;
			__xR += __size;
			__xL += __size;
			__xR -= __size;
			Blocks[0].setX(0);
			Blocks[0].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(1 * __size);

			Blocks[2].setX(0);
			Blocks[2].setY(1 * __size);

			Blocks[3].setX(0);
			Blocks[3].setY(2 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(1 * __size);

					Blocks[2].setX(0);
					Blocks[2].setY(1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(2 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(2 * __size);
						__y += __size;
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
		else {
			placeXY(false);
			__x -= __size;
			__xR -= __size;
			__xL -= __size;
			__xR -= __size;
			Blocks[0].setX(0);
			Blocks[0].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(1 * __size);

			Blocks[2].setX(0);
			Blocks[2].setY(1 * __size);

			Blocks[3].setX(0);
			Blocks[3].setY(2 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(1 * __size);

					Blocks[2].setX(0);
					Blocks[2].setY(1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(2 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(2 * __size);
						__y += __size;
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
	}
	case 2:
	{
		if (__xR / __size < __maxX && __xL / __size > 1) {
			placeXY(false);
			__xR += __size;
			Blocks[0].setX(0);
			Blocks[0].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(1 * __size);
			Blocks[2].setY(0);

			Blocks[3].setX(0);
			Blocks[3].setY(-1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(1 * __size);

					Blocks[2].setX(0);
					Blocks[2].setY(1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(2 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(2 * __size);
						__y += __size;
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
		else if (__xR / __size < __maxX && !(__xL / __size > 1)) {
			placeXY(false);
			__x += __size;
			__xR += __size;
			__xL += __size;
			__xR += __size;
			Blocks[0].setX(0);
			Blocks[0].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(1 * __size);
			Blocks[2].setY(0);

			Blocks[3].setX(0);
			Blocks[3].setY(-1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(1 * __size);

					Blocks[2].setX(0);
					Blocks[2].setY(1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(2 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(2 * __size);
						__y += __size;
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
		else {
			placeXY(false);
			__x -= __size;
			__xR -= __size;
			__xL -= __size;
			__xR += __size;
			Blocks[0].setX(0);
			Blocks[0].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(1 * __size);
			Blocks[2].setY(0);

			Blocks[3].setX(0);
			Blocks[3].setY(-1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(1 * __size);

					Blocks[2].setX(0);
					Blocks[2].setY(1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(2 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(2 * __size);
						__y += __size;
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
	}
	}
}
void TBlock::placeXY(bool self) {
	if(!self)
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1, -1);
		}
	else {
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index, i.__id__);
		}
	}
}