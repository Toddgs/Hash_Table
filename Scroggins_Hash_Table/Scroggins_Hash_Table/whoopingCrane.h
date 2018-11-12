#pragma once
using namespace std;

//Preventing multiple definitions.
#ifndef whoopingCrane_H
#define whoopingCrane_H

class whoopingCrane
{
	//Data values
	int uniqueID;
	char location[50];
	double age;
	char gender[8];

	//Friends and countrymen...
	friend ostream &operator << (ostream& out, const whoopingCrane& theCrane);
public:
	//Constructors
	whoopingCrane();
	whoopingCrane(int theID, char *theLocation, double theAge, char *theGender);

	//Destructors
	~whoopingCrane();

	//Getters and Setters
	int getID() const;
	string getLocation() const;
	double getAge() const;
	string getGender() const;
	void setID(int theID);
	void setLocation(char *theLocation);
	void setAge(double theAge);
	void setGender(char *theGender);

};

#endif