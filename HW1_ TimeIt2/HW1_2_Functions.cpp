#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
#include <random> //mt19937
#include <vector>
#include <list>
#include <set>
#include "StopWatch.h"
#include "HW1_2_Functions.h"
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
void randomVect(std::vector<int>& rVector, int vectSize, int vectMin, int vectMax) {
	rVector.clear(); // clears out vector
	// Pushes random Values into vector.
	for (size_t i = 0; i < vectSize; ++i) {
		rVector.push_back(randomNum(vectMin, vectMax));
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

	cout << "Running " << name << " Book Vector Tests" << endl << endl;
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

	// binary search tests
	averageTime_sec = 0.0;
	averageTime_msec = 0.0;

	for (size_t i = 0; i < 5; ++i) {
		rWord.push_back(book[randomNum(0, book.size())]); // random value to search

		timer.start();
		std::binary_search(sorted_book.begin(), sorted_book.end(), rWord[0]);
		timer.stop();

		rWord.clear();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "average binary search time: " << endl;
	cout << "sec: " << averageTime_sec << endl;;
	cout << "milisec: " << averageTime_msec << endl;
	cout << endl;

	// Reverse Algorithm Tests
	averageTime_sec = 0.0;
	averageTime_msec = 0.0;

	std::vector<string> copy_book;

	for (size_t i = 0; i < 5; ++i) {
		copy_book = book;
		timer.start();
		std::reverse(copy_book.begin(), copy_book.end());
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Reverse Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << endl << "----------------------------------------" << endl;

}

// Time tests for list based on given size
void testList(string name) {
	double averageTime_sec = 0; // used for average time sec
	double averageTime_msec = 0; // used for average time sec

	std::list<string> rWord;// random word vector to use search

	cout << "Running " << name << " Book List Tests" << endl << endl;
	std::list<string> book;

	Stopwatch timer; // timer using Stopwatch class

	for (size_t i = 0; i < 5; i++) {
		book.clear();
		timer.start();
		readFile_list(name, book);
		timer.stop();
		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();
	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average List Read Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << endl;

	// Search tests
	for (size_t i = 0; i < 5; ++i) {
		auto book_front = book.begin();
		std::advance(book_front, randomNum(0, book.size()));
		rWord.push_back(*book_front);

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

	// sorting tests
	averageTime_sec = 0.0; // needed to reset vaules for averaging
	averageTime_msec = 0.0;

	std::list<string> sorted_book; // vector that will be sorted

	for (size_t i = 0; i < 5; ++i) {
		sorted_book = book;
		timer.start();
		sorted_book.sort(); // using sort function that comes with list
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "average sort time: " << endl;
	cout << "sec: " << averageTime_sec << endl;;
	cout << "milisec: " << averageTime_msec << endl;
	cout << endl;

	// binary search tests
	averageTime_sec = 0.0;
	averageTime_msec = 0.0;

	for (size_t i = 0; i < 5; ++i) {
		auto book_front = book.begin();
		std::advance(book_front, randomNum(0, book.size()));
		//rWord.push_back(*book_front);
		string temp = *book_front;

		timer.start();
		std::binary_search(sorted_book.begin(), sorted_book.end(), temp);
		timer.stop();

		rWord.clear();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "average binary search time: " << endl;
	cout << "sec: " << averageTime_sec << endl;;
	cout << "milisec: " << averageTime_msec << endl;
	cout << endl;

	// Reverse Algorithm Tests
	averageTime_sec = 0.0;
	averageTime_msec = 0.0;

	std::list<string> copy_book;

	for (size_t i = 0; i < 5; ++i) {
		copy_book = book;
		timer.start();
		std::reverse(copy_book.begin(), copy_book.end());
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Reverse Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << endl << "----------------------------------------" << endl;

}

// Time tests for vectors based on given size
void testSet(string name) {
	double averageTime_sec = 0; // used for average time sec
	double averageTime_msec = 0; // used for average time sec

	std::set<string> rWord;// random word vector to use search

	cout << "Running " << name << " Book Set Tests" << endl << endl;
	std::set<string> book;

	Stopwatch timer; // timer using Stopwatch class

	for (size_t i = 0; i < 5; i++) {
		book.clear();
		timer.start();
		readFile_set(name, book);
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
		//rWord.push_back(book[randomNum(0, book.size())]); // random value to search

		auto book_front = book.begin();
		std::advance(book_front, randomNum(0, book.size()));
		rWord.insert(*book_front);

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

	std::set<string> sorted_book; // vector that will be sorted

	for (size_t i = 0; i < 5; ++i) {
		sorted_book = book;
		timer.start();
		//std::sort(sorted_book.begin(), sorted_book.end());
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Sort Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << "Sets can not be sorted" << endl;
	cout << endl;

	// binary search tests
	averageTime_sec = 0.0;
	averageTime_msec = 0.0;

	for (size_t i = 0; i < 5; ++i) {
		auto book_front = book.begin();
		std::advance(book_front, randomNum(0, book.size()));
		string temp = *book_front;
		//rWord.insert(*book_front);

		timer.start();
		std::binary_search(book.begin(), book.end(), temp);
		timer.stop();

		rWord.clear();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "average binary search time: " << endl;
	cout << "sec: " << averageTime_sec << endl;;
	cout << "milisec: " << averageTime_msec << endl;
	cout << endl;

	// Reverse Algorithm Tests
	averageTime_sec = 0.0;
	averageTime_msec = 0.0;

	std::set<string> copy_book;

	for (size_t i = 0; i < 5; ++i) {
		copy_book = book;
		timer.start();
		//std::reverse(copy_book.begin(), copy_book.end());
		timer.stop();

		averageTime_sec += timer.time_sec();
		averageTime_msec += timer.time_msec();

	}

	averageTime_sec = averageTime_sec / 5.0;
	averageTime_msec = averageTime_msec / 5.0;

	cout << "Average Reverse Time: " << endl;
	cout << "Sec: " << averageTime_sec << endl;;
	cout << "miliSec: " << averageTime_msec << endl;
	cout << "Sets can not be reversed, but one can reverse iterators." << endl;
	cout << endl << "----------------------------------------" << endl;

}