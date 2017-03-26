#include "stdafx.h"
#include "MyHeap.h"
#include <iostream>


MyHeap::MyHeap()
{
	heapSize = 0;
	heapptr = nullptr;
}

MyHeap::MyHeap(unsigned int size)
{
	try
	{
		heapSize = size;
		heapptr = new int[heapSize];
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
	return heapSize;
}

int MyHeap::at(unsigned int index)
{
	return heapptr[index];
}

void MyHeap::pushBack(int val)
{
	resize(heapSize + 1);
	heapptr[heapSize - 1] = val;
}

void MyHeap::resize(unsigned int newSize)
{
	try
	{
		int *temp = new int[newSize];
		//przepisanie calej tablicy i zostawienie pol dodanych niezainicjalizowanych (moga tam byc smieci)
		if (newSize > heapSize)
		{
			for (int i = 0; i < heapSize; i++)
			{
				temp[i] = heapptr[i];
			}
		}
		//przepisanie tablicy az do osiagniecia nowego rozmiaru (ostatnie elementy tracimy)
		else if (newSize < heapSize)
		{
			for (int i = 0; i < newSize; i++)
			{
				temp[i] = heapptr[i];
			}
		}
		delete[] heapptr;
		heapptr = temp;
		heapSize = newSize;
	}
	catch (std::bad_alloc)
	{
		std::cerr << "Nie udalo sie poprawnie zaalokowac kopca.\n";
	}
}
void MyHeap::swap(unsigned int element1, unsigned int element2)
{
	int temp = heapptr[element1];
	heapptr[element1] = heapptr[element2];
	heapptr[element2] = temp;
}
//do poprawy indeksy
void MyHeap::deleteRoot()
{
	if (heapSize == 0) return;
	heapptr[0] = heapptr[heapSize - 1];
	resize(heapSize - 1);
	int i = 1;
	while (leftSon(i) < heapSize)
	{
		if (heapptr[i] < heapptr[leftSon(i)] || heapptr[i] < heapptr[rightSon(i)])
		{
			if (heapptr[leftSon(i)] > heapptr[rightSon(i)] || rightSon(i) >= heapSize)
			{
				swap(heapptr[i], heapptr[leftSon(i)]);
				i = leftSon(i);
			}
			else
			{
				swap(heapptr[i], heapptr[rightSon(i)]);
				i = rightSon(i);
			}
		}
		else break;
	}
}
//sortowanie wywoluje blad
void MyHeap::addToTail(int val)
{
	if (heapSize == 0)
	{
		resize(1);
		heapptr[0] = val;
	}
	else
	{
		pushBack(val);
		int i = heapSize - 1;
		heapUp(i);
	}
}

void MyHeap::heapUp(unsigned int index)
{
	while (index > 0 && heapptr[parent(index)] < heapptr[index])
	{
		swap(heapptr[index], heapptr[parent(index)]);
		index = (index - 1) / 2;
	}
}

int MyHeap::leftSon(unsigned int index)
{
	return index * 2 + 1;
}

int MyHeap::rightSon(unsigned int index)
{
	return index * 2 + 2;
}

int MyHeap::parent(unsigned int index)
{
	return (index - 1) / 2;
}

void MyHeap::printHeap(unsigned int index, unsigned int level)
{
	if (index < heapSize)
	{
		std::cout << "Poziom " << level << ": ";
		if (index * 2 < heapSize)
		{
			for (int i = index - 1; i < index * 2 - 1; i++)
			{
				std::cout << heapptr[i] << " ";
			}
			std::cout << "\n";
			printHeap(index * 2, ++level);
		}
		else
		{
			for (int i = index - 1; i < heapSize; i++)
			{
				std::cout << heapptr[i] << " ";
			}
			std::cout << "\n";
		}
	}
}

void MyHeap::heapPush(int v)
{
	int i, j;
	resize(heapSize + 1);
	i = heapSize - 1;
	j = parent(i);

	while (i > 0 && heapptr[j] < v)
	{
		heapptr[i] = heapptr[j];
		i = j;
		j = parent(i);
	}
	heapptr[i] = v;
}

void MyHeap::heapPop()
{
	int i, j, val;
	//resize(heapSize - 1);
	if (heapSize - 1)
	{
		val = heapptr[heapSize - 1];

		i = 0;
		j = leftSon(i);

		while (j < heapSize - 1)
		{
			if (rightSon(i) < heapSize - 1 && heapptr[rightSon(i)] > heapptr[leftSon(i)]) j++;
			if (val >= heapptr[j]) break;
			heapptr[i] = heapptr[j];
			i = j;
			j = leftSon(i);
		}
		heapptr[i] = val;
		resize(heapSize - 1);
	}
}