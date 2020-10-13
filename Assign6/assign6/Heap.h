#pragma once

#include <iostream>	// inclusion of libraries
#include <vector>

using namespace std;

class Heap
{
public:
	bool Built = false;	// boolean variable that is set to false meaning that the heap has not been built
	Heap()
	{
		arr = new int[100];
	}

	~Heap()
	{
		delete[] arr;
	}

	//O(nlg(n))
	void BuildHeap()
	{
		Built = true;	// if the function BuildHeap() is called then Built is set equal to true.
		cout << "Build Heap (Expensive!)" << endl;
		for (int i = (end - 1) / 2; i >= 0; --i)
			Heapify(i);
	}


	//O(lg(n))
	void Heapify(int pIndex)//Take any 3 nodes (parent, children) and make sure they form a valid min-heap (just makes sure the smallest is the parent)
	{
		int lCIndex = LeftChild(pIndex);
		int rCIndex = RightChild(pIndex);

		if (lCIndex >= end)//no children
			return;
		else if (rCIndex >= end)//only has a left child
		{
			if (arr[pIndex] > arr[lCIndex])
				swap(arr[pIndex], arr[lCIndex]);
		}
		else// 2 children
		{
			// 2  ->   0
			//1 0     1 2
			int smallestIndex = pIndex;
			if (arr[smallestIndex] > arr[lCIndex])
				smallestIndex = lCIndex;
			if (arr[smallestIndex] > arr[rCIndex])
				smallestIndex = rCIndex;

			if (smallestIndex != pIndex)
			{
				swap(arr[pIndex], arr[smallestIndex]);
				Heapify(smallestIndex);
			}
		}
	}


	void Display()
	{
		if(!Built)	// if the heap is not built
			BuildHeap();	// BuildHeap()
		else	// else just display
		{
			for (int i = 0; i < end; ++i)
				cout << arr[i] << ", ";
			cout << endl;
		}
	}

	void Add(int val)
	{
		//should resize if end == capacity - skipping to save class time, this is identical to how a vector/smart array resizes.

		arr[end++] = val;//place the value in the next available slot

	}

	//O(1)
	int Top()//return the root value which should be the smallest value in a min-heap
	{
		if(!Built)	// if the heap is not built
			BuildHeap();	// BuildHeap()
		else	// otherwise return arr[0]
			return arr[0];
	}

	void Pop()//removes the top element, and ensures that the next smallest ends up as the root
	{
		swap(arr[0], arr[--end]);//swap first value with last and move end up
		Heapify(0);
	}

private:
	int Parent(int index)
	{
		return (index - 1) / 2;
	}

	int LeftChild(int index)
	{
		return index * 2 + 1;
	}

	int RightChild(int index)
	{
		return index * 2 + 2;
	}

	int* arr = nullptr;
	int end = 0;
};