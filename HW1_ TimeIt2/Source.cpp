#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
#include <random> //mt19937
#include <vector>
#include <list>
#include <set>
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

			while (iss >> word) {
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

void readFile_set(string filename, std::set<string>& book) {
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
				book.insert(word);
			}
		}
	}
}

// Time tests for vectors based on given size
void testVector(string name) {
	double averageTime_sec = 0; // used for average time sec
	double averageTime_msec = 0; // used for average time sec

	std::vector<string> rWord;// random word vector to use search

	cout << "Running " << name << " Book Tests" << endl << endl;
	std::vector<string> book;

	Stopwatch timer; // timer using Stopwatch class

	for (size_t i = 0; i < 5; i++) {
		book.clear();
		timer.start();
		readFile_vector(name, book);
		timer.stop();
		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();
	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Vector Read Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << endl;



	// Search tests
	for (size_t i = 0; i < 5; ++i) {
		rWord.push_back(book[randomNum(0, book.size())]); // random value to search

		timer.start();
		std::search(book.begin(), book.end(), rWord.begin(), rWord.end());
		timer.stop();

		rWord.clear();

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

	std::vector<string> sorted_book; // vector that will be sorted

	for (size_t i = 0; i < 5; ++i) {
		sorted_book = book;
		timer.start();
		std::sort(sorted_book.begin(), sorted_book.end());
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

	//// binary search tests
	//averagetime_sec = 0.0;
	//averagetime_msec = 0.0;

	//for (size_t i = 0; i < 5; ++i) {
	//	timer.start();
	//	std::binary_search(rvector.begin(), rvector.end(), rnum[0]);
	//	timer.stop();

	//	averagetime_sec += timer.time_sec();
	//	averagetime_msec += timer.time_msec();

	//}

	//averagetime_sec = averagetime_sec / 5.0;
	//averagetime_msec = averagetime_msec / 5.0;

	//cout << "average binary search time: " << endl;
	//cout << "sec: " << averagetime_sec << endl;;
	//cout << "milisec: " << averagetime_msec << endl;
	//cout << endl;

	//// Reverse Algorithm Tests
	//averageTime_sec = 0.0;
	//averageTime_msec = 0.0;

	//std::vector<int> copy_rVector;

	//for (size_t i = 0; i < 5; ++i) {
	//	copy_rVector = rVector;
	//	timer.start();
	//	std::reverse(rVector.begin(), rVector.end());
	//	timer.stop();

	//	averageTime_sec += timer.time_sec();
	//	averageTime_msec += timer.time_msec();

	//}

	//averageTime_sec = averageTime_sec / 5.0;
	//averageTime_msec = averageTime_msec / 5.0;

	//cout << "Average Reverse Time: " << endl;
	//cout << "Sec: " << averageTime_sec << endl;;
	//cout << "miliSec: " << averageTime_msec << endl;
	//cout << endl <<"----------------------------------------" << endl;

}



int main() {
	//std::vector<string> vectorBook;
	//Stopwatch vectorTime;
	//double vector_msec_average = 0;

	//for (size_t i = 0; i < 5; i++){
	//	vectorBook.clear();
	//	vectorTime.start();
	//	readFile_vector("Anthem.txt", vectorBook);
	//	vectorTime.stop();
	//	vector_msec_average += vectorTime.time_msec();
	//}

	//cout << "Vector msec:" << vector_msec_average / 5.0 << endl;;

	//testVector("Anthem.txt", vectorBook);

	testVector("Anthem.txt");


	std::list<string> listBook;
	Stopwatch listTime;
	double list_msec_average = 0;

	for (size_t i = 0; i < 5; i++) {
		listBook.clear();
		listTime.start();
		readFile_list("Anthem.txt", listBook);
		listTime.stop();
		list_msec_average += listTime.time_msec();
	}

	cout << "List msec:" << list_msec_average / 5.0 << endl;;

	std::set<string> setBook;
	Stopwatch setTime;
	double set_msec_average = 0;

	for (size_t i = 0; i < 5; i++) {
		setBook.clear();
		setTime.start();
		readFile_set("Anthem.txt", setBook);
		setTime.stop();
		set_msec_average += setTime.time_msec();
	}

	cout << "Set msec:" << set_msec_average / 5.0 << endl;;


	return 0;
}