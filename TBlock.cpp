#include "TBlock.h"
void TBlock::drawItem() {
	drawBlocks();
}
void TBlock::rotate(bool directon) {
	switch (rotation % 4)
	{
	case 0:
	{
		if (__y / __size >= __maxY - 1) {
			placeXY(false);
			__y -= __size;
		}
		if (__xR / __size < __maxX && __xL / __size > 0) {
			placeXY(false);
			__xL -= __size;
			Blocks[3].setX(0);
			Blocks[3].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(1 * __size);
			Blocks[2].setY(0);

			Blocks[0].setX(0);
			Blocks[0].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(-1*__size);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(0);

					Blocks[2].setX(0);
					Blocks[2].setY(0);

					Blocks[3].setX(0);
					Blocks[3].setY(1 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[3].setX(0);
						Blocks[3].setY(0);

						Blocks[1].setX(-1 * __size);
						Blocks[1].setY(0);

						Blocks[2].setX(1 * __size);
						Blocks[2].setY(0);

						Blocks[0].setX(0);
						Blocks[0].setY(1 * __size);
						__y += __size;
						placeXY(true);
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
		else if (__xR / __size < __maxX && !(__xL / __size > 0)) {
			placeXY(false);
			__x += __size;
			__xR += __size;
			__xL += __size;
			__xL -= __size;
			Blocks[3].setX(0);
			Blocks[3].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(1 * __size);
			Blocks[2].setY(0);

			Blocks[0].setX(0);
			Blocks[0].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(-1 * __size);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(0);

					Blocks[2].setX(0);
					Blocks[2].setY(0);

					Blocks[3].setX(0);
					Blocks[3].setY(1 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[3].setX(0);
						Blocks[3].setY(0);

						Blocks[1].setX(-1 * __size);
						Blocks[1].setY(0);

						Blocks[2].setX(1 * __size);
						Blocks[2].setY(0);

						Blocks[0].setX(0);
						Blocks[0].setY(1 * __size);
						__y += __size;
						placeXY(true);
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
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
			Blocks[3].setX(0);
			Blocks[3].setY(0);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(1 * __size);
			Blocks[2].setY(0);

			Blocks[0].setX(0);
			Blocks[0].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(-1 * __size);

					Blocks[1].setX(1 * __size);
					Blocks[1].setY(0);

					Blocks[2].setX(0);
					Blocks[2].setY(0);

					Blocks[3].setX(0);
					Blocks[3].setY(1 * __size);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(-1 * __size);
						Blocks[1].setY(0);

						Blocks[2].setX(1 * __size);
						Blocks[2].setY(0);

						Blocks[3].setX(0);
						Blocks[3].setY(1 * __size);
						__y += __size;
						placeXY(true);
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
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

		if (__y / __size >= __maxY - 1) {
			placeXY(false);
			__y-= __size;
		}
		if (__xR / __size < __maxX && __xL / __size >= 0) {
			placeXY(false);
			__xR -= __size;
			Blocks[0].setX(0);
			Blocks[0].setY(-1 * __size);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(0);
			Blocks[2].setY(0);

			Blocks[3].setX(0);
			Blocks[3].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(-1 * __size);

					Blocks[1].setX(-1 * __size);
					Blocks[1].setY(-1 * __size);

					Blocks[2].setX(1 * __size);
					Blocks[2].setY(-1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(0);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(-1 * __size);

						Blocks[1].setX(-1 * __size);
						Blocks[1].setY(0);

						Blocks[2].setX(0);
						Blocks[2].setY(0);

						Blocks[3].setX(0);
						Blocks[3].setY(1 * __size);
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
		else if (__xR / __size < __maxX && !(__xL / __size >= 0)) {
			placeXY(false);
			__x += __size;
			__xR += __size;
			__xL += __size;
			__xR -= __size;
			Blocks[0].setX(0);
			Blocks[0].setY(-1 * __size);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0);

			Blocks[2].setX(0);
			Blocks[2].setY(0);

			Blocks[3].setX(0);
			Blocks[3].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 2) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(-1 * __size);

					Blocks[1].setX(-1 * __size);
					Blocks[1].setY(-1 * __size);

					Blocks[2].setX(1 * __size);
					Blocks[2].setY(-1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(0);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(-1*__size);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(1 * __size);
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
			Blocks[0].setY(-1*__size);

			Blocks[1].setX(-1 * __size);
			Blocks[1].setY(0 * __size);

			Blocks[2].setX(0);
			Blocks[2].setY(0 * __size);

			Blocks[3].setX(0);
			Blocks[3].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(-1 * __size);

					Blocks[1].setX(-1 * __size);
					Blocks[1].setY(-1 * __size);

					Blocks[2].setX(1 * __size);
					Blocks[2].setY(-1 * __size);

					Blocks[3].setX(0);
					Blocks[3].setY(0);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 2) {
						Blocks[0].setX(0);
						Blocks[0].setY(-1 * __size);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(1 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(1 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(1 * __size);
						__y += __size;
						placeXY(true);
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
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
		if (__y / __size == 0) {
			placeXY(false);
			__y += __size;
		}
		if (__xR / __size < __maxX - 1 && __xL / __size >= 0) {
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
			if (checkOverlap(grid) || __y / __size > __maxY - 2) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(-1 * __size);

					Blocks[1].setX(-1 * __size);
					Blocks[1].setY(0);

					Blocks[2].setX(0);
					Blocks[2].setY(0);

					Blocks[3].setX(0);
					Blocks[3].setY(1 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 2) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(-1 * __size);
						Blocks[1].setY(0);

						Blocks[2].setX(1 * __size);
						Blocks[2].setY(0);

						Blocks[3].setX(0);
						Blocks[3].setY(-1 * __size);
						__y += __size;
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
						placeXY(true);
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
		else if (__xR / __size < __maxX - 1 && !(__xL / __size >= 0)) {
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
			if (checkOverlap(grid) || __y / __size > __maxY - 2) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(-1 * __size);

					Blocks[1].setX(-1 * __size);
					Blocks[1].setY(0);

					Blocks[2].setX(0);
					Blocks[2].setY(0);

					Blocks[3].setX(0);
					Blocks[3].setY(1 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 2) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(-1 * __size);
						Blocks[1].setY(0);

						Blocks[2].setX(1 * __size);
						Blocks[2].setY(0);

						Blocks[3].setX(0);
						Blocks[3].setY(-1 * __size);
						__y += __size;
						placeXY(true);
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
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
			if (checkOverlap(grid) || __y / __size > __maxY - 2) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(-1 * __size);

					Blocks[1].setX(-1 * __size);
					Blocks[1].setY(0);

					Blocks[2].setX(0);
					Blocks[2].setY(0);

					Blocks[3].setX(0);
					Blocks[3].setY(1 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 2) {
						Blocks[0].setX(0);
						Blocks[0].setY(0);

						Blocks[1].setX(-1 * __size);
						Blocks[1].setY(0);

						Blocks[2].setX(1 * __size);
						Blocks[2].setY(0);

						Blocks[3].setX(0);
						Blocks[3].setY(-1 * __size);
						__y += __size;
						placeXY(true);
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
	}
	case 3:
	{
		if (__y / __size >= __maxY - 1) {
			placeXY(false);
			__y += __size;
		}
		if (__xR / __size < __maxX && __xL / __size >= 0) {
			placeXY(false);
			__xL += __size;
			Blocks[0].setX(0);
			Blocks[0].setY(-1 * __size);

			Blocks[1].setX(1 * __size);
			Blocks[1].setY(0 * __size);

			Blocks[2].setX(0);
			Blocks[2].setY(0 * __size);

			Blocks[3].setX(0);
			Blocks[3].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 1) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(-1 * __size);
					Blocks[1].setY(0);

					Blocks[2].setX(1 * __size);
					Blocks[2].setY(0);

					Blocks[3].setX(0);
					Blocks[3].setY(-1 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 1) {
						Blocks[0].setX(0);
						Blocks[0].setY(-1 * __size);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(0 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(0 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(1 * __size);
						__y += __size;
						placeXY(true);
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
						break;
					}
				}
			}
			placeXY(true);
			rotation++;
			break;
		}
		else if (__xR / __size < __maxX && !(__xL / __size >= 0)) {
			placeXY(false);
			__x += __size;
			__xR += __size;
			__xL += __size;
			__xL += __size;
			Blocks[0].setX(-1 * __size);
			Blocks[0].setY(0);

			Blocks[1].setX(0);
			Blocks[1].setY(1 * __size);

			Blocks[2].setX(-1 * __size);
			Blocks[2].setY(1 * __size);

			Blocks[3].setX(0);
			Blocks[3].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 2) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(-1 * __size);
					Blocks[1].setY(0);

					Blocks[2].setX(1 * __size);
					Blocks[2].setY(0);

					Blocks[3].setX(0);
					Blocks[3].setY(-1 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 2)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 2) {
						Blocks[0].setX(0);
						Blocks[0].setY(-1 * __size);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(0 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(0 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(1 * __size);
						__y += __size;
						placeXY(true);
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
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
			__xL += __size;
			Blocks[0].setX(0);
			Blocks[0].setY(-1 * __size);

			Blocks[1].setX(1 * __size);
			Blocks[1].setY(0 * __size);

			Blocks[2].setX(0);
			Blocks[2].setY(0 * __size);

			Blocks[3].setX(0);
			Blocks[3].setY(1 * __size);
			if (checkOverlap(grid) || __y / __size > __maxY - 2) {
				if (checkOverlap(grid)) {
					Blocks[0].setX(0);
					Blocks[0].setY(0);

					Blocks[1].setX(-1 * __size);
					Blocks[1].setY(0);

					Blocks[2].setX(1 * __size);
					Blocks[2].setY(0);

					Blocks[3].setX(0);
					Blocks[3].setY(-1 * __size);
					placeXY(true);
					break;
				}
				if ((__y / __size < __maxY - 1)) {
					__y -= __size;
					if (checkOverlap(grid) || __y / __size > __maxY - 2) {
						Blocks[0].setX(0);
						Blocks[0].setY(-1 * __size);

						Blocks[1].setX(1 * __size);
						Blocks[1].setY(0 * __size);

						Blocks[2].setX(0);
						Blocks[2].setY(0 * __size);

						Blocks[3].setX(0);
						Blocks[3].setY(1 * __size);
						__y += __size;
						placeXY(true);
						if (__y / __size > __maxY - 1) {
							__live = false;
						}
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