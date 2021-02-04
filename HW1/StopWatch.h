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
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
};
#endif