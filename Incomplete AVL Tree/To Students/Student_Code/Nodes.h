#pragma once

#include "NodeInterface.h"

class Node : public NodeInterface
{
	private:
		int node_data;
		int height=1;
		Node* left=NULL;
		Node* right=NULL;
		Node* parent=NULL;
		


	public:
		Node(int data, Node* left_ptr=NULL, Node* right_ptr=NULL, Node* parent_ptr=NULL)
		{
			node_data=data;
			left=left_ptr;
			right=right_ptr;
			parent=parent_ptr;
		}
		
		int getHeight();
		int getData();
		Node * getLeftChild();
		Node * getRightChild();
		Node * getParent();
		void setleft(Node* pointer);
		void setparent(Node* pointer);
		void setright(Node* pointer);
		void setdata(int data);
		void setheight(int newheight);
};