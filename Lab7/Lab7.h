#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

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
		std::vector<T> combined;
		combined.reserve(16);

		typename std::vector<T>::const_iterator iter1 = v1.begin();
		typename std::vector<T>::const_iterator iter2 = v2.begin();

		for (size_t i = 0; i < v1.size(); i++)
		{
			combined.push_back(*iter1++);
		}

		for (size_t i = 0; i < v2.size(); i++)
		{
			combined.push_back(*iter2++);
		}

		for (size_t i = 0; i < combined.size() - 1; i++)
		{
			for (size_t j = 1 + i; j < combined.size(); j++)
			{
				if (combined[i] == combined[j])
				{
					for (size_t k = j; k < combined.size() - 1; k++)
					{
						combined[k] = combined[k + 1];
					}
					combined.pop_back();
					--j;
				}
			}
		}

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