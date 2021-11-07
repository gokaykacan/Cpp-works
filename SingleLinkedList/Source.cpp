#include <iostream>
#include <memory>

using namespace std;

class SingleLinkedList
{
public:
	SingleLinkedList* next = nullptr;
	int data;

	SingleLinkedList(int data) : data(data) {} // constructor


	
	void addDataToTheList(int data)
	{
		SingleLinkedList* _node = new SingleLinkedList(data);
		SingleLinkedList* n = this;

		while (n->next != nullptr)
		{
			n = n->next;
		}
		n->next = _node;
	}
	void deleteDataFromTheList(int data)
	{
		SingleLinkedList* n = this;
		SingleLinkedList* n_previous = nullptr;

		while (n != nullptr)
		{
			if (n->data == data)
			{
				if (n_previous == nullptr) // this means HEAD
				{
					*n = *n->next;
					//n = nullptr;
				}
				else
				{
					n_previous->next = n->next;
					delete n;
				}
				return;
			}
			n_previous = n;
			n = n->next;
		}
	}
	void printListItems()
	{
		SingleLinkedList* n = this;
		while (n != nullptr)
		{
			cout << n->data; 
			n = n->next;
			if(n!=nullptr)
				cout << "->";
		}
	}
};

int main()
{
	std::unique_ptr< SingleLinkedList> n(new SingleLinkedList(5));
	n->addDataToTheList(3);
	n->addDataToTheList(6);
	n->addDataToTheList(7);
	n->addDataToTheList(10);

	n->deleteDataFromTheList(3);
	n->deleteDataFromTheList(5);
	n->printListItems();

	//delete n;
	return 0;
}