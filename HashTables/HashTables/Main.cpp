#include <iostream>
#include"HashTables.h"

HashTables hashTables;

int main()
{
	bool coding = true;
	while (coding == true)
	{

		char userChoice;
		std::cout << "1.add 2.exit 3.search 4.display array" << std::endl;
		std::cin >> userChoice;

		switch (userChoice)
		{
		case '1': //ADD
		{
			//getting user input for there name
			std::cout << "enter your user name\n";
			std::string userInput;
			std::cin >> userInput;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());

			//getting user input for there phone number
			std::cout << "enter your user phone number\n";
			int phoneNumberInput;
			std::cin >> phoneNumberInput;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());

			//adding users input and phone number into array
			hashTables.Add(userInput, phoneNumberInput);
			break;
		}
		case'2'://EXIT
		{
			coding = false;
			break;
		}
		case'3'://SEARCH
		{
			//USER NAME
			std::cout << "enter your user name\n";
			std::string userInput;
			std::cin >> userInput;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "phone number is: " << hashTables.Search(userInput) << std::endl;
			break;
		}
		case '4'://DISPLAY ARRAY
		{
			for (size_t i = 0; i < hashTables.arraySize; i++)
			{
				std::cout << "index: " << (i) << "	 " << "name:" << hashTables.array[i].userName << "		" << "PhoneNumber:" << hashTables.array[i].phoneNumber << std::endl;
			}
			break;
		}
		default:	//ERROR CHECK IF INCORRECT INPUT
		{
			std::cout << "incorrect input" << std::endl;
			//clears buffer
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			break;
		}
		}
	}
}