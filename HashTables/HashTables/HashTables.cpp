#include "HashTables.h"
#include<string>
HashTables::HashTables()
{

}

HashTables::~HashTables()
{

}
//function to hash parameter str returns a random number that is always the same if the same name keeps being passed
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

//adds data into array into a specified index based of the hash function % arraysize
void HashTables::Add(std::string userNameInput, unsigned int phoneNumber)
{
	//count variable to check if array is full
	int count = 0;
	//changes userNameinput into a const char
	const char* nameInput = userNameInput.c_str();
	//hash the value of nameInput and store into hashedName
	unsigned int hashedName = RSHash(nameInput, 10);
	//% the hashedName into a number between 0 and arraysize
	unsigned int index = hashedName % arraySize;
	  	
	//collision logic
	while (array[index].valid == false)
	{
		//if username already exists break out of loop 
		if (array[index].userName == userNameInput) 
		{
			break;
		}
		//increment position in array by 1
		index++;
		//incremement count by 1
		count++;

		//reset index back to 0 so we can loop through the start of the array also
		if (index == arraySize)
		{
			index = 0;
		}
		//array full if count reaches arraysize
		if (count >= arraySize)  
		{
			std::cout << "array is full data wasnt added" << std::endl;
			return;
		}
	}
	//adding data into array at the position of index
	array[index].userName = userNameInput;
	array[index].phoneNumber = phoneNumber;
	//sets valid for this array pos to false so we cant enter in same pos again
	array[index].valid = false;         
}
//searches array for userInput and returns phone number
int HashTables::Search(std::string userInput)
{
	//count to check if couldnt find data
	int count = 0;

	//changes userinput into a const char
	const char* input = userInput.c_str();
	//hash the value of input and store into result
	unsigned int result = RSHash(input, 10);
	//% the hash number into a number between 0 and arraysize
	unsigned int index = result % arraySize;

	//collision logic
	while (array[index].userName != userInput)
	{	
		//increment index and count
		index++;
		count++;		

		//reset index back to 0 so we can loop through the start of the array also
		if (index == arraySize)
		{
			index = 0;
		}
		//couldnt find data inside of array
		if (count >= arraySize)
		{
			std::cout << "couldnt find your data" << std::endl;
			return 0;
		}
	}
	//return phone number at array[index]
	return array[index].phoneNumber;
}
