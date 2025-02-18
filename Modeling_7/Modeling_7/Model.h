#pragma once
#include <queue>
#include <vector>
#include <time.h>

using namespace std;

class Model {
private:
	queue<double> q;
	double timeOfTaskDoneFirst;
	double timeOfTaskDoneSecond;
	double mu;
	bool active_1;
	bool active_2;
	vector<double> timeInQueue;

	double generateTime();

public:
	Model(double mu);

	void addToQueue(double time);
	size_t getQueueLength();
	
	double getTimeOfTaskDoneFirst();
	double getTimeOfTaskDoneSecond();
	
	void analyze(double time);
	
	vector<double>& getTimeInQueue();
};

