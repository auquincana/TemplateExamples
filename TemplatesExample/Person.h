#include <string>
#ifndef _PERSON_H_
#define _PERSON_H_

class Person
{
private:
	std::string firstName;
	std::string lastName;
	int arbitraryNumber;

public:
	Person(std::string first, std::string last, int arbitrary);
	~Person(void);

	std::string GetName() const;
	int GetNumber() const { return arbitraryNumber;}
	void SetNumber(int number) {arbitraryNumber = number;}
	void SetFirstName(std::string name) {firstName = name;}
};
#endif

/*
	//Person(const Person& p); 
	//bool operator<(Person& p);
	//bool operator<(int i);
	//Person& operator=(const Person& p);
	//friend bool operator<(int i, Person& p);
	//void addResource();
	//std::string GetResourceName() const {return pResource->GetName();}
	
bool operator<(int i, Person& p);
*/