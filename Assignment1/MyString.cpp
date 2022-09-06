#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mString(nullptr)
		, mLength(0)
	{
		if (s != nullptr)
		{
			mLength = strLen(s);

			mString = new char[mLength + 1];
			strCpy(mString, s, mLength);
		}
	}

	MyString::MyString(const MyString& other)
		: mLength(other.mLength)
		, mString(nullptr)
	{
		if (other.mString != nullptr)
		{
			delete[] mString;

			mLength = other.mLength;

			mString = new char[mLength + 1];
			strCpy(mString, other.mString, mLength);
		}
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		if (s == nullptr || strLen(s) == 0)
		{
			return;
		}


		char* backup = new char[mLength + 1];
		size_t backupLength = mLength;

		strCpy(backup, mString, mLength);

		delete[] mString;
		mLength += strLen(s);
		mString = new char[mLength + 1];
		strCpy(mString, backup, backupLength);
		strCat(mString, s);

		delete[] backup;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString str(mString);
		str.Append(other.mString);
		return str;
	}

	int MyString::IndexOf(const char* s)
	{
		if (s == nullptr)
		{
			return -1;
		}

		const char* source = s;
		const char* dest = mString;
		int index = -1;
		size_t sourceLength = strLen(source);
		size_t sourceCount = 0;
		int count = 0;

		bool bCheck = false;


		if (sourceLength == 0)
		{
			return 0;
		}

		for (size_t i = 0; i < mLength; i++)
		{
			bCheck = false;

			if (*(dest + i) == *(source + sourceCount))
			{

				if (source[sourceCount] == '\0')
				{
					index = i;
					return index;
				}

				for (size_t j = i; j < sourceLength + i; j++)
				{
					if (*(dest + j) == *(source + sourceCount++))
					{
						continue;
					}
					else
					{
						sourceCount = 0;
						bCheck = true;
						break;
					}
				}

				if (bCheck)
				{
					continue;
				}

				index = i;
				return index;
			}

		}

		return index;
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (s == nullptr)
		{
			return -1;
		}


		const char* source = s;
		const char* dest = mString;
		int index = -1;
		size_t sourceLength = strLen(source);
		size_t sourceCount = 0;
		int count = 0;

		bool bCheck = false;


		if (sourceLength == 0)
		{
			return mLength;
		}

		for (size_t i = 0; i < mLength; i++)
		{
			bCheck = false;

			if (*(dest + i) == *(source + sourceCount))
			{

				if (source[sourceCount + 1] == '\0')
				{
					index = i;
					//return index;
					continue;
				}

				for (size_t j = i; j < sourceLength + i; j++)
				{
					if (*(dest + j) == *(source + sourceCount++))
					{
						continue;
					}
					else
					{
						sourceCount = 0;
						bCheck = true;
						break;
					}
				}

				if (bCheck)
				{
					continue;
				}

				index = i;
				sourceCount = 0;
				//return index;
			}



		}

		return index;
	}

	void MyString::Interleave(const char* s)
	{
		if (s == nullptr || mString == nullptr || strLen(s) == 0)
		{
			return;
		}


		const char* source = s;
		const char* str = mString;
		size_t sourceLength = strLen(s);

		char* dest = new char[mLength + sourceLength + 1];
		size_t destLength = sourceLength + mLength;

		size_t strCount = 0;
		size_t sourceCount = 0;
		size_t destCount = 0;
		bool bStrCheck = true;
		bool bSourceCheck = true;

		while (destCount < destLength)
		{
			if (*(str + strCount) == '\0' && *(source + sourceCount) != '\0')
			{
				bStrCheck = false;
				bSourceCheck = true;
			}

			if (*(source + sourceCount) == '\0' && *(str + strCount) != '\0')
			{
				bStrCheck = true;
				bSourceCheck = false;
			}

			if (bStrCheck)
			{
				*(dest + destCount) = *(str + strCount);
				strCount++;
				destCount++;
				bStrCheck = false;
				bSourceCheck = true;
				continue;
			}

			if (bSourceCheck)
			{
				*(dest + destCount) = *(source + sourceCount);
				sourceCount++;
				destCount++;
				bStrCheck = true;
				bSourceCheck = false;
				continue;
			}

		}

		*(dest + destLength) = '\0';

		delete[] mString;
		mString = dest;
		mLength = destLength;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		size_t count = i;

		if (mLength <= i)
		{
			return false;
		}

		for (size_t i = count + 1; i < mLength; i++)
		{
			*(mString + i - 1) = *(mString + i);
		}

		mLength--;

		*(mString + mLength) = '\0';

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (mLength >= totalLength)
		{
			return;
		}

		size_t moveCount;
		char* backupString = new char[mLength + 1];
		strCpy(backupString, mString, mLength);

		char* newString;
		moveCount = totalLength - mLength;

		newString = new char[totalLength + 1];

		for (size_t i = 0; i < moveCount; i++)
		{
			*(newString + i) = c;
		}

		for (size_t i = moveCount; i < mLength + moveCount; i++)
		{
			*(newString + i) = *(backupString + i - moveCount);
		}

		*(newString + totalLength) = '\0';

		delete[] backupString;
		delete[] mString;
		mString = newString;
		mLength = totalLength;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (mLength >= totalLength)
		{
			return;
		}

		size_t moveCount;

		char* newString;
		moveCount = totalLength - mLength;

		newString = new char[totalLength + 1];

		for (size_t i = 0; i < mLength; i++)
		{
			*(newString + i) = *(mString + i);
		}

		for (size_t i = mLength; i < mLength + moveCount; i++)
		{
			*(newString + i) = c;
		}

		*(newString + totalLength) = '\0';

		delete[] mString;
		mString = newString;
		mLength = totalLength;
	}

	void MyString::Reverse()
	{
		char* source = mString;
		char temp;
		char* a = mString;
		char* b = mString + mLength - 1;

		while (a < b)
		{
			temp = *a;
			*a = *b;
			*b = temp;

			a++;
			b--;
		}

	}

	bool MyString::operator==(const MyString& rhs) const
	{
		char* lv = mString;
		char* rv = rhs.mString;

		if (mLength != rhs.mLength)
		{
			return false;
		}


		for (size_t i = 0; i < mLength; i++)
		{
			if (*lv++ == *rv++)
			{
				continue;
			}
			else
			{
				return false;
			}
		}


		return true;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}


		delete[] mString;
		mLength = rhs.mLength;

		mString = new char[mLength + 1];
		strCpy(mString, rhs.mString, mLength);

		return *this;
	}

	void MyString::ToLower()
	{
		char* source = mString;

		for (size_t i = 0; i < mLength; i++)
		{
			if (*source >= 65 && *source <= 90)
			{
				*source += 32;
			}
			source++;
		}

	}

	void MyString::ToUpper()
	{
		char* source = mString;

		for (size_t i = 0; i < mLength; i++)
		{
			if (*source >= 97 && *source <= 122)
			{
				*source -= 32;
			}
			source++;
		}
	}
	size_t MyString::strLen(const char* s) const
	{
		size_t length = 0;

		while (*s++ != '\0')
		{
			length++;
		}
		return length;
	}
	size_t MyString::strCpy(char* dest, const char* source, size_t length) const
	{
		for (size_t i = 0; i < length; i++)
		{
			*dest++ = *source++;
		}
		*dest = '\0';

		return 1;
	}
	size_t MyString::strCat(char* dest, const char* source) const
	{

		while (*dest != '\0')
		{
			dest++;
		}

		while (*source != '\0')
		{
			*dest = *source;
			dest++;
			source++;
		}
		*dest = '\0';
		return 1;
	}

}