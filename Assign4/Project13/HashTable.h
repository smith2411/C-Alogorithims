#pragma once

#include <vector>
#include <string>

using namespace std;

/*
Problem: Searching in any container
is O(n) (linear time) to look at every element
OR O(log(n)) for binary search if its sorted

Is there any way to search in constant time? O(1)?

Accessing any value:
	Vector: O(1) (just index to the value)
	Linked List: O(n) (have to walk to the value)

Inserting:
	Linked List: O(1) if its head or tail
				O(n) if its in the middle
	Vector/Array: O(n) (unless a vector doesn't need to grow)
Removing is similar

Can we insert/remove/etc. in constant time? O(1)

*/

//Counting Sort O(n)
	//Just put the values in the index
	//of the value itself
	//aka put 1 at arr[1]
	//Fast, but downside: only works for positive whole numbers

//Key-Value pairs
//The value itself, and a 'key' value that identifies it
//Example, if the value is a Marshall Student object, the key would be a 901#

template<class T>
class DirectAddressTable
{
public:
	void Add(T value, int key)
	{
		arr[key] = value;
	}

	T Get(int index)
	{
		return arr[index];
	}

private:
	T arr[100];
};

//Solution to all the problems of a Direct Address Table is to use a Hash Table
//Hash: A fixed length value
//deterministically generated from a variable length value
//Password: password1234
//Hash(password1234) = lkj39qa8dap3ja9893842s
//Hash(password1234) = lkj39qa8dap3ja9893842s
//Hash(password1235) = 0a98uva03lkdfja3854ads

//In a hash table, 
//Hash(Student1) = index 0
//Hash(Student2) = index 73
//We can Hash 901555555 into an array index within 0-99
//deterministically: for any input, the output will always be the same (aka no random element)

//Hash Collisions
//Two keys hashing to the same hash value is called
//a collision
//Hash collisions are a notoriously difficult part of hasing
//A Perfect Hash function is one that produces no collisions - possible, if you know all the data beforehand
//Multiple hashing (linear probing)
	//Hash again or look x number of spaces away
	//until you find an unused slot
//Chaining
	//store lists of values, and each one that
	//hashes to the location gets added to the list at that location

template <class T, class K = long long>
class HashTable
{
public:
	struct ValuePair//POD Plain Old Data type
	{
		ValuePair(T d, K k)
			: data(d), key(k) {}
		T data;
		K key;
	};

	HashTable(int s = 100)
	{
		size = s;
		arr.resize(size);
	}

	void Add(T value, K key)
	{
		//calculate 1 then save value
		//int hash = Hash(key);

		//Method 1: Ignore if something is already there
		//if (arr[hash] != "")
		//	return;

		//Method 2, use Chaining
		//ValuePair v;
		//v.data = value;
		//v.key = key;
		//arr[hash].push_back(v);

		arr[Hash(key)].push_back({ value, key });
	}

	bool KeyExists(K key)	// Function will return true or false depending on whether the entered in key exists within the hash table.
	{
		int hash = Hash(key);	// local variable for the value of hash.

		for (int i = 0; i < arr[hash].size(); ++i)
		{
			if (arr[hash][i].key == key)	// if the hashed key is the same as the passed in key
			{
				cout << "Key Valid" << endl;
				return true;	// return true.
			}
		}
		cout << "Key NOT Valid" << endl;
		return false;	// if it made it here the key did not exist so return false.

	}

	bool ValueExists(T value)	// function will check to see if an entered in value is in the hash table.
	{
		
		for(int i = 0; i < arr.size(); ++i)	// for loop iterating through the array.
		{
			for (int j = 0; j < arr[i].size(); ++j)	// for loop iterating through each element.
			{
				if (arr[i][j].data == value)	// if the array's data matches the entered in value.
				{
					cout << "Entered in Value does exist" << endl;
					return true;	// return true.
				}
			}
		}

		
			cout << "Entered in Value does NOT exist" << endl;
			return false;	// if it made it here then the value does not exist.
	}

	void DeleteByKey(K key)	// function that will take an entered in key and delete it from the hash table.
	{
		int hash = Hash(key);	// local variable for the value of the hashed key/

		for (int i = 0; i < arr[hash].size(); ++i)	// for loop iterating through the arrays hash values.
		{
			if (KeyExists(key) && arr[hash][i].key == key)	// if the key exists and equals the entered in value.
			{
				arr.erase(arr.begin()+i);	// erase that pair.
			}
		}
	}




	//O(n) (On average, assuming collisions are rare, this will usually be O(1))
	T Get(K key)
	{
		int hash = Hash(key);//Improves this function's constant factors Ex. (3n + 4) -> (n + 2)

		for (int i = 0; i < arr[hash].size(); ++i)
		{
			if (arr[hash][i].key == key)
				return arr[hash][i].data;
		}
		//return arr[Hash(key)][1];
	}

	int Hash(K key)
	{//Calculates valid array index from key value
		//Requirement: must calculate numbers that are between 0 and the size of the array - 1.
		//Ideally, provides seemingly random distribution of those numbers to avoid collisions
		return abs(key) % size;
	}

private:
	//T arr[100];
	//vector<T> arr[100];
	vector<vector<ValuePair>> arr;
	int size = 100;

	//Jagged Array - Multidimensional but each 
		//row can have a different size

	//Multidimensional array
	//char tictactoe [3][3];//all rows have 3 elements
};

//Template Specialization class
//Use this one when the template argument is string,
//otherwise use the generic template class
template <class T>
class HashTable<T, string>
{
public:
	struct ValuePair//POD Plain Old Data type
	{
		ValuePair(T d, string k)
			: data(d), key(k) {}
		T data;
		string key;
	};

	HashTable(int s = 100)
	{
		size = s;
		arr.resize(size);
	}

	void Add(T value, string key)
	{
		//calculate 1 then save value
		//int hash = Hash(key);

		//Method 1: Ignore if something is already there
		//if (arr[hash] != "")
		//	return;

		//Method 2, use Chaining
		//ValuePair v;
		//v.data = value;
		//v.key = key;
		//arr[hash].push_back(v);

		arr[Hash(key)].push_back({ value, key });
	}

	//O(n) (On average, assuming collisions are rare, this will usually be O(1))
	T Get(string key)
	{
		int hash = Hash(key);//Improves this function's constant factors Ex. (3n + 4) -> (n + 2)

		for (int i = 0; i < arr[hash].size(); ++i)
		{
			if (arr[hash][i].key == key)
				return arr[hash][i].data;
		}
		//return arr[Hash(key)][1];
	}

	//O(n) n = size of key
	//but n is usually small in this case, so closer to O(1) on average
	int Hash(string key)
	{
		//Requirement: must calculate numbers that are between 0 and the size of the array - 1.
		//Ideally, provides seemingly random distribution of those numbers to avoid collisions

		   //return key.size() % size;//Lots of collisions

		int sum = 0;
		for (int i = 0; i < key.size(); ++i)
			sum += (int)key[i];
		return sum % size;
	}

	void Resize()
	{
		//Invalidates all previous hash values
		//So recalculate and move everything in the table
	}

	void DisplayTableSizes()
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			cout << arr[i].size() << endl;
		}
	}

	

private:
	//T arr[100];
	//vector<T> arr[100];
	vector<vector<ValuePair>> arr;
	int size = 100;

	//Jagged Array - Multidimensional but each 
	//row can have a different size

	//Multidimensional array
	//char tictactoe [3][3];//all rows have 3 elements
};