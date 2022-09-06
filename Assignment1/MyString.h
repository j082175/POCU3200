#pragma once
namespace assignment1
{
	class MyString
	{
	public:
		MyString(const char* s);
		MyString(const MyString& other);
		~MyString();

		unsigned int GetLength() const;
		const char* GetCString() const;
		void Append(const char* s);
		MyString operator+(const MyString& other) const;
		int IndexOf(const char* s);
		int LastIndexOf(const char* s);
		void Interleave(const char* s);
		bool RemoveAt(unsigned int i);
		void PadLeft(unsigned int totalLength);
		void PadLeft(unsigned int totalLength, const char c);
		void PadRight(unsigned int totalLength);
		void PadRight(unsigned int totalLength, const char c);
		void Reverse();
		bool operator==(const MyString& rhs) const;
		MyString& operator=(const MyString& rhs);
		void ToLower();
		void ToUpper();

		MyString(MyString&& other) noexcept;
		MyString& operator=(MyString&& other) noexcept;

	private:
		size_t strLen(const char* s) const;
		size_t strCpy(char* dest, const char* source, size_t length) const;
		size_t strCat(char* dest, const char* source) const;

	private:
		char* mString;
		size_t mLength;
	};
}