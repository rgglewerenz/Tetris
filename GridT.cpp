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
		num = vector<int>(__x, 0);
	}
}
int GridT::getItem(int x, int y) {
	//cout << "X = " << x << " , Y = " << y << endl;
	return gridObj[y][x];
}
void GridT::placeItem(int x, int y, int value) {
	//cout << "X = " << x << " , Y = " << y << endl;
	gridObj[y][x] = value;
}