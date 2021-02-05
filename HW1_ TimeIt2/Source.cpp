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


	testVector("Anthem.txt");
	testList("Anthem.txt");
	testSet("Anthem.txt");


	return 0;
}