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
	tsec = std::chrono::duration_cast<std::chrono::seconds>(elapsed_time).count();
	tmsec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time).count();

}

double Stopwatch::time_sec()
{
	return tsec;
}

double Stopwatch::time_msec()
{
	return tmsec;
}

Stopwatch::Stopwatch()
{
	start_time = std::chrono::steady_clock::now();
}
