#include <iostream>
#include "StopWatch.h"

void Stopwatch::Start()
{
	start = std::chrono::steady_clock::now();
}

void Stopwatch::Stop()
{
	end = std::chrono::steady_clock::now();
}

Stopwatch::Stopwatch()
{
	start = std::chrono::steady_clock::now();
}
