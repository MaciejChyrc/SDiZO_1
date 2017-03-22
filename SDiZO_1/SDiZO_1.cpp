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

	lista.print();

	MyArray *tablica = new MyArray(3);
	tablica->insert(1, 0);
	tablica->insert(2, 1);
	tablica->insert(3, 2);
	tablica->pushFront(10);
	tablica->print();
	_getch();
	
	return 0;
}