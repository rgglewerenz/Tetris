#pragma once
class ScoreKeeper
{
public:
	int getScore();
	void DistroyedRows(int row_count);
	void resetScore();
private:
	int __score__ = 0;
	int __points_per_row__ = 100;
};

