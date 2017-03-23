#include "stdafx.h"
#include "MyHeap.h"


MyHeap::MyHeap()
{
	
}

MyHeap::MyHeap(unsigned int size)
{

}

MyHeap::~MyHeap()
{

}
//powinno byc ok
void MyHeap::deleteRoot()
{
	arrayptr[0] = arrayptr[arraySize - 1];
	resize(arraySize - 1);
	int i = 0;
	while ((i * 2 + 1) < arraySize)
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

int MyHeap::leftSon(unsigned int index)
{
	return arrayptr[index * 2 + 1];
}

int MyHeap::rightSon(unsigned int index)
{
	return arrayptr[index * 2 + 2];
}