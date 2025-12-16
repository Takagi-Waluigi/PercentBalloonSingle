#pragma once

#include "AppConstants.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "BalloonView.h"
#include "BalloonModel.h"
#include "QAView.h"

#define MAX_LIFE 100
#define MAX_INTERVAL 0.5
#define MIN_INTERVAL 0.03
#define INT_VELOCITY 0.05
#define NUM_TEAM 4

class ofApp : public ofBaseApp{

	public:
		void setup();
		void setupGUI();
		void setupGame();
		void update();
		void draw();
		void drawGUI(ofEventArgs& args);

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

		AppConstants appConstants;

		ofxPanel gui;
		ofParameterGroup qaDisplayGroup;
		ofParameter<int> questionId;
		ofParameter<bool> showQuestion;
		ofParameter<bool> showAnswer;
		
		
		ofParameter<int> channel;		
		ofParameter<int> percent_true;
		ofParameterGroup percent_answered_group;
		array<ofParameter<int>, NUM_TEAM> percent_answered;
		ofParameter<bool> answer_go;
		ofParameter<bool> next_question;
		

		int percent_life;
		int percent_life_visual;
		float timef_balloon_destroy_interval = MAX_INTERVAL;
		float timef_balloon_last_destory = 0;

		ofSoundPlayer sound;

		array<BalloonView, NUM_TEAM> balloonViews;
		array<BalloonModel, NUM_TEAM> balloonModels;

		QAView qaView;
};
