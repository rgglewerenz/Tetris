#include "Block.h"
void Block::DrawBlock() {
	ofRectangle new_Rect;
	new_Rect.setSize(__size__, __size__);
	new_Rect.setPosition(__x__, __y__);
	ofSetColor(255);
	ofDrawRectangle(new_Rect);
}
void Block::updateBlock() {

}
double Block::getX() {
	return __x__;
}
double Block::getY() {
	return __y__;
}
int Block::getSize() {
	return __size__;
}
void Block::setX(double x) {
	__x__ = x;
}
void Block::setY(double y) {
	__y__ = y;
}
bool Block::checkIntercect(Block* otherBlock) {
	double oX = otherBlock->getX();
	double oY = otherBlock->getY();
	int oSize = otherBlock->getSize();
	if (oX + oSize < __x__ || oX  > __x__ || oY + oSize < __y__ || oY > __y__) {
		return false; 
	}
	return true;
}
bool Block::Equal(GridT* grid, int size, int index, int x, int y) {
	if (grid->getItem(x,y) != -1 && grid->getItem(x,y) != index)
		return true;
	return false;
}