#pragma once
#include "ofMain.h"
class GridT
{
public:
	GridT(int X, int Y) {
		__x = X;
		__y = Y;
		for (int i = 0; i < Y; i++) {
			vector<int> temp = { -1,-1 };
			vector<vector<int>> temp2;
			for (int j = 0; j < X; j++) {
				temp2.push_back(temp);
			}
			gridObj.push_back(temp2);
			
		}
	}
	void printGridT();
	void resetGrid();
	int getId(int x, int y);
	int getItem(int x, int y);
	void placeItem(int x, int y, int val, int id);
	bool checkRow(int row);
private:
	vector<vector<vector<int>>> gridObj;
	int __x;
	int __y;
};

