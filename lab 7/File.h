#pragma once
#include <fstream>
#include <iostream>

template <class T>
class File
{
	friend File& operator <<(File& stream, const T& x)
	{
		stream.file << x << std::endl;
		return stream;
	}

	friend File& operator >>(File& stream, T& x)
	{
		stream.file >> x;
		return stream;
	}
private:
	std::fstream file;
public:
	File();
	File(std::string file_name);
	~File();
	void showfile();
	void putinfile(T);
	T takefromfile();
	void filebegin();
	int eof();
	void close();
	void clear();
	void opentowrite(std::string);
};

template<class T>
inline File<T>::File()
{
	std::cout << "If you did not give a file name, a new file named \"new_file.txt\" will be created, \nif such a file is present it will be completely cleared. Are you sure?" << std::endl;
	std::string choose;
	std::getline(std::cin, choose);
	if (choose != "1" && choose != "Yes")
		exit(-1);
	system("CLS");
	file.open("new_file.txt", std::fstream::out | std::fstream::trunc);
	if (!file.is_open())
	{
		std::cout << "ERROR FILE CAN'T BE OPENED " << std::endl;
		exit(-1);
	}
	else
		std::cout << "New file correctly created" << std::endl;
}

template<class T>
inline File<T>::File(std::string file_name)
{
	file.open(file_name, std::fstream::in);
	if (!file.is_open())
	{
		std::cout << "ERROR FILE CAN'T BE OPENED " << std::endl;
		exit(-1);
	}
	else
		std::cout << "File correctly opened" << std::endl;
}

template<class T>
inline File<T>::~File()
{
	file.close();
}

template<class T>
inline void File<T>::showfile()
{
	file.seekg(0);
	T info;
	while (1)
	{
		file >> info;
		if (file.eof())
			break;
		std::cout << info << std::endl;
	}
}

template<class T>
inline void File<T>::putinfile(T info)
{
	file << info << std::endl;
}

template<class T>
inline T File<T>::takefromfile()
{
	T info;
	file >> info;
	return info;
}

template<class T>
inline void File<T>::filebegin()
{
	file.seekg(std::ios::beg);
}

template<class T>
inline int File<T>::eof()
{
	if (file.eof())
		return 1;
	return 0;
}

template<class T>
inline void File<T>::close()
{
	file.close();
}

template<class T>
inline void File<T>::clear()
{
	file.clear();
}

template<class T>
inline void File<T>::opentowrite(std::string file_name)
{
	file.open(file_name, std::fstream::out);
	if (!file.is_open())
	{
		std::cout << "ERROR FILE CAN'T BE OPENED TO WRITE" << std::endl;
		exit(-1);
	}
}



