#include "Nodes.h"

int Node::getData()
{
	return node_data;
}
//----------------------------------------------------------------------------------------------------------------------------
//  
//----------------------------------------------------------------------------------------------------------------------------
Node * Node::getLeftChild()
{
	return left;
}
//----------------------------------------------------------------------------------------------------------------------------
//  
//----------------------------------------------------------------------------------------------------------------------------
Node * Node::getRightChild()
{
	return right;
}
//----------------------------------------------------------------------------------------------------------------------------
//  
//----------------------------------------------------------------------------------------------------------------------------
Node * Node::getParent()
{
	return parent;
}
void Node::setleft(Node* pointer)
{
	left=pointer;
}
void Node::setparent(Node* pointer)
{
	parent=pointer;
}
void Node::setright(Node* pointer)
{
	right=pointer;
}
void Node::setdata(int data)
{
	node_data=data;
}
