#include "tetremino.h"
void tetremino::__init__(ofImage* yellow) {
	images.push_back(yellow);
}
void tetremino::DrawBlocks() {
	for (int i = 0; i < cubes__; i++) 
	{
		images[0]->draw(blocks[i].getX(),blocks[i].getY());
	}
	return ;
}
void tetremino::update() {
	bool skip;
	time++;
	vector<int> temp;
	for (int i = blocks.size() - 1; i > -1; i--) 
	{
		Grounded[i] = false;
		skip = false;
		if (blocks[i].getY() + size__ < maxY__) {
			for (int b = 0; b < cubes__; b++) {
				if (i != b) {
					if (blocks[b].checkIntercect(&blocks[i])) {
						skip = true;
						Grounded[i] = true;
						break;
					}
				}
			}
			if (!skip) {
				blocks[i].setY(blocks[i].getY() + speed__);
			}
		}
		else {
			Grounded[i] = true;
		}
	}
	for (int i = 0; i < blocks.size(); i++) {
		if (i == 0) {
			temp.push_back(0);
			temp.push_back(0);
		}
		temp[1] = int(int(blocks[i].getX() / size__)) - int(maxX__ / size__ / 4);
		temp[0] = int(int(blocks[i].getY() / size__)) + 1;
		if (Grounded[i]) {
			//cout << "Block" << i << "X =" << blocks[i].getX() << " Y = " << blocks[i].getY() << endl;
			coordinates[i] = temp;
		}
	}
	//cout << "Size" << size__ << endl;
}
vector<int> tetremino::getCoordinate(int block) {
	if(block < blocks.size())
		return coordinates[block];
}
void tetremino::BreakBlock(vector<int> coordinate) {
	
	for (int i = 0; i < cubes__; i++) {
		if (coordinate == coordinates[i]) {
			cout << "Similar" << endl;
			cout << i << endl;
			blocks.erase(blocks.begin() + i);
			Grounded.erase(Grounded.begin() + i);
			coordinates.erase(coordinates.begin() + i);
			cubes__--;
		}
		if (i >= cubes__)
			break;
	}
}
int tetremino::getSize() {
	return cubes__;
}