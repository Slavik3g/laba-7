#include "libs.h"

void chooseinstr()
{
	std::cout << "Enter 1 to add person" << std::endl;
	std::cout << "Enter 2 to show persons" << std::endl;
	std::cout << "Enter 3 to delete person" << std::endl;
	std::cout << "Enter any other number to exit" << std::endl;
}


int getintValue()
{
	int value = 0;

	while (true)
	{
		std::cin >> value;
		if (std::cin.peek() != '\n')
		{

			std::cin.clear();
			std::cin.ignore(32767, '\n');
			system("CLS");
			std::cout << "¬ведено неверное значение, поврторите ввод" << std::endl;
		}
		else
		{
			return value;
		}
	}
}

void deleteeelem(std::vector<human>& humans)
{
	std::cout << "Enter number of person with you like to delete" << std::endl;
	int number = getintValue();
	if (number >= humans.size())
	{
		std::cout << "Person do not found" << std::endl;
		return;
	}
	humans.erase(humans.begin() + number);
}

void perfomance(std::vector<human>& humans)
{
	while (true)
	{
		chooseinstr();
		int choose = getintValue();
		human temp;
		int number;
		switch (choose)
		{
		case 1:
			system("CLS");
			std::cin >> temp;
			humans.push_back(temp);
			break;
		case 2:
			system("CLS");
			if (humans.empty())
			{
				std::cout << "The array is empty" << std::endl;
				break;
			}
			for (auto& x : humans)
			{
				x.showinf();
				std::cout << std::endl;
			}
			break;
		case 3:
			system("CLS");
			deleteeelem(humans);
			break;
		default:
			system("CLS");
			return;
		}
	}
}