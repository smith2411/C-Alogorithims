#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T, class K = int>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		K key;
		Node* left;
		Node* right;
		//Node* parent;//Some tree variations do this. It isn't necessary for a BST.

		Node(T d, K k, Node* l = nullptr, Node* r = nullptr)
			: data(d), key(k), left(l), right(r)//Member Initialization List
		{

		}
	};

	Node* root = nullptr;

public:
	//This is the publicly accessible Add
	//function that can be used without having
	//to pass in any nodes.
	void Add(T data, K key)
	{
		Add(data, key, root);
	}

	void Clear()
	{
		Clear(root);
	}

	~BinarySearchTree()
	{
		Clear(root);
	}
	BinarySearchTree& operator=(BinarySearchTree &otherTree)
	{

	}

	BinarySearchTree()
	{

	}

	BinarySearchTree(BinarySearchTree &otherTree)
	{

	}

	//3 Ways to traverse a tree
	//Inorder Traversal - left first, then parent, then child (visits in sorted order)
	//PreOrder Traversal - parent node first (visits root first)
	//PostOrder Traversal - children first (usually left first, but doesn't matter) (visits root last)
	void DisplayInOrder()
	{
		DisplayInOrder(root);
	}
	void DisplayInOrderIterative()
	{
		DisplayInOrderIterative(root);
	}
	void DisplayInTreeFormat()
	{
		DisplayInTreeFormat(root, 0);
	}
	void DisplayPreOrder()
	{
		DisplayPreOrder(root);
	}

	void DisplayPostOrder()
	{
		DisplayPostOrder(root);
	}

	void Remove(K key)
	{
		//if (!root)return;//Tree is empty//Don't even need this line if we write Remove just right
		Remove(key, root);
	}

	T Get(K key) const
	{
		return Get(key, root);
	}

	T GetIterative(K key) const
	{
		Node* temp = root;
		while (temp != nullptr)
		{
			if (temp->key == key)
				return temp->data;
			else if (key > temp->key)
				temp = temp->right;
			else
				temp = temp->left;
		}

		throw string("Key: " + to_string(key) + " Not Found");
	}

	void Balance() // vector of node pointers
	{
		vector<Node*> vecNode; //creating vector of pointers
		root = vecNode[0];	//setting the first node to the root
		// should call helper1, 
		//randomly shuffle
		Helper1(vecNode); // adding in from post order
		random_shuffle(vecNode.begin(), vecNode.end());	// randomly shuffle the nodes.
		// first node is the new root
		root = vecNode[0];	
		//loop through at 2nd spot
		for (int i = 1; i < vecNode.size(); ++i)
		{
		//add node to the tree
			AddNode(root, vecNode);
		}
		
		
	}
private:
	void Add(T data, K key, Node*& n)
	{
		if (n == nullptr)
			n = new Node(data, key);
		else if (key > n->key)//go to the right
			Add(data, key, n->right);
		else//go to the left
			Add(data, key, n->left);
	}

	T Get(K key, Node* n) const
	{
		//T temp = T();//Gives T a default value, like 0 for int, "" for string
		if (!n)
			throw string("Value " + to_string(key) + " not found.");

		if (n->key == key)
			return n->data;
		else if (key > n->key)
			return Get(key, n->right);
		else
			return Get(key, n->left);
	}


	void Remove(K key, Node*& node)
	{
		if (node)// != nullptr)
		{
			if (node->key == key)//Found the node to delete
			{
				Node* temp = node;
				if (node->right == nullptr)//Only has a left child OR is a leaf (it would work in both cases)
					node = node->left;
				else if (node->left == nullptr)//Only has a right child
					node = node->right;
				else//Node has two children
				{
					Node* attachPoint = node->right;
					while (attachPoint->left != nullptr)
						attachPoint = attachPoint->left;
					attachPoint->left = node->left;
					node = node->right;
				}
				delete temp;
			}
			else if (key > node->key)
				Remove(key, node->right);
			else
				Remove(key, node->left);
		}
	}

	//This is from where we ran out of time on 3/11
	//We could finish this version, but adding code to account for
	//the root would make it almost twice as long.
	//So instead we'll use a clever trick (using Node*&) to simplify it above
	void UnfinishedRemove(K key, Node* n, Node* p)
	{
		if (!n)
			return;//key isn't found

		if (n->key == key)
		{
			//remove the node
			if (!n->left && !n->right)//leaf/has no children
			{
				if (p->left == n)
					p->left = nullptr;
				else
					p->right = nullptr;
				delete n;
			}
			else if (n->left && !n->right)//has a left child, no right child
			{
				if (p->left == n)
					p->left = n->left;
				else
					p->right = n->left;
				delete n;
			}
			else if (n->right && !n->left)//has a right child, no left
			{
				if (p->left == n)
					p->left = n->right;
				else
					p->right = n->right;
				delete n;
			}
			else//has 2 children
			{
				//Promote left child
				if (p->left == n)
					p->left = n->left;
				else
					p->right = n->left;

				//Reattach right child to rightmost point
					//in left subtree
				Node* temp = n->left;
				while (temp->right)
					temp = temp->right;
				temp->right = n->right;
				delete n;
			}
		}
		else if (key > n->key)
			UnfinishedRemove(key, n->right, n);
		else
			UnfinishedRemove(key, n->left, n);
	}


	void DisplayInOrder(Node* n)
	{
		if (!n)
			return;

		DisplayInOrder(n->left);
		cout << n->key << ": " << n->data << endl;
		DisplayInOrder(n->right);
	}

	void DisplayInOrderIterative(Node* n)// function will display the order of the tree without the function needing to be recursive.
	{
		stack<Node*> nodeStack;	// creation of the stack
		Node *currentNode = root;	// node pointing to the current node and setting that equal to the root

		while (currentNode != nullptr || !nodeStack.empty() )	// while current node is not pointing to nothing or if the stack is not empty
		{
			while (currentNode != nullptr)	// while current node isnt equal to nothing
			{
				nodeStack.push(currentNode);	// push the current node to the stack
				currentNode = currentNode->left;	// set current node to the current node's left child
			}
			currentNode = nodeStack.top();	// set current node to the top of the stack
			nodeStack.pop();	// pop the top of the stack off

			cout << currentNode->key << ": " << currentNode->data << endl;	// output current node's key and data
			currentNode = currentNode->right;	// set current node to the current node's right child
		}
	}

	void DisplayInTreeFormat(Node* n, int height)	// this function will display the tree, visually so that the user is able to see the full tree.
	{
		if (!n)
			return;	// if no node then exit
		
		for (int i = 0; i < height; ++i)	// for loop that will add in tabs depending on the height
		{
			cout << "\t ";	// tab
		}
		
		cout << n->key << ": " << n->data;	// displaying the number(key) and data associated with element
		cout << endl;
		DisplayInTreeFormat(n->left, height + 1);	// display child left according to height
		DisplayInTreeFormat(n->right, height + 1);	// display child right according to height
		
		
	}
	void Helper1(Node* n, vector<Node> &vecNode)
	{
		// should call itself
		if (!n)
			return;

		Helper1(n->left);
		Helper1(n->right);	// loop through in post oder
		cout << n->key << ": " << n->data << endl;
		//add addresses into vector
		vecNode.emplace_back(n);
		//set children to nullptr
		n->right = nullptr;
		n->left = nullptr;
	}
	void AddNode(Node* n, Node* addedInNode)
	{
		if (n->key == nullptr)// if no key then the addedInNode is equal to n.
			n = addedInNode;
		else if (n->key > addedInNode->key)// if key is larger than the added in node's key then go right
			AddNode(addedInNode->right);	// adding in the node
		else//else, go to the left
			AddNode(addedInNode->left);
	}

	void DisplayPreOrder(Node* n)
	{
		if (!n)
			return;

		cout << n->key << ": " << n->data << endl;
		DisplayInOrder(n->left);
		DisplayInOrder(n->right);
	}

	void DisplayPostOrder(Node* n)
	{
		if (!n)
			return;

		DisplayInOrder(n->left);
		DisplayInOrder(n->right);
		cout << n->key << ": " << n->data << endl;
	}

	void Clear(Node* n)
	{
		if (n)
		{
			Clear(n->left);
			Clear(n->right);
			delete n;
		}
	}
};