

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
void initializeHash();
int hashME(int theID);
void addNewCrane();
void searchForCrane();
void searchByLocation();
void removeCrane();
void displayHashTable();

//Globals...
fstream craneFile;
int maxHashSize = 19;
const whoopingCrane placeHolderCrane(0000, (char *)"----------------------", 0.0, (char *)"-------");
unordered_map<int, whoopingCrane> hashMap;


void pressAnyKey() //Function for pausing the program, use getch.
{
	cout << "Press any key to continue" << endl << endl;
	_getch(); //Waits and gets next character entered.		
}

//Startup functions...

void initializeHash()
{
	hashMap = { {1111, whoopingCrane(1111, (char *)"Mobile", 2.3, (char *)"Male")},
				{5721, whoopingCrane(5721, (char *)"Florida", 3.5, (char *)"Female")},
				{8246, whoopingCrane(8246, (char *)"Mobile", 1.2, (char *)"Male")},
				{1843, whoopingCrane(1843, (char *)"Mississippi", 5.7, (char *)"Male")},
				{6424, whoopingCrane(6424, (char *)"Mobile", 1.2, (char *)"Male")},
				{9999, whoopingCrane(9999, (char *)"Mobile", 1.2, (char *)"Male")},
	};
	
}

//Helper functions...

int hashME(int theID) //A function to hash the Crane's ID number.
{
	return 0;
}

void addNewCrane() //Function for adding a new crane, likely will just call the constructor for the crane with provided data.
{
	int theID, theAge;
	string tempLocation, tempGender;
	//char *theLocation, *theGender;
	//ID, Location, Age, Gender
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
	hashMap[theID] = theCrane;
	cout << hashMap[theID] << endl;
}

void searchForCrane()
{
	/*
	This function needs to search for a crane by it's ID at the very least.
	I'd like to be able to give them a way to search for them another way as well, 
	maybe add a name to the class?
	*/
	int value;
	cout << "What unique ID do you wish to search for?\n";
	cin >> value;
	int temp = hashMap.count(value);
	
	
	if(temp == 1)
	{ 
		cout << hashMap[value] << endl;
	}
	else 
	{
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
	
	int temp = hashMap.count(key);


	if (temp == 1)
	{
		
		cout << hashMap[key] << " has been deleted" << endl;
		hashMap.erase(key);
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

	for (const auto& n : hashMap)
	{
		cout << n.second << endl;
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
			searchForCrane();
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

int main()
{
	initializeHash();
	menu();
	return 0;
}