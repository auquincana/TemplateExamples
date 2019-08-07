// Timing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <chrono>

using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;

template<typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<seconds>(end - begin).count();
}
long fibonacci(unsigned int n)
{
	// The nth fibonacci number
	if (n < 2)
	{
		return n; // 0, 1...
	}
	return fibonacci(n - 2) + fibonacci(n - 1);
}

long fib20()
{
	return fibonacci(20);
}

int main()
{
	long fib40;
	auto seconds = TimeFunc([&]{ fib40 = fibonacci(40); });

	double thirty;
	seconds = TimeFunc([&]() {thirty = 10.0 + 20.0; });

	seconds = TimeFunc(fib20);

    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
