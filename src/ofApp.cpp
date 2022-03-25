#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0,0,0);
	bar = int(int(ScreenX / 4)/size);
	YellowBlock->load("Images\\YellowTile.png");
	YellowBlock->resize(size, size);
	test.__init__();
}

//--------------------------------------------------------------
void ofApp::update(){
	cout << "Testing bool = "  << test.gameOverBool() << endl;
	if (test.gameOverBool()) {
		cout << "Game Over " << endl;
		gameOver();
		return;
	}
	test.update();
	if (time % 1 == 0) {
		for (int i = 0; i < ScreenY / size; i++) {
			bool testVar = grid.checkRow(i);
			cout << "Testing row  " << i << " Results are = " << testVar << endl;
			if (testVar == true && test.Grounded == true) {
				test.eraseRow(i);
			}
		}
		test.CreatePiece(1, 0, 0);
		grid.printGridT();
	}
	time++;
}
//--------------------------------------------------------------
void ofApp::gameOver() {
	drawGameOver();
	test.reset();
	grid.resetGrid();
}
//--------------------------------------------------------------
void ofApp::drawGameOver() {

}
//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawLine(int(ScreenX / 4), 0, int(ScreenX/ 4), ScreenY - bottom*size);
	ofDrawLine(int(ScreenX*3 / 4), 0, int(ScreenX*3 / 4), ScreenY - bottom*size);
	ofDrawLine(int(ScreenX / 4), ScreenY - bottom * size, int(ScreenX*3 / 4), ScreenY - bottom * size);
	test.draw();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
