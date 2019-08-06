#pragma once
#include "Entities.h"
#include "Features.h"

using Dragon = Entity<Fly, Laser>;

Dragon createDragon(std::string name, int fuel, int intensity)
{
	Dragon d{ name };
	d.fly_load_fuel(fuel);
	d.laser_set_intensity(intensity);
	return d;
}
