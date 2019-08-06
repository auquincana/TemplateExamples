#pragma once
//-------------------------- Entities:

#include <string>

class Basic_Entity
{
	std::string name;

public:
	Basic_Entity(std::string n) : name{ n } 
	{}

	void print_name() const;
	
};

template<class ... Features>
class Entity : public Basic_Entity, public Features...
{
public:
	Entity(std::string name) : Basic_Entity{ name } {}
};



