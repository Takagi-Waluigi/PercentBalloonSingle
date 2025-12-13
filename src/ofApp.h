#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
		void drawTruePercentBar(float pos_y, float width, float height, int percent_true);
		void drawAnsweredPercentBar(float pos_y, float width, float height, int percent_answered);
		void drawBalloon(float pos_root_y, float radius, float theta, ofColor balloonColor);
		void drawCabin(float pos_cavin_y, float width_cavin, float height_cavin);

		ofxPanel gui;
		ofParameter<int> percent_true;
		ofParameter<int> percent_answered;
		ofParameter<int> percent_life;

		array<ofVec2f, 100> balloonVisualInfo;
		array<ofColor, 100> balloonColors;
};
