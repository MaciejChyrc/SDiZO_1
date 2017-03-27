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
		std::cerr << "Nie udalo sie poprawnie zaalokowac kopca.\n";
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
		std::cout << "\nPoziom " << level << ": ";
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

