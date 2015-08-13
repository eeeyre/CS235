#pragma once
#include "LinkedListInterface.h"

class LinkedList : public LinkedListInterface
{
private:
	struct Node
		{
			int data;
			Node* next;
		
			Node(const int& data_item, Node* next_ptr = NULL) : 
				data(data_item), next(next_ptr) {}
				
		};
		Node* head=NULL;

public:
	LinkedList(void){};
	~LinkedList(void);

	void insertHead(int value);

	void insertTail(int value);

	void insertAfter(int value, int insertionNode);

	void remove(int value);

	void clear();

	int at(int index);

	int size();
	
};
