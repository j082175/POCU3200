#include "Lab2.h"
#include <iostream>
#include <iomanip>

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		unsigned int value[128] = { 0, };
		unsigned int count = 0;

		while (!in.eof())
		{
			in >> value[count];

			if (in.eof())
			{
				break;
			}

			if (in.fail() || value[count] > std::numeric_limits<int>::max())
			{
				//in.clear();
				//in.ignore(std::numeric_limits<long long>::max(), ' ');
				//in.ignore(std::numeric_limits<long long>::max(), '\n');
				continue;
			}

			count++;

		}

		value[count] = std::numeric_limits<unsigned int>::max();



		out << std::right;
		out << std::setw(12) << "oct" <<
			std::setw(11) << "dec" <<
			std::setw(10) << "hex" << std::endl;

		out << std::setfill('-') << std::setw(12) << " " <<
			std::setw(11) << " " <<
			std::setw(10) << "" << std::endl << std::setfill(' ');

		int index = 0;

		while (value[index] != std::numeric_limits<unsigned int>::max())
		{
			out << std::setw(12) << std::oct << value[index] <<
				std::setw(11) << std::dec << value[index] <<
				std::setw(10) << std::hex << std::uppercase << value[index] << std::endl;
			index++;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{

	}
}