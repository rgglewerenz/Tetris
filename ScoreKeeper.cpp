#include "ScoreKeeper.h"
void ScoreKeeper::DistroyedRows(int row_count) {
	__score__ += row_count * __points_per_row__;
}
void ScoreKeeper::resetScore() {
	__score__ = 0;
}
int ScoreKeeper::getScore() {
	return __score__;
}