#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
#include <random> //mt19937
#include <vector>
#include "StopWatch.h"


int main() {
	//Stopwatch test;
	std::vector<int> rVector; // random vector
	int vectSize = 1000;
	int vectMin = 0; int vectMax = 3000;
	
	std::random_device rDevice;
	std::mt19937 generator(rDevice());
	std::uniform_int_distribution<int> distribution(vectMin, vectMax);

	for (size_t i = 0; i < vectSize; ++i) {
		rVector.push_back(distribution(generator));
	}

	
	//td::cout << x << std::endl;
	//test.stop();
	//std::cout << test.time_msec();
}