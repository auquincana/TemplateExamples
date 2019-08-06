#pragma once

//-------------------------- Features:
#include <iostream>

class Walk
{
	int speed{ 0 };
public:
	void walk()
	{
		std::cout << "\tWalk speed " << speed << "\n";
	}
	void walk_set_speed(int s) { speed = s; }
};

class Fly
{
	int fuel{ 0 };
public:
	void fly()
	{
		if (fuel > 0)
		{
			std::cout << "\tFlying\n";
			--fuel;
		}
		else
			std::cout << "\tNo fuel to fly\n";
	}
	void fly_load_fuel(int f) { fuel = f; }
};

class Gun
{
	int bullets{ 0 };
public:
	void gun_fire()
	{
		if (bullets > 0)
		{
			std::cout << "\tGun fire\n"; --bullets;
		}
		else std::cout << "\tGun no more bullets\n";
	}
	void gun_set_bullets(int b) { bullets = b; }
};

class Laser
{
	int intensity{ 2 };
public:
	void laser_fire()
	{
		std::cout << "\tLaser fire intensity " << intensity << "\n";
		if (intensity > 2) --intensity;
	}
	void laser_set_intensity(int i) { if (i < 2) i = 2; intensity = i; }
};