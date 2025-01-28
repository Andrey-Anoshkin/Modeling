	#include <iostream>

	using namespace std;

	const int a = 20;
	const float k = 0.02;
	const float dt = 1e-3;
	const float T = 40;
	const float eps = 1e-3;

	float f(const float x) {
		return -k * (x - a);
	}

	int main() {
		float x = 150;
		float t = 0;
	
		for (; abs(x - T) >= eps; t += dt) 
			x += dt * f(x);
	
		cout << "Time: " << t << "\n";

		system("pause");

		return 0;
	}