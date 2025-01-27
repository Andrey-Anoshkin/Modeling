#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

const float lambda = 1;
const int n = 1e+4;

float generate() {
	return -1.f / lambda * log(rand() * 1.f / RAND_MAX);
}

int main() {
	srand(time(0));
	float chance = 0;
	float T = 0;

	for (int i = 0; i < n; ++i) {
		float t = generate();
		T += t;
		while (t > 0) {
			t -= 0.5;
			if (rand() % 10 < 7)
				break;
			else if (t < 0)
				chance++;
		}
	}

	chance /= n;

	cout << "Chance = " << chance * 100 << "%\n";

	system("pause");
	return 0;
}