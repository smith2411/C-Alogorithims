#pragma once

#include <iostream>	// inclusion of libraries
#include <vector>

using namespace std;

class Change
{

public:

	void ChangeMaker(vector<int> coins, int value)	// function will take in a predetermined vector and value to be calculated
	{
		vector<int> intVec;	//results will go here, into this vector
		int n = sizeof(coins) / sizeof(coins[0]);	// setting int n to the size of the coins over the size of the first coin
			// *note* sizeof function returns number of bytes
		for (int i = n - 1; i >= 0; i--)	// for loop that will loop through the vector in reverse so that it starts with the largest valued coin
		{
			while (value >= coins[i])	// while loop that will loop until the entered value is greater than or equal to the coin at position i
			{
				value -= coins[i];	// value will be subtracted from the current coin at position i
				intVec.push_back(coins[i]);	// push the coin at position i to the intVec that will store our results
			}
		}

		for (int i = 0; i < intVec.size(); ++i)	// for loop displaying our vector with results
			cout << intVec[i] << ",";	// outputting result at position i
	}




};