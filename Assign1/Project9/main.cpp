// Zach Smith
// 1/29
// Algorithms, Prof: Dr. Mundell
// This program will generate a vector of a 1000 random numbers and display the largest value in an unsorted vector, display the 3rd largest number in an unsorted
// vector, and display the 3rd largest number in a sorted vector.
// Helped by: Scarlett Scarberry and Dr. Mundell

#include <iostream>		//inclusion of needed libraries
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>		//time()


using namespace std;

int main()
{
	int max = 0;		// Local Variables 
	int max1 = 0;
	int max2 = 0;
	int max3 = 0;
	int numVecSize = 0;

	srand(time(0));		// seeding time to try and have the least amount of duplicate numbers possible
	vector<int> thousandVec;	// Vector declaration
	for (int i = 0; i < 1000; ++i)	// For loop that will generate a vector of a 1000 random ints
		thousandVec.emplace_back(rand() % 1000 + 1);	// placing numbers in vector

	for (int i = 0; i < 1000; ++i)	// for loop outputting the vector (unsorted)
		cout << thousandVec[i] << ", ";	

	cout << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl << endl;

	for (int i = 0; i < thousandVec.size(); ++i)	// for loop that will search through the vector and store the largest number in the variable max
		if (max < thousandVec[i])	// if statement will evaluate if the number the vector is on in the loop is larger than what is already stored in the variable max
			max = thousandVec[i];

	cout << "The largest Number is: " << max;

	cout << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl << endl;

	for (int i = 0; i < thousandVec.size(); ++i)	// for loop that will store the largest three values from the vector
	{
		if (thousandVec[i] > max1 && thousandVec[i] > max2 && thousandVec[i] > max3)	// will evaluate if the number is greater than the largest max and still greater than max2 and max3
		{
			max1 = thousandVec[i];
		}
		else if (thousandVec[i] > max2 && thousandVec[i] < max1 && thousandVec[i] > max3)	// will evaluate if the number is greater than max2, but less than max1, and still greater than max3
		{
			max2 = thousandVec[i];
		}
		else if (thousandVec[i] > max3 && thousandVec[i] < max2 && thousandVec[i] < max1)	// will evaluatte if the number is greater than max3 and less than max1 and max2
		{
			max3 = thousandVec[i];
		}
	}

	cout << " 3rd Largest in Unsorted Vector is " << max3;

	cout << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl << endl;


	sort(thousandVec.begin(), thousandVec.end());	// sort() function that will sort our vector starting from smallest to largest
	cout << "after Sort" << endl;	
	auto last = unique(thousandVec.begin(), thousandVec.end());	// storing the duplicates in the vector
	thousandVec.erase(last, thousandVec.end());	// deleting duplicates
		
		
	numVecSize = thousandVec.size();	// setting the new size of the vector in a variable
	
		


	for (int i = 0; i < thousandVec.size(); ++i)	// for loop that will display the new sorted, and unique number valued vector
		cout << thousandVec[i] << ", ";

	cout << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl << endl;

	cout << " 3rd Largest in Sorted: " << thousandVec[numVecSize - 3] << endl;	// outputting the 3rd to last element in the vector, which is the 3rd largest unique value

	cout << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl << endl;

	system("pause");	//not really sure why my programs will not run without this, I think it has to be the way I am creating a new project because I had this issue at the end of last semester.
	return 0;
}


// 5. The algorithm for finding the 3rd largest unique value that was more efficient was when I was trying to find the 3rd largest value in the sorted vector. I believe this because
//	once it was sorted, all you needed to do was delete the duplicates and then just output the 3rd to last element since they were all unique numbers. I was not sure why a reverse for loop (like you had 
//	suggested) would be better suited for this as all the numbers were unique and sorted. Sorting does affect the algorithm that you are trying to write as it can make it easier to find certain numbers in a 
//	large vector such as this one. I can assume that the sorted algorithm is faster as you would just need to output the element you are looking for as long as there are no duplicates in your data.