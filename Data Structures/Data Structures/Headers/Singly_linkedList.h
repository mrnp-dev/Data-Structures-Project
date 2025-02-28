#pragma once

#include "Node.h"
#include "linkedList.h"
#include <iostream>
using namespace std;

template <class type>
class Singly
{
private:
	node<type>* head;
	node<type>* tail;
	int size;
private:
	bool isEmpty();
public:
	Singly();
	~Singly();
	//Insertion
	void insertHead(type);
	void insertTail(type);
	void insertAt(int,type);
	//Deletion
	void deleteHead();
	void deleteTail();
	void deleteAt(int);
	//Utilities
	int getSize();
	void display();
	node<type>* getNode();
};

template <class type>
Singly<type>::Singly()
{
	size = 0;
	tail = nullptr;
	head = nullptr;
}

template <class type>
Singly<type>::~Singly()
{
	node<type>* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<class type>
bool Singly<type>::isEmpty()
{
	return head == nullptr;
}


//---------------------Insertion---------------------
template <class type>
void Singly<type>::insertHead(type data)
{
	node<type>* newNode = new node<type>;
	newNode->data = data;
	newNode->next = nullptr;

	if (isEmpty())
	{
		tail = newNode;
		head = newNode;
		size++;
		return;
	}

	node<type>* temp = head;
	head = newNode;
	head->next = temp;
	size++;
}

template <class type>
void Singly<type>::insertTail(type data)
{
	node<type>* newNode = new node<type>;
	newNode->data = data;
	newNode->next = nullptr;

	if (isEmpty())
	{
		tail = newNode;
		head = newNode;
		size++;
		return;
	}

	tail->next = newNode;
	tail = tail->next;
	size++;
}

template <class type>
void Singly<type>::insertAt(int pos, type data)
{
	node<type>* newNode = new node<type>;
	newNode->data = data;
	newNode->next = nullptr;

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

	if (pos == 0)
	{
		insertHead(data);
		return;
	}

	if (pos == size)
	{
		insertTail(data);
		return;
	}

	node<type>* temp = head;

	for (int row = 1; row < pos; row++)
	{
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;

	size++;
}

//---------------------Deletion---------------------
template <class type>
void Singly<type>::deleteHead()
{
	if (isEmpty())
		return;

	node<type>* temp = head;
	head = head->next;

	if (size == 1)
		tail = nullptr;

	delete temp;
	temp = nullptr;
	size--;
}

template <class type>
void Singly<type>::deleteTail()
{
	if (isEmpty())
		return;

	if (size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
		return;	
	}

	node<type>* temp = head;
	while (temp->next != tail)
	{
		temp = temp->next;
	}

	size--;
	delete tail;

	tail = temp;
	tail->next = nullptr;

	temp = nullptr;
}

template <class type>
void Singly<type>::deleteAt(int pos)
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

	if (pos == 0)
	{
		deleteHead();
		return;
	}

	if (pos == size - 1)
	{
		deleteTail();
		return;
	}

	node<type>* temp = head->next;
	node<type>* prev = head;
	for (int row = 1; row < pos; row++)
	{
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;

	size--;
	delete temp;
	temp = nullptr;

}


//---------------------Utilities---------------------
template <class type>
void Singly<type>::display()
{
	node<type>* temp = head;
	for (int row = 0; row < size; row++)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <class type>
int Singly<type>::getSize()
{
	return size;
}

template <class type>
node<type>* Singly<type>::getNode()
{
	return head;
}

//1 2 (4) 3