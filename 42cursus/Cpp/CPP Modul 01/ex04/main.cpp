#include <string>
#include <iostream>
#include <fstream>

int	replace(int ac, char **av)
{
	std::ofstream	outfile;
	outfile.open(std::string(av[1]) + ".replace");
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error - Use ./Sed [file] [Original string] [Replace string]" << std::endl;
		return (1);
	}

	std::ifstream	infile;
	std::string		str;
	char			c;

	infile.open(av[1]);
	if (infile.fail())
	{
		std::cout << "Error, unable to open the file" << std::endl;
		return (2);
	}

	while (!infile.eof())
	{
		infile >> std::noskipws >> c;
		str += c;
	}

	infile.close();
	std::cout << str << std::endl;
	return (replace(ac, av, str));
}

// 0 - everythings ok
// 1 - Wrong usage
// 2 - File open error
// 3 - 