#pragma once
#include <iostream>
class HashTables
{
public: 
	//variables stored inside of array
	struct Table
	{
		bool valid = true;
		std::string userName;
		int phoneNumber;
	};

	HashTables();
	~HashTables();

	//size of array
	static const int arraySize = 5;
	Table array[arraySize];

	// function to hash parameter str returns a random number that is always the same if the same name keeps being passed
	unsigned int RSHash (const char* str, unsigned int length);

	//adds data into array into a specified index based of the hash function % arraysize
	void Add(std::string userInput, unsigned int phoneNumber);

	//searches array for userInput and returns phone number
	int Search(std::string userInput);


};

