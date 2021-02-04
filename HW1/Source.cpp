#include <iostream>
#include "StopWatch.h"


int main() {
	Stopwatch test;
	double x = 2;
	for (int i = 0; i < 100; i++) {
		x = x * 2;
	}
	std::cout << x << std::endl;
	test.Stop();
	std::cout << test.time_msec();
}