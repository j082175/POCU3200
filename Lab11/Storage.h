#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage& other)
			: mLength(other.mLength)
		{
			for (size_t i = 0; i < mLength; i++)
			{
				mArr[i] = other.mArr[i];
			}
		}

		Storage& operator=(const Storage& other)
		{
			if (this == &other)
			{
				return *this;
			}

			mLength = other.mLength;

			for (size_t i = 0; i < mLength; i++)
			{
				mArr[i] = other.mArr[i];
			}

			return *this;
		}

		Storage(Storage&& other) noexcept
			//: mArr(other.mArr)
			: mArr(std::move(other.mArr))
			, mLength(other.mLength)
		{
			other.mArr = nullptr;
			other.mLength = 0;
		}

		Storage& operator=(Storage&& other) noexcept
		{
			if (this == &other)
			{
				return *this;
			}

			//delete[] mArr;

			mArr = std::move(other.mArr);
			mLength = other.mLength;

			other.mArr = nullptr;
			other.mLength = 0;

			return *this;
		}

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		//T* mArr;
		std::unique_ptr<T[]> mArr;
		size_t mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mLength(length)
		, mArr(new T[length]{ T() })
	{
		//mArr = new T[length];
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mLength(length)
		, mArr(new T[length])
	{
		for (size_t i = 0; i < length; i++)
		{
			mArr[i] = initialValue;
		}
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mLength)
		{
			return false;
		}

		mArr[index] = data;
		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		//std::unique_ptr<T[]> temp = std::make_unique<T[]>(mArr);
		return std::move(mArr);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}