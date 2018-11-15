

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <conio.h>
#include <fstream>
#include <cstring>

#include "whoopingCrane.h"

using namespace std;

//Function declarations
void pressAnyKey();
int initializeHash();
int hashME(int theID);
void addNewCrane();
void searchForCrane();
void searchByLocation();
void removeCrane();
void displayHashTable();
void addActualCrane(int attempts, int theID, whoopingCrane theCrane);

//Globals...
fstream craneFile;
int maxHashSize = 19;
unordered_map<int, whoopingCrane> hashMap;


void pressAnyKey() //Function for pausing the program, use getch.
{
	cout << "Press any key to continue" << endl << endl;
	_getch(); //Waits and gets next character entered.		
}

//Startup functions...

int initializeHash()
{
	craneFile.open("craneFile.dat", ios::in | ios::out | ios::binary | ios::trunc);
	if (!craneFile)
	{
		cout << "File error - file didn't open properly\n"
			<< "Program will end.\n";
		pressAnyKey();
		return 1;
	}

	hashMap = { {hashME(1111), whoopingCrane(1111, (char *)"Mobile", 2.3, (char *)"Male")},
				{hashME(5721), whoopingCrane(5721, (char *)"Florida", 3.5, (char *)"Female")},
				{hashME(8246), whoopingCrane(8246, (char *)"Mobile", 1.2, (char *)"Male")},
				{hashME(1843), whoopingCrane(1843, (char *)"Mississippi", 5.7, (char *)"Male")},
				{hashME(6424), whoopingCrane(6424, (char *)"Mobile", 1.2, (char *)"Male")},
				{hashME(9999), whoopingCrane(9999, (char *)"Mobile", 1.2, (char *)"Male")},
	};
}

//Helper functions...

int hashME(int theID) //A function to hash the Crane's ID number.
{
	int hashedID = theID / maxHashSize;
	return hashedID;
}

void addNewCrane() //Function for adding a new crane, likely will just call the constructor for the crane with provided data.
{
	int theID, theAge;
	string tempLocation, tempGender;
	cout << "To add a new Whooping Crane we will need some information\n"
		<< "What is the Unique ID of the crane? (4 digit number)\n";
	cin >> theID;
	cin.ignore();
	cout << "What is the location of this Whooping Crane?\n";
	getline(cin, tempLocation);
	cout << "How old is this Whooping Crane?\n";
	cin >> theAge;
	cin.ignore();
	cin.clear();
	cout << "Finally, what gender is this whooping crane? (Male or Female)\n";
	getline(cin, tempGender);

	char * theLocation = new char[tempLocation.size() + 1];
	char * theGender = new char[tempGender.size() + 1];

	copy(tempLocation.begin(), tempLocation.end(), theLocation);
	theLocation[tempLocation.size()] = '\0';
	
	copy(tempGender.begin(), tempGender.end(), theGender);
	theGender[tempGender.size()] = '\0';
	whoopingCrane theCrane = whoopingCrane(theID, theLocation, theAge, theGender);
	
	int attempts = 0;
	addActualCrane(attempts, theID, theCrane);
}

void addActualCrane(int attempts, int theID, whoopingCrane theCrane)
{

	int temp = hashMap.count(hashME(theID) + attempts);
	if (temp == 1)
	{
		if (attempts == 0 || attempts == 1)
		{
			attempts++;
		}
		else
		{
			attempts = attempts * attempts;
		}

		addActualCrane(attempts, theID, theCrane);
	}
	else
	{
		hashMap[hashME(theID) + attempts] = theCrane;
		cout << hashMap[hashME(theID) + attempts] << endl;
		return;
	}
}

void searchForCrane(int value, int attempts)
{
	/*
	This function needs to search for a crane by it's ID at the very least.
	I'd like to be able to give them a way to search for them another way as well, 
	maybe add a name to the class?
	*/
	
	int temp = hashMap.count(hashME(value) + attempts);
	cout << attempts << endl;
	if(temp == 1)
	{ 
		if (hashMap[hashME(value) + attempts].getID == value) //FIXME having a problem right here, can't compare the ID to the passed value because reasons.
			cout << hashMap[hashME(value) + attempts] << endl;
		else
		{
			if (attempts == 0 || attempts == 1)
				attempts++;
			else
				attempts = attempts ^ 2;
			searchForCrane(value, attempts);
			cout << "It ain't here son, try again.\n";
		}
	}
	else 
	{
		if (attempts == 0 || attempts == 1)
			attempts++;
		else
			attempts = attempts ^ 2;
		searchForCrane(value, attempts);
		cout << "It ain't here son, try again.\n";
	}
}

void searchByLocation()
{
	string searchedLocation;
	cout << "Please enter a location to search for: \n";
	getline(cin, searchedLocation);
	pressAnyKey();
	for (const auto& item : hashMap)
	{
		if (searchedLocation == item.second.getLocation())
			cout << item.second.getID() << " is located in " << searchedLocation << endl;
	}
}

void removeCrane()
{
	/*
	This function needs to remove a listed crane. Again, can prolly reuse most of the search code
	and just add a delete function to that.
	*/
	int key;
	cout << "Which crane would you like to delete?\n";
	cin >> key;
	
	int temp = hashMap.count(hashME(key));

	if (temp == 1)
	{
		cout << hashMap[hashME(key)] << " has been deleted" << endl;
		hashMap.erase(hashME(key));
	}
	else
	{
		cout << "It ain't here son, try again.\n";
	}
}

void displayHashTable()
{
	/*
	This function needs to display the entire hash table and print out the cranes in their proper position. 
	*/
	for (const auto& item : hashMap)
	{
		cout << item.second << endl;
	}
}

void menu() //For displaying and possibly returning the menu options
{
	/*Menu needs to include:
	1. Adding a new crane.
	2. Searching for a crane by it's ID number.
	3. Display all the cranes from a user defined area.
	4. Remove a crane
	5. Display the hash table with each cranes position.
	*/
	int choice;
	bool theMeaningOfLife = true;
	while (theMeaningOfLife)
	{
		cout << "Please select an option from the following menu:\n"
			<< "1. Add a new Whooping Crane to the list.\n"
			<< "2. Search for a Whooping Crane by it's ID number.\n"
			<< "3. Display all the cranes from a user defined area.\n"
			<< "4. Remove a crane.\n"
			<< "5. Display the hash table with each cranes position.\n"
			<< "6. Exit the program\n";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
		{
			addNewCrane();
			pressAnyKey();
			break;
		}
		case 2:
		{
			int value, attempts;
			cout << "What unique ID do you wish to search for?\n";
			cin >> value;
			attempts = 0;
			searchForCrane(value, attempts);
			cin.ignore();
			pressAnyKey();
			break;
		}
		case 3:
		{
			searchByLocation();
			pressAnyKey();
			break;
		}
		case 4:
		{
			removeCrane();
			pressAnyKey();
			break;
		}
		case 5:
		{
			displayHashTable();
			pressAnyKey();
			break;
		}
		case 6:
		{
			theMeaningOfLife = false;
			pressAnyKey();
			break;
		}
		}
	}
}

void readBinary(int pos, whoopingCrane& theCrane)
{
	craneFile.seekg(pos * sizeof(whoopingCrane));
	craneFile.read((char *)&theCrane, sizeof(whoopingCrane));
}

void writeBinary(int pos, whoopingCrane theCrane)
{
	craneFile.seekp(pos * sizeof(whoopingCrane));
	craneFile.write((char *)&theCrane, sizeof(whoopingCrane));
	craneFile.flush();
	craneFile.seekp(0 * sizeof(whoopingCrane));
}


int main()
{
	initializeHash();
	menu();
	return 0;
}

