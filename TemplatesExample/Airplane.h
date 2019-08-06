#pragma once
#include "Entities.h"
#include "Features.h"

using Airplane = Entity<Fly, Laser, Gun>;

Airplane createAirplane(std::string name, int fuel, int intensity, int bullets)
{
	Airplane a{ name };
	a.fly_load_fuel(fuel);
	a.laser_set_intensity(intensity);
	a.gun_set_bullets(bullets);
	return a;
}