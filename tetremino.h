#pragma once
#include "Block.h"
#include "ofMain.h"
class tetremino
{
public:
	tetremino(int size = 0, double speed = 0, int cubes = 0, int x = 0, int y = 0, int maxX = 0, int maxY = 0, int color = 0)
	{
		int temp[2];
	
		if (size != 0 && x > (maxX / 2 / size)) {
			cout << "**ERROR** went out of bounds" << endl;
			return;
		}
		for (int i = 0; i < cubes; i++) {
			Grounded.push_back(false);
			vector<int> temp;
			temp.push_back(0);
			temp.push_back(0);
			blocks.push_back(Block(x*size + (maxX/4), (size)*i,size));
			coordinates.push_back(temp);
		}
		color__ = color;
		size__ = size;
		speed__ = speed;
		cubes__ = cubes;
		maxX__ = maxX;
		maxY__ = maxY;
	}
	void DrawBlocks();
	void update();
	double CheckInteract(tetremino otherTet);
	vector<int> getCoordinate(int block);
	int getSize();
	vector<Block> getBlock();
	void __init__(ofImage* yellow);
	void BreakBlock(vector<int> coordinate);
private:
	int time = 0;
	vector<Block> blocks;
	vector<ofImage*> images;
	vector<bool> Grounded;
	vector<vector<int>> coordinates;
	int cubes__;
	int color__;
	double speed__;
	int size__;
	int maxX__;
	int maxY__;
};

