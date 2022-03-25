#include "TetrisManager.h"

void TetrisManager::__init__() {
	_count = 0;
}
void TetrisManager::CreatePiece(int type, int x, int y) {
	if (Grounded == true) {
		Grounded = false;
		switch (type) {
		case 1:
			objs.push_back(LineBlock(_size, x, y, _speed, _maxX, _maxY, _images[0], _count, _grid,_num/16));
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
	if (objs[_count - 1].getXL()/_size != _maxX/_size - 1 && direction == true) {
		if (direction == true) {
			cout << "Moved left" << endl;
			objs[_count - 1].move(direction);
		}
		cout << "Failed to move left" << endl;
	}
	if(objs[_count - 1].getXR()/_size != 0 && direction == false) {
		if (direction == false) {
			cout << "Moved right" << endl;
			objs[_count - 1].move(direction);
		}
		cout << "Failed to move right" << endl;
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
void TetrisManager::eraseRow(int row) {
	vector<vector<int>> remove;
	for (int i = 0; i < _maxX/_size; i++) {
		vector<int> temp;
		temp.push_back(_grid->getItem(i,row));
		temp.push_back(_grid->getId(i, row));
		remove.push_back(temp);
	}
	for (Tetrimino& i : objs) {
		for (int m = 0; m < remove.size();m++) {
			if (i.__index == remove[m][0]) {
				cout << "in remove";
				i.removeBlock(remove[m][1]);
				remove.erase(remove.begin() + m);
				m--;
			}
		}
	}
}