#include "Person.h"
#include "File.h"
#include "libs.h"

int main()
{
	setlocale(0, "");
	std::vector <human> humans;
	human temp;
	std::string filename = "Humans.txt";
	File<human> file(filename);
	while (1)
	{
		file >> temp;
		if (file.eof())
			break;
		humans.push_back(temp);
	}
	system("CLS");
	perfomance(humans);
	file.close();
	file.opentowrite(filename);
	for (auto& x : humans)
		file << x;
	return 0;
}