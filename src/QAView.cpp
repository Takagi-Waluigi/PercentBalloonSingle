#include "QAView.h"

void QAView::loadQA() {
	for (int i = 0; i < NUM_QA; i++) {
		if(!img_questions[i].load("/Question/Q"  + ofToString(i + 1) + ".png")) cout << "[ERROR] image load is failure(question)." << endl;
		if(!img_answers[i].load("/Answer/A" + ofToString(i + 1) + ".png")) cout << "[ERROR] image load is failure(answer)." << endl;
	}
}

void QAView::drawQuestion(int id) {
	ofPushStyle();
	ofSetColor(255);
	ofSetRectMode(OF_RECTMODE_CENTER);
	img_questions[id].draw(ofGetWidth() * 0.5, ofGetHeight() * 0.5, ofGetWidth() * 0.75, ofGetHeight() * 0.75);

	ofPopStyle();
}

void QAView::drawAnswer(int id) {
	ofPushStyle();
	ofSetColor(255);
	ofSetRectMode(OF_RECTMODE_CENTER);
	img_answers[id].draw(ofGetWidth() * 0.5, ofGetHeight() * 0.5, ofGetWidth() * 0.75, ofGetHeight() * 0.75);

	ofPopStyle();
}