#include <iostream>
#include <memory>
#include <stack>

using namespace std;

/* add 7,5,9,10,6,8,4,3,12
*							7
*						  /   \
*						5      9
*					  /   \   /  \
*					 4     6 8    10
*					/               \
*				   3				 12
* Zigzag Traversal should be: 7-9-5-4-6-8-10-12-3
*/
class BinaryTree
{
	int val;
	BinaryTree* right;
	BinaryTree* left;
public:
	BinaryTree(int val): val(val), right(nullptr), left(nullptr) {};

	void addValueToTree(int value)
	{
		BinaryTree* root = this;
		if (root == nullptr)
		{
			root = new BinaryTree(value);
			return;
		}

		while (root != nullptr)
		{
			if (root->val < value)
			{
				if (root->right == nullptr)
				{
					root->right = new BinaryTree(value);
					return;
				}
				else
					root = root->right;
			}
			else
			{
				if (root->left == nullptr)
				{
					root->left = new BinaryTree(value);
					return;
				}
				else
					root = root->left;
			}
		}
	}

	void zizagTraversal()
	{
		BinaryTree* root = this;
		if (root == nullptr)
			return;
		// declare two stacks
		stack<BinaryTree*> currentlevel;
		stack<BinaryTree*> nextlevel;

		// push the root
		currentlevel.push(root);

		bool lefttoright = true;

		// check if stack is empty 
		while (!currentlevel.empty()) {
			// pop out of stack
			BinaryTree* temp = currentlevel.top();
			currentlevel.pop();

			// if not null
			if (temp) {

				// print the data in it
				cout << temp->val << " ";

				// store data according to current order.
				if (lefttoright) 
				{
					if (temp->left)
						nextlevel.push(temp->left);
					if (temp->right)
						nextlevel.push(temp->right);
				}
				else 
				{
					if (temp->right)
						nextlevel.push(temp->right);
					if (temp->left)
						nextlevel.push(temp->left);
				}
			}
			//if the currentlevel is empty, then swap it with nextLevel
			//now nextlevel is empty and currentlevel is not.
			if (currentlevel.empty()) 
			{
				lefttoright = !lefttoright;
				swap(currentlevel, nextlevel);
			}
		}
	}
};

int main()
{
	std::unique_ptr<BinaryTree> bT(new BinaryTree(7));

	//add 7,5,9,10,6,8,4,3,12
	bT->addValueToTree(5);
	bT->addValueToTree(9);
	bT->addValueToTree(10);
	bT->addValueToTree(6);
	bT->addValueToTree(8);
	bT->addValueToTree(4);
	bT->addValueToTree(3);
	bT->addValueToTree(12);

	bT->zizagTraversal();


	return 0;
}