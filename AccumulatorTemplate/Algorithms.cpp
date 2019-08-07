#pragma
// generate_canonical
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>


bool isOdds(int& value)
{
	return (value % 2 != 0);
}

bool islowerThan(int valueL, int valueR)
{
	return (valueL < valueR);
}


// https://en.cppreference.com/w/cpp/named_req/Compare

bool islowerThan(double& valueL, double& valueR)
{
	return (valueL < valueR );
}

bool isGreaterThan(double& valueL, double& valueR)
{
	return (valueL > valueR);
}

bool isGreaterThan(int valueL, int valueR)
{
	return (valueL > valueR);
}

int myAlgorithms()
{
	const int nrolls = 10; // number of experiments

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 1000);
	std::vector<int> p(nrolls);

	unsigned long long int odds = 0;
	for (auto& elem : p)
	{
		elem = distribution(generator);

		if (elem % 2 != 0)
		{
			odds++;
		}
		std::cout << "element :" << elem << std::endl;
	}
	std::cout << "odd :" << odds << std::endl;

	odds = std::count_if(begin(p), end(p), isOdds);

	std::cout << "odd :" << odds << std::endl;

	std::sort(begin(p), end(p));

	bool allof, noneof, anyof;

	allof = std::all_of(begin(p), end(p), isOdds);
	noneof = std::none_of(begin(p), end(p), isOdds);
	anyof = std::any_of(begin(p), end(p), isOdds);

	std::cout << "allof :" << allof << std::endl;
	std::cout << "noneof :" << noneof << std::endl;
	std::cout << "anyof :" << anyof << std::endl;
	int x = 0;

	int index = std::count_if(begin(p), end(p), [x](auto elem) { return islowerThan(elem, x); });
    
	// Encontrar el primer elemento mas grande que x
	auto it = std::find_if(begin(p), end(p), [x](auto elem) { return isGreaterThan(elem, x); });
	auto position = (it > begin(p)) ? (--it - begin(p)): 0;

	std::cout << "index :" << p[position] << std::endl;

	// particular sorting (descending)
	std::sort(begin(p), end(p),[] (auto elem1, auto elem2) { return isGreaterThan(elem1, elem2); });

	for (auto& elem : p)
	{
		std::cout << ": "<< elem << std::endl;
	}

	return 0;
}