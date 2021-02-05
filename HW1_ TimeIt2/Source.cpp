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
	testList("Anthem.txt");

	//std::list<string> listBook;
	//Stopwatch listTime;
	//double list_msec_average = 0;

	//for (size_t i = 0; i < 5; i++) {
	//	listBook.clear();
	//	listTime.start();
	//	readFile_list("Anthem.txt", listBook);
	//	listTime.stop();
	//	list_msec_average += listTime.time_msec();
	//}

	//cout << "List msec:" << list_msec_average / 5.0 << endl;;

	//std::set<string> setBook;
	//Stopwatch setTime;
	//double set_msec_average = 0;

	//for (size_t i = 0; i < 5; i++) {
	//	setBook.clear();
	//	setTime.start();
	//	readFile_set("Anthem.txt", setBook);
	//	setTime.stop();
	//	set_msec_average += setTime.time_msec();
	//}

	//cout << "Set msec:" << set_msec_average / 5.0 << endl;;


	return 0;
}