#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>
#include "Model.h"

using namespace std;

double lambda = 20;
double mu = 15;

double generateTask() {
	int r = rand();
	return -1.0 / lambda * log(min(max(r, 1), RAND_MAX - 1) * 1.0 / RAND_MAX);
}

double nextMoment(Model& model, double time_of_task) {
	double min_time =
		(model.getTimeOfTaskDoneFirst() <= model.getTimeOfTaskDoneSecond()) ?
		model.getTimeOfTaskDoneFirst() : model.getTimeOfTaskDoneSecond();

	double next_moment = (min_time <= time_of_task) ? min_time : time_of_task;

	return next_moment;
}

double u(Model& model) {
	float U = 0;
	vector<double>::iterator begin = model.getTimeInQueue().begin();
	vector<double>::iterator end = model.getTimeInQueue().end();
	for (vector<double>::iterator it = begin; it != end; U += *it, ++it);

	return U / model.getTimeInQueue().size();
}

double n(vector<double>& v, double T) {
	float n = 0;
	for (int i = 0; i < v.size(); n += i * v[i] / T, ++i);
	
	return n;
}

int main() {
	srand(time(0));

	double current_time = 0;
	int current_count = 0;
	int total_count = 1000;

	cout << "Model M|M|2\n\n";

	cout << "lambda = "; cin >> lambda;
	cout << "mu = "; cin >> mu;
	cout << "\n";

	Model model(mu);

	double time_of_task = 0;
	vector<double> countInQueue;

	while ((current_count < total_count) || (model.getTimeInQueue().size() < total_count)) {
		if (current_time == time_of_task) {
			current_count++;
			
			model.addToQueue(time_of_task);

			time_of_task += generateTask();
		}
		
		model.analyze(current_time);
		for (int i = countInQueue.size(); i < model.getQueueLength() + 1; countInQueue.push_back(0), ++i);

		countInQueue[model.getQueueLength()] -= current_time;
		current_time = nextMoment(model, time_of_task);
		countInQueue[model.getQueueLength()] += current_time;
	}

	cout << "u = " << u(model) << "\n";
	cout << "n = " << n(countInQueue, current_time) << "\n";

	system("pause");

	return 0;
}