#include "Model.h"

Model::Model(double mu) {
	srand(time(0));
	this->mu = mu;
	this->active_1 = false;
	this->active_2 = false;
	this->timeOfTaskDoneFirst = 100000;
	this->timeOfTaskDoneSecond = 100000;
}

void Model::addToQueue(double time) {
	this->q.push(time);
}

double Model::getFromQueue() {
	return this->q.front();
}

size_t Model::getQueueLength() {
	return this->q.size();
}

double Model::getTimeOfTaskDoneFirst() {
	return this->timeOfTaskDoneFirst;
}

double Model::getTimeOfTaskDoneSecond() {
	return this->timeOfTaskDoneSecond;
}

double Model::generateTime() {
	int r = rand();
	return -1.f / this->mu * log((r % RAND_MAX + 1) * 1.f / RAND_MAX);
}

void Model::analyze(double time) {
	if (this->active_1) {
		if (time >= this->timeOfTaskDoneFirst && time <= this->timeOfTaskDoneFirst) {
			this->active_1 = false;
			this->timeOfTaskDoneFirst = 100000;
		}
	}
	else {
		if (!this->q.empty()) {
			this->active_1 = true;
			this->timeInQueue.push_back(time - this->q.front());
			this->q.pop();
			this->timeOfTaskDoneFirst = time + this->generateTime();
		}
	}

	if (this->active_2) {
		if (time >= this->timeOfTaskDoneSecond && time <= this->timeOfTaskDoneSecond) {
			this->active_2 = false;
			this->timeOfTaskDoneSecond = 100000;
		}
	}
	else {
		if (!this->q.empty()) {
			this->active_2 = true;
			this->timeInQueue.push_back(time - this->q.front());
			this->q.pop();
			this->timeOfTaskDoneSecond = time + this->generateTime();
		}
	}
}

vector<double>& Model::getTimeInQueue() {
	return this->timeInQueue;
}