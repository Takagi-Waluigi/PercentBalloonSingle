#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	percent_answered.set("answered percent", 50, 0, 100);
	percent_true.set("true percent", 100, 0, 100);
	percent_life.set("life", 100, 0, 100);
	
	gui.setup();
	gui.add(percent_answered);
	gui.add(percent_true);
	gui.add(percent_life);

	for (int i = 0; i < balloonVisualInfo.size(); i++)
	{
		balloonVisualInfo[i].x = ofRandom(1.6, 1.9);
		balloonVisualInfo[i].y = ofRandom(0.7, 0.8);
		balloonColors[i] = ofColor(
			ofRandom(50, 255),
			ofRandom(50, 255),
			ofRandom(50, 255)
		);
	}
	
	ofBackground(188, 226, 232);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < percent_life; i++)
	{
		ofPushStyle();
		drawBalloon(ofGetHeight() * 2.0, ofGetHeight() * balloonVisualInfo[i].x, TWO_PI * balloonVisualInfo[i].y, balloonColors[i]);
		ofPopStyle();
	}	

	float y_percent_bar = ofGetHeight() * 0.9;
	float w_percent_bar = ofGetWidth() * 0.6;
	float h_percent_bar = ofGetHeight() * 0.1;

	drawCabin(ofGetHeight() * 0.9, ofGetWidth() * 0.9, ofGetHeight() * 0.2);

	drawTruePercentBar(y_percent_bar, w_percent_bar, h_percent_bar, percent_true);
	drawAnsweredPercentBar(y_percent_bar, w_percent_bar, h_percent_bar, percent_answered);
	
	
	gui.draw();
}

void ofApp::drawTruePercentBar(float pos_y, float width, float height, int percent_true) {
	int percent_max = 100;
	float margin = width / percent_max;
	for (int i = 0; i < percent_true; i++) {
		ofPushStyle();
		ofSetColor(255);
		ofSetRectMode(OF_RECTMODE_CENTER);

		ofVec2f pos_rect = ofVec2f(
			ofGetWidth() * 0.5 + (i - percent_max * 0.5) * margin,
			pos_y
		);

		ofDrawRectangle(pos_rect, margin * 0.5, height);

		ofPopStyle();
	}
}

void ofApp::drawAnsweredPercentBar(float pos_y, float width, float height, int percent_answered) {
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(255, 0, 0);

	int percent_max = 100;
	float margin = width / percent_max;

	ofVec2f pos_rect = ofVec2f(
		ofGetWidth() * 0.5 + (percent_answered - percent_max * 0.5) * margin,
		pos_y
	);

	ofDrawRectangle(pos_rect, margin * 0.5, height);

	ofPopStyle();
}

void ofApp::drawBalloon(float pos_root_y, float radius, float theta, ofColor balloonColor) {
	ofPushStyle();
	ofVec2f rootPos = ofVec2f(
		ofGetWidth() * 0.5,
		pos_root_y
	);

	ofVec2f balloonPos = ofVec2f(
		rootPos.x + radius * cos(theta),
		rootPos.y + radius * sin(theta)
	);

	ofSetColor(255);
	ofDrawLine(rootPos, balloonPos);

	ofSetColor(balloonColor);
	ofDrawCircle(balloonPos, 50);

	ofPopStyle();
}

void ofApp::drawCabin(float pos_cavin_y, float width_cavin, float height_cavin) {
	ofPushMatrix();

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(50, 0, 0);

	ofDrawRectangle(ofGetWidth() * 0.5, pos_cavin_y, width_cavin, height_cavin);

	ofPopMatrix();
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
