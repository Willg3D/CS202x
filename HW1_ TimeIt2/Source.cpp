//#include <iostream>
//using std::cout;
//using std::endl;
//#include <algorithm>
//#include <random> //mt19937
//#include <vector>
//#include <list>
//#include <set>
//#include "StopWatch.h"
#include "HW1_2_Functions.h"
//#include <string>
//using std::string;
//#include <fstream>
//#include <sstream> //istreamstring used for words




int main() {
	// All needed used functions mentioned in header
	// Test for each book (text file)
	testVector("Anthem.txt");
	testList("Anthem.txt");
	testSet("Anthem.txt");
	testVector("Alice.txt");
	testList("Alice.txt");
	testSet("Alice.txt");
	testVector("frankenstein.txt");
	testList("frankenstein.txt");
	testSet("frankenstein.txt");
	testVector("Metamorphosis.txt");
	testList("Metamorphosis.txt");
	testSet("Metamorphosis.txt");
	testVector("The Yellow Wallpaper.txt");
	testList("The Yellow Wallpaper.txt");
	testSet("The Yellow Wallpaper.txt");

	return 0;
}