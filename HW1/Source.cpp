#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
#include <random> //mt19937
#include <vector>
#include "StopWatch.h"

int randomNum(int min, int max) {
	std::random_device rDevice;
	std::mt19937 generator(rDevice());
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}

void randomVect(std::vector<int> &rVector,int vectSize,int vectMin,int vectMax) {
	rVector.clear(); // clears out vector
	// Pushes random Values into vector.
	for (size_t i = 0; i < vectSize; ++i) {
		rVector.push_back(randomNum(vectMin,vectMax));
	}
}


int main() {
	//Stopwatch test;
	std::vector<int> rVector; // random vector
	randomVect(rVector, 10, 0, 10);
	
	
	for (size_t i = 0; i < 10; ++i) {
		cout << rVector[i];
	}


	
	//td::cout << x << std::endl;
	//test.stop();
	//std::cout << test.time_msec();
	return 0;
}