#include "stdafx.h"
#include "MyHeap.h"
#include <iostream>


MyHeap::MyHeap()
{
	arraySize = 0;
	arrayptr = nullptr;
}

MyHeap::MyHeap(unsigned int size)
{
	try
	{
		arraySize = size;
		arrayptr = new int[arraySize];
	}
	catch (std::bad_alloc)
	{
		std::cerr << "Nie udalo sie poprawnie zaalokowac tablicy.\n";
	}
}

MyHeap::~MyHeap()
{

}

unsigned int MyHeap::getSize()
{
	return arraySize;
}

int MyHeap::at(unsigned int index)
{
	return arrayptr[index];
}

void MyHeap::pushBack(int val)
{
	resize(arraySize + 1);
	arrayptr[arraySize - 1] = val;
}

void MyHeap::resize(unsigned int newSize)
{
	try
	{
		int *temp = new int[newSize];
		//przepisanie calej tablicy i zostawienie pol dodanych niezainicjalizowanych (moga tam byc smieci)
		if (newSize > arraySize)
		{
			for (int i = 0; i < arraySize; i++)
			{
				temp[i] = arrayptr[i];
			}
		}
		//przepisanie tablicy az do osiagniecia nowego rozmiaru (ostatnie elementy tracimy)
		else if (newSize < arraySize)
		{
			for (int i = 0; i < newSize; i++)
			{
				temp[i] = arrayptr[i];
			}
		}
		delete[] arrayptr;
		arrayptr = temp;
		arraySize = newSize;
	}
	catch (std::bad_alloc)
	{
		std::cerr << "Nie udalo sie poprawnie zaalokowac kopca.\n";
	}
}
void MyHeap::swap(unsigned int element1, unsigned int element2)
{
	int temp = arrayptr[element1];
	arrayptr[element1] = arrayptr[element2];
	arrayptr[element2] = temp;
}
//do poprawy indeksy
void MyHeap::deleteRoot()
{
	if (arraySize == 0) return;
	arrayptr[0] = arrayptr[arraySize - 1];
	resize(arraySize - 1);
	int i = 1;
	while (leftSon(i) < arraySize)
	{
		if (arrayptr[i] < leftSon(i) || arrayptr[i] < rightSon(i))
		{
			if (leftSon(i) > rightSon(i) || (i * 2 + 2) >= arraySize)
			{
				swap(arrayptr[i], leftSon(i));
				i = i * 2 + 1;
			}
			else
			{
				swap(arrayptr[i], rightSon(i));
				i = i * 2 + 2;
			}
		}
		else break;
	}
}
//sortowanie wywoluje blad
void MyHeap::addToTail(int val)
{
	if (arraySize == 0)
	{
		resize(1);
		arrayptr[0] = val;
	}
	else
	{
		pushBack(val);
		int i = arraySize - 1;
		while (i > 0 && parent(i) < val)
		{
				swap(arrayptr[i], parent(i));
				i = (i - 1) / 2;
		}
	}
}

int MyHeap::leftSon(unsigned int index)
{
	return arrayptr[index * 2 + 1];
}

int MyHeap::rightSon(unsigned int index)
{
	return arrayptr[index * 2 + 2];
}

int MyHeap::parent(unsigned int index)
{
	return arrayptr[(index - 1) / 2];
}

void MyHeap::printHeap(unsigned int index)
{
	if (index < arraySize)
	{
		std::cout << "Poziom " << index << ": ";
		if (index * 2 < arraySize)
		{
			for (int i = index - 1; i < index * 2; i++)
			{
				std::cout << arrayptr[i] << " ";
			}
			std::cout << "\n";
			printHeap(index * 2);
		}
		else
		{
			for (int i = index - 1; i < arraySize; i++)
			{
				std::cout << arrayptr[i] << " ";
			}
			std::cout << "\n";
		}
	}
}
