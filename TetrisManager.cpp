#include "TetrisManager.h"

void TetrisManager::__init__() {
	_count = 0;
}
void TetrisManager::CreatePiece(int type, int x, int y) {
	if (Grounded == true) {
		Grounded = false;
		switch (type) {
		case 1:
			objs.push_back(LineBlock(_size, x, y, _speed, _maxX, _maxY, images[0], _count, _grid));
			break;
		}
		_count++;
	}
}
void TetrisManager::update() {
	cout << Grounded << endl;
	for (Tetrimino& i : objs) {
		i.update();
	}
	if(_count > 0)
		checkGrounded();
	
}
void TetrisManager::draw() {
	for (Tetrimino i : objs) {
		i.drawBlocks();
	}
}
void TetrisManager::checkGrounded() {
	if (objs[_count - 1].__live == false) {
		Grounded = true;
	}
}
void TetrisManager::move(bool direction) {
	cout << _count;
	if (_count == 0)
		return ;
	cout << "X = " << objs[_count - 1].getX()/_size << endl;
	cout << "Max X = " << _maxX/_size << endl;
	if (objs[_count - 1].getX()/_size != _maxX/_size - 1 && direction == true) {
		if (direction == true) {
			objs[_count - 1].move(direction);
		}
	}
	if(objs[_count - 1].getX() != 0 && direction == false) {
		if (direction == false) {
			objs[_count - 1].move(direction);
		}
	}
}