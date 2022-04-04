#pragma once

#include "ofMain.h"
#include "TetrisManager.h"
#include "GridT.h"
#include "ScoreKeeper.h"
#include "Printer.h"
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		int ScreenY = ofGetWindowHeight();
		int ScreenX = ofGetWindowWidth();
		int num = 32;
		int size = ScreenX/num;
		int bar;
		GridT grid = GridT(ScreenX/size/2,ScreenY/size);
		int time = 0;
		int bottom = int((ScreenY/size)/10);
		double speed = 1;
		ofImage Yellow;
		ofImage Green;
		ofImage Blue;
		ofImage Red;
		ofImage Orange;
		ofImage Purple;
		Printer printingObj;
		vector<ofImage*> images = {&Yellow,&Green,&Blue,&Red,&Orange,&Purple};
		TetrisManager test = TetrisManager(size,speed,ScreenX/2,ScreenY,images,&grid,num);
		const wstring MUSICSOURCE = L"Sound.mp3";
		const wstring WINSOURCE = L"Win.mp3";
		const wstring HITSOURCE = L"Hit.mp3";
		const wstring LOSESOURCE = L"Lose.mp3";
		const wstring TIESOURCE = L"Tie.mp3";
		const wstring ENDSOURCE = L"End.mp3";
		const wstring SOURCES[6] = { MUSICSOURCE,WINSOURCE,HITSOURCE,LOSESOURCE,TIESOURCE,ENDSOURCE };
		const wstring names[6] = { L"Music", L"Win", L"Hit" , L"Lose" , L"Tie", L"End" };
		const wstring direcotry = L"Sounds/";
		int error;
		bool aDown = false;
		bool dDown = false;
		bool rDown = false;
		bool sDown = false;
		bool sound = false;
		bool Over = false;
		time_t start_time;
		ScoreKeeper scoreObj;
		int timesWon = 0;
		int timesDropped = 0;
		int randomize = 0;
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void gameOver();
		void drawGameOver();
		
};
