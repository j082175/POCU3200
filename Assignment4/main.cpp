#include <iostream>
#include <memory>

#include "BinarySearchTree.h"
#include "TreeNode.h"
using namespace assignment4;


int main()
{
	BinarySearchTree<int> tree;
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(5));

	for (size_t i = 0; i < 10; i++)
	{
		tree.Insert(std::make_unique<int>(i));
	}

	tree.Search(11);

	tree.Delete(9);
}