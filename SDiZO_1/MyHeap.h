#pragma once
class MyHeap
{
private:
	unsigned int heapSize;
	int* heapptr;
public:
	MyHeap();
	MyHeap(unsigned int size);
	~MyHeap();
	unsigned int getSize();
	int at(unsigned int index);
	void heapPush(int v);
	void heapPop();
	void resize(unsigned int newSize);
	int leftSon(unsigned int index);
	int rightSon(unsigned int index);
	int parent(unsigned int index);
	void printHeap(unsigned int index, unsigned int level);
};