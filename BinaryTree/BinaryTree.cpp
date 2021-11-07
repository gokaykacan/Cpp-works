/*
* Gokay Kacan, Binary Tree Implementation
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class BinaryTree
{
	int mValue;
	BinaryTree* mLeft;
	BinaryTree* mRight;

	void findInOrder(BinaryTree* root, vector<int>& ans)
	{
		if (root == nullptr)
			return;
		findInOrder(root->mLeft, ans);
		ans.push_back(root->mValue);
		findInOrder(root->mRight, ans);

	}
	void findPreOrder(BinaryTree* root, vector<int>& ans)
	{
		if (root == nullptr)
			return;
		ans.push_back(root->mValue);
		findPreOrder(root->mLeft, ans);
		findPreOrder(root->mRight, ans);
	}
	void findPostOrder(BinaryTree* root, vector<int>& ans)
	{
		if (root == nullptr)
			return;
		findPostOrder(root->mLeft, ans);
		findPostOrder(root->mRight, ans);
		ans.push_back(root->mValue);
	}
public:
	BinaryTree() : mLeft(nullptr), mRight(nullptr), mValue(0) {}
	BinaryTree(int value) : mValue(value), mLeft(nullptr), mRight(nullptr) {}
	BinaryTree(int value, BinaryTree* left, BinaryTree* right) : mValue(value), mLeft(left), mRight(right) {}

	void addNewLeaf(int value)
	{
		BinaryTree* mRoot = this;

		if (mRoot == nullptr)
		{
			mRoot = new BinaryTree(value);
			return;
		}
		BinaryTree* newRoot = new BinaryTree(value);

		while (mRoot != nullptr)
		{
			if (mRoot->mValue < value)
			{
				if (mRoot->mRight == nullptr)
				{
					mRoot->mRight = newRoot;
					return;
				}
				mRoot = mRoot->mRight;
			}
			else
			{
				if (mRoot->mLeft == nullptr)
				{
					mRoot->mLeft = newRoot;
					return;
				}
				mRoot = mRoot->mLeft;
			}
		}

	}

	vector<int> inOrderTraversal()
	{
		BinaryTree* root = this;
		vector<int> ans;
		findInOrder(root, ans);
		return ans;
	}

	vector<int> preOrderTraversal()
	{
		BinaryTree* root = this;
		vector<int> ans;
		findPreOrder(root, ans);
		return ans;
	}

	vector<int> postOrderTraversal()
	{
		BinaryTree* root = this;
		vector<int> ans;
		findPostOrder(root, ans);
		return ans;
	}
};

int main()
{
	BinaryTree* bT = new BinaryTree(3);
	bT->addNewLeaf(5);
	bT->addNewLeaf(4);
	bT->addNewLeaf(2);
	bT->addNewLeaf(9);
	bT->addNewLeaf(1);
	bT->addNewLeaf(3);

	cout << "InOrder Traversal: ";
	for (auto x : bT->inOrderTraversal())
		cout << x << " ";
	cout << endl;

	cout << "PreOrder Traversal: ";
	for (auto x : bT->preOrderTraversal())
		cout << x << " ";
	cout << endl;

	cout << "PostOrder Traversal: ";
	for (auto x : bT->postOrderTraversal())
		cout  << x << " ";
	cout << endl;

		return 0;
}