//============================================================================
// Name        : Linked.cpp
// Author      : Gokay Kacan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Node{
	Node *next = nullptr;
	int data;
public:
	Node(int d): data(d) {}
/*	Node(const Node &node)
	{
		next = node.next;
		data = node.data;
	}
	void operator = (const Node &node)
	{
		next = node.next;
		data = node.data;
	}
*/
	void insertDataToTail(int _data)
	{
		Node *end = new Node(_data);
		Node *n = this;
		while(n->next != nullptr)
		{
			n = n->next;
		}
		n->next = end;
	}

	void deleteDataFromList(Node **_node, int _data)
	{
		Node *node = *_node;
		Node* previousNode = nullptr;
		while(node != nullptr)
		{
			//cout << "DEBUG: " << node->data << endl;
			if(node->data == _data)
			{
				if(previousNode == nullptr) //this mean data at the HEAD
				{
					Node *temp = node;
					*_node = node->next;
					delete temp;
					//*node = *(node->next); // bu da olur
					return;
				}
				else
				{
					previousNode->next = node->next;
					delete node;
					return;
				}
			}
			else
			{
				previousNode = node;
				node = node->next;
			}
		}
	}

	void printNodesData()
	{
		Node* node = this;
		while(node != nullptr)
		{
			cout << node->data << " ";
			node = node->next;
		}

	}

	Node* removeNthFromEnd(Node* head, int n) {
	        int sz = 0;
	        Node* startNode = head;
	        while(startNode != nullptr)
	        {
	            startNode = startNode->next;
	            sz += 1;
	        }
	        delete startNode;
	        startNode = nullptr;
	        int m = sz-n+1; //mth node will be deleted from the beginning(start count from 1).

	        Node* node = head;
	        Node* previousNode = nullptr;;
	        sz = 1;
	        while(head != nullptr)
	        {
	            //std::cout << "sz:" << sz  << " ";
	            //std::cout << "m: " << m << endl;
	            if(sz == m)
	            {
	            	cout << "DEBUG: removing element: " << m << "..." << endl;
	                if(previousNode != nullptr)
	                {
	                    previousNode->next = head->next;
	                    delete head;
	                }
	                else //this means HEAD
	                {
	                    cout << "DEBUG: removing HEAD..." << endl;
	                    *node = *(node->next);

	                }
	                break;

	            }
	            else
	            {
	                sz += 1;
	                previousNode = head;
	                head = head->next;
	                //cout << "DEBUG3" << endl;
	            }
	        }

	        return node;
	    }

};
int main() {

	Node *node = new Node(5);
	node->insertDataToTail(6);
	node->insertDataToTail(9);
	node->insertDataToTail(88);
	node->insertDataToTail(11);
	node->insertDataToTail(1245);

	node->deleteDataFromList(&node, 5);
	node->insertDataToTail(999);
	node->insertDataToTail(2);

	cout << "STARTED" << endl;

	node->printNodesData();

	cout << endl;
	node->removeNthFromEnd(node, 7);
	node->printNodesData();
	cout << endl;

	node->removeNthFromEnd(node, 6);
	node->printNodesData();
	cout << endl;

	node->removeNthFromEnd(node, 3);
	node->printNodesData();

	cout << endl << "FINISHED" << endl;
	return 0;
}
