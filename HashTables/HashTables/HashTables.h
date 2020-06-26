#pragma once
#include <iostream>
class HashTables
{
public: 
	struct Table
	{
		bool valid = true;
		std::string userName;
		int phoneNumber;
	};

	HashTables();
	~HashTables();

	static const int arraySize = 5;
	Table array[arraySize];

	unsigned int RSHash (const char* str, unsigned int length);

	void Add(std::string userInput, unsigned int phoneNumber);

	int Search(std::string userInput);


};

