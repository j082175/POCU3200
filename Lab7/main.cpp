#include "Lab7.h"
#include <iostream>
#include <cassert>
using namespace lab7;
using namespace std;

enum eCapacityForMain
{
	DEFAULT_CAPACITY = 16
};

int main()
{
	//vector<char> keys = { 'a', 'b', 'c' };
	//vector<int>	values = { 1, 2, 3, 4 };
	//vector<int> values2 = { 4, 5, 6, 7 };

	//auto result = values2 + values;
	//auto result2 = values + values2;


	//map<char, int> m1 = { {'a',1}, {'b',2}, {'c',3} };
	//map<char, int> m2 = { {'f',4}, {'d',5}, {'a',6}, {'b',7} };

	//auto m3 = m1 + m2;

	//cout << m3;



	// ----------------------

	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	std::vector<char> v2;
	v2.push_back('a');
	v2.push_back('b');
	v2.push_back('c');

	std::vector<int> v3;
	v3.push_back(4);
	v3.push_back(5);
	v3.push_back(6);

	std::vector<int> v4;
	v4.push_back(1);
	v4.push_back(1);
	v4.push_back(2);
	v4.push_back(3);

	std::vector<int> v5;
	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(4);
	v5.push_back(3);

	std::map<char, int> m1;
	m1['a'] = 1;
	m1['b'] = 2;
	m1['c'] = 3;

	std::map<char, int> m2;
	m2['d'] = 4;
	m2['e'] = 5;
	m2['f'] = 6;

	std::map<int, char> m = lab7::ConvertVectorsToMap(v1, v2);
	{
		std::map<int, char>::const_iterator it = m.begin();

		assert(it->first == 1);
		assert(it->second == 'a');
		it++;
		assert(it->first == 2);
		assert(it->second == 'b');
		it++;
		assert(it->first == 3);
		assert(it->second == 'c');
	}

	std::vector<char> keys = lab7::GetKeys(m1);
	{
		std::vector<char>::const_iterator it = keys.begin();

		assert(*it == 'a');
		it++;
		assert(*it == 'b');
		it++;
		assert(*it == 'c');
	}

	std::vector<int> values = lab7::GetValues(m1);
	{
		std::vector<int>::const_iterator it = values.begin();

		assert(*it == 1);
		it++;
		assert(*it == 2);
		it++;
		assert(*it == 3);
	}

	std::vector<int> reversedV1 = lab7::Reverse(v1);
	{
		assert(reversedV1[0] == v1[2]);
		assert(reversedV1[1] == v1[1]);
		assert(reversedV1[2] == v1[0]);
	}

	/*std::vector<int> combinedVector = v1 + v3;
	{
		assert(combinedVector.size() == 6);
		assert(combinedVector[0] == 1);
		assert(combinedVector[1] == 2);
		assert(combinedVector[2] == 3);
		assert(combinedVector[3] == 4);
		assert(combinedVector[4] == 5);
		assert(combinedVector[5] == 6);
	}*/

	std::vector<int> v4plusv5 = v4 + v5;   // v4에 중복된 원소가 있을 경우
	{
		std::vector<int>::const_iterator it = v4plusv5.begin();

		assert(v4plusv5.size() == 4);

		assert(*it == 1);
		it++;
		assert(*it == 2);
		it++;
		assert(*it == 3);
		it++;
		assert(*it == 4);
	}

	std::map<char, int> combinedMap = m1 + m2;
	{
		std::map<char, int>::const_iterator it = combinedMap.begin();

		assert(combinedMap.size() == 6);

		assert(it->first == 'a');
		assert(it->second == 1);
		it++;
		assert(it->first == 'b');
		assert(it->second == 2);
		it++;
		assert(it->first == 'c');
		assert(it->second == 3);
		it++;
		assert(it->first == 'd');
		assert(it->second == 4);
		it++;
		assert(it->first == 'e');
		assert(it->second == 5);
		it++;
		assert(it->first == 'f');
		assert(it->second == 6);
	}

	std::cout << v1 << std::endl;
	std::cout << m1 << std::endl;



	{
		std::vector<int> vector1;
		vector1.reserve(eCapacityForMain::DEFAULT_CAPACITY);

		for (size_t i = 0; i < 6; i++)
		{
			vector1.push_back(7 + i);
		}

		std::vector<int> vector2;
		vector2.reserve(eCapacityForMain::DEFAULT_CAPACITY);

		vector2.push_back(7);
		vector2.push_back(8);
		vector2.push_back(9);
		vector2.push_back(1);
		vector2.push_back(2);
		vector2.push_back(3);

		std::vector<int> combinedVector = vector1 + vector2;
		assert(combinedVector.size() == 9);

	}

	{
		std::vector<int> vector1;
		vector1.reserve(eCapacityForMain::DEFAULT_CAPACITY);

		vector1.push_back(3);
		vector1.push_back(6);
		vector1.push_back(4);
		vector1.push_back(7);
		vector1.push_back(2);
		vector1.push_back(2);

		std::vector<int> vector2;
		vector2.reserve(eCapacityForMain::DEFAULT_CAPACITY);

		vector2.push_back(2);
		vector2.push_back(3);
		vector2.push_back(5);
		vector2.push_back(1);
		vector2.push_back(7);
		vector2.push_back(4);

		std::vector<int> combinedVector = vector1 + vector2;
	}

	{
		std::vector<int> v1 = { 3, 1, 2, 3, 3 };
		std::vector<int> v2 = { 3, 4, 4 };
		std::vector<int> result = v1 + v2;
		std::vector<int> expected = { 3, 1, 2, 4 };
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(result[i] == expected[i]);
		}
		std::string strExpected = "3, 1, 2, 4";
		std::cout << strExpected << std::endl;
		std::cout << result << std::endl;
	}

	{
		std::vector<int> v1 = { 3, 1, 2, 3, 3, 5, 3, 1, 2, 2, 1, 6, 3, 2 };
		std::vector<int> v2 = { 3, 4, 4, 4, 1, 2, 3, 4, 5, 7, 2, 1 };
		std::vector<int> result = v1 + v2;
		std::vector<int> expected = { 3, 1, 2, 5, 6, 4, 7 };
		for (size_t i = 0; i < expected.size(); ++i)
		{
			assert(result[i] == expected[i]);
		}
		std::string strExpected = "3, 1, 2, 4";
		std::cout << strExpected << std::endl;
		std::cout << result << std::endl;
	}
}