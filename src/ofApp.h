#pragma once

#include "ofMain.h"
#include "TetrisManager.h"
#include "GridT.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		int ScreenY = ofGetWindowHeight();
		int ScreenX = ofGetWindowWidth();
		int size = ScreenX/64;
		int bar;
		GridT grid = GridT(ScreenX/size/2,ScreenY/size);
		int time = 0;
		int bottom = int((ScreenY/size)/10);
		double speed = 1;
		ofImage Yellow;
		ofImage* YellowBlock = &Yellow;
		ofImage RedBlock;
		ofImage BlueBlock;
		TetrisManager test = TetrisManager(size,speed,ScreenX/2,ScreenY,YellowBlock,&grid);
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
		
};
