#include "GridT.h"
void GridT::printGridT() {
	for (vector<vector<int>> y : gridObj) {
		for (vector<int> i : y) {
			cout << "{";
			for(int b :i)
				cout << b << " , ";
			cout << "},";
		}
		cout <<  "   |   " << endl;
	}
}
void GridT::resetGrid() {
	for (int i = 0; i < gridObj.size(); i++) {
		vector<int> temp = { -1,-1 };
		vector<vector<int>> temp2;
		for (int j = 0; j < gridObj[i].size(); j++) {
			temp2.push_back(temp);
		}
		gridObj[i] = temp2;
	}
}
int GridT::getItem(int x, int y) {
	//cout << "X = " << x << " , Y = " << y << endl;
	return gridObj[y][x][0];
}
int GridT::getId(int x, int y) {
	return gridObj[y][x][1];
}
bool GridT::checkRow(int row) {
	int times = 0;
	vector<int> test = { -1,-1 };
	for (int i = 0; i < gridObj[row].size(); i++) {
		if (gridObj[row][i] != test)
			times++;
	}
	//cout << " Times = " << times << endl;
	//cout << " Max = " << gridObj[row].size();
	if (times == gridObj[row].size())
		return true;
	return false;
}
void GridT::placeItem(int x, int y, int value, int id) {
	//cout << "X = " << x << " , Y = " << y << endl;
	vector<int> temp = {value,id};
	gridObj[y][x] = temp;
}