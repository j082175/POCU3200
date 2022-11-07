#pragma once

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();

		//FixedVector(const FixedVector<T, N>& other)
		//	: mCurrentPosition(other.mCurrentPosition)
		//	, mArr(other.mArr)
		//{}


		bool Add(const T& t);

		bool Remove(const T& t);

		const T& Get(unsigned int index);

		T& operator[](unsigned int index);

		int GetIndex(const T& t);

		size_t GetSize();

		size_t GetCapacity();


	private:
		size_t mCurrentPosition;
		T mArr[N];
	};

	template<typename T, size_t N>
	inline FixedVector<T, N>::FixedVector()
		: mCurrentPosition(0)
		, mArr{ T() }
	{
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Add(const T& t)
	{
		if (mCurrentPosition >= N)
		{
			return false;
		}

		mArr[mCurrentPosition++] = t;
		return true;
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Remove(const T& t)
	{

		for (size_t i = 0; i < mCurrentPosition; i++)
		{
			if (mArr[i] == t)
			{
				for (size_t j = i; j < mCurrentPosition - 1; j++)
				{
					mArr[j] = mArr[j + 1];
				}
				--mCurrentPosition;
				return true;
			}
		}

		return false;
	}

	template<typename T, size_t N>
	inline int FixedVector<T, N>::GetIndex(const T& t)
	{

		for (size_t i = 0; i < mCurrentPosition; i++)
		{
			if (mArr[i] == t)
			{
				return i;
			}
		}

		return -1;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetSize()
	{
		return mCurrentPosition;
	}

	template<typename T, size_t N>
	inline const T& FixedVector<T, N>::Get(unsigned int index)
	{
		// index 의 값은 항상 범위 내라 가정

		return mArr[index];
	}

	template<typename T, size_t N>
	inline T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArr[index];
	}
}