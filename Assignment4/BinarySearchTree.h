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
		std::shared_ptr<TreeNode<T>>& findMinValue(std::shared_ptr<TreeNode<T>>& node)
		{
			std::shared_ptr<TreeNode<T>>& currentNode = node;

			while (currentNode->Left != nullptr)
			{
				currentNode = currentNode->Left;
			}

			return currentNode;
		}

		std::shared_ptr<TreeNode<T>>& searchRecursive(std::shared_ptr<TreeNode<T>>& node, T data)
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


		std::shared_ptr<TreeNode<T>>& searchRecursiveBefore(std::shared_ptr<TreeNode<T>>& node, T data)
		{
			std::shared_ptr<TreeNode<T>>& node2 = node;

			//if (node2->mData == data)
			//{
			//	return node2;
			//}

			if (node2 == nullptr)
			{
				return node2;
			}

			if (*node2->Data == data)
			{
				return node2;
			}

			if (node2->Left != nullptr)
			{
				if (*(node2->Left->Data) == data)
				{
					return node2;
				}
			}

			if (node->Right != nullptr)
			{
				if (*(node2->Right->Data) == data)
				{
					return node2;
				}
			}


			if (data > *(node2->Data))
			{
				return searchRecursiveBefore(node2->Right, data);
			}

			return searchRecursiveBefore(node2->Left, data);
		}

		void insertRecursive(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T> data, std::shared_ptr<TreeNode<T>>& prevNode)
		{
			std::shared_ptr<TreeNode<T>>& node2 = node;
			
			if (node2 == nullptr)
			{
				//*node2 = new TreeNode<T>(std::make_unique<T>(data));
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

		bool deleteRecursive(std::shared_ptr<TreeNode<T>>& node, T data)
		{
			//// in-order successor ������� �Ұ���
			//std::shared_ptr<TreeNode<T>>& node2 = node;

			//if (*node2->Data == data)
			//{
			//	if (node2->Right)
			//	{
			//		if (node2->Right->Left)
			//		{
			//			std::shared_ptr<TreeNode<T>>& node3 = node2->Right;

			//			std::shared_ptr<TreeNode<T>>& node4 = searchRecursiveLeft(node3);

			//			std::swap(node2->Data, node4->Left->Data);
			//			node4->Left.reset();
			//			//(*node4)->mLeft = nullptr;
			//			return true;

			//		}

			//		std::swap(node2->Data, node2->Right->Data);
			//		if (*node2->Right->Data == data && node2->Right->Right == nullptr)
			//		{
			//			node2->Right.reset();
			//			//(*node2)->mRight = nullptr;
			//			return true;
			//		}
			//		return deleteRecursive(node2->Right, data);
			//	}

			//	// ������ ��忡 �ƹ��͵� ������, ��¿�� ���� in-order predecessor ��� ���
			//	if (node2->Left)
			//	{
			//		if (node2->Left->Right)
			//		{
			//			std::shared_ptr<TreeNode<T>>& node3 = node2->Left;

			//			std::shared_ptr<TreeNode<T>>& node4 = searchRecursiveRight(node3);

			//			std::swap(node2->Data, node4->Right->Data);
			//			node4->Right.reset();
			//			//(*node4)->mRight = nullptr;
			//			return true;
			//		}

			//		std::swap(node2->Data, node2->Left->Data);
			//		if (*node2->Left->Data == data && node2->Left->Left == nullptr)
			//		{
			//			node2->Left.reset();
			//			//(*node2)->mLeft = nullptr;
			//			return true;
			//		}
			//		return deleteRecursive(node2->Left, data);
			//	}

			//	// ���� ��� , ������ ��� �ƹ��͵� ������
			//	*node2->Data = -1;
			//	node2->Left = nullptr;
			//	node2->Right = nullptr;
			//	return true;
			//}

			//std::shared_ptr<TreeNode<T>>& result = searchRecursive(node2, data);

			//if (result == nullptr)
			//{
			//	return false;
			//}

			//std::shared_ptr<TreeNode<T>>& resultBefore = searchRecursiveBefore(node2, data);
			//deleteRecursive(result, data);

			//if (*result->Data == -1)
			//{
			//	if (resultBefore->Left != nullptr)
			//	{
			//		resultBefore->Left.reset();
			//		//resultBefore->Left = nullptr;
			//		return true;
			//	}

			//	if (resultBefore->Right != nullptr)
			//	{
			//		resultBefore->Right.reset();
			//		//resultBefore->mRight = nullptr;
			//		return true;
			//	}
			//}

			//return true;

			static mCheck check = IS_RIGHT;


			// if root node has a data
			// using in-order successor
			// remember, always delete the leaf node

			auto& resultNode = node;


			// �ߺ��˻�
			//////////////////////
			//if (resultNode->Right != nullptr)
			//{
			//	if (*resultNode->Data == *resultNode->Right->Data)
			//	{
			//		resultNode->Parent.lock()->Right = resultNode->Right;
			//		resultNode->Parent.lock()->Left = nullptr;
			//		return true;
			//	}
			//}

			//if (resultNode->Left != nullptr)
			//{
			//	if (*resultNode->Data < *resultNode->Left->Data)
			//	{
			//		resultNode->Parent.lock()->Left = resultNode->Left;
			//		resultNode->Parent.lock()->Right = nullptr;
			//		return true;
			//	}
			//}


			/////////////////////


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
				check = IS_RIGHT;
				return deleteRecursive(result, data);
			}

			if (resultNode->Right == nullptr && resultNode->Left != nullptr)
			{
				auto& result = searchRecursiveRight(resultNode->Left);
				std::swap(*resultNode->Data, *result->Data);
				check = IS_LEFT;
				return deleteRecursive(result, data);
			}


			// if there is a node

			// if node has two leaf node

			if (resultNode->Left != nullptr && resultNode->Right != nullptr)
			{

				auto& result = searchRecursiveLeft(resultNode->Right);
				std::swap(*resultNode->Data, *result->Data);
				return deleteRecursive(result, data);

				if (check == IS_LEFT)
				{

				}

				if (check == IS_RIGHT)
				{

				}

			}
		}

		std::shared_ptr<TreeNode<T>>& searchRecursiveLeft(std::shared_ptr<TreeNode<T>>& node)
		{
			//TreeNode<T>* node2 = node;
			std::shared_ptr<TreeNode<T>>& node2(node);

			if (node2->Left == nullptr)
			{
				return node2;
			}

			return searchRecursiveLeft(node2->Left);
		}

		std::shared_ptr<TreeNode<T>>& searchRecursiveRight(std::shared_ptr<TreeNode<T>>& node)
		{
			//TreeNode<T>* node2 = node;
			std::shared_ptr<TreeNode<T>>& node2(node);

			if (node2->Right == nullptr)
			{
				return node2;
			}

			return searchRecursiveRight(node2->Right);
		}

		static std::vector<T> traverseInOrder(const std::shared_ptr<TreeNode<T>> startNode, std::vector<T>& v)
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

	private:
		std::shared_ptr<TreeNode<T>> mNode;

		enum mCheck
		{
			IS_LEFT,
			IS_RIGHT
		};
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
}