#pragma once

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector()
			: mCurrentPosition(0)
			, mArr { T() }
		{
		}

		//FixedVector(const FixedVector<T, N>& other)
		//	: mCurrentPosition(other.mCurrentPosition)
		//	, mArr(other.mArr)
		//{}


		bool Add(const T& t)
		{
			if (mCurrentPosition >= N)
			{
				return false;
			}

			mArr[mCurrentPosition++] = t;
			return true;
		}

		bool Remove(const T& t)
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

		const T& Get(unsigned int index)
		{
			// index 의 값은 항상 범위 내라 가정

			return mArr[index];
		}

		T& operator[](unsigned int index)
		{
			return mArr[index];
		}

		int GetIndex(const T& t)
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

		size_t GetSize()
		{
			return mCurrentPosition;
		}

		size_t GetCapacity()
		{
			return N;
		}


	private:
		size_t mCurrentPosition;
		T mArr[N];
	};

}