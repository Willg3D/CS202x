#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
#include <random> //mt19937
#include <vector>
#include <list>
#include "StopWatch.h"
#include <string>
using std::string;
#include <fstream>
#include <sstream> //istreamstring used for words


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

// reads ever word from text file and pushes back to a vector
void readFile_vector(string filename, std::vector<string>& book) {
	std::ifstream open(filename);
	string word;
	if (!open) { // quick error check
		cout << "Error Can't Load Data!" << std::endl;
	}
	else {
		while (!open.eof()) {
			string data;
			std::getline(open, data);
			std::istringstream iss(data);
			
			while (iss >> word){
				book.push_back(word);
			}
		}
	}
}

void readFile_list(string filename, std::list<string>& book) {
	std::ifstream open(filename);
	string word;
	if (!open) { // quick error check
		cout << "Error Can't Load Data!" << std::endl;
	}
	else {
		while (!open.eof()) {
			string data;
			std::getline(open, data);
			std::istringstream iss(data);

			while (iss >> word) {
				book.push_back(word);
			}
		}
	}
}

int main() {
	std::vector<string> test;
	Stopwatch vectorTime;
	double vector_msec_average = 0;

	for (size_t i = 0; i < 5; i++){
		test.clear();
		vectorTime.start();
		readFile_vector("Anthem.txt", test);
		vectorTime.stop();
		vector_msec_average += vectorTime.time_msec();
	}

	cout << "Vector msec:" << vector_msec_average / 5.0 << endl;;

	
	std::list<string> test2;
	Stopwatch listTime;
	double list_msec_average = 0;

	for (size_t i = 0; i < 5; i++) {
		test2.clear();
		listTime.start();
		readFile_list("Anthem.txt", test2);
		listTime.stop();
		list_msec_average += listTime.time_msec();
	}

	cout << "List msec:" << list_msec_average / 5.0 << endl;;

	//for (size_t i = 0; i < test.size(); i++) {
	//	cout << test[i] << endl;
	//}

	return 0;
}