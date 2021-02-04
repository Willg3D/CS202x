#include <iostream>
#include<chrono>
#include "StopWatch.h"

void Stopwatch::Start()
{
	start_time = std::chrono::steady_clock::now();
}

void Stopwatch::Stop()
{
	end_time = std::chrono::steady_clock::now();
	elapsed_time = end_time-start_time;
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time).count();

}

Stopwatch::Stopwatch()
{
	start_time = std::chrono::steady_clock::now();
}
