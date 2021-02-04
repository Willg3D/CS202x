#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
#include <random> //mt19937
#include <vector>
#include "StopWatch.h"

void randomVect(std::vector<int> &rVector,int vectSize,int vectMin,int vectMax) {

	std::random_device rDevice;
	std::mt19937 generator(rDevice());
	std::uniform_int_distribution<int> distribution(vectMin, vectMax);

	for (size_t i = 0; i < vectSize; ++i) {
		rVector.push_back(distribution(generator));
	}


}
int main() {
	//Stopwatch test;
	std::vector<int> rVector; // random vector
	randomVect(rVector, 1000, 0, 3000);



	
	//td::cout << x << std::endl;
	//test.stop();
	//std::cout << test.time_msec();
}