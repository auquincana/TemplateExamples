#pragma

#include <algorithm>
#include <numeric>
//#include <functional>
#include <iostream>
#include <string>
#include <vector>

// This is LegacyCode
#ifndef TOL
#define TOL 10e-7
#endif

class Tolerance
{
public:
	static int const epsilon = 10e-7;
};

struct NettingSet
{
	int st;
	std::string name;  // Does not participate in comparisons
};

typedef unsigned long int st;

typedef std::string name;

typedef std::pair<st, name> pairNettingSet;

bool operator<(const NettingSet & lhs, const NettingSet & rhs)
{
	return lhs.st < rhs.st;
}

bool operator<(const pairNettingSet & lhs, const pairNettingSet & rhs)
{
	return lhs.first < rhs.first;
}

bool myOwnOrder(const pairNettingSet & lhs, const pairNettingSet & rhs)
{
	// ordenamos los dos niveles, primero stopping time y luego nombre descendente.
	auto result = (lhs.first > rhs.first) ? (lhs.first > rhs.first):(lhs.second > rhs.second);
	return result;
}

bool isGreaterThanCero(const double& value)
{
	return (value - Tolerance::epsilon > 0 );
}

bool isLessThanCero(const double& value)
{
	return (value - Tolerance::epsilon < 0);
}

int main()
{
	std::vector<NettingSet> v =
	{
		{108, "Zaphod"},
		{32, "Arthur"},
		{108, "Ford"},
	    {108, "Iris"}
	};

	std::stable_sort(v.begin(), v.end());

	for (auto e : v)
		std::cout << e.st << ", " << e.name << '\n';

	pairNettingSet first{ 108, "Zaphod" };

	std::vector<pairNettingSet> vv =
	{
		{108, "Zaphod"},
		{32, "Arthur"},
		{108, "Ford"},
		{108, "Iris"}
	};

	std::stable_sort(vv.begin(), vv.end(), myOwnOrder);

	for (auto e : vv)
		std::cout << e.first << ", " << e.second << '\n';

	std::vector<double> exposure{ -5.0, 7, 4, 2, -8.0, 6, 1, 9, 0, 3.0 };

	auto posexp = exposure;
	auto negexp = exposure;

	std::replace_copy_if(begin(exposure), end(exposure), begin(posexp), isLessThanCero, 0.0);
	std::replace_copy_if(begin(exposure), end(exposure), begin(negexp), isGreaterThanCero, 0.0);

	auto k = 0;
	for (auto e : exposure)
	{
		std::cout << " max(v, 0) : " << e << ':' << posexp[k] << '\n';
		//std::cout << " min(v, 0) : " << e << ':' <<negexp[k] << '\n';
		++k;
	}

	k = 0;
	for (auto e : exposure)
	{
		//std::cout << " max(v, 0) : " << e << ':' << posexp[k] << '\n';
		std::cout << " min(v, 0) : " << e << ':' << negexp[k] << '\n';
		++k;
	}

	double sumPosExposure = std::accumulate(begin(posexp), end(posexp), 0.0);
	double sumNegExposure = std::accumulate(begin(negexp), end(negexp), 0.0);
	double sumExposure = std::accumulate(begin(exposure), end(exposure), 0.0);

	size_t totalSim = posexp.size();

	std::cout << " promedio max(v, 0) : " << sumPosExposure / totalSim << '\n';
	std::cout << " promedio min(v, 0) : " << sumNegExposure / totalSim << '\n';
	std::cout << " promedio v : " << sumExposure / totalSim << '\n';


	std::vector<double> pnl{ -5.0, -7, 4.0 , 2, -8.0, 6, 1, 9, 0, 3.0 };
	double var = -5.0; // Supongamos que fuimos capaces de calcular el percentil.

	std::sort(begin(pnl), end(pnl));                         // Ordenamos el vector

	for (auto p : pnl)
	{
		std::cout <<  p << '\t';
	}

	auto findVar = std::find(begin(pnl), end(pnl), var);     // Encontramos la posición del var
	auto numElements = std::distance(begin(pnl), findVar);   // Determinamos cuantos elementos hay entre el inicio y el var
	double sumForCvaR = std::accumulate(begin(pnl), findVar, 0.0); // Acumulamos lo que es menor que VaR
	double cVaR = sumForCvaR / numElements;  // Determinamos cVaR

	return 0;
}