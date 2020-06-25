#pragma once
#include <iostream>
class HashTables
{
public: 
	struct Table
	{
		bool valid = true;
		std::string key;
		int phoneNumber;
	};

	HashTables();
	~HashTables();

	Table array[10];

	unsigned int RSHash (const char* str, unsigned int length);

	void Add(std::string userInput, unsigned int phoneNumber);


};

