#include "Headers/DataStructures.h"
#include <iostream>

int main()
{
	int sz = 10000;
	Doubly<int> list;
	for (int row = 0; row < sz; row++)
	{
		list.insertHead(rand());
	}

	cout << "\nUnsorted: " << endl;
	list.display();
	list.selectionSort("reverse");

	cout << "\nSorted: " << endl;
	list.display();
	/*
	cout << "\nAll Data:" << endl;
	for (int row = 0; row < sz; row++)
	{
		cout << list.getAt(row) << " ";
	}
	*/
	//cout << list.getAt(-1);
}