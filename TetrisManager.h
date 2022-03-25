#pragma once
#include "ofMain.h"
#include "GridT.h"
#include "Tetrimino.h"
#include "LineBlock.h"
#include "TBlock.h"
class TetrisManager
{
public:
	TetrisManager(int size, int speed, int maxX, int maxY, vector<ofImage*> images = { nullptr }, GridT* grid = nullptr, int num = 0) {
		_size = size;
		_speed = speed;
		_maxX = maxX;
		_maxY = maxY;
		_grid = grid;
		_count = 0;
		for (ofImage* image : images) {
			_images.push_back(image);
		}
		_num = num;
	}
	void __init__();
	void CreatePiece(int type);
	void update(int time);
	void draw();
	void checkGrounded();
	void move(bool direction);
	bool gameOverBool();
	void reset();
	void eraseRow(int row);
	void hardDrop();
	void rotate(bool direction);
	bool Grounded = true;
private:
	int _size;
	int _speed;
	int _maxX;
	int _num;
	int _maxY;
	vector<Tetrimino*> objs;
	vector<ofImage*> _images;
	int _count;
	bool gameOver = false;
	GridT* _grid;
	bool __hardDrop = false;

};

