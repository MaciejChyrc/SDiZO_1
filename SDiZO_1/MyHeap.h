#pragma once
#include "MyArray.h"
class MyHeap : MyArray
{
private:
	
public:
	MyHeap();
	MyHeap(unsigned int size);
	~MyHeap();
	void deleteRoot();
	int leftSon (unsigned int index);
	int rightSon (unsigned int index);
};