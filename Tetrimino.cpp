#include "Tetrimino.h"
/*
* Moves the entire tetremino down
*/
void Tetrimino::moveDown() {
	__y += __speed * __size;
}
/*
* Moves the entire tetremino up
*/
void Tetrimino::moveUp() {
	__y -= __speed * __size;
}
/*
* Updates the tetrimino's position, and makes sure that the new Pos is a valid one
*/
void Tetrimino::update(int time) {
	int lowest_pt = 0;
	if (__live) {
		int py = __y;
		if (time % 30 == 0) {
			moveDown();
		}
		bool worked = true;
		for (Block i : Blocks) {
			if (i.getY() > lowest_pt)
				lowest_pt = i.getY();
		}
		//cout << "Overlap = " << checkOverlap(grid) << endl;
		if (checkOverlap(grid) || (__y + lowest_pt) / __size >= __maxY - __num__) {
			worked = false;
		}
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + py) / __size, -1, -1);
		}
		if (!worked) {
			if ((__y + lowest_pt) / __size >= __maxY - __num__){
			__bottom = true;
			}
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
/*
* Used to see if a tetrimino's piece overlaps with any other pieces on the grid
*/
bool Tetrimino::checkOverlap(GridT* grid) 
{
	for (Block item : Blocks) {
		if (item.Equal(grid,__size,__index, (item.getX() + __x) / __size, (item.getY() + __y) / __size)) {
			return true;
		}
	}
	return false;
}
/*
* Used to get the spesific index of one of the blocks
*/
Block Tetrimino::getBlock(int index) {
	if (index < 4)
		return Blocks[index];
}
/*
*  gets the leftmost block x cord that it occupies
*/
int Tetrimino::getXL() {
	//cout <<  "XL from get X = " << __xL << endl;
	return __xL;
}
/*
* gets the rightmost block x cord that it occupies
*/
int Tetrimino::getXR() {
	//cout << "XR from get X = " << __xR << endl;
	return __xR;
}
/*
* gets the current y value of the tetrimino
*/
int Tetrimino::getY() {
	return __y;
}
/*
* returns the size of the tetrimino
*/
int Tetrimino::size() {
	int working = 0;
	for (Block i : Blocks) {
		if (i.getSize() != -1) {
			working++;
		}
	}
	return working;
}
/*
* draws all of the block in a given tetrimino
*/
void Tetrimino::drawBlocks() {
	for (Block i : Blocks) {
		//i.getX() and i.getY() is the blocks relative position to other blocks
		//__x and __y are the positions in the grid
		//and (__maxX*__size/2) is the ofset of the gameboard
		image__->draw(i.getX() + __x + (__maxX*__size/2), i.getY() + __y);
	}
}
/*
* move the tetrimino left or right depending on the input var
* true = right, false = left
*/
void Tetrimino::move(bool direction) {
	bool worked = true;
	int lowest_pt = 0;
	if (!__live)
		return;
	for (Block i : Blocks) {
		if (i.getY() > lowest_pt)
			lowest_pt = i.getY();
	}
	if (direction) {
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1,-1);
		}
		__x += __speed * __size;
		__xL += __speed * __size;
		__xR += __speed * __size;
	}
	else {
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, -1,-1);
		}
		__x -= __speed * __size;
		__xL -= __speed * __size;
		__xR -= __speed * __size;
		//cout << "New X value added = " << __x << endl;
	}
	if (checkOverlap(grid) || (__y + lowest_pt) / __size >= __maxY - __num__) {
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
	if (worked == true) {
		for (Block i : Blocks) {
			grid->placeItem((i.getX() + __x) / __size, (i.getY() + __y) / __size, __index,i.__id__);
		}
	}
	else
	{
		if (direction) {
			__x -= __speed * __size;
			__xL -= __speed * __size;
			__xR -= __speed * __size;
		}
		else {
			__x += __speed * __size;
			__xL += __speed * __size;
			__xR += __speed * __size;
		}
	}
}
/*
* removes a block from the vector of a given tetrimino by the id given to the block at startup
*/
void Tetrimino::removeBlock(int id) {
	if (id > 3) {
		cout << "INVALID ID  = " << id << endl;
		return;
	}
	int b = 0;
	int newY = -3;
	for (Block m : Blocks) {
		if (m.__id__ == id) {
			//cout << "Id = " << id << " b = " << b << " Len = " << Blocks.size() << endl;
			Blocks.erase(Blocks.begin() + b);
			grid->placeItem((m.getX() + __x)/__size,(m.getY() + __y)/__size,-1,-1);
			newY = m.getY();
		}
		b++;
	}
	if (newY == -3)
		return ;
	for (Block m : Blocks) {
		grid->placeItem((m.getX() + __x) / __size, (m.getY() + __y) / __size, -1, -1);
	}
	for (Block& m : Blocks) {
		if (newY != -3 && m.getY() < newY) {
			//cout << "Tetrimino = " << __index << "Block = " << m.__id__ << " :: new Y = " << m.getY() + __size << ", Old Y = " << m.getY() << endl;
			m.setY(m.getY() + __size);
		}
	}
	for (Block m : Blocks) {
		grid->placeItem((m.getX() + __x) / __size, (m.getY() + __y) / __size, __index, m.__id__);
	}
}
/**/
void Tetrimino::rotate(bool direction) {

}