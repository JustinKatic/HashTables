#include "HashTables.h"

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

void HashTables::Add(std::string userInput, unsigned int phoneNumber)
{
	std::cout << "enter your user name\n";
	std::string userInput;
	std::cin >> userInput;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	//changes userinput into a const char
	const char* input = userInput.c_str();
	//hash the value of input and store into result
	unsigned int result = RSHash(input, 10);
	//% the hash number into a number between 0-9
	unsigned int index = result % 10;

	int count = 0;
	while (array[index].valid == false)
	{
		if (index == 10)
		{
			index = 0;
		}
		index++;
		count++;
		if (count >= 10)
		{
			std::cout << "array is full soz buddy" << std::endl;
			break;
		}
	}
	std::cout << "enter your user phone number\n";
	int phoneNumberInput;
	std::cin >> phoneNumberInput;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	array[index].phoneNumber = phoneNumberInput;
	array[index].valid = false;
	array[index].key = userInput;

	std::cout << "index:" <<  index << std::endl;
}
