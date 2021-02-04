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

void searchVect(int size) {
	cout << "Running Size " << size << " Search..." << endl;
	Stopwatch vector_size;
	for (size_t i = 0; i < 5; ++i) {
		std::vector<int> rVector; // random vector size 10
		randomVect(rVector, size, 0, size);
		std::vector<int> rNum;// random num vector to use search
		rNum.push_back(randomNum(0, size)); // random value to search

		vector_size.start();
		std::search(rVector.begin(), rVector.end(), rNum.begin(), rNum.end());
		vector_size.stop();

		cout << "Run " << i + 1 << ":" << endl;
		cout << "Sec: " << vector_size.time_sec() << endl;;
		cout << "miliSec: " << vector_size.time_msec() << endl;
	}

	cout << endl;
}


int main() {
	//std::vector<double> secTime, msecTime;

	searchVect(10);
	searchVect(100);
	searchVect(1000);
	searchVect(1000000);


	
	//td::cout << x << std::endl;
	//test.stop();
	//std::cout << test.time_msec();
	return 0;
}