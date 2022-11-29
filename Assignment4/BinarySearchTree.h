#pragma once

#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		BinarySearchTree()
			: mNode(nullptr)
		{}

		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		std::shared_ptr<TreeNode<T>>& searchRecursive(std::shared_ptr<TreeNode<T>>& node, T data);
		void insertRecursive(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T> data, std::shared_ptr<TreeNode<T>>& prevNode);
		bool deleteRecursive(std::shared_ptr<TreeNode<T>>& node, T data);
		std::shared_ptr<TreeNode<T>>& searchRecursiveLeft(std::shared_ptr<TreeNode<T>>& node);
		std::shared_ptr<TreeNode<T>>& searchRecursiveRight(std::shared_ptr<TreeNode<T>>& node);

		static std::vector<T> traverseInOrder(const std::shared_ptr<TreeNode<T>> startNode, std::vector<T>& v);

	private:
		std::shared_ptr<TreeNode<T>> mNode;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		insertRecursive(mNode, std::move(data), mNode);
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mNode;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> result = searchRecursive(mNode, data);

		if (result)
		{
			return true;
		}

		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		//return deleteRecursive(mNode, data);

		auto& resultNode = searchRecursive(mNode, data);

		auto result = deleteRecursive(resultNode, data);

		if (result)
		{
			return true;
		}

		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> vec;

		traverseInOrder(startNode, vec);

		return vec;
	}

	template<typename T>
	inline std::shared_ptr<TreeNode<T>>& BinarySearchTree<T>::searchRecursive(std::shared_ptr<TreeNode<T>>& node, T data)
	{
		//TreeNode<T>* node2 = node;
		std::shared_ptr<TreeNode<T>>& node2 = node;

		if (node2 == nullptr)
		{
			return node2;
		}

		if (*(node2->Data) == data)
		{
			return node2;
		}

		if (data > *(node2->Data))
		{
			return searchRecursive(node2->Right, data);
		}

		return searchRecursive(node2->Left, data);
	}

	template<typename T>
	inline void BinarySearchTree<T>::insertRecursive(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T> data, std::shared_ptr<TreeNode<T>>& prevNode)
	{
		std::shared_ptr<TreeNode<T>>& node2 = node;

		if (node2 == nullptr)
		{
			node2 = std::make_shared<TreeNode<T>>(std::move(data));
			node2->Parent = prevNode;
			return;
		}

		if (*node2->Data < *data)
		{
			return insertRecursive(node2->Right, std::make_unique<T>(*data), node2);
		}

		return insertRecursive(node2->Left, std::make_unique<T>(*data), node2);
	}

	template<typename T>
	inline bool BinarySearchTree<T>::deleteRecursive(std::shared_ptr<TreeNode<T>>& node, T data)
	{
		// if root node has a data
		// using in-order successor
		// remember, always delete the leaf node

		auto& resultNode = node;

		// if there isn't a node
		if (resultNode == nullptr)
		{
			return false;
		}

		//if there is no leaf node
		if (resultNode->Left == nullptr && resultNode->Right == nullptr)
		{
			resultNode.reset();
			return true;
		}

		//if there is a right node
		if (resultNode->Left == nullptr && resultNode->Right != nullptr)
		{
			auto& result = searchRecursiveLeft(resultNode->Right);
			std::swap(*resultNode->Data, *result->Data);
			return deleteRecursive(result, data);
		}

		//if there is a left node
		if (resultNode->Right == nullptr && resultNode->Left != nullptr)
		{
			auto& result = searchRecursiveRight(resultNode->Left);
			std::swap(*resultNode->Data, *result->Data);
			return deleteRecursive(result, data);
		}

		// if there is a node

		// if node has two leaf nodes

		if (resultNode->Left != nullptr && resultNode->Right != nullptr)
		{
			auto& result = searchRecursiveLeft(resultNode->Right);
			std::swap(*resultNode->Data, *result->Data);
			return deleteRecursive(result, data);
		}

		return false;
	}

	template<typename T>
	inline std::shared_ptr<TreeNode<T>>& BinarySearchTree<T>::searchRecursiveLeft(std::shared_ptr<TreeNode<T>>& node)
	{
		//TreeNode<T>* node2 = node;
		std::shared_ptr<TreeNode<T>>& node2(node);

		if (node2->Left == nullptr)
		{
			return node2;
		}

		return searchRecursiveLeft(node2->Left);
	}

	template<typename T>
	inline std::shared_ptr<TreeNode<T>>& BinarySearchTree<T>::searchRecursiveRight(std::shared_ptr<TreeNode<T>>& node)
	{
		//TreeNode<T>* node2 = node;
		std::shared_ptr<TreeNode<T>>& node2(node);

		if (node2->Right == nullptr)
		{
			return node2;
		}

		return searchRecursiveRight(node2->Right);
	}

	template<typename T>
	inline std::vector<T> BinarySearchTree<T>::traverseInOrder(const std::shared_ptr<TreeNode<T>> startNode, std::vector<T>& v)
	{

		if (startNode == nullptr)
		{
			return v;
		}

		traverseInOrder(startNode->Left, v);
		v.push_back(*startNode->Data);
		traverseInOrder(startNode->Right, v);

		return v;
	}
}