#include "GridT.h"
void GridT::printGridT() {
	for (vector<int> y : gridObj) {
		for (int i : y) {
			cout << i << " || ";
		}
		cout <<  "   |   " << endl;
	}
}
void GridT::resetGrid() {
	for (vector<int>& num : gridObj) {
		num = vector<int>(__x, -1);
	}
}
int GridT::getItem(int x, int y) {
	//cout << "X = " << x << " , Y = " << y << endl;
	return gridObj[y][x];
}
bool GridT::checkRow(int row) {
	int times = 0;
	for (int i = 0; i < gridObj[row].size(); i++) {
		if (gridObj[row][i] != -1)
			times++;
	}
	if (times = gridObj[row].size() - 1)
		return true;
	return false;
}
void GridT::placeItem(int x, int y, int value) {
	//cout << "X = " << x << " , Y = " << y << endl;
	gridObj[y][x] = value;
}