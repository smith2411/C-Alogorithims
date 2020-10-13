#pragma once
#include <iostream>	//inclusion of needed libraries
#include <vector>	


using namespace std;

class complexity
{

private:
	 
public:
	// Ω(n)
	int min(const vector<int> &vec)	// Function that will iterate through a vector and return the minimum number in the vector.
	{
		int min = vec[0];	// local variable starting at the begining of the vector.
		for (int i = 0; i < vec.size(); ++i)	// loop iterating through vector.
		{
			if (vec[i] < min)	// if the current number in the vector is lower than the min.
				min = vec[i];	// then min is set equal to the current number.
		}
		
		return min;	// return minimum number.
	}
	// Ω(n)
	int max(const vector<int> &vec)	// Function that will iterate through a vector and return the maximum number in the vector.
	{
		int max = vec[0];	// local variable starting at the begining of the vector.
		for (int i = 0; i < vec.size(); ++i)	// for loop iterating through vector.
		{
			if (vec[i] > max)	// if the current number in the vector is larger than max.
				max = vec[i];	// then max is set equal to the current number in the vector.
		}

		return max;	// returns maximum number in the vector.
	}
	// Ω(n)
	int mean(const vector<int> &vec)	// Function that will iterate through a vector and display its mean, or average.
	{
		int sum = 0;	// local variable being used to add up all the numbers in the vector.
		for (int i = 0; i < vec.size(); ++i)	// for loop iterating through vector.
		{
			sum += vec[i];	// adding all the numbers in the vector into the variable sum.
		}
		return sum / vec.size();	// returns the sum divided by the size of the vector.
	}
	// Ω(n)
	int mode(const vector<int> &vec)	// Function that will iterate through a vector and display the vectors most often element.
	{
		int count = 0;	// local variables to keep track of count, maxCount, and the Mode.
		int maxCount = 0;	// local variable to keep track of the highest count.
		int rMode = 0;	// Mode
		for (int i = 0; i < vec.size() - 1; ++i)	// for loop iterating through the vector size - 1 due to us comparing elements next to eachother.
		{
			if (vec[i] == vec[i + 1])	// if the current element of the vector is the same as the next element.
			{
				count++;			// then count increases.
				if (count > maxCount)	// if count is larger than the maxCount.
				{
					maxCount = count;	// maxCount now is set to count.
					rMode = vec[i];		// Mode is set to the current number in the vector.
				}
			}
			else
				count = 0;	// if count is not larger than maxCount; reset count back to 0.

		}
		return rMode;	// returns the mode of the vector.
	}

	template<class T> 
	void OurSwap(T &num1, T &num2)	// Our swap function that we made in class.
	{
		T temp = num1;	// temp is set num1.
		num1 = num2;	// num1 is set to num2.
		num2 = temp;	// num2 is set to temp.
	}

	void BubbleSort(vector<int> &vec)	// Function that is an improved version of the BubbleSort function that we did in class, and will sort the numbers by floating them to the end of the vector.
	{
		bool swapped;	// local bool variable in order to check if the numbers iterated through were swapped.
		for (int i = 0; i < vec.size() - 1; ++i)	// for loop iterating through the vector - 1 due to our nested for loop that is starting at [1] spot in the vector.
		{
			swapped = false;	// swapped set to false since no elements have beens swapped yet.
			for (int j = 1; j < vec.size(); ++j)	// for loop iterating through the vector starting at spot [1].
			{
				if (vec[j] < vec[j - 1])	// if the current element is smaller than the element before it.
				{
					OurSwap(vec[j], vec[j - 1]);	// swap those elements.
					swapped = true;	// set swapped to true since the elements were swapped.
				}
			}
			if (!swapped)	// if numbers were not swapped.
				return;	// then return.
		}

	}

	void oldBubbleSort(vector<int> &vec)	// Orginal Version of the BubbleSort that we did in class to compare to improved function.
	{
		
		for (int i = 0; i < vec.size() - 1; ++i)	// for loop iterating through the vector - 1 due to the nested for loop starting at [1].
		{
			for (int j = 1; j < vec.size(); ++j)	// for loop iterating through the vector at position [1].
			{
				if (vec[j] < vec[j - 1])	// if the current element in the array is smaller than the element before it. 
				{
					OurSwap(vec[j], vec[j - 1]);	// swap those elements.
				}
			}
		
		}

	}
};