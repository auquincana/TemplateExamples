// Template.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Accum<int> integer(0);
	integer += 3;
	integer += 7;
	cout << integer.getTotal() << endl;

	Accum<string> string("");
	string += "Hello";
	string += " world";
	cout << string.getTotal() << endl;

	//Person start("", "", 0);
	Accum<Person> people(0);
	Person p1("Solange", "Becerra", 976);
	Person p2("Someone", "else", 456);
	people += p1;
	people += p2;
	cout << people.getTotal() << endl;
	return 0;
}

