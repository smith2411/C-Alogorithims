// Zach Smith
// Dr. Mundell, CIT 238, Assignment 6
// This Program will demonstrate knowledge of heaps by modifying the Heap.h class we made in class by making sure that BuildHeap() is called as infrequently as possible by using a boolean variable, as well as
// demonstrate knowledge about Greedy Programming by writing a function that will find the smallest number of coins needed to make a certain amount of change, and this program will also demonstrate an attempt of
// pattern matching by writing the Rabin Karp Pattern Matching Algorithm from the psuedocode given on assignment.
// ** Note: I could not get the timer.h or .cpp to work again as every time I included an existing item, it broke my code. Even copy/paste of it broke my code **
// Helped by: Dr. Mundell, Scarlett Scarberry, Thomas O'Leary
#include <iostream>
#include <vector>
#include "Heap.h"	
#include "Change.h"
#include "KMP.h"

using namespace std;

int main()
{
	/* Assignment 6, Part 1:
	Modify the heap class so 'BuildHeap' only runs once (without changing main() at all)
	and still displays the correct values. The BuildHeap() in Heap::Display() counts too.

	The 'BuildHeap' method in the Heap class is the most expensive part of maintaining a heap.
	Currently, our implementaiton has it either getting called every time a value is added to the heap,
	or everytime a value is retrieved from the heap. Either way we end up doing it more than necessary,
	and thats inefficient.
	BuildHeap() should only run if
		1. We are trying to access or display a value in the heap and
		2. The heap has not been built since the last time something was added.

	Note that the 'Pop' function already makes sure it maintains
	the 'heap property' so it doesn't have to rebuild when Pop is called.
	*/

	Heap heap;

	heap.Add(5);
	heap.Add(12);
	heap.Add(7);
	heap.Add(21);
	heap.Add(3);
	heap.Add(14);
	heap.Add(4);
	heap.Add(17);
	heap.Add(13);

	cout << "Displaying the Heap." << endl;
	heap.Display();

	cout << "The top is: " << heap.Top() << endl;//Should output 3
	cout << "Popping!" << endl;
	heap.Pop();

	cout << "The top is: " << heap.Top() << endl;//Should output 4
	cout << "Popping!" << endl;
	heap.Pop();

	cout << "The top is: " << heap.Top() << endl;//Should output 5
	cout << "Popping!" << endl;
	heap.Pop();

	cout << "The top is: " << heap.Top() << endl;//Should output 7
	cout << "Popping!" << endl;
	heap.Pop();

	cout << "The top is: " << heap.Top() << endl;//Should output 12
	cout << "Popping!" << endl;
	heap.Pop();

	cout << "The top is: " << heap.Top() << endl;//Should output 13
	cout << "Popping!" << endl;
	heap.Pop();

	cout << "The top is: " << heap.Top() << endl;//Should output 14
	cout << "Popping!" << endl;
	heap.Pop();

	cout << "The top is: " << heap.Top() << endl;//Should output 17
	cout << "Popping!" << endl;
	heap.Pop();

	cout << "The top is: " << heap.Top() << endl;//Should output 21
	cout << "Popping!" << endl;
	heap.Pop();


	cout << endl << endl;

	vector<int> coinVec{ 1, 5, 10, 25 };	// creation of coin vector with US currency coins
	

	Change change;	// object creation of the Change Class
	change.ChangeMaker(coinVec, 78);	// ChangeMaker function call, taking in the parameters of the coin vector and the number in which you want change for 


	cout << endl << endl;



	string text = "On a dark and stormy night, there was a careful careful cat named Bob.";	// source text to be given to the algorithm
	string pattern = "cat";	// patttern the algorithm is looking for

	int pSum = 0;	// intialization of pSum and sSum
	int sSum = 0;

	for (int i = 0; i < pattern.size(); ++i)	// for loop summing the size of the pattern
	{
		pSum += (int)pattern[i];	// casting each letter of the patttern to an integer value that is then added to pSum
	}

	for (int i = 0; i < pattern.size(); ++i)	// for loop summing the source text
	{
		sSum += (int)text[i];	// casting each letter of the text to an integer value that is then added to sSum
	}

	RabinKarp algo;	// object creation
	algo.RK(text, pattern, pSum, sSum); // function call


	system("pause");
	return 0;
} 