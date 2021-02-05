#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
#include <random> //mt19937
#include <vector>
#include "StopWatch.h"
#include <string>
using std::string;
#include <fstream>


//uses mt19937 to generate a randnom in a given range
int randomNum(int min, int max) {
	std::random_device rDevice;
	std::mt19937 generator(rDevice());
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}

// makes random vector of a given size
void randomVect(std::vector<int> &rVector,int vectSize,int vectMin,int vectMax) {
	rVector.clear(); // clears out vector
	// Pushes random Values into vector.
	for (size_t i = 0; i < vectSize; ++i) {
		rVector.push_back(randomNum(vectMin,vectMax));
	}
}

// Time tests for vectors based on given size
void testVector(int size) {
	double averageTime_sec = 0; // used for average time sec
	double averageTime_msec = 0; // used for average time sec

	// Makes random int Vector (Very Time Consuming)
	cout << "Making size " << size << " random vector..." << endl;
	std::vector<int> rVector; // vector made to be random
	randomVect(rVector, size, 0, size); // rvector to assigned size and a max of assigned size
	std::vector<int> rNum;// random num vector to use search
	rNum.push_back(randomNum(0, size)); // random value to search
	cout << "Done making vector." << endl;

	cout << "Running size " << size << " Tests" << endl << endl;
	Stopwatch timer; // timer using Stopwatch class

	// Search tests
	for (size_t i = 0; i < 5; ++i) {

		timer.start();
		std::search(rVector.begin(), rVector.end(), rNum.begin(), rNum.end());
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	// averaging time
	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Search Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << endl;

	// Sorting Tests
	averageTime_sec = 0.0; // needed to reset vaules for averaging
	averageTime_msec = 0.0;

	std::vector<int> sorted_rVector; // vector that will be sorted

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

	// Binary Search Tests
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

	// Reverse Algorithm Tests
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
	cout << endl <<"----------------------------------------" << endl;

}

void readFile(std::string filename) {
	std::ifstream open(filename);
	if (!open) { // quick error check
		cout << "Error Can't Load Data!" << std::endl;
	}
	else {
		while (!open.eof()) {
			string input;
			std::getline(open, input);
			cout << input << std::endl;
		}
	}
}

int main() {

	// code to test Search, Sort, Binary Search, and Reverse Algorithms
	// based on provided size.

	return 0;
}