#pragma once
#include "ofMain.h"
#include "GridT.h"
#include "Tetrimino.h"
#include "LineBlock.h"
class TetrisManager
{
public:
	TetrisManager(int size, int speed, int maxX, int maxY, ofImage* image = nullptr, GridT* grid = nullptr) {
		_size = size;
		_speed = speed;
		_maxX = maxX;
		_maxY = maxY;
		_grid = grid;
		_count = 0;
		images.push_back(image);
	}
	void __init__();
	void CreatePiece(int type, int x, int y);
	void update();
	void draw();
	void checkGrounded();
	void move(bool direction);
private:
	int _size;
	int _speed;
	int _maxX;
	int _maxY;
	vector<Tetrimino> objs;
	vector<ofImage*> images;
	int _count;
	bool Grounded = true;
	GridT* _grid;

};

