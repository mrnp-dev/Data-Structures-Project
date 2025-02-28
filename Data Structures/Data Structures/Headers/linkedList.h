#pragma once
#include "Node.h"
#include <iostream>
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


