#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	setupGame();	
	ofBackground(188, 226, 232);

	sound.load("balloon_pop.mp3");

	for (int i = 0; i < NUM_TEAM; i++) {
		balloonModels[i].setSound(sound);
		balloonViews[i].setup(i, MAX_LIFE);
	}
}

void ofApp::setupGUI() {
	channel.set("channel", 0, 0, 4);
	percent_answered_group.setName("Answers");
	percent_true.set("true percent", 100, 0, 100);
	percent_answered[0].set("[RED]TeamA answer", 50, 0, 100);
	percent_answered[1].set("[BLUE]TeamB answer", 50, 0, 100);
	percent_answered[2].set("[YELLOW]TeamC answer", 50, 0, 100);
	percent_answered[3].set("[GREEN]TeamD answer", 50, 0, 100);
	for (int i = 0; i < NUM_TEAM; i++) percent_answered_group.add(percent_answered[i]);
	answer_go.set("GO", false);	

	gui.setup();
	gui.add(channel);
	gui.add(percent_true);
	gui.add(percent_answered_group);	
	gui.add(answer_go);
}

void ofApp::setupGame() {
	for (int i = 0; i < NUM_TEAM; i++) balloonModels[i].initValue(MAX_LIFE, MAX_INTERVAL);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < NUM_TEAM; i++) {
		balloonModels[i].updateValue(MAX_INTERVAL, MIN_INTERVAL, INT_VELOCITY);
		balloonViews[i].setPercentAnswered(percent_answered[i]);
		balloonViews[i].setPercentTrue(percent_true);
		balloonViews[i].setPercentLife(balloonModels[i].percent_life_visual);
	}

	if (answer_go) {
		for (int i = 0; i < NUM_TEAM; i++) {
			balloonModels[i].calculateDifferential(percent_answered[i], percent_true);
		};
		answer_go = false;
	}	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofHideCursor();
	switch (channel)
	{
	case 1:
		balloonViews[0].drawAllComponent(0, 0,1.0);
		break;

	case 2:
		balloonViews[1].drawAllComponent(0, 0, 1.0);
		break;

	case 3:
		balloonViews[2].drawAllComponent(0, 0, 1.0);
		break;

	case 4:
		balloonViews[3].drawAllComponent(0, 0, 1.0);
		break;

	default:
		balloonViews[0].drawAllComponent(0, 0, 0.5);
		balloonViews[1].drawAllComponent(ofGetWidth() * 0.5, 0, 0.5);
		balloonViews[2].drawAllComponent(0, ofGetHeight() * 0.5, 0.5);
		balloonViews[3].drawAllComponent(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 0.5);
		break;
	}	

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(0, 128);
	ofDrawRectangle(ofGetWidth() * 0.5, ofGetHeight() * 0.5, ofGetWidth() * 0.7, ofGetHeight() * 0.75);
}

void ofApp::drawGUI(ofEventArgs& args) {
	ofShowCursor();
	gui.draw();
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
