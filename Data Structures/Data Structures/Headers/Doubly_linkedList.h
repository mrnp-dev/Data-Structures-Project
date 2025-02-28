#pragma once
#include "linkedList.h"

template <class type>
class Doubly : public linkedList<type>
{

public:
	//Insertion
	void insertHead(type);
	void insertTail(type);
	void insertAt(int, type);
	//Deletion
	void deleteHead();
	void deleteTail();
	void deleteAt(int);
};


//---------------------Insertion---------------------

template <class type>
void Doubly<type>::insertHead(type data) 
{
	node<type>* newNode = new node<type>;
	newNode->data = data;
	newNode->next = nullptr;
	newNode->before = nullptr;

	if (linkedList<type>::isEmpty())
	{
		this->tail = newNode;
		this->head = newNode;
		this->size++;
		return;
	}

	newNode->next = this->head;
	this->head = newNode;
	this->size++;
}

template <class type>
void Doubly<type>::insertTail(type data) 
{
	node<type>* newNode = new node<type>;
	newNode->data = data;
	newNode->next = nullptr;
	newNode->before = nullptr;

	if (linkedList<type>::isEmpty())
	{
		this->tail = newNode;
		this->head = newNode;
		this->size++;
		return;
	}

	newNode->before = this->tail;
	this->tail->next = newNode;
	this->tail = newNode;
	this->size++;
}

template <class type>
void Doubly<type>::insertAt(int pos, type data) 
{
	node<type>* newNode = new node<type>;
	newNode->data = data;
	newNode->next = nullptr;
	newNode->before = nullptr;

	if (linkedList<type>::isEmpty() || pos >= this->size || pos < 0)
	{
		linkedList<type>::insertAt(pos, data);
		return;
	}

	if (pos == 0)
	{
		insertHead(data);
		return;
	}

	if (pos == this->size)
	{
		insertTail(data);
		return;
	}

	if (pos <= (this->size - 1) / 2)
	{
		node<type>* temp = this->head;
		for (int row = 1; row < pos;row++)
		{
			temp = temp->next;
		}
		temp->next->before = newNode;
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->before = temp;
		this->size++;
	}
	else
	{
		node<type>* temp = this->tail;
		for (int row = this->size - 1; row > pos; row--)
		{
			temp = temp->before;
			// 1 2 (3) 3 4 (4)
		}
		temp->before->next = newNode;
		newNode->before = temp->before;
		newNode->next = temp;
		temp->before = newNode;
		this->size++;
	}
	
}

//---------------------Deletion---------------------

template <class type>
void Doubly<type>::deleteHead() 
{
	if (linkedList<type>::isEmpty())
		return;

	node<type>* temp = this->head;
	this->head = this->head->next;
	this->head->before = nullptr;

	if (this->size == 1)
		this->tail = nullptr;

	delete temp;
	temp = nullptr;
	this->size--;
}

template <class type>
void Doubly<type>::deleteTail() 
{
	if (linkedList<type>::isEmpty())
		return;

	if (this->size == 1)
	{
		delete this->tail;
		this->head = nullptr;
		this->tail = nullptr;
		this->size--;
		return;
	}

	node<type>* temp = this->tail;
	this->tail = this->tail->before;
	this->tail->next = nullptr;

	delete temp;
	temp = nullptr;
	this->size--;
}

template <class type>
void Doubly<type>::deleteAt(int pos) 
{
	if (linkedList<type>::isEmpty() || pos >= this->size || pos < 0)
	{
		linkedList<type>::deleteAt(pos);
		return;
	}

	if (pos == 0)
	{
		deleteHead();
		return;
	}

	if (pos == this->size - 1)
	{
		deleteTail();
		return;
	}

	if (pos <= (this->size - 1) / 2)
	{
		node<type>* temp = this->head->next;
		for (int row = 1; row < pos;row++)
		{
			temp = temp->next;
		}
		temp->before->next = temp->next;
		temp->next->before = temp->before;
		delete temp;
		temp = nullptr;
		this->size--;
	}
	else
	{
		node<type>* temp = this->tail->before;
		for (int row = this->size - 1; row > pos; row--)
		{
			temp = temp->before;
		}
		temp->before->next = temp->next;
		temp->next->before = temp->before;
		delete temp;
		temp = nullptr;
		this->size--;
		//1 2 3 4
	}
}