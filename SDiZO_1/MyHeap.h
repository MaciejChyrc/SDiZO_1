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
	void pushBack(int val);
	void resize(unsigned int newSize);
	void swap(unsigned int element1, unsigned int element2);
	void deleteRoot();
	void addToTail(int val);
	void heapUp(unsigned int index);
	int leftSon(unsigned int index);
	int rightSon(unsigned int index);
	int parent(unsigned int index);
	void printHeap(unsigned int index, unsigned int level);
	void heapPush(int v);
	void heapPop();
};