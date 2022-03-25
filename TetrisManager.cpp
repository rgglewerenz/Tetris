#include "TetrisManager.h"

void TetrisManager::__init__() {
	_count = 0;
}
void TetrisManager::CreatePiece(int type, int x, int y) {
	if (Grounded == true) {
		Grounded = false;
		switch (type) {
		case 1:
			//The plus 1 to x makes it more human understandable
			_count % (_maxX) / _size;
			objs.push_back(LineBlock(_size,x , y, _speed, _maxX, _maxY, images[0], _count, _grid));
			cout <<  "Placement worked val = " << objs[_count].__placementWorked << endl;
			if (objs[_count].__placementWorked == false) {
				gameOver = true;
				objs.erase(objs.begin() + _count);
				_count--;
			}
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
	if(objs[_count - 1].getX()/_size != 0 && direction == false) {
		if (direction == false) {
			objs[_count - 1].move(direction);
		}
	}
}
bool TetrisManager::gameOverBool() {
	return gameOver;
}
void TetrisManager::reset() {
	cout << _count;
	for (int i = _count; i > 0; i--) {
		cout << " i = " << i << endl;
		objs.erase(objs.begin() + i - 1);
	}
	_count = 0;
	gameOver = false;
	Grounded = true;
}