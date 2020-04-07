#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "please, enter \"compare.exe\" and"
			<< " <first file> <second file>";
		return 1;
	}

	std::ifstream firstFile(argv[1]);

	if (!firstFile.is_open())
	{
		std::cout << "unable to open file " << argv[1];
		return 1;
	}

	std::ifstream secondFile(argv[2]);

	if (!secondFile.is_open())
	{
		std::cout << "unable to open file " << argv[2];
		return 1;
	}

	std::string stringFirstFile, stringSecondFile;

	int lineOfDifference = 1;

	while (!firstFile.eof() || !secondFile.eof())
	{
		std::getline(firstFile, stringFirstFile);
		std::getline(secondFile, stringSecondFile);

		if (stringFirstFile == stringSecondFile)
			++lineOfDifference;
		else
		{
			std::cout << "Files are different. Line number is " << lineOfDifference;
			return 1;
		}

		if ((!firstFile.eof() && secondFile.eof()) || (firstFile.eof() && !secondFile.eof()))
		{
			std::cout << "Files are different. Line number is " << lineOfDifference;
			return 1;
		}
	}

	firstFile.close();
	secondFile.close();

	std::cout << "Files are equal";

	return 0;
}
