#include "ofApp.h"
#include <windows.h>
#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0,0,0);
	bar = int(int(ScreenX / 4)/size);
	Yellow.load("Images\\YellowTile.png");
	Blue.load("Images\\BlueTile.png");
	Red.load("Images\\RedTile.png");
	Green.load("Images\\GreenTile.png");
	Orange.load("Images\\OrangeTile.png");
	Purple.load("Images\\PurpleTile.png");
	for (ofImage* image : images) {
		image->resize(size, size);
	}
	test.__init__();
	int i = 0;
	for (wstring sound : SOURCES)
	{
		wstring item = L"open \"" + direcotry + sound + L"\" type mpegvideo alias " + names[i];
		error = mciSendStringW(item.c_str(), NULL, 0, 0);

		wchar_t msg[128];
		int err = mciGetErrorString(error, msg, 128);
		if (error != 0) {
			wchar_t file[10] = L"";
			int m = 0;
			for (char character : sound) {
				file[m] = sound[m];
				m++;
			}
			if (error == 277) {
				cout << "Please make sure that the file is a .mp3\nIf it is then try to use an online converted to switch it to .wav, and then back to .mp3" << endl;
				wprintf(L"The file in question is %s\n\n", file);
				system("pause");
				system("exit");
				return;
			}
			else if (error == 275) {
				cout << "Please make sure that the directory, and file names are correct.\nThe directory should end with a / and the file should end with a .mp3 " << endl;
				wprintf(L"The file in question is %s\n\n", file);
				system("pause");
				system("exit");
				return;
				
			}
			else
			{
				cout << "This is an unexpected error, if possible contact me." << endl;
				wprintf(L"The file in question is %s\n\n", file);
				system("pause");
				system("exit");
				return ;
			}
		}
		i++;
	}
	wstring item = L"play " + names[0] + L" repeat";
	if(sound)
		mciSendStringW(item.c_str(), NULL, 0, NULL);
}

//--------------------------------------------------------------
void ofApp::update(){
	bool noise = false;
	//cout << "Testing bool = "  << test.gameOverBool() << endl;
	if (test.gameOverBool()) {
		cout << "Game Over " << endl;
		gameOver();
		return;
	}
	test.update(time);
	for (int i = 0; i < ScreenY / size; i++) {
		bool testVar = grid.checkRow(i);
		//cout << "Testing row  " << i << " Results are = " << testVar << endl;
		if (testVar == true && test.Grounded == true) {
			noise = true;
			test.eraseRow(i);
		}
		if (test.Grounded == false) {
			break;
		}
	}
	if (noise && sound) {
		if (timesWon > 0) {
				wstring item = L"play " + names[1];
				mciSendStringW(item.c_str(), NULL, 0, NULL);
				timesWon++;
			}
		else {
				wstring item = L"play " + names[1] + L" from 0";
				mciSendStringW(item.c_str(), NULL, 0, NULL);
			}
	}

	test.CreatePiece(4 + 1);
	//test.CreatePiece(rand()%2  + 1);
	randomize++;
	//grid.printGridT();
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
	if ((key == 'a' || key == 'A')) {
		test.move(false);
		aDown = true;
	}
	if ((key == 'd' || key == 'D') ) {
		test.move(true);
		dDown = true;
	}
	if ((key == 'w' || key == 'W') ) {
		test.rotate(true);
		rDown = true;
	}
	if ((key == 's' || key == 'S') ) {
		test.hardDrop();
		if (sound) {
			if (timesDropped > 0) {
				timesDropped++;
				wstring item = L"play " + names[2];
				mciSendStringW(item.c_str(), NULL, 0, NULL);
			}
			else
			{
				wstring item = L"play " + names[2] + L" from 0";
				mciSendStringW(item.c_str(), NULL, 0, NULL);
			}
		}
		sDown = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if ((key == 'a' || key == 'A') && aDown == true) {
		aDown = false;
	}
	if ((key == 'd' || key == 'D') && dDown == true) {
		dDown = false;
	}
	if ((key == 'r' || key == 'R') && rDown == true) {
		rDown = false;
	}
	if ((key == 's' || key == 'S') && sDown == true) {
		sDown = false;
	}
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
