#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(188, 226, 232);

	setupGame();			
}

void ofApp::setupGUI() {
	questionId.set("question ID", 0, 0, 4);
	channel.set("channel", 0, 0, 4);

	showQuestionBoard.set("1.QUESTION", false);
	percent_answered_group.setName("2. SET ANSWERS");
	percent_answered[0].set("[RED]TeamA answer", 50, 0, 100);
	percent_answered[1].set("[BLUE]TeamB answer", 50, 0, 100);
	percent_answered[2].set("[YELLOW]TeamC answer", 50, 0, 100);
	percent_answered[3].set("[GREEN]TeamD answer", 50, 0, 100);
	for (int i = 0; i < NUM_TEAM; i++) percent_answered_group.add(percent_answered[i]);	
	percent_manual.set("3.MANIPULATE PERCENT", 100, 0, 100);

	showAnswerPercent.set("4.SHOW RESULT", false);
	enablePop.set("5.START POP", false);
	showAnswerBoard.set("6.SHOW MORE", false);
	enableNextQuestion.set("7.NEXT", false);

	//Setup for game flow
	gameFlowSwitches.setName("Game Flow");	
	gameFlowSwitches.add(showQuestionBoard);
	percent_answered_group.setParent(gameFlowSwitches);
	gameFlowSwitches.add(percent_manual);
	gameFlowSwitches.add(showAnswerPercent);
	gameFlowSwitches.add(enablePop);
	gameFlowSwitches.add(showAnswerBoard);
	gameFlowSwitches.add(enableNextQuestion);

	gui.setup();
	gui.add(questionId);
	gui.add(channel);
	gui.add(percent_answered_group);
	gui.add(gameFlowSwitches);	
}

void ofApp::setupGame() {
	percents_true[0] = 53;
	percents_true[1] = 77;
	percents_true[2] = 26;
	percents_true[3] = 60;
	percents_true[4] = 82;



	sound.load("balloon_pop.mp3");

	for (int i = 0; i < NUM_TEAM; i++) {
		balloonModels[i].setSound(sound);
		balloonViews[i].setup(i, MAX_LIFE);
	}

	for (int i = 0; i < NUM_TEAM; i++) balloonModels[i].initValue(MAX_LIFE, MAX_INTERVAL);

	qaView.loadQA();
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < NUM_TEAM; i++) {
		balloonModels[i].updateValue(MAX_INTERVAL, MIN_INTERVAL, INT_VELOCITY);
		
		balloonViews[i].setPercentAnswered(percent_answered[i]);
		
		float inputAnswerPercent = (showAnswerPercent) ? percents_true[questionId] : percent_manual;
		balloonViews[i].setPercentTrue(inputAnswerPercent);

		balloonViews[i].setPercentLife(balloonModels[i].percent_life_visual);		
	}

	if (enablePop) {
		for (int i = 0; i < NUM_TEAM; i++) {
			balloonModels[i].calculateDifferential(percent_answered[i], percents_true[questionId]);
		}
		showQuestionBoard = false;
		showAnswerBoard = false;
		enablePop = false;
	}

	if (enableNextQuestion) {
		showAnswerPercent = false;

		if (questionId < 5) questionId++;

		percent_manual = 100;
		for (int i = 0; i < NUM_TEAM; i++) percent_answered[i] = 50;

		showQuestionBoard = false;
		showAnswerBoard = false;
		enableNextQuestion = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofHideCursor();
	switch (channel)
	{
	case 1:
		balloonViews[0].drawAllComponent(0, 0,1.0, showAnswerPercent);
		break;

	case 2:
		balloonViews[1].drawAllComponent(0, 0, 1.0, showAnswerPercent);
		break;

	case 3:
		balloonViews[2].drawAllComponent(0, 0, 1.0, showAnswerPercent);
		break;

	case 4:
		balloonViews[3].drawAllComponent(0, 0, 1.0, showAnswerPercent);
		break;

	default:
		balloonViews[0].drawAllComponent(0, 0, 0.5, showAnswerPercent);
		balloonViews[1].drawAllComponent(ofGetWidth() * 0.5, 0, 0.5, showAnswerPercent);
		balloonViews[2].drawAllComponent(0, ofGetHeight() * 0.5, 0.5, showAnswerPercent);
		balloonViews[3].drawAllComponent(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 0.5, showAnswerPercent);
		break;
	}	

	if (showQuestionBoard) qaView.drawQuestion(questionId);
	if (showAnswerBoard) qaView.drawAnswer(questionId);
	
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
