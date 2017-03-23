#pragma once
#include "MyArray.h"
class MyHeap : MyArray
{
private:
	
public:
	MyHeap() : MyArray(){}
	MyHeap(unsigned int size) : MyArray(size){}
	~MyHeap();
	void deleteRoot();
	int leftSon (unsigned int index);
	int rightSon (unsigned int index);
};