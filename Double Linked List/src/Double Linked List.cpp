//============================================================================
// Name        : Double.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>    // std::reverse
using namespace std;

class Node{

public:
	Node* next = nullptr;
	Node* previous = nullptr;
	int data;

	Node(int data): data(data) {}

	void addDataToTail(int data){
		Node* node = new Node(data);
		Node* n = this;

		while(n->next != nullptr)
		{
			Node* temp = n;
			n = n->next;
			n->previous = temp;
		}
		n->next = node;
		node->previous = n;
	}


	void deleteDataFromNode(Node** node, int data)
	{
		Node* temp = *node;
		//cout << "DEBUG1" << endl;
		while(temp != nullptr)
		{
			//cout << "DEBUG2" << endl;
			if(temp->data == data)
			{
				if(temp->previous == nullptr) //this means head
				{
					//cout << "DEBUG HEAD" << endl;
					Node* temp2 = temp;
					*node = temp->next;
					temp->previous = nullptr;
					delete temp2;
					temp2 = nullptr;
					return;

				}
				else
				{
					//cout << "DEBUG NOT HEAD" << endl;
					temp->next->previous = temp->previous;
					temp->previous->next = temp->next;
					delete temp;
					temp = nullptr;
					return;
				}
			}
			else
			{
				temp = temp->next;
			}
		}
	}

	void printValues(Node* node)
	{
		while(node != nullptr)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}

	void printValuesReverse(Node* node)
	{
		while(node != nullptr)
		{
			if(node->next == nullptr)
				break;
			node = node->next;
		}
		cout << "Reverse: ";
		while(node != nullptr)
		{
			cout << node->data << " ";
			node = node->previous;
		}
		cout << endl;
	}

};

int main() {

	Node *node = new Node(5);
	node->addDataToTail(6);
	node->addDataToTail(9);
	node->addDataToTail(88);
	node->addDataToTail(11);
	node->addDataToTail(1245);

	node->deleteDataFromNode(&node, 6);

	node->printValuesReverse(node);
	//node->deleteDataFromNode(&node, 6);
	node->printValues(node);

	delete node;
	return 0;
}
