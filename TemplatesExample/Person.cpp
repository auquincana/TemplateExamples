
#include "Person.h"


Person::Person(std::string first, std::string last, int arbitrary):firstName(first), lastName(last), arbitraryNumber(arbitrary)
{
	//std::cout << " constructing Person " << arbitraryNumber << std::endl;
}


Person::~Person(void)
{
	//std::cout << " destructing Person " << arbitraryNumber << std::endl;
}


std::string Person::GetName() const
{
	return firstName + " " + lastName;
}

/*

// No need destructor  with use smart pointer
Person::~Person(void)
{
	//delete pResource; // Clean up memory allocated on pResource;
}

bool Person::operator<(Person& p)
{
	return arbitraryNumber < p.arbitraryNumber;

}

bool Person::operator<(int i)
{
	return arbitraryNumber < i;
}

// friend function
bool operator<(int i, Person& p)
{
	return i < p.arbitraryNumber;
}

void Person::addResource()
{
	//delete pResource;
	pResource.reset();
	pResource = std::make_shared<Resource>("Resource for " + GetName());
}


// Operator "=" return a reference
Person& Person::operator=(const Person& p)
{
	firstName = p.firstName;
	lastName = p.lastName;
	arbitraryNumber = p.arbitraryNumber;
	delete pResource;
	pResource = new Resource(p.pResource->GetName());
	return *this;
}

//, pResource(nullptr) No need initialize a shared pointer

// Al copiar un puntero a una referencia de memoria no se debe copiar la direccion de memoria sino hacer que el nuevo objeto apunte al mismo elemento que está apuntado el objeto copiado
Person::Person(const Person& p):firstName(p.firstName), lastName(p.lastName), arbitraryNumber(p.arbitraryNumber), pResource(new Resource(p.pResource->GetName()))
{
}




*/