// Zach Smith
// CIT 238
// Assignment 4
// This program will demonstrate a working pop_front and back functions and will be able to make linked list be set equal to other lists. This program will also modify the hash table
// that we created in class by adding 2 bool functions to check if a key and value exist within the hash table and by adding a function to delete a value pair in the hash table by an entered
// in key. This program will also use the STL library unordered_map to find multiple modes within a given map.
// Helped by Scarlett Scarberry and Thomas O'Leary

#include <iostream>	//inclusion of needed libraries
#include <time.h>
#include <unordered_map>

#include "doublyLinkList.h"
#include "HashTable.h"


using namespace std;


	
int main()
{

	srand(time(0));
	LinkedList<string> linkedList;
	linkedList.PushFront("Blue Man Group");
	linkedList.PushFront("Fall Out Boy");
	linkedList.PushFront("Lady Gaga");
	linkedList.PushBack("Black Eyed Peas");
	linkedList.Display();

	linkedList.Remove("Black Eyed Peas");
	linkedList.PopBack();//should remove Blue Man Group
	linkedList.PopFront();//should remove Lady Gaga
	linkedList.PushFront("Beatles");
	linkedList.PushBack("Eagles");
	linkedList.Display();
	LinkedList<string> linkedList1;
	//linkedList = linkedList1;

	//linkedList1.Display();
	cout << endl;
	HashTable<int> numbers;
	numbers.Add(1, 2);
	numbers.Add(44, 3);
	numbers.Add(23, 4);
	numbers.Add(5, 5);
	numbers.Add(8, 6);
	numbers.KeyExists(1);
	numbers.ValueExists(7);
	numbers.DeleteByKey(2);
	
	cout << endl << endl;

	unordered_map<int, int> moreNumbers;	// unordered map call generating my map of numbers.
	vector<int> vec = { 1, 2, 4, 5, 6, 7, 4, 3, 2, 6, 2, 7 ,2 ,7, 9, 7, 1, 7, 6, 2 };	// vector of 20 ints so I can validate multiple modes for testing purposes.
	for (int i = 0; i < 20; ++i)	// for loop adding the numbers from the vector to the unordered map
	{
		moreNumbers[vec[i]]++;
	}
	
	
	int count = 0;	// count for counting how many times a number occurs
	
	for (auto it = moreNumbers.begin(); it != moreNumbers.end(); ++it)	// for loop iterating through the list
	{
		if (count < it->second)	// if the count is less than it->second
		{
			count = it->second;	// count is set to it->second
		}
	}
	for (auto it = moreNumbers.begin(); it != moreNumbers.end(); ++it)	// for loop iteratingt through the list
	{
		if (it->second == count)	// if second == to count
		{
			cout << it->first << endl;	// outputting first (the modes) 
		}
	}

	
	

	system("pause");	// Still dont know why I need this, Does installing MinGW mess with visual studio compiler?
	return 0;
}