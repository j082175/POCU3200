#include <iostream>
#include <memory>
#include <cassert>
#include "BinarySearchTree.h"
#include "TreeNode.h"
using namespace assignment4;

void Test_Random_Delete()
{
	BinarySearchTree<int> tree;
	size_t testSize = 100;
	int arr[100];
	for (size_t i = 0; i < testSize; ++i)
	{
		arr[i] = rand() % 100;
	}

	//arr[0] = 60;
	//arr[1] = 77;
	//arr[2] = 56;
	//arr[3] = 23;
	//arr[4] = 44;
	//arr[5] = 2;
	//arr[6] = 66;
	//arr[7] = 34;
	//arr[8] = 62;
	//arr[9] = 22;
	//arr[10] = 1;
	//arr[11] = 5;
	//arr[12] = 6;
	//arr[13] = 87;
	//arr[14] = 67;
	//arr[15] = 41;
	//arr[16] = 99;
	//arr[17] = 70;
	//arr[18] = 13;
	//arr[19] = 19;
	//arr[20] = 9;
	//arr[21] = 93;
	//arr[22] = 55;
	//arr[23] = 18;
	//arr[24] = 72;
	//arr[25] = 39;
	//arr[26] = 85;
	//arr[27] = 95;
	//arr[28] = 4;
	//arr[29] = 8;


	for (size_t i = 0; i < testSize; ++i)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	std::vector<int> v;
	v = tree.TraverseInOrder(tree.GetRootNode().lock());

	for (size_t i = 0; i < testSize; i++)
	{
		tree.Delete(arr[i]);
		v = tree.TraverseInOrder(tree.GetRootNode().lock());
		assert(v.size() == testSize - i - 1);
	}

}

void Test_Delete_0hoo()
{
	bool bDelete = false;
	bool bSearch = false;
	BinarySearchTree<int> tree;
	std::vector<int> traverseResult;

	bDelete = tree.Delete(15);
	bSearch = tree.Search(15);
	traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(!bDelete);
	assert(!bSearch);
	assert(traverseResult.empty());

	tree.Insert(std::make_unique<int>(15));
	traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
	bDelete = tree.Delete(15);
	assert(bDelete);
	assert(traverseResult.size() == 1);
	assert(traverseResult[0] == 15);
	assert(tree.GetRootNode().lock());
}


void Test_Insert_GetRoot()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	tree.Insert(std::make_unique<int>(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));

	std::shared_ptr<TreeNode<int>> test0 = tree.GetRootNode().lock();
	assert(*test0->Data.get() == 10);
	assert(test0->Parent.lock().get() == nullptr);
	std::shared_ptr<TreeNode<int>> test1 = test0->Left;
	assert(*test1->Data.get() == 5);
	assert(*test1->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test2 = test1->Left;
	assert(*test2->Data.get() == 4);
	assert(*test2->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test3 = test1->Right;
	assert(*test3->Data.get() == 7);
	assert(*test3->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test4 = test0->Right;
	assert(*test4->Data.get() == 15);
	assert(*test4->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test5 = test4->Left;
	assert(*test5->Data.get() == 12);
	assert(*test5->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test6 = test4->Right;
	assert(*test6->Data.get() == 19);
	assert(*test6->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test7 = test6->Left;
	assert(*test7->Data.get() == 17);
	assert(*test7->Parent.lock()->Data.get() == 19);
	std::shared_ptr<TreeNode<int>> test8 = test6->Right;
	assert(*test8->Data.get() == 20);
	assert(*test8->Parent.lock()->Data.get() == 19);

	return;
}

void Test_Search()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	assert(!tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[0]));
	assert(tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	assert(tree.Search(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	assert(tree.Search(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	assert(tree.Search(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	assert(tree.Search(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	assert(tree.Search(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	assert(tree.Search(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	assert(tree.Search(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));
	assert(tree.Search(arr[8]));
	assert(!tree.Search(arr[9]));

	return;
}

void Test_Delete()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };

	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	//	End
	assert(!tree.Delete(9)); 	// �������� �ʴ� ��� ����
	assert(tree.Delete(20));	// Right ��� ����
	assert(!tree.Search(20));	// ���� Ȯ��
	assert(tree.Delete(12));	// Left ��� ����
	assert(!tree.Search(12));	// ���� Ȯ��
	assert(!tree.Delete(11));	// �������� �ʴ� ��� ����

	//	Middle
	assert(tree.Delete(19));	// Left�� �ִ� ��� ����
	assert(!tree.Search(19));	// ���� Ȯ��
	assert(tree.Search(17));

	assert(tree.Delete(4));
	assert(tree.Delete(7));
	assert(tree.Delete(17));	// Left, Right ��� ���� ��� ����
	assert(!tree.Search(17));	// ���� Ȯ��
	assert(!tree.Delete(17));	// ����ִ� ���¿��� ����

	assert(tree.Delete(15));	// Right�� �ִ� ��� ����
	assert(!tree.Search(15));	// ���� Ȯ��
	assert(tree.Delete(5)); 	// Left, Right ��� �ִ� ��� ����
	assert(!tree.Search(5));
	assert(!tree.Delete(5));	// �������� �ʴ� ��� ����

	//	Head
	assert(tree.Delete(10)); 	// Left, Right ��� �ִ� ��� ����
	assert(!tree.Search(10));	// ���� Ȯ��

	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	tree.Delete(arr[0]);
	tree.Delete(arr[1]);
	tree.Delete(arr[2]);
	tree.Delete(arr[3]);
	tree.Delete(arr[4]);
	tree.Delete(arr[5]);
	tree.Delete(arr[6]);
	tree.Delete(arr[7]);
	tree.Delete(arr[8]);

	return;
}

void Test_Traverse()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };
	int arr_chk[9] = { 4, 5, 7, 10, 12, 15, 17, 19, 20 };

	// �� Ʈ��
	std::vector<int> v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 0);
	assert(v1.empty());

	tree.Insert(std::make_unique<int>(arr[0]));
	// ��常 �ִ� Ʈ��
	std::vector<int> v2 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v2.size() == 1);
	assert(v2[0] == arr[0]);

	// empty ������
	std::vector<int> v3 = tree.TraverseInOrder(tree.GetRootNode().lock()->Left);
	assert(v3.size() == 0);
	assert(v3.empty());

	// Ʈ�� �Է�
	for (size_t i = 1; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	// ��� ��� �Է�
	std::vector<int> v4 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v4.size() == 9);
	assert(v4[0] == arr_chk[0]);
	assert(v4[1] == arr_chk[1]);
	assert(v4[2] == arr_chk[2]);
	assert(v4[3] == arr_chk[3]);
	assert(v4[4] == arr_chk[4]);
	assert(v4[5] == arr_chk[5]);
	assert(v4[6] == arr_chk[6]);
	assert(v4[7] == arr_chk[7]);
	assert(v4[8] == arr_chk[8]);

	// �߰� ��� �Է�
	std::vector<int> v5 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Right);
	assert(v5.size() == 3);
	assert(v5[0] == arr_chk[6]);
	assert(v5[1] == arr_chk[7]);
	assert(v5[2] == arr_chk[8]);

	// ���� ��� �Է�
	std::vector<int> v6 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Left);
	assert(v6.size() == 1);
	assert(v6[0] == arr_chk[4]);

	// ��� ����
	for (size_t i = 0; i < 8; i++)
	{
		tree.Delete(arr[i]);
	}

	// 7�� ����� ��� ������ Ʈ��
	std::vector<int> v7 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v7.size() == 1);
	assert(v7[0] == arr[8]);

	// ��尡 ��� ������ Ʈ��
	tree.Delete(arr[8]);
	std::vector<int> v8 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v8.size() == 0);
	assert(v8.empty());

	return;
}


void test2()
{
	BinarySearchTree<int> tree;
	//tree.Insert(std::make_unique<int>(10));
	//tree.Insert(std::make_unique<int>(8));
	//tree.Insert(std::make_unique<int>(16));
	//tree.Insert(std::make_unique<int>(7));
	//tree.Insert(std::make_unique<int>(9));
	//tree.Insert(std::make_unique<int>(14));
	////tree.Insert(std::make_unique<int>(18));
	//tree.Insert(std::make_unique<int>(4));
	//tree.Insert(std::make_unique<int>(6));
	//tree.Insert(std::make_unique<int>(12));
	//tree.Insert(std::make_unique<int>(15));
	//tree.Insert(std::make_unique<int>(13));
	////tree.Insert(std::make_unique<int>(16));
	////tree.Insert(std::make_unique<int>(20));


	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(6));
	tree.Insert(std::make_unique<int>(6));


	tree.Delete(5);
}


int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	////_CrtSetBreakAlloc(76); // �߰�

	//BinarySearchTree<int> tree2;
	//tree2.Insert(std::make_unique<int>(6));
	//tree2.Insert(std::make_unique<int>(4));
	//tree2.Insert(std::make_unique<int>(3));
	//tree2.Insert(std::make_unique<int>(5));



	//BinarySearchTree<int> tree;

	//tree.Insert(std::make_unique<int>(10));
	//tree.Insert(std::make_unique<int>(15));
	//tree.Insert(std::make_unique<int>(5));
	//tree.Insert(std::make_unique<int>(4));
	//tree.Insert(std::make_unique<int>(19));
	//tree.Insert(std::make_unique<int>(20));
	//tree.Insert(std::make_unique<int>(17));
	//tree.Insert(std::make_unique<int>(12));

	//std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

	//assert(v.size() == 8);
	//assert(v[0] == 4);
	//assert(v[1] == 5);
	//assert(v[2] == 10);
	//assert(v[3] == 12);
	//assert(v[4] == 15);
	//assert(v[5] == 17);
	//assert(v[6] == 19);
	//assert(v[7] == 20);

	//bool bSearched = tree.Search(15);
	//assert(bSearched);

	//bool bDeleted = tree.Delete(6);
	//assert(!bDeleted);

	//bDeleted = tree.Delete(100);
	//assert(!bDeleted);

	//bDeleted = tree.Delete(15);
	//assert(bDeleted);

	//v = tree.TraverseInOrder(tree.GetRootNode().lock());

	//assert(v.size() == 7);
	//assert(v[0] == 4);
	//assert(v[1] == 5);
	//assert(v[2] == 10);
	//assert(v[3] == 12);
	//assert(v[4] == 17);
	//assert(v[5] == 19);
	//assert(v[6] == 20);

	//bSearched = tree.Search(15);
	//assert(!bSearched);

	

	Test_Random_Delete();
	//Test_Delete_0hoo();
	//Test_Insert_GetRoot();
	//Test_Search();
	Test_Delete();
	//Test_Traverse();


	test2();
}