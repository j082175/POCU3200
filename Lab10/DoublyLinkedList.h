#pragma once

#include <memory>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		std::shared_ptr<Node<T>> mNode;
		size_t mLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mNode(nullptr)
		, mLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{

		std::shared_ptr<Node<T>>* second = &mNode;

		if (*second == nullptr)
		{
			*second = std::make_shared<Node<T>>(std::move(data));
			(*second)->Next = nullptr;
			++mLength;
			return;
		}

		while ((*second)->Next != nullptr)
		{
			second = &(*second)->Next;
		}

		(*second)->Next = std::make_shared<Node<T>>(std::move(data));
		(*second)->Next->Previous = *second;
		++mLength;

	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		std::shared_ptr<Node<T>>* second = &mNode;
		size_t count = 0;

		if (*second == nullptr)
		{

			*second = std::make_shared<Node<T>>(std::move(data));
			(*second)->Next = nullptr;
			++mLength;
			return;
		}

		if (count == index)
		{
			goto label1;
		}

		++count;

		while ((*second)->Next != nullptr)
		{
			second = &(*second)->Next;

			if (count == index)
			{

			label1:

				std::shared_ptr<Node<T>> origin = (*second);
				std::shared_ptr<Node<T>> originPrev = (*second)->Previous.lock();

				(*second) = std::make_shared<Node<T>>(std::move(data));

				(*second)->Next = origin;
				(*second)->Next->Previous = (*second);

				(*second)->Previous = originPrev;
				
				++mLength;
				return;
			}

			++count;
		}

		(*second)->Next = std::make_shared<Node<T>>(std::move(data));
		(*second)->Next->Previous = *second;

		++mLength;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>>* second = &mNode;

		if (*second == nullptr)
		{
			return false;
		}

		while ((*second)->Next != nullptr)
		{
			if (*(*second)->Data == data)
			{
				std::shared_ptr<Node<T>> origin = (*second);
				std::shared_ptr<Node<T>> originPrev = (*second)->Previous.lock();

				if (originPrev == nullptr)
				{
					*second = (*second)->Next;
					--mLength;
					return true;
				}

				originPrev->Next = origin->Next;
				origin->Next->Previous = originPrev;

				--mLength;

				return true;
			}

			second = &(*second)->Next;
		}

		if (*(*second)->Data == data)
		{
			std::shared_ptr<Node<T>> origin = (*second);
			std::shared_ptr<Node<T>> originPrev = (*second)->Previous.lock();

			if (originPrev == nullptr)
			{
				--mLength;
				*second = nullptr;
				return true;
			}

			originPrev->Next = origin->Next;
			--mLength;

			return true;
		}

		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> second = mNode;

		if (second == nullptr)
		{
			return false;
		}

		while ((second)->Next != nullptr)
		{
			if (*(second)->Data == data)
			{
				return true;
			}

			second = (second)->Next;
		}

		if (*(second)->Data == data)
		{
			return true;
		}

		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		std::shared_ptr<Node<T>> second = mNode;
		size_t count = 0;

		if (second == nullptr)
		{
			return nullptr;
		}

		while ((second)->Next != nullptr)
		{
			if (count == index)
			{
				return second;
			}

			++count;
			second = (second)->Next;
		}

		if (count == index)
		{
			return second;
		}

		return nullptr;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}