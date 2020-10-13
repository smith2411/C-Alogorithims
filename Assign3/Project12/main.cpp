//Zach Smith
//Dr. Mundell
//Assignment 3
// This program will demonstrate implementations and optimizatiton of the algorithms; Merge Sort, Insertion Sort, Quick Select and an Iterative version of Quick Select.
// !! My program was giving me unresolved file issues when I included your time.h file, and when I deleted it, then copy and pasted the code into a fresh .h file, it still was breaking everything.
// I was not able to test time for this assignment. !!
// Helped by Scarlett Scarberry and Dr. Mundell.

#include <iostream>	// Includsion of Libraries
#include <random>
#include <time.h>
#include <vector>
#include "sorting.h"
//#include "timer.h"

using namespace std;

int main()
{
	//seed random generation so its different every time the program runs.
	srand((unsigned int)time(0));

	Sorting sort1;	// object creations.
	Sorting sort2;
	Sorting sort3;
	int numElements;
	//Prepare a vector of random numbers
	vector<int> vec1;
	int n = 10;
	for (int i = 0; i < n; ++i)
		vec1.emplace_back(rand() % 1000 + 1);

	
	sort1.DisplayVector(vec1);

	//Make copies of random vector for testing 
	//how long it takes to sort each with different methods
	vector<int> vec2 = vec1, vec3 = vec1, vec4 = vec1, vec5 = vec1, vec6 = vec1;

	//Timer timer;

	cout << endl;
	//timer.Start();
	sort1.MergeSort(vec1, 0, vec1.size() - 1);
	//timer.Stop();
	//timer.Report();
	sort1.DisplayVector(vec1);

	sort2.DisplayVector(vec2);
	cout << endl;
	//timer.Start();
	cout << sort2.QuickSelect(vec2, 0, vec2.size() - 1, 3);
	//timer.Stop();
	//timer.Report();
	
	sort3.DisplayVector(vec3);
	cout << endl;
	//timer.Start();
	cout << sort3.iterativeQS(vec3, 0, vec3.size() - 1, 2);
	//timer.Stop();
	//timer.Report();


	system("pause");
	return 0;
}