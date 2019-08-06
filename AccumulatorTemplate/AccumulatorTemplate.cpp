// AccumulatorTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <vector>

#include "Accum.h"

int myAlgorithms();

int tttmain()
{
    std::cout << "Hello World!\n"; 

	Accum integers(0);
	integers += 3;
	integers += 7;
	std::cout << integers.getTotal() << "\n";

	Accum strings(std::string{ "" });
	strings += "Hello";
	strings += " World!";	
	std::cout << strings.getTotal() << "\n";

	Person im{ Person::Person("Solange", "Becerra", 123) };
	Person yr{ Person::Person("Fabian", "Mancilla", 456) };

	Accum<Person> myAccum(0);
	myAccum += im;
	myAccum += yr;
	std::cout << myAccum.getTotal() << "\n";

	myAlgorithms();

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
