#pragma once
#include <vector>
#include <iostream>

using namespace std;

class RabinKarp
{
public:
	void RK(const string &txt, const string &pattern, int pSum, int sSum)
	{
		int sSize = txt.size();	// intialization of the source text size and pattern size
		int pSize = pattern.size();
		vector<int> intVec;	// results will go here
		for (int i = 0; i < sSize-(pSize-1); ++i)	// looping through all elements in the source from 0 to the source size - (pattern size - 1)
		{
			if (sSum == pSum)	// if sSum is equal to pSum this might be a match
			{
				for (int j = 0; j < pSize; ++j)	// Checking each character from here to the pattern size to see if it is an exact match
				{
					if (txt[i + j] != pattern[j])	// if it is not a match
					{
						break;	// then break out of the loop
					}
					if (j == pSize - 1)	// if it is a match
					{
						intVec.push_back(i);	// push the index to the vector
					}
				}
			}
			else	// otherwise
			{
				if (i < sSize - pSize)	// if i is less than the text size - pattern size
				{
					sSum -= (int)txt[i];	// subtract sSum from the source[i]
					sSum += txt[i + pSize];	// add value of source[i] to sSum
				}
			}
		}	
			// checking to see if there were results
		if (intVec.empty())
		{
			cout << "No pattern found" << endl;
		}
		else	// if there were results, display them
		{
			for (int i = 0; i < intVec.size(); ++i)	// for loop displaying the vector
				cout << "Pattern found at index: " << intVec[i] << endl;
		}
	}

};