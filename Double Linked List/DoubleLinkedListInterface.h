#pragma once

template <class T> class DoubleLinkedListInterface
{
public:
	DoubleLinkedListInterface(void){}
	virtual ~DoubleLinkedListInterface(void){}
		
	/**
	* addFront
	* Inserts a new node containing data at the front of the list
	*/
	virtual void addFront(T data) = 0;

	/**
	* addRear
	* Inserts a new node containing data at the rear of the list
	*/
	virtual void addRear(T data) = 0;

	/**
	* addAt
	* Inserts a new node containing data at the specified index
	* Returns true if successfully added, false if the information could not be added
	*/
	virtual bool addAt(T data, int index) = 0;

	/**
	* remove
	* Removes the node at the specified index
	* Returns true if successfully removed, false otherwise
	*/
	virtual bool remove(int index) = 0;

	/**
	* at
	* Returns the data contained in the node at the specified index
	* The index passed in will be a valid location in the existing list
	*/
	virtual T at(int index) = 0;

	/**
	* contains
	* Returns true if the list contains a node containing data, false otherwise
	*/
	virtual bool contains(T data) = 0;

	/**
	* size
	* Returns the size of the list
	*/
	virtual int size() = 0;

	/**
	* swap
	* Swaps the contents of the nodes at the specified indexes
	* Returns true if the swap was successful, false otherwise
	*/
	virtual bool swap(int index1, int index2) = 0;

	/**
	* shuffle
	* Randomly rearranges the nodes in the list
	* Use a random number generator as a part of your shuffling
	* Every node must be affected at least once in the shuffling
	*/
	virtual void shuffle() = 0;

	/**
	* isPalindrome
	* Returns true if the data in the nodes in the list make a palindrome, false otherwise
	* A palindrome exists when the list reads the same in both forward and reverse direction
	* i.e. h - a - n - n - a - h is a palindrome
	* 1 - 2 - 3 - 2 is not a palindrome
	*/
	virtual bool isPalindrome() = 0;

	/**
	* getKthFromLast
	* Returns the data in the node k positions from the rear of the list
	* Precondition: k is a valid location in the existing list
	* If k == 0, the data of the last node should be returned
	*/
	virtual T getKthFromRear(int k) = 0;

	/**
	* removeDuplicates
	* Removes nodes with duplicate data
	* i.e. before 0 - 1 - 5 - 1 - 3 - 5 - 4 - 5
	*	   after  0 - 1 - 5 - 3 - 4
	*
	* i.e. before 2 - 1 - 2
	*      after  2 - 1
	*/
	virtual void removeDuplicates() = 0;

	/**
	* reverse
	* Reverses the order of the nodes in the list
	* i.e. before a - b - c - d - e - f
	*      after  f - e - d - c - b - a
	*/
	virtual void reverse() = 0;

	/**
	* count
	* Returns the number of nodes in the list with the given data
	*/
	virtual int count(T data) = 0; // returns the number of nodes with data



	//Extra Credit
	
	/**
	* sort
	* Sorts the nodes in the list from lowest to highest
	****** Does nothing if the sort extra credit is not implemented
	*/
	virtual void sort() = 0;

	/**
	* JosephusSafe
	* Returns the safe index for the Josephus problem using a list of size n, and count m
	* Refer to the specifications for details on the Josephus problem
	***** Return -1 if this extra credit problem is not implemented
	*/
	virtual int JosephusSafe(int n, int m) = 0;
};
