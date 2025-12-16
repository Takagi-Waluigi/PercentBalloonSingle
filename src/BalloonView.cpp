#include "BalloonView.h"

void BalloonView::setup(int g_id, int max_life) {
	groupID = g_id;

	if(!img_basket.load("basket.png"))  cout << "[ERROR] image load is failure(basket)." << endl;

	for (int i = 0; i < imgs_balloon.size(); i++) {
		if (!imgs_balloon[i].load("/Group" + ofToString(groupID) + "/Balloon" + ofToString(i) + ".png"))  cout << "[ERROR] image load is failure(balloon)." << endl;
	}

	for (int i = 0; i < balloonVisualInfo.size(); i++)
	{
		balloonVisualInfo[i].x = ofRandom(1.6, 1.9);
		balloonVisualInfo[i].y = ofRandom(0.7, 0.8);
	}

	font.load(OF_TTF_SANS, 64);
}

void BalloonView::setPercentLife(int p_life) {
	if (p_life < 0) p_life = 0;
	percent_life_visual = p_life;
}

void BalloonView::setPercentAnswered(int p_answered)
{
	if (p_answered < 0 || 100 < p_answered) return;
	percent_answered = p_answered;
}

void BalloonView::setPercentTrue(int p_true)
{
	if (p_true < 0 || 100 < p_true) return;
	percent_true = p_true;
}

void BalloonView::drawAllComponent(float pos_x, float pos_y, float scale) {
	ofPushMatrix();
	ofTranslate(pos_x, pos_y);
	ofScale(scale, scale);

	ofPushStyle();
	ofSetColor(188, 226, 232);
	ofDrawRectangle(pos_x * (1 / scale), pos_y * (1 / scale), 0, ofGetWidth() * (1 / scale), ofGetHeight() * (1 / scale));
	ofPopStyle();

	if (scale < 1)
	{
		ofPushStyle();
		ofNoFill();
		ofSetLineWidth(2.0);
		ofSetColor(50);
		ofDrawRectangle(pos_x * (1 / scale), pos_y * (1 / scale), 0, ofGetWidth() * (1 / scale), ofGetHeight() * (1 / scale));
		ofPopStyle();
	}


	for (int i = 0; i < percent_life_visual; i++)
	{
		ofPushStyle();
		float theta_swing = TWO_PI * 0.0125 * sin(ofGetElapsedTimef() * 0.1 - i * 0.05) + TWO_PI * balloonVisualInfo[i].y;
		drawBalloon(ofGetHeight() * 2.0, ofGetHeight() * balloonVisualInfo[i].x, theta_swing, balloonColors[i], i % imgs_balloon.size());
		ofPopStyle();
	}

	float y_percent_bar = ofGetHeight() * 0.9;
	float w_percent_bar = ofGetWidth() * 0.75;
	float h_percent_bar = ofGetHeight() * 0.1;

	drawBasket(ofGetHeight() * 0.9, ofGetWidth() * 0.9, ofGetHeight() * 0.2);

	drawTruePercentBar(y_percent_bar, w_percent_bar, h_percent_bar, percent_true);
	drawAnsweredPercentBar(y_percent_bar, w_percent_bar, h_percent_bar, percent_answered);
	drawLife(ofGetWidth() * 0.9, ofGetHeight() * 0.8);
	drawAnswer(ofGetWidth() * 0.05, y_percent_bar);
	drawGroup(ofGetWidth() * 0.1, ofGetHeight() * 0.125);

	ofPopMatrix();
}

void BalloonView::drawTruePercentBar(float pos_y, float width, float height, int percent_true) {
	int percent_max = 100;
	float margin = width / percent_max;
	for (int i = 0; i < percent_true; i++) {
		ofPushStyle();
		ofSetColor(255, 255.0 * (float(i) - 100.0) * 0.01, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);

		ofVec2f pos_rect = ofVec2f(
			ofGetWidth() * 0.5 + (i - percent_max * 0.5) * margin,
			pos_y
		);

		ofDrawRectangle(pos_rect, margin * 0.5, height);

		ofPopStyle();
	}
}

void BalloonView::drawAnsweredPercentBar(float pos_y, float width, float height, int percent_answered) {
	ofPushStyle();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(0, 0,255);

	int percent_max = 100;
	float margin = width / percent_max;

	ofVec2f pos_rect = ofVec2f(
		ofGetWidth() * 0.5 + (percent_answered - percent_max * 0.5) * margin,
		pos_y
	);

	ofDrawRectangle(pos_rect, margin * 0.75, height * 1.2);

	ofPopStyle();
}

void BalloonView::drawBalloon(float pos_root_y, float radius, float theta, ofColor balloonColor, int img_index) {
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

	imgs_balloon[img_index].draw(balloonPos.x, balloonPos.y - imgs_balloon[img_index].getHeight() * 0.5);

	ofPopStyle();
}

void BalloonView::drawBasket(float pos_cavin_y, float width_cavin, float height_cavin) {
	ofPushMatrix();

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(255);

	ofVec2f basketPos = ofVec2f(
		ofGetWidth() * 0.5,
		pos_cavin_y
	);

	img_basket.draw(basketPos);

	ofPopMatrix();
}

void BalloonView::drawLife(float pos_x, float pos_y) {
	ofPushStyle();

	ofRectMode(OF_RECTMODE_CENTER);
	float imgScale = 2.0;
	ofVec2f imgScaleXY = ofVec2f(
		imgs_balloon[3].getWidth() * imgScale,
		imgs_balloon[3].getHeight() * imgScale
		);

	float pos_y_siwinging = pos_y + 15 * sin(ofGetElapsedTimef());

	ofSetColor(255);
	ofDrawLine(pos_x, pos_y_siwinging, pos_x, ofGetHeight());

	imgs_balloon[3].draw(pos_x, pos_y_siwinging,  imgScaleXY.x, imgScaleXY.y);
	font.drawStringCentered(ofToString(percent_life_visual), pos_x, pos_y_siwinging);	
	
	ofPopStyle();
}

void BalloonView::drawAnswer(float pos_x, float pos_y) {
	ofPushStyle();

	ofSetColor(255, 128);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectangle(pos_x, pos_y, 120, 120);

	ofSetColor(0);
	font.drawStringCentered(ofToString(percent_answered), pos_x, pos_y);

	ofPopStyle();
}

void BalloonView::drawGroup(float pos_x, float pos_y) {
	ofPushStyle();

	string teamName = "NAME";
	switch (groupID)
	{
	case 0:
		ofSetColor(128, 0, 0);
		teamName = "A";
		break;

	case 1:
		ofSetColor(0, 0, 128);
		teamName = "B";
			break;

	case 2:
		ofSetColor(128, 128, 0);
		teamName = "C";
			break;

	case 3:
		ofSetColor(0, 128, 0);
		teamName = "D";
			break;
	}

	ofDrawCircle(pos_x, pos_y, 75);

	ofSetColor(255);
	font.drawStringCentered(teamName, pos_x, pos_y);

	ofPopStyle();
}