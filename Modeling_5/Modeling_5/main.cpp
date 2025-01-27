#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

const int n = 1000;
const int Mu = 100;
const int sigma = 5;

float generate() {
	float R = 0;
	for (int i = 0; i < 12; ++i) 
		R += rand() * 1.f / RAND_MAX;
	
	return Mu + sigma * (R - 6);
}

int main() {
	srand(time(0));
	vector<float> weights;

	float M = 0;
	for (int i = 0; i < n; ++i) {
		float weight = 0;
		for (int j = 0; j < 10; ++j) 
			weight += generate();
		
		M += weight * 1.0f / n;
		weights.push_back(weight);
	}


	float sqr_sum = 0;
	for (int i = 0; i < n; ++i) 
		sqr_sum += (weights[i] - M) * (weights[i] - M);
	
	float S = sqrt(sqr_sum / (n - 1));

	cout << "M = " << M << "\n";
	cout << "S = " << S << "\n";

	system("pause");
	return 0;
}