
#pragma once

#include <iostream>
using namespace std;

//Linked List
//Chain of nodes that contain data and a pointer to the next node

template<class T>
class LinkedList
{
private:
	struct Node
	{
		Node(T d, Node* n = nullptr, Node* p = nullptr)
		{
			data = d;
			next = n;//Singly linked list has next only
			prev = p;//Doubly Linked List has a prev pointer in each node
		}
		T data;
		Node* next, *prev;
	};

public:
	Node * head = nullptr;
	Node * tail = nullptr;

	//vector pushback - O(n) (when it grows)
	//but vectors are Random Access containers
	//meaning we can access any random element in constant (O(1)) time

	//O(1)- constant time, same amount no matter how many nodes there are
	void PushFront(T data)
	{
		if (head == nullptr)
			tail = head = new Node(data, head);
		else
		{
			head = new Node(data, head);
			head->next->prev = head;
		}
	}

	//O(n) - linear time complexity
	//because of the loop
	//With Tail pointer, O(1)
	void PushBack(T data)
	{
		if (head == nullptr)
			tail = head = new Node(data);
		else
		{
			tail->next = new Node(data);
			tail->next->prev = tail;
			tail = tail->next;
		}

		//Without tail (notice while loop)
		//Node* temp = head;
		//while (temp->next)
		//	temp = temp->next;
		//temp->next = new Node(data);
	}

	LinkedList()//Default Constructor - no parameters (or all default params)
	{
		cout << "In LL Constructor" << endl;
	}

	//Rule of 3
	//If we have 1 of these functions, you need the other 2
		//Purpose- to avoid shallow copying of pointers
		//Destructor
		//Copy Constructor
		//Overloaded = assignment operator
	~LinkedList()
	{
		cout << "In LL Destructor" << endl;
		Node* temp = head;
		while (temp)//Traversal
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}

	LinkedList(LinkedList &otherToCopy)//Copy Constructor
	{
		this = *otherToCopy;//Just use operator= overload, so we don't have duplicate code
	}

	LinkedList& operator=(LinkedList &otherToCopy)
	{
		
/*		if (otherToCopy)
			return *this;
		else
		{
			Node* temp = otherToCopy.head;
			
			while (temp.head != nullptr)
			{
				temp.PopFront();
			}
			while (temp)
			{
				PushBack(temp->data);
				temp = temp->next;
			}
		}
		return *this;
	*/
	}

	void Display()
	{
		Node* temp = head;
		while (temp)
		{
			cout << temp->data << ", ";
			temp = temp->next;//moving temp through the list
		}
		cout << endl;
	}

	//should be O(1). Shouldn't need any temporary pointers in a doubly linked list
	void PopFront()	// function that will remove the first element in a doubly linked list.
	{
		if (!head)	// if no head
			return;	// return, theres no list
		if(head)	// if there is a head 
		{
			head = head->next;	// head is now set to its next element
			head->prev = nullptr;	// since the new head has a prev, set to nullptr since it is now the head
		}
		
	}

	//should be O(1) if we maintain a tail pointer. Shouldn't need any temporary pointers in a doubly linked list
	void PopBack()	// function will remove the last element in a doubly linked list.
	{
		if (!tail)	// if no tail
			return;	// then return, theres no list
		if (tail)	// if there is a tail
		{
			tail = tail->prev;	// tail is set to its prev element
			tail->next = nullptr;	// since the new tail should not have a next, set next to nullptr
		}
	}

	//O(n)
	void Remove(T data)
	{
		if (!head)
			return;//list is empty
		if (head->data == data)
		{
			PopFront();
			return;
		}
		else if (tail->data == data)
		{
			PopBack();
			return;
		}

		//The rest of this function could be done without the variable 'temp2' in a doubly linked list.
		Node* temp = head;
		Node* temp2 = head;
		while (temp != nullptr && temp->data != data)
		{
			temp2 = temp;
			temp = temp->next;
		}

		if (!temp)
			return;//data wasn't found 
		else//element found somewhere in the middle
		{
			temp2->next = temp2->next->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}

	//O(n) but...
	//O(1) if using a doubly linked list (and no temp's necessary)
	void Remove(Node* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
	}
};