// Zach Smith
// 2/11/19
// Dr. Mundell, CIT 238, Assignment 2
// Helped by Dr. Mundell, and Scarlett Scarberry
#include <vector>	// inclusion of needed libraries
#include <iostream>
#include <random>
#include <algorithm>
#include <time.h>
#include "complexity.h"
#include "Timer.h"

using namespace std;

int main()
{

	srand(time(0));	// seeding time so that the numbers are all random.

	vector<int> randVec;	// vector declaration.
	int n = 1000;	// int n, which will be the variable in for loop.
	for (int i = 0; i < n; ++i)	// for loop creating a vector the size of n.
		randVec.emplace_back(rand() % 100 + 1);	// placing the numbers in the vector.

	for (int i = 0; i < n; ++i)	// for loop iterating through the vector in order to display the numbers in the vector.
		cout << randVec[i] << ", ";	// outputting the numbers in the vector.
	cout << endl;

	cout << "---------------------------------------------------------------------------------------" << endl << endl;

	cout << "Unsorted Vectors:" << endl;
	
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	complexity com1;	//object creation.
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	cout << " The Minimum number in the Vector is: " << com1.min(randVec) << endl;	//min
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	cout << " The Maximum number in the Vector is: " << com1.max(randVec) << endl;	//max
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	cout << " The Mean of the Vector is: " << com1.mean(randVec) << endl; //mean
	cout << "---------------------------------------------------------------------------------------" << endl << endl;

	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	vector<int> randVec100;	// vector declaration.
	int n100 = 100;	// int n100, which will be the variable in for loop.
	for (int i = 0; i < n100; ++i)	// for loop creating a vector the size of n100.
		randVec100.emplace_back(rand() % 100 + 1);	// placing the numbers in the vector.

	Timer timer100;	// Timer declaration.
	timer100.Start();	// start timing.
	com1.BubbleSort(randVec100);	// New, Improved, BubbleSort
	timer100.Stop();	// stop timing.
	timer100.Report("New Bubble Sort 100 numbers");	// report of time.


	for (int i = 0; i < n100; ++i)	// for loop iterating through the vector in order to display the numbers in the vector.
		cout << randVec100[i] << ", ";	// outputting the numbers in the vector.
	cout << endl;
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	vector<int> randVec10;	// vector declaration.
	int n10 = 10;	// int n10, which will be the variable in for loop.
	for (int i = 0; i < n10; ++i)	// for loop creating a vector the size of n10.
		randVec10.emplace_back(rand() % 100 + 1);	// placing the numbers in the vector.

	Timer timer10;	// Timer declaration.
	timer10.Start();	// start timing.
	com1.BubbleSort(randVec10);	// New, Improved, BubbleSort
	timer10.Stop();	// stop timing.
	timer10.Report("New Bubble Sort 10 numbers");	// report of time.

	for (int i = 0; i < n10; ++i)	// for loop iterating through the vector in order to display the numbers in the vector.
		cout << randVec10[i] << ", ";	// outputting the numbers in the vector.
	cout << endl;
	cout << "---------------------------------------------------------------------------------------" << endl << endl;

	Timer timer;	// Timer declaration.
	timer.Start();	// start timing.
	com1.oldBubbleSort(randVec);	// old Bubble Sort we did in class.
	timer.Stop();	// stop timing.
	timer.Report("Old Bubble Sort 1000 numbers");	// report of time.

	cout << "---------------------------------------------------------------------------------------" << endl << endl;

	timer.Start();	// Timer declaration.
	com1.BubbleSort(randVec);	// New Bubble Sort.
	timer.Stop();	// stop timing.
	timer.Report("New Bubble Sort 1000 numbers");	// report of time.
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	
	sort(randVec.begin(), randVec.end());

	for (int i = 0; i < n; ++i)	// for loop iterating through the vector in order to display the numbers in the vector.
		cout << randVec[i] << ", ";	// outputting the numbers in the vector.
	cout << endl;


	cout << "---------------------------------------------------------------------------------------" << endl << endl;

	cout << "Sorted Vectors:" << endl;

	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	complexity com2;	//objectt creation.
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	cout << " The Minimum number of the Vector is: " << com2.min(randVec) << endl;	//min
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	cout << " The Maximum number of the Vector is: " << com2.max(randVec) << endl;	//max
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	cout << " The Mean of the Vector is: " << com2.mean(randVec) << endl; //mean
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	cout << " The Mode of the Vector is: " << com2.mode(randVec) << endl;	//mode
	cout << "---------------------------------------------------------------------------------------" << endl << endl;
	


	system("pause");
	return 0;
}