#pragma once
#include "ofMain.h"
class GridT
{
public:
	GridT(int X, int Y) {
		__x = X;
		__y = Y;
		for (int i = 0; i < Y; i++) {
			vector<int> num(X, -1);
			gridObj.push_back(num);
		}
	}
	void printGridT();
	void resetGrid();
	int getItem(int x, int y);
	void placeItem(int x, int y, int val);
	bool checkRow(int row);
private:
	vector<vector<int>> gridObj;
	int __x;
	int __y;
};

