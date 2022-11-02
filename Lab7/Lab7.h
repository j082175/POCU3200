#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		// V는 기본 자료형
		// Key 는 중복되지 않음
		
		std::map<K, V> m;

		size_t minSize = (keys.size() < values.size()) ? keys.size() : values.size();
		
		for (size_t i = 0; i < minSize; i++)
		{
			if (m.find(keys[i]) != m.end())
			{
				continue;
			}
			m.insert(std::make_pair(keys[i], values[i]));
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		v.reserve(100);

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back((*iter).first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		v.reserve(100);

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back((*iter).second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		rv.reserve(100);

		for (int i = static_cast<int>(v.size()) - 1; i >= 0; i--)
		{
			rv.push_back(v[i]);
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> vec1;
		std::vector<T> vec2;
		vec1.reserve(100);
		vec2.reserve(100);
		vec1 = v1;
		vec2 = v2;
		

		size_t vec1Length = vec1.size();
		for (size_t i = 0; i < vec1Length - 1; i++)
		{
			for (size_t j = i + 1; j < vec1Length; j++)
			{
				if (vec1[vec1Length - i - 1] == vec1[vec1Length - j - 1])
				{
					for (size_t k = vec1Length - i - 1; k < vec1Length - 1; k++)
					{
						vec1[k] = vec1[k + 1];
					}
					vec1.pop_back();
				}
			}
		}

		/*for (size_t i = 0; i < vec1.size() - 1; i++)
		{
			for (size_t j = 0; j < vec1.size() - 1 - i; j++)
			{
				if (vec1[j] > vec1[j + 1])
				{
					std::swap(vec1[j], vec1[j + 1]);
				}
			}
		}

		vec1.erase(std::unique(vec1.begin(), vec1.end()), vec1.end());*/

		size_t vec2Length = vec2.size();
		for (size_t i = 0; i < vec2Length - 1; i++)
		{
			for (size_t j = i + 1; j < vec2Length; j++)
			{
				if (vec2[vec2Length - i - 1] == vec2[vec2Length - j - 1])
				{
					for (size_t k = vec2Length - i - 1; k < vec2Length - 1; k++)
					{
						vec2[k] = vec2[k + 1];
					}
					vec2.pop_back();
				}
			}
		}

		/*for (size_t i = 0; i < vec2.size() - 1; i++)
		{
			for (size_t j = 0; j < vec2.size() - 1 - i; j++)
			{
				if (vec2[j] > vec2[j + 1])
				{
					std::swap(vec2[j], vec2[j + 1]);
				}
			}
		}

		vec2.erase(std::unique(vec2.begin(), vec2.end()), vec2.end());*/


		std::vector<T> combined;
		combined.reserve(100);

		typename std::vector<T>::const_iterator iter1 = vec1.begin();
		typename std::vector<T>::const_iterator iter2 = vec2.begin();
		
		/*bool isChecked = false;

		while (iter1 != vec1.end() || iter2 != vec2.end())
		{
			if (iter1 != vec1.end() && !isChecked)
			{
				if (*iter1 < *iter2)
				{
					combined.push_back(*iter1++);
					continue;
				}
			}
			else
			{
				isChecked = true;
			}

			if (iter2 != vec2.end() && !isChecked)
			{
				if (*iter1 > *iter2)
				{
					combined.push_back(*iter2++);
					continue;
				}
			}
			else
			{
				isChecked = true;
			}

			if (iter1 == vec1.end())
			{
				combined.push_back(*iter2++);
				continue;
			}

			if (iter2 == vec2.end())
			{
				combined.push_back(*iter1++);
				continue;
			}

			if (*iter1 == *iter2)
			{
				T value = *iter1;
				combined.push_back(value);
				iter1++;
				iter2++;
			}

			if (iter1 == vec1.end() || iter2 == vec2.end())
			{
				isChecked = true;
			}
		}*/




		for (size_t i = 0; i < vec1.size(); i++)
		{
			combined.push_back(*iter1++);
		}

		while (iter2 != vec2.end())
		{
			for (size_t i = 0; i < combined.size(); i++)
			{
				if (combined[i] == *iter2)
				{
					iter2++;
					if (iter2 == vec2.end())
					{
						goto label1;
					}
				}
			}

			combined.push_back(*iter2);
			iter2++;
		}

	label1:

		//for (size_t i = 0; i < combined.size() - 1; i++)
		//{
		//	for (size_t j = 0; j < combined.size() - 1 - i; j++)
		//	{
		//		if (combined[j] > combined[j + 1])
		//		{
		//			std::swap(combined[j], combined[j + 1]);
		//		}
		//	}
		//}

		//combined.erase(std::unique(combined.begin(), combined.end()), combined.end());

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		typename std::map<K, V>::const_iterator iter1 = m1.begin();
		typename std::map<K, V>::const_iterator iter2 = m2.begin();

		for (size_t i = 0; i < m1.size(); i++)
		{
			combined.insert(*iter1++);
		}

		while (iter2 != m2.end())
		{
			if (combined.find(iter2->first) == combined.end())
			{
				combined.insert(*iter2);
			}
			iter2++;
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		typename std::vector<T>::const_iterator iter = v.begin();

		while (true)
		{
			os << *iter++;
			if (iter == v.end())
			{
				break;
			}
			os << ',' << ' ';
		}

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		typename std::map<K, V>::const_iterator iter = m.begin();

		while (iter != m.end())
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
			iter++;
		}

		return os;
	}
}