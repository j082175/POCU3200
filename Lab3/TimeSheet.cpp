#include "TimeSheet.h"
#include <cstring>
#include <cmath>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mEntryCount(0)
		, mSheetSize(maxEntries)
		, mName(name)
	{
		mSheetArr = new int[maxEntries];
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (mEntryCount >= mSheetSize)
		{
			return;
		}

		if (timeInHours > 0 && timeInHours <= 10)
		{
			mSheetArr[mEntryCount++] = timeInHours;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index < mEntryCount)
		{
			return mSheetArr[index];
		}

		return -1;
	}

	int TimeSheet::GetTotalTime() const
	{
		int32_t sum = 0;

		for (size_t i = 0; i < mEntryCount; i++)
		{
			sum += mSheetArr[i];
		}

		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		if (mEntryCount == 0)
		{
			return 0.f;
		}

		float sum = 0;
		float average = 0.f;

		for (size_t i = 0; i < mEntryCount; i++)
		{
			sum += mSheetArr[i];
		}

		average = sum / mEntryCount;

		return average;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float averageTime = GetAverageTime();
		float powSum = 0.f;

		if (averageTime <= 0.f)
		{
			return 0.f;
		}

		// 분산구하기
		float* backupArr = new float[mEntryCount];
		for (size_t i = 0; i < mEntryCount; i++)
		{
			backupArr[i] = mSheetArr[i];
		}

		for (size_t i = 0; i < mEntryCount; i++)
		{
			backupArr[i] -= averageTime;
		}

		for (size_t i = 0; i < mEntryCount; i++)
		{
			backupArr[i] *= backupArr[i];
		}

		for (size_t i = 0; i < mEntryCount; i++)
		{
			powSum += backupArr[i];
		}

		float variance = powSum / (mEntryCount);

		float standardDeviation = std::sqrtf(variance);

		delete[] backupArr;

		return standardDeviation;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		: mName(other.mName)
		, mSheetSize(other.mSheetSize)
		, mEntryCount(other.mEntryCount)
	{
		mSheetArr = new int[mSheetSize];

		for (size_t i = 0; i < mSheetSize; i++)
		{
			mSheetArr[i] = other.mSheetArr[i];
		}
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mName = other.mName;
		mSheetSize = other.mSheetSize;
		mEntryCount = other.mEntryCount;

		delete[] mSheetArr;
		mSheetArr = new int[mSheetSize];

		for (size_t i = 0; i < mSheetSize; i++)
		{
			mSheetArr[i] = other.mSheetArr[i];
		}

		return *this;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mSheetArr;
	}
}