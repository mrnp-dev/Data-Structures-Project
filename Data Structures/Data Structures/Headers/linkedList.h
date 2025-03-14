#pragma once
#include "Node.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <class type>
class linkedList
{
protected:
	node<type> *head, *tail;
	int size;
protected:
	bool isEmpty();
public:
	linkedList();
	~linkedList();
	//Insertion
	virtual void insertHead(type) = 0;
	virtual void insertTail(type) = 0;
	virtual void insertAt(int, type);
	//Deletion
	virtual void deleteHead() = 0;
	virtual void deleteTail() = 0;
	virtual void deleteAt(int);
	//Utilities
	virtual type getAt(int);
	virtual int getSize();
	virtual void display();
};

template <class type>
linkedList<type>::linkedList()
{
	size = 0;
	tail = head = nullptr;
}

template <class type>
linkedList<type>::~linkedList()
{
	//cout << "\nDestructor" << endl;
	node<type>* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

//---------------------Utilities---------------------

template<class type>
bool linkedList<type>::isEmpty()
{
	return head == nullptr;
}

template <class type>
void linkedList<type>::display()
{
	node<type>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <class type>
int linkedList<type>::getSize()
{
	return size;
}

//---------------------Insertion---------------------

template <class type>
type linkedList<type>::getAt(int index)
{
	if (!isEmpty() && (index < size && index > -1))
	{
		node<type>* temp = head;
		int ind = 0;
		while (temp != nullptr)
		{
			if (ind++ == index)
				return temp->data;
			temp = temp->next;
		}
	}
	else
		throw out_of_range("Index out of Range");
}

template <class type>
void linkedList<type>::insertAt(int pos,type data) 
{
	if (isEmpty())
	{
		cerr << "Error: Linked List is empty" << endl;
		return;
	}

	if (pos >= size || pos < 0)
	{
		cerr << "Error: Invalid Index" << endl;
		return;
	}
}

//---------------------Deletion---------------------
	
template <class type>
void linkedList<type>::deleteAt(int pos) 
{
	if (isEmpty())
	{
		cerr << "Error: Linked List is empty" << endl;
		return;
	}

	if (pos >= size || pos < 0)
	{
		cerr << "Error: Invalid Index" << endl;
		return;
	}
}


