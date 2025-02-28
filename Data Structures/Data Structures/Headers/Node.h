#pragma once

template<class type>
struct node
{
	type data;
	node<type>* next;
	node<type>* before;
};
