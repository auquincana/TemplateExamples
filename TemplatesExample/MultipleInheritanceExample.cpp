#pragma

#include "Dragon.h"
#include "Elephant.h"
#include "Airplane.h"

#include <iostream>

int main()
{	
	std::cout << "Hello World!\n";

	//---------------------------- Dragon
	Dragon dragon = createDragon("Dragon", 2, 4);
	dragon.print_name();
	dragon.fly();
	dragon.laser_fire();
	dragon.fly();
	dragon.fly();
	dragon.laser_fire();

	//----------------------------- Elephant
	Elephant elephant = createElephant("Elephant", 3, 2);
	elephant.print_name();
	elephant.walk();
	elephant.gun_fire();
	elephant.gun_fire();
	elephant.gun_fire();

	//----------------------------- Airplane
	Airplane airplane = createAirplane("Airplane", 2, 3, 2);
	airplane.print_name();
	airplane.fly();
	airplane.laser_fire();
	airplane.gun_fire();
	airplane.gun_fire();
	airplane.fly();
	airplane.laser_fire();
	airplane.gun_fire();
	airplane.fly();

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
