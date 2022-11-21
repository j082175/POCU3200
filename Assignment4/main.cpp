#include <iostream>
#include <memory>
#include <cassert>
#include "BinarySearchTree.h"
#include "TreeNode.h"
using namespace assignment4;


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(76); // Ãß°¡

	BinarySearchTree<int> tree2;
	tree2.Insert(std::make_unique<int>(6));
	tree2.Insert(std::make_unique<int>(4));
	tree2.Insert(std::make_unique<int>(3));
	tree2.Insert(std::make_unique<int>(5));



	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(10));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(19));
	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(12));

	/*std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 8);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 15);
	assert(v[5] == 17);
	assert(v[6] == 19);
	assert(v[7] == 20);*/

	bool bSearched = tree.Search(15);
	assert(bSearched);

	bool bDeleted = tree.Delete(6);
	assert(!bDeleted);

	bDeleted = tree.Delete(100);
	assert(!bDeleted);

	bDeleted = tree.Delete(15);
	assert(bDeleted);

	/*v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 7);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 17);
	assert(v[5] == 19);
	assert(v[6] == 20);*/

	bSearched = tree.Search(15);
	assert(!bSearched);

	return 0;
}