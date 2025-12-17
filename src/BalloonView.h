#pragma once
#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"

class BalloonView
{
public:
	void setup(int g_id, int max_life);
	void setPercentLife(int p_life);
	void setPercentAnswered(int p_answered);
	void setPercentTrue(int p_true);
	void setShowAnswerPercent(bool show_p_answered);

	void drawTruePercentBar(float pos_y, float width, float height, int percent_true, bool showAnswerPercent);
	void drawAnsweredPercentBar(float pos_y, float width, float height, int percent_answered);
	void drawBalloon(float pos_root_y, float radius, float theta, ofColor balloonColor, int img_index);
	void drawBasket(float pos_cavin_y, float width_cavin, float height_cavin);
	void drawAllComponent(float pos_x, float pos_y, float scale, bool showAnswerPercent);
	void drawLife(float pos_x, float pos_y);
	void drawAnswer(float pos_x, float pos_y);
	void drawGroup(float pos_x, float pos_y);

private:
	int groupID = 1;
	int percent_true;
	int percent_answered;
	int percent_life_visual;
	
	array<ofVec2f, 100> balloonVisualInfo;
	array<ofColor, 100> balloonColors;

	array<ofImage, 4> imgs_balloon;
	ofImage img_basket;
	ofImage img_answer_bg;

	ofxCenteredTrueTypeFont font;
};

