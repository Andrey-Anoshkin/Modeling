#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

const int n = 1e+5;

int main() {
	vector<int> experiments(1000, 0);
	srand(time(0));

	for (int i = 0; i < n; ++i) {
		int days_counter = 0;
		int space_left = 10;
		do {
			days_counter++;
			space_left -= rand() % 4;
		} while (space_left > 0);

		experiments[days_counter] += 1;
	}

	float M = 0;
	for (int i = 1; i < experiments.size(); ++i) 
		M += i * 1.0f * experiments[i] / n;
	
	cout << "M = " << M << "\n";

	system("pause");
	return 0;
}