#include "Tetrimino.h"
void Tetrimino::moveDown() {
	__y += __speed * __size;
}
void Tetrimino::moveUp() {
	__y -= __speed*__size;
}
void Tetrimino::update() {
	if (__live) {
		int py = __y;
		moveDown();
		bool worked = true;
		int lowest_pt = 0;
		for (Block i : Blocks) {
			if (i.getY() > lowest_pt)
				lowest_pt = i.getY();
		}
		cout << "Overlap = " << checkOverlap(grid) << endl;
		if (checkOverlap(grid) || (__y + lowest_pt) / __size >= __maxY - 2) {
			worked = false;
		}
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + py) / __size, -1,-1);
		}
		if (!worked) {
			moveUp();
			__live = false;
			for (Block i : Blocks) {
				grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index,i.__id__);
			}
		}
		else {
			for (Block i : Blocks) {
				grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index,i.__id__);
			}
		}
	}
}
bool Tetrimino::checkOverlap(GridT* grid) 
{
	for (Block item : Blocks) {
		if (item.Equal(grid,__size,__index, (item.getX() + __x) / __size, (item.getY() + __y) / __size)) {
			return true;
		}
	}
	return false;
}
Block Tetrimino::getBlock(int index) {
	if (index < 4)
		return Blocks[index];
}
int Tetrimino::getX() {
	cout <<  "X from get X = " << __x << endl;
	return __x;
}
int Tetrimino::getY() {
	return __y;
}
int Tetrimino::size() {
	int working = 0;
	for (Block i : Blocks) {
		if (i.getSize() != -1) {
			working++;
		}
	}
	return working;
}
void Tetrimino::drawBlocks() {
	for (Block i : Blocks) {
		//i.getX() and i.getY() is the blocks relative position to other blocks
		//__x and __y are the positions in the grid
		//and (__maxX*__size/2) is the ofset of the gameboard
		image__->draw(i.getX() + __x + (__maxX*__size/2), i.getY() + __y);
	}
}
void Tetrimino::move(bool direction) {
	bool worked = true;
	int lowest_pt = 0;
	for (Block i : Blocks) {
		if (i.getY() > lowest_pt)
			lowest_pt = i.getY();
	}
	if (direction) {
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1,-1);
		}
		__x += __speed * __size;
	}
	else {
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1,-1);
		}
		__x -= __speed * __size;
		cout << "New X value added = " << __x << endl;
	}
	if (checkOverlap(grid) || (__y + lowest_pt) / __size >= __maxY - 2) {
		worked = false;
	}
	else
	{
		__y += __speed * __size;
		if (checkOverlap(grid)) {
			worked = false;
		}
		__y -= __speed * __size;
	}
	if (worked) {
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index,i.__id__);
		}
	}
	else
	{
		if (direction) {
			__x -= __speed * __size;
		}
		else {
			__x += __speed * __size;
		}
	}
}
void Tetrimino::removeBlock(int id) {
	if (id > 3) {
		cout << "INVALID ID  = " << id << endl;
		return;
	}
	int b = 0;
	for (Block m : Blocks) {
		if (m.__id__ == id) {
			Blocks.erase(Blocks.begin() + b);
			grid->placeItem((m.getX() + __x)/__size,(m.getY() + __y)/__size,-1,-1);
		}
		b++;
	}
}