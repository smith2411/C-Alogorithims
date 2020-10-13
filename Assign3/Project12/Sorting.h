#pragma once
#include <vector>
#include <algorithm>
#include <iomanip>//setw

using namespace std;

class Sorting
{
private:

public:
	void Merge(vector<int>& vec, int lIndex, int rIndex)
	{
		//Calculate midpoint of the current subsection of the array
		int mIndex = (lIndex + rIndex) / 2;

		//Create 2 temporary arrays to store data to be merged in
		vector<int> lSubArray;
		vector<int> rSubArray;

		//Copy all the left half of the current portion of the array
		for (int i = 0; i < mIndex - lIndex + 1; ++i)
			lSubArray.push_back(vec[lIndex + i]);

		//Copy all the right half of the current portion of the array
		for (int i = 0; i < rIndex - mIndex; ++i)
			rSubArray.push_back(vec[mIndex + i + 1]);

		lSubArray.push_back(INT_MAX);
		rSubArray.push_back(INT_MAX);

		//lsubarray 2 5 9 Infinity
		//rsubarray 3 4 7 Infinity
		//2 5 9 3 4 7//Wrong (just mushing them together doesn't work)
		//2 3 4 5 7 9//Take the smallest (first) in each array
		for (int k = lIndex, i = 0, j = 0; k <= rIndex;)
		{
			if (lSubArray[i] <= rSubArray[j])//j == rSubArray.size() ||
				vec[k++] = lSubArray[i++];
			else
				vec[k++] = rSubArray[j++];
		}

	}

	void InsertionSort(vector<int>& vec)	//Insertion Sort function that we did in class.
	{
		int current = -1;
		int j = -1;
		for (int i = 1; i < vec.size(); ++i)
		{
			current = vec[i];
			j = i - 1;
			while (j >= 0 && vec[j] > current)
			{
				vec[j + 1] = vec[j];
				--j;
			}
			vec[j + 1] = current;
		}
	}

	void MergeSort(vector<int>& vec, int lIndex, int rIndex)	// Merge Sort that is attempted to be optimized.
	{
		int smallVecs = 10;	// threshold number so that the function knows when to insertion sort.
		//Base Case
		if (lIndex >= rIndex)
			return;

		//General Case
		if (abs(lIndex - rIndex) <= smallVecs)
			InsertionSort(vec);
		else
		{
			int mIndex = (lIndex + rIndex) / 2;
			MergeSort(vec, lIndex, mIndex);//Repeat with 1st half of array
			MergeSort(vec, mIndex + 1, rIndex);//Repeat with 2nd half of array
			Merge(vec, lIndex, rIndex);
		}
	}

	int Partition(vector<int>& vec, int lIndex, int rIndex)	// Partition Function that was done in class.
	{
		//Picks a number, such as the middle number
		//Then moves all numbers smaller than that one to the left of the 'pivot'
		//And all numbers larger than that number to the right of the 'pivot'
		//Returns the index where the pivot number ends up.

		int pivot = vec[(lIndex + rIndex) / 2];
		//Optionally can use random component to help
		//avoid worst case scenario of having very uneven splits
		//like a partition of 1 and a partition of vec.size-1
		//pivot = vec[lIndex];

		int low = lIndex;
		int high = rIndex;

		bool done = false;
		while (!done)
		{
			//Find first number left of pivot to swap to the right of pivot
			while (vec[low] < pivot)
				++low;

			//Find first number right of pivot to swap to the left of pivot
			while (vec[high] > pivot)
				--high;

			if (low >= high)
				done = true;
			else
				swap(vec[low++], vec[high--]);
		}
		return high;
	}


	

	int QuickSelect(vector<int>& vec, int lIndex, int rIndex, int k)	// Quick Select Algorithm
	{
		if (lIndex >= rIndex)	// if the left index is greater or = to the right index
			return vec[rIndex];	// return the number, Base Case
		int pIndex = Partition(vec, lIndex, rIndex);	// pIndex is made so that the vector can divide up the numbers by a midpoint
		if (vec.size() - k <= pIndex)	// General Case
			return QuickSelect(vec, lIndex, pIndex, k);	// return QuickSelect left
		else
			return QuickSelect(vec, pIndex + 1, rIndex, k);	// return QuickSelect right

	}

	int iterativeQS(vector<int>& vec, int lIndex, int rIndex, int k)	// Iterative form of Quick Select so that the function is not recursive.
	{
		k = vec.size() - k;
		while (lIndex <= rIndex)	// While the lIndex is less than or = to the right index
		{
			if (lIndex >= rIndex)	// if lIndex is greater than or = to rIndex
				return vec[rIndex];	// return the number at rIndex
			int pIndex = Partition(vec, lIndex, rIndex);	// pIndex to create mid point for numbers to split off
			if (vec.size() - k <= pIndex)	// if the size of the vector - k is less than or = to pIndex
				lIndex = pIndex + 1;	// lIndex is set to pIndex +1 
			else
				rIndex = pIndex;	// else set rIndex to pIndex
			

			return vec[pIndex];

		}
		return -1;
	}


	bool VerifySort(const vector<int>& vec)
	{
		for (int i = 0; i < vec.size() - 1; ++i)
			if (vec[i] > vec[i + 1])
				return false;
		return true;
	}

	void DisplayVector(const vector<int> &vec, int limit = 100)
	{
		for (unsigned int i = 0; i < limit && i < vec.size(); ++i)
			cout << setw(3) << vec[i] << ", ";
		cout << endl;
	}
};
