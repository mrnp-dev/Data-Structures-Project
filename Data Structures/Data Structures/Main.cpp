#include "Headers/DataStructures.h"
#include <iostream>

int main()
{
	Doubly<int> list;
	for (int row = 0; row < 5; row++)
	{
		list.insertHead(row);
	}
	list.display();
}