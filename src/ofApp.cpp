#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	initGame();	
	ofBackground(188, 226, 232);

	sound.load("balloon_pop.mp3");

	for(int i = 0; i < NUM_TEAM; i ++) balloonViews[i].setup(i, MAX_LIFE);
}

void ofApp::setupGUI() {
	channel.set("channel", 0, 0, 4);
	percent_answered.set("answered percent", 50, 0, 100);
	percent_true.set("true percent", 100, 0, 100);

	gui.setup();
	gui.add(channel);
	gui.add(percent_answered);
	gui.add(percent_true);
}

void ofApp::initGame() {

	percent_life = MAX_LIFE;
	percent_life_visual = MAX_LIFE;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (percent_life == percent_life_visual) {
		timef_balloon_destroy_interval = MAX_INTERVAL;
	}
	if (percent_life_visual > percent_life) {
		if (ofGetElapsedTimef() - timef_balloon_last_destory > timef_balloon_destroy_interval) {			
			percent_life_visual--;
			sound.play();
			timef_balloon_last_destory = ofGetElapsedTimef();

			timef_balloon_destroy_interval -= INT_VELOCITY;
			if (timef_balloon_destroy_interval < MIN_INTERVAL) timef_balloon_destroy_interval = MIN_INTERVAL;

			cout << "[GAME SYSTEM] balloon update:" << "percent life visual->" << percent_life_visual << "/ percent life->" << percent_life << endl;
		}
	}

	if (percent_life < 0) percent_life = 0;
	if (percent_life_visual < 0) percent_life_visual = 0;

	for (int i = 0; i < NUM_TEAM; i++) {
		balloonViews[i].setPercentAnswered(percent_answered);
		balloonViews[i].setPercentTrue(percent_true);
		balloonViews[i].setPercentLife(percent_life_visual);
	}
	
}

void ofApp::updateGame()
{
	int differential = abs(percent_answered - percent_true);
	percent_life = percent_life - differential;
}

//--------------------------------------------------------------
void ofApp::draw(){
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
}

void ofApp::drawGUI(ofEventArgs& args) {
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
	case OF_KEY_RETURN:		
		updateGame();
		cout << "[GAME SYSTEM] balloon update begin:" << endl;
		break;

	case OF_KEY_ESC:
		initGame();
		cout << "[GAME SYSTEM] game initialized:" << endl;
		break;

	default:
		break;
	}
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
