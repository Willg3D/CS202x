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
	//std::vector<double> secTime, msecTime;

	cout << "Running Size 10 Search..." << endl;
	Stopwatch vector_size_10;
	for (size_t i = 0; i < 5; ++i){
		std::vector<int> rVector10; // random vector size 10
		randomVect(rVector10, 10, 0, 10);
		std::vector<int> rNum10;// random num vector to use search
		rNum10.push_back(randomNum(0, 10)); // random value to search

		vector_size_10.start();
		std::search(rVector10.begin(), rVector10.end(), rNum10.begin() , rNum10.end());
		vector_size_10.stop();

		cout << "Run " << i + 1 << ":" << endl;
		cout << "Sec: " << vector_size_10.time_sec() << endl;;
		cout << "miliSec: " << vector_size_10.time_msec() << endl;
	}
	



	
	//td::cout << x << std::endl;
	//test.stop();
	//std::cout << test.time_msec();
	return 0;
}