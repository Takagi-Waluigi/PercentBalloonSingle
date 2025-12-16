#pragma once
#include "ofMain.h"

#define NUM_QA 5
class QAView
{
public:
	void loadQA();
	void drawQuestion(int id);
	void drawAnswer(int id);

private:
	array<ofImage, NUM_QA> img_questions;
	array<ofImage, NUM_QA> img_answers;
};

