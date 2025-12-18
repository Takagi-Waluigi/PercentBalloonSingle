#pragma once
#include "ofMain.h"
#define NUM_QA 5

class QAView
{
public:
	void loadQA();
	void drawQuestion(int id);
	void drawAnswer(int id);
	void drawTitle();

private:
	array<ofImage, NUM_QA> img_questions;
	array<ofImage, NUM_QA> img_answers;
	ofImage img_title;
};

