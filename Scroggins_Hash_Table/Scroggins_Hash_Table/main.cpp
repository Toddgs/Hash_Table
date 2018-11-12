

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <conio.h>
#include <fstream>
#include <cstring>

#include "whoopingCrane.h"

using namespace std;

//Globals...
fstream craneFile;
unordered_map<int, whoopingCrane> hashMap;


void menu() //For displaying and possibly returning the menu options
{
	/*Menu needs to include:
	1. Adding a new crane.
	2. Searching for a crane by it's ID number.
	3. Display all the cranes from a user defined area.
	4. Remove a crane
	5. Display the hash table with each cranes position. 
	*/
}

void pressAnyKey() //Function for pausing the program, use getch.
{
	cout << "Press any key to continue" << endl << endl;
	_getch(); //Waits and gets next character entered.		
}

//Startup functions...

void initializeHash()
{
	/*
	This function needs to be called first, create the hash table and then populate it with 
	6 hand coded cranes. We need to set a hash table size of 19.
	*/

	
	
	//Open the file.
	/*
	craneFile.open("craneFile.bin", ios::in | ios::out | ios::binary | ios::trunc);
	if (!craneFile)
	{
		cout << "Hash file error - file didn't open successfully\n"
			<< "Program will end.";
		pressAnyKey();
		return;
	}
	*/
	
	
	whoopingCrane theCrane = whoopingCrane(1111, (char *)"Mobile", 2.0, (char *)"Male");
	hashMap[1111] = theCrane;
	cout << hashMap[1111];
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
}

void removeCrane()
{
	/*
	This function needs to remove a listed crane. Again, can prolly reuse most of the search code
	and just add a delete function to that.
	*/
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

int main()
{
	initializeHash();
	
	addNewCrane();

	displayHashTable();
	return 0;
}