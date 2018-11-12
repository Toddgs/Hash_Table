#include "pch.h"
#include <iostream>
#include <fstream>

#include "whoopingCrane.h"

using namespace std;

//Constructors
whoopingCrane::whoopingCrane()
{
	setID(0);
	setLocation((char *)"");
	setAge(0);
	setGender((char *)"");
}

whoopingCrane::whoopingCrane(int theID, char *theLocation, double theAge, char *theGender)
{
	setID(theID);
	setLocation(theLocation);
	setAge(theAge);
	setGender(theGender);
}


//Destructors



//Get and Set functions.

int whoopingCrane::getID() const
{
	return uniqueID;
}

string whoopingCrane::getLocation() const
{
	return location;
}

double whoopingCrane::getAge() const
{
	return age;
}

string whoopingCrane::getGender() const
{
	return gender;
}

void whoopingCrane::setID(int theID)
{
	if (theID < 1111)
	{
		uniqueID = 0000;
	}
	else
	{
		uniqueID = theID;
	}
}

void whoopingCrane::setLocation(char *theLocation)
{
	strcpy_s(location, theLocation);
}

void whoopingCrane::setAge(double theAge)
{
	if (theAge < 0.0)
	{
		age = 0.0;
	}
	else
	{
		age = theAge;
	}
}

void whoopingCrane::setGender(char *theGender)
{
	strcpy_s(gender, theGender);
}

void whoopingCrane::print()
{
	cout << uniqueID << " is located at: " << location << " and is a " << age
		<< " year old " << gender;
}

ostream & operator<<(ostream & out, const whoopingCrane & theCrane)
{
	out << theCrane.uniqueID << " is located at: " << theCrane.location << " and is a " << theCrane.age
		<< " year old " << theCrane.gender;
	return out;
}
