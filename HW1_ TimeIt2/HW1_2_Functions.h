#ifndef HW1_2_Functions
#define HW1_2_Functions
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
int randomNum(int min, int max);

// makes random vector of a given size
void randomVect(std::vector<int>& rVector, int vectSize, int vectMin, int vectMax); //not used

// reads ever word from text file and pushes back to a vector
void readFile_vector(string filename, std::vector<string>& book);

// reads ever word from text file and pushes back to a list
void readFile_list(string filename, std::list<string>& book);

// reads ever word from text file and pushes back to a set
void readFile_set(string filename, std::set<string>& book);

// Time tests for vectors based on given size
void testVector(string name); // uses in readFile_vector and randomNum

// Time tests for list based on given size
void testList(string name); // uses in readFile_list and randomNum

// Time tests for set based on given size
void testSet(string name); // uses in readFile_set and randomNum


#endif