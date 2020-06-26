#include "HashTables.h"
#include<string>
HashTables::HashTables()
{

}

HashTables::~HashTables()
{

}

unsigned int HashTables::RSHash(const char* str, unsigned int length)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < length; ++str, ++i)
	{
		hash = hash * a + (*str);
		a = a * b;
	}
	return hash;
}

void HashTables::Add(std::string userNameInput, unsigned int phoneNumber)
{

	//hashing username
	const char* nameInput = userNameInput.c_str();
	unsigned int hashedName = RSHash(nameInput, 10);
	unsigned int index = hashedName % arraySize;
	  
	int count = 0;
	while (array[index].valid == false)
	{
		if (array[index].userName == userNameInput)
		{
			break;
		}
		index++;
		count++;
		if (index == arraySize)
		{
			index = 0;
		}
		if (count >= arraySize)  
		{
			std::cout << "array is full data wasnt added" << std::endl;
			return;
		}
	}
	array[index].userName = userNameInput;
	array[index].phoneNumber = phoneNumber;
	array[index].valid = false;       
}

int HashTables::Search(std::string userInput)
{
	//changes userinput into a const char
	const char* input = userInput.c_str();
	//hash the value of input and store into result
	unsigned int result = RSHash(input, 10);
	//% the hash number into a number between 0-9
	unsigned int index = result % arraySize;
	int count = 0;
	while (array[index].userName != userInput)
	{		
		index++;
		count++;
		if (index == arraySize)
		{
			index = 0;
		}

		if (count >= arraySize)
		{
			std::cout << "couldnt find your data" << std::endl;
			return 0;
		}
	}
	return array[index].phoneNumber;
}
