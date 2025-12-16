#include "BalloonModel.h"

void BalloonModel::initValue(int max_life, float max_interval) {
	percent_life = max_life;
	percent_life_visual = max_life;
	timef_balloon_destroy_interval = max_interval;
}

void BalloonModel::setSound(ofSoundPlayer s) {
	sound = s;
}

void BalloonModel::calculateDifferential(int p_answered, int p_true) {
	int differential = abs(p_answered - p_true);
	percent_life = percent_life - differential;
}

void BalloonModel::updateValue(float max_interval, float min_interval, float interval_velocity) {
	sound.setVolume(1.0);

	if (percent_life == percent_life_visual) {
		timef_balloon_destroy_interval = max_interval;
	}

	if (percent_life_visual > percent_life) {
		if (ofGetElapsedTimef() - timef_balloon_last_destory > timef_balloon_destroy_interval) {
			percent_life_visual--;

			if (timef_balloon_destroy_interval > 0.25 || percent_life == percent_life_visual) sound.play();

			timef_balloon_last_destory = ofGetElapsedTimef();

			timef_balloon_destroy_interval -= interval_velocity;
			if (timef_balloon_destroy_interval < min_interval) timef_balloon_destroy_interval = min_interval;

			cout << "[GAME SYSTEM] balloon update:" << "percent life visual->" << percent_life_visual << "/ percent life->" << percent_life << endl;
		}
	}

	if (percent_life < 0) percent_life = 0;
	if (percent_life_visual < 0) percent_life_visual = 0;
}