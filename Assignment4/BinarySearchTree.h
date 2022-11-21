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


		std::shared_ptr<TreeNode<T>>& searchRecursive2(std::shared_ptr<TreeNode<T>>& node, T data)
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
				return searchRecursive2(node2->Right, data);
			}

			return searchRecursive2(node2->Left, data);
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
			// in-order successor 방식으로 할거임
			std::shared_ptr<TreeNode<T>>& node2 = node;

			if (*node2->Data == data)
			{
				if (node2->Right)
				{
					if (node2->Right->Left)
					{
						std::shared_ptr<TreeNode<T>>& node3 = node2->Right;

						std::shared_ptr<TreeNode<T>>& node4 = searchRecursiveLeft(node3);

						std::swap(node2->Data, node4->Left->Data);
						node4->Left.reset();
						//(*node4)->mLeft = nullptr;
						return true;

					}

					std::swap(node2->Data, node2->Right->Data);
					if (*node2->Right->Data == data && node2->Right->Right == nullptr)
					{
						node2->Right.reset();
						//(*node2)->mRight = nullptr;
						return true;
					}
					return deleteRecursive(node2->Right, data);
				}

				// 오른쪽 노드에 아무것도 없을때, 어쩔수 없이 in-order predecessor 방식 사용
				if (node2->Left)
				{
					if (node2->Left->Right)
					{
						std::shared_ptr<TreeNode<T>>& node3 = node2->Left;

						std::shared_ptr<TreeNode<T>>& node4 = searchRecursiveRight(node3);

						std::swap(node2->Data, node4->Right->Data);
						node4->Right.reset();
						//(*node4)->mRight = nullptr;
						return true;
					}

					std::swap(node2->Data, node2->Left->Data);
					if (*node2->Left->Data == data && node2->Left->Left == nullptr)
					{
						node2->Left.reset();
						//(*node2)->mLeft = nullptr;
						return true;
					}
					return deleteRecursive(node2->Left, data);
				}

				// 왼쪽 노드 , 오른쪽 노드 아무것도 없을때
				*node2->Data = -1;
				node2->Left = nullptr;
				node2->Right = nullptr;
				return true;
			}

			std::shared_ptr<TreeNode<T>>& result = searchRecursive(node2, data);

			if (result == nullptr)
			{
				return false;
			}

			std::shared_ptr<TreeNode<T>>& resultBefore = searchRecursive2(node2, data);
			deleteRecursive(result, data);

			if (*result->Data == -1)
			{
				if (resultBefore->Left != nullptr)
				{
					resultBefore->Left.reset();
					//resultBefore->Left = nullptr;
					return true;
				}

				if (resultBefore->Right != nullptr)
				{
					resultBefore->Right.reset();
					//resultBefore->mRight = nullptr;
					return true;
				}
			}

			return true;
		}

		std::shared_ptr<TreeNode<T>>& searchRecursiveLeft(std::shared_ptr<TreeNode<T>>& node)
		{
			//TreeNode<T>* node2 = node;
			std::shared_ptr<TreeNode<T>>& node2(node);

			if (node2->Left->Left == nullptr)
			{
				return node2;
			}

			return searchRecursiveLeft(node2->Left);
		}

		std::shared_ptr<TreeNode<T>>& searchRecursiveRight(std::shared_ptr<TreeNode<T>>& node)
		{
			//TreeNode<T>* node2 = node;
			std::shared_ptr<TreeNode<T>>& node2(node);

			if (node2->Right->Right == nullptr)
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

			//if (startNode == nullptr)
			//{
			//	vec.push_back(*startNode->Parent.lock()->Data);
			//}

			traverseInOrder(startNode->Left, v);
			v.push_back(*startNode->Data);
			traverseInOrder(startNode->Right, v);

			return v;
		}

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
		std::shared_ptr<TreeNode<T>>& result = searchRecursive(mNode, data);
		if (result)
		{
			return true;
		}
		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return deleteRecursive(mNode, data);
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> vec;

		traverseInOrder(startNode, vec);

		return vec;
	}
}