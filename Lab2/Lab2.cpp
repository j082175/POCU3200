#include "Lab2.h"
#include <iostream>
#include <iomanip>

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		unsigned int maxSize = 128;

		//int value[128] = { 0, };
		int* value = new int[maxSize];
		unsigned int count = 0;

		while (!in.eof())
		{
			in >> value[count];

			if (in.eof())
			{
				count++;
				break;
			}

			if (in.fail())
			{
				in.clear();
				in.ignore();
				continue;
			}

			count++;

			if (count >= maxSize)
			{
				int* temp = new int[maxSize * 2];
				for (size_t i = 0; i < maxSize; i++)
				{
					temp[i] = value[i];
				}

				delete[] value;
				maxSize *= 2;
				value = temp;
			}

		}

		value[count] = std::numeric_limits<unsigned int>::max();

		
		out << std::right;
		out << std::setw(12) << "oct" <<
			std::setw(11) << "dec" <<
			std::setw(9) << "hex" << std::endl;

		out << std::setfill('-') << std::setw(13) << " " <<
			std::setw(11) << " " <<
			std::setw(8) << "" << std::endl << std::setfill(' ');

		int index = 0;

		while (value[index] != std::numeric_limits<unsigned int>::max())
		{
			out << std::setw(12) << std::oct << value[index] <<
				std::setw(11) << std::dec << value[index] <<
				std::setw(9) << std::hex << std::uppercase << value[index] << std::endl;
			index++;
		}

		delete[] value;
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		unsigned int maxSize = 8;

		//float value[128] = { 0, };
		float* value = new float[maxSize];

		unsigned int count = 0;

		while (!in.eof())
		{
			in >> value[count];

			if (in.eof())
			{
				count++;
				break;
			}

			if (in.fail())
			{
				in.clear();
				in.ignore();
				continue;
			}

			count++;

			if (count >= maxSize)
			{
				float* temp = new float[maxSize * 2];
				for (size_t i = 0; i < maxSize; i++)
				{
					temp[i] = value[i];
				}

				delete[] value;
				maxSize *= 2;
				value = temp;
			}
		}

		value[count] = std::numeric_limits<float>::max();

		out << std::internal << std::showpos << std::showpoint << std::fixed << std::setprecision(3);

		int index = 0;

		while (value[index] != std::numeric_limits<float>::max())
		{
			out << std::setw(5) << " " <<
				std::setw(15) << value[index] << std::endl;
			index++;
		}

		index = 0;
		float max = 0.f;

		while (value[index] != std::numeric_limits<float>::max())
		{
			if (max < value[index])
			{
				max = value[index];
			}
			
			index++;
		}

		out << std::setw(5) << std::left << "max:" << std::internal <<
			std::setw(15) << max << std::endl;


		delete[] value;
	}
}