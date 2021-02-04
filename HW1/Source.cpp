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

void testVector(int size) {
	double averageTime_sec = 0;
	double averageTime_msec = 0;

	cout << "Making size " << size << " random vector..." << endl;
	std::vector<int> rVector; // vector made to be random
	randomVect(rVector, size, 0, size); // rvector to assigned size and a max of assigned size
	std::vector<int> rNum;// random num vector to use search
	rNum.push_back(randomNum(0, size)); // random value to search
	cout << "Done making vector." << endl;


	cout << "Running size " << size << " Tests" << endl << endl;
	Stopwatch timer;
	for (size_t i = 0; i < 5; ++i) {

		timer.start();
		std::search(rVector.begin(), rVector.end(), rNum.begin(), rNum.end());
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Search Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << endl;

	averageTime_sec = 0.0;
	averageTime_msec = 0.0;

	std::vector<int> sorted_rVector;

	for (size_t i = 0; i < 5; ++i) {
		sorted_rVector = rVector;
		timer.start();
		std::sort(rVector.begin(), rVector.end());
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}
	
	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Sort Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << endl;

	averageTime_sec = 0.0;
	averageTime_msec = 0.0;

	for (size_t i = 0; i < 5; ++i) {
		timer.start();
		std::binary_search(rVector.begin(), rVector.end(), rNum[0]);
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Binary Search Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << endl;

	averageTime_sec = 0.0;
	averageTime_msec = 0.0;

	std::vector<int> copy_rVector;

	for (size_t i = 0; i < 5; ++i) {
		copy_rVector = rVector;
		timer.start();
		std::reverse(rVector.begin(), rVector.end());
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Reverse Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << endl;
}


int main() {
	//std::vector<double> secTime, msecTime;

	testVector(10);
	cout << "----------------------------------------" << endl;
	testVector(100);
	cout << "----------------------------------------" << endl;
	testVector(1000);
	cout << "----------------------------------------" << endl;
	testVector(10000);
	cout << "----------------------------------------" << endl;
	testVector(100000);
	cout << "----------------------------------------" << endl;
	testVector(1000000);
	cout << "----------------------------------------" << endl;
	testVector(10000000);


	
	//td::cout << x << std::endl;
	//test.stop();
	//std::cout << test.time_msec();
	return 0;
}