#pragma once


namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();

		bool Add(bool t);

		bool Remove(bool t);

		bool Get(unsigned int index);

		bool operator[](unsigned int index);

		int GetIndex(bool t);

		size_t GetSize();

		size_t GetCapacity();


	private:
		size_t mCurrentPosition;
		unsigned char mArr[N];
	};

	template<size_t N>
	inline FixedVector<bool, N>::FixedVector()
		: mCurrentPosition(0)
		, mArr{ 0 }
	{}

	template<size_t N>
	inline bool FixedVector<bool, N>::Add(bool t)
	{
		if (mCurrentPosition >= N)
		{
			return false;
		}

		mArr[mCurrentPosition++] = t;
		return true;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(bool t)
	{

		for (size_t i = 0; i < mCurrentPosition; i++)
		{
			if (mArr[i] == static_cast<unsigned char>(t))
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

	template<size_t N>
	inline bool FixedVector<bool, N>::Get(unsigned int index)
	{
		// index 의 값은 항상 범위 내라 가정

		return static_cast<bool>(mArr[index]);
	}

	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(bool t)
	{

		for (size_t i = 0; i < mCurrentPosition; i++)
		{
			if (mArr[i] == static_cast<unsigned char>(t))
			{
				return i;
			}
		}

		return -1;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetSize()
	{
		return mCurrentPosition;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return static_cast<bool>(mArr[index]);
	}
}