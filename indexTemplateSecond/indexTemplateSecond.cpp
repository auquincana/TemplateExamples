// indexTemplateSecond.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// max.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>
T max(T& t1, T& t2)
{
	return t1 < t2 ? t2 : t1;
}

template <class T>
T abs(T& t1)
{
	return 	 t1 < 0 ? -t1 : t1;
}


template <class InputIterator, class T>
InputIterator lower_than_element(InputIterator first, InputIterator last, const T& val)
{
	if (first == last) return last;
	InputIterator largest = first;

	while (++first != last) 
	{
		if (*first > val) return largest;
		largest = first;
	}
	return largest;
}

template <class InputIterator, class T>
unsigned int index(InputIterator first, InputIterator last, const T& val)
{
	if (first == last) return 0;
	unsigned int largest = 0;

	while (++first != last) {
		if (*first > val) return largest;
		++largest;
	}
	return largest;
};

template <class ForwardIterator, class T>
ForwardIterator lower_than_element_fast(ForwardIterator first, ForwardIterator last, const T& val)
{
	ForwardIterator it = --last;

	if (*first >= val) return first;
	else if (*it < val) return it;
	else
	{
		it =  lower_bound(first, last, val);
		if (*it > val)
			--it;

		return it;
	}
}

int main()
{
	int a{ 220 };
	int b{ 44 };

	cout << "Ingrese un entero " << endl;

	cin >> a;
	int c{ a };

	cout << "max of " << a << " and " << b << " is " << max(a, b) << endl;

	vector<int>	 myInstegers{ 100, 120, 140, 150, 160, 180, 200 };
	for (auto i : myInstegers)
	{
		cout << " i : " << i << '\n';
	}

	b = *lower_than_element(myInstegers.begin(), myInstegers.end(), a);

	cout << "The value of index of " << a << " is: " << b << endl;
	cout << "The index is: " << index(myInstegers.begin(), myInstegers.end(), a) << endl;

	cout << "The value of lower bound of  " << a;
	auto it = lower_bound(myInstegers.begin(), myInstegers.end(), a);
	
	if (it == myInstegers.end())
		--it;

	cout << " is: " << *it << endl;

	cout << "The value lower_than_element_fast of  " << c;
	a = *lower_than_element_fast(myInstegers.begin(), myInstegers.end(), c);
	cout << " is: " << a << endl;

	cout << "The value of find_of  " << c;
	it = std::find_if(myInstegers.begin(), myInstegers.end(), [&](auto & element) {return (c < element);});
	if (it == myInstegers.end())
		--it;

	cout << " is: " << *it << endl;

	return 0;
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
