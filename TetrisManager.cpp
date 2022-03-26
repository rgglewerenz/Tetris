#include "TetrisManager.h"

void TetrisManager::__init__() {
	_count = 0;
}
void TetrisManager::CreatePiece(int type) {
	LineBlock* __pt;
	TBlock* __ptB;
	if (Grounded == true) {
		Grounded = false;
		switch (type) {
		case 1:
			cout <<  "Count = " << _count << endl;
			if (_count != 0) {
				__pt = new LineBlock(_size, objs[_count-1]->__x/_size, 0, _speed, _maxX, _maxY, _images[_count % 6], _count, _grid, _num / 16);
			}
			else
			{
				__pt = new LineBlock(_size, _maxX/_size/2 , 0, _speed, _maxX, _maxY, _images[_count % 6], _count, _grid, _num / 16);
			}
			objs.push_back(__pt);
			cout << "Placement worked val = " << objs[_count]->__placementWorked << endl;
			if (objs[_count]->__placementWorked == false) {
				gameOver = true;
				objs.erase(objs.begin() + _count);
				_count--;
			}
			break;
		case 2:
			cout << "Count = " << _count << endl;
			if (_count != 0) {
				__ptB = new TBlock(_size, objs[_count - 1]->__x / _size, 0, _speed, _maxX, _maxY, _images[_count % 6], _count, _grid, _num / 16);
			}
			else
			{
				__ptB = new TBlock(_size, _maxX / _size / 2, 0, _speed, _maxX, _maxY, _images[_count % 6], _count, _grid, _num / 16);
			}
			objs.push_back(__ptB);
			cout << "Placement worked val = " << objs[_count]->__placementWorked << endl;
			if (objs[_count]->__placementWorked == false) {
				gameOver = true;
				objs.erase(objs.begin() + _count);
				_count--;
			}
		}
		_count++;
	}
}
void TetrisManager::update(int time) {
	cout << Grounded << endl;
	for (Tetrimino* i : objs) {
		i->update(time);
	}
	if(_count > 0)
		checkGrounded();
}
void TetrisManager::draw() {
	for (int i = 0; i < _count; i++) {
		objs[i]->drawBlocks();
	}
}
void TetrisManager::checkGrounded() {
	if (objs[_count - 1]->__live == false) {
		Grounded = true;
		_grid->printGridT();
		//system("pause");
	}
}
void TetrisManager::move(bool direction) {
	cout << _count;
	if (__hardDrop)
		return;
	if (_count == 0)
		return ;
	cout << "RX = " << objs[_count - 1]->getXR() / _size << endl;
	cout << "LX = " << objs[_count - 1]->getXL() / _size << endl;
	cout << "Max X = " << _maxX / _size - 1 << endl;
	if (objs[_count - 1]->getXL()/_size != 0 && direction == false) {
		if (direction == false) {
			cout << "Moved left" << endl;
			objs[_count - 1]->move(direction);
		}
		cout << "Failed to move left" << endl;
	}

	if(objs[_count - 1]->getXR()/_size != _maxX / _size - 1 && direction == true) {
		if (direction == true) {
			cout << "Moved right" << endl;
			objs[_count - 1]->move(direction);
		}
		cout << "Failed to move right" << endl;
	}
}
void TetrisManager::rotate(bool direction) {
	if(Grounded == false)
		objs[_count - 1]->rotate(direction);
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
	bool test = false;
	for (int i = 0; i < _maxX/_size; i++) {
		vector<int> temp;
		temp.push_back(_grid->getItem(i,row));
		temp.push_back(_grid->getId(i, row));
		remove.push_back(temp);
	}
	for (Tetrimino* i : objs) {
		for (int m = 0; m < remove.size();m++) {
			if (i->__index == remove[m][0]) {
				cout << "in remove";
				i->removeBlock(remove[m][1]);
				remove.erase(remove.begin() + m);
				m--;
			}
		}
	}
	for (Tetrimino* i : objs) {
		i->__live = true;
		while (i->__live == true) {
			i->update(0);
		}
	}
}
void TetrisManager::hardDrop() {
	__hardDrop = true;
	if (_count == 0)
		return;
	while (objs[_count - 1]->__live) {
		objs[_count - 1]->update(0);
	}
	__hardDrop = false;
}