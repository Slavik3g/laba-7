#pragma once
#include <iostream>
#include <string>

class human
{
	friend std::ostream& operator << (std::ostream&, const human&);
	friend std::istream& operator >> (std::istream&, human&);
private:
	std::string name;
	std::string pathranomic;
	int age;
public:
	human(std::string, std::string, int);
	human();
	human(const human&);
	std::string getname();
	std::string getpathranomic();
	int getage();
	void setname(std::string);
	void setpathranomic(std::string);
	void setage(int);
	void showinf();
	bool operator == (const human& man);
};

