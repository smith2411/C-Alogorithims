// Zach Smith
// Algorithms Assignment 5
// Helped by Scarlett Scarberry, Thomas O'Leary, and Dr. Mundell
// This program will attempt to demonstrate knowledge on trees by modifying the recursive display function to be iterative, Display a tree, visually, to the user, and by adding in a funciton that
// will balance the given tree.
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#include "BinarySearchTree.h"

using namespace std;

int main() 
{
	BinarySearchTree<string, double> tree;
	tree.Add("Pancakes", 5);
	tree.Add("Pasta", 3);
	tree.Add("Coffee", 7);
	tree.Add("Spaghetti", 2);
	tree.Add("Cookie", 9);
	tree.Add("Pizza", 1);
	tree.Add("Sub", 8);
	tree.Add("Fries", 4);
	tree.Add("Tea", 6);
	tree.Add("Crackers", 6.5);
	tree.Add("Cake", 10);
	tree.Add("Scones", 2.5);
	tree.Add("Bread", 8.5);
	tree.Add("Toast", 9.5);
	tree.DisplayInTreeFormat();

	//tree.DisplayTreeForm();
	cout << tree.Get(10) << endl;

	tree.DisplayInOrder();
	cout << endl << endl;
	//tree.DisplayPreOrder();
	//cout << endl << endl;
	//tree.DisplayPostOrder();
	cout << tree.Get(6) << endl;
	cout << tree.GetIterative(6) << endl;

	tree.Remove(2.5);//test removing a leaf
	tree.Remove(6);//test removing a node with a right child
	tree.Remove(9.5);
	tree.Remove(7);//test removing a node with 2 children
	tree.Remove(5);//test removing the root
	tree.Remove(-1);//test removing a value that isn't in the tree
	tree.DisplayInOrder();

	cout << endl;

	BinarySearchTree<string> tree2;
	tree2.Add("Candy", 1);
	tree2.Add("Twix", 2);
	tree2.Add("Hersheys", 3);
	tree2.Add("Sweet Tarts", 4);
	tree2.Add("Ropes", 5);
	tree2.DisplayInTreeFormat();
	


	BinarySearchTree<string> tree3;
	tree3.Add("Candy", 1);
	tree3.Add("Twix", 2);
	tree3.Add("Hersheys", 3);
	tree3.Add("Sweet Tarts", 4);
	tree3.Add("Ropes", 5);
	//tree3.Balance(); does not work :(
	

	cout << endl;

	//vector<int> food;
	//for (int i = 11; i < 100; ++i)
	//	food.push_back(i);
	//random_shuffle(food.begin(), food.end());
	//for (int i = 0; i < food.size(); ++i)
	//	tree.Add("Random Food " + to_string(food[i]), food[i]);
	//
	//tree.DisplayInOrder();
	//
	//cout << "------------------------------------" << endl;

	
	
	

	system("pause");

	return 0;
}