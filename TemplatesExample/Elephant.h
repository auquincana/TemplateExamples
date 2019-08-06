#pragma once
#include "Entities.h"
#include "Features.h"

using Elephant = Entity<Walk, Gun>;

Elephant createElephant(std::string name, int speed, int bullets)
{
	Elephant e{ name };
	e.walk_set_speed(speed);
	e.gun_set_bullets(bullets);
	return e;
}