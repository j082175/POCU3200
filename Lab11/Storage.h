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

		Storage(const Storage& other);
		Storage& operator=(const Storage& other);

		Storage(Storage&& other) noexcept;
		Storage& operator=(Storage&& other) noexcept;

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
		, mArr(new T[length])
		// , mArr(new T[length]{ T() })
	{
		for (size_t i = 0; i < length; i++)
		{
			mArr[i] = T();
		}
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
	Storage<T>::Storage(const Storage& other)
		: mLength(other.mLength)
		, mArr(new T[other.mLength])
	{
		for (size_t i = 0; i < mLength; i++)
		{
			mArr[i] = other.mArr[i];
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage&& other) noexcept
		: mArr(std::move(other.mArr))
		, mLength(other.mLength)
	{
		other.mArr = nullptr;
		other.mLength = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mLength = other.mLength;
		mArr.reset();
		mArr = std::make_unique<T[]>(mLength);

		for (size_t i = 0; i < mLength; i++)
		{
			mArr[i] = other.mArr[i];
		}

		return *this;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other) noexcept
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