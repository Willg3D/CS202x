#ifndef StopWatch_H
#define StopWatch_H
#include<iostream>
#include<chrono>
#include<string>


class Stopwatch
{
public:
	void Start();
	void Stop();
	Stopwatch();
private:
	std::chrono::steady_clock::time_point start_time;
	std::chrono::steady_clock::time_point end_time;
	std::chrono::duration<double> elapsed_time;
	double time_sec;
	double time_msec;
};
#endif