// SDiZO_1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "MyList.h"
#include "MyArray.h"
#include "MyHeap.h"


int main()
{
	MyList lista;
	lista.pushFront(1);
	lista.pushFront(2);
	lista.pushFront(3);
	lista.pushFront(4);
	lista.push(5, 2);
	lista.popBack();
	lista.printList();

	MyArray *tablica = new MyArray(3);
	tablica->pushBack(9);
	tablica->insert(1, 0);
	tablica->insert(2, 1);
	tablica->insert(3, 2);
	tablica->pushFront(10);
	tablica->swap(0, 1);
	tablica->printArray();

	MyArray tablica2;
	tablica2.pushBack(5);
	tablica2.printArray();
	
	MyHeap kopiec;
	kopiec.addToTail(1);
	kopiec.addToTail(4);
	kopiec.addToTail(3);
	//kopiec.printHeap(1);
	std::cout << kopiec.at(0) << " " << kopiec.at(1) << " " << kopiec.at(2);
	_getch();
	
	return 0;
}