#include "BST.h"
#include "Nodes.h"
#include <iostream>
using namespace std;


NodeInterface * BST::getRootNode()
	{
		return rootNode;
	}

/*
 * ---------------------------------------------------------------------
 */

bool BST::rec_add(int data, Node* node_ptr)
	{
		if (data==node_ptr->getData()){
					return false;
				}
		if(data>node_ptr->getData()) {
				if (node_ptr->getRightChild()==NULL)
				{

					Node* node_ptr_new=new Node(data,NULL,NULL,node_ptr);
					node_ptr->setright(node_ptr_new);
					return true;
				}
				if(rec_add(data, node_ptr->getRightChild()))
					return true;
				else
					return false;
		} else if (data<node_ptr->getData())
			{
				if (node_ptr->getLeftChild()==NULL)
				{
					Node* node_ptr_new=new Node(data,NULL,NULL,node_ptr);
					node_ptr->setleft(node_ptr_new);
					return true;
				}
				if(rec_add(data, node_ptr->getLeftChild()))
					return true;
				else
					return false;
			} 

	}


 /*
 * ---------------------------------------------------------------------
 */
bool BST::rec_remove(int data, Node* node_ptr)
 {
 	if (data==node_ptr->getData())
 	{
 		if (node_ptr==rootNode)
 		{
 			//1 leaf
 				if (node_ptr->getLeftChild()==NULL && node_ptr->getRightChild()==NULL)
 				{
 					delete node_ptr;
 					rootNode=NULL;
 					return true;
 				}
 			//2 no left-side
 				if (node_ptr->getLeftChild()==NULL)
 				{
 					rootNode=rootNode->getRightChild();
 					rootNode->setparent(NULL);
 					delete node_ptr;
 					return true;
 				}

 			//3 left with no rights
 				Node* node_ptr_new=node_ptr->getLeftChild();
 				if (node_ptr_new->getRightChild()==NULL)
 				{
 					node_ptr_new->setright(node_ptr->getRightChild());
 					node_ptr_new->setparent(NULL);
 					rootNode=node_ptr_new;
 					delete node_ptr;
 					return true;
 				}

 			//4 left all right with left leaf
 				else
 				{
 					while (node_ptr_new->getRightChild()!=NULL)
 						node_ptr_new=node_ptr_new->getRightChild();
 				}
 				if (node_ptr_new->getLeftChild()!=NULL)
 				{
 					node_ptr_new->getLeftChild()->setparent(node_ptr_new->getParent());
 					node_ptr_new->getParent()->setright(node_ptr_new->getLeftChild());
 					node_ptr->setdata(node_ptr_new->getData());
 					delete node_ptr_new;
 					return true;
 				}
 			//5 normal left all right
 				else
 				{
 					if (node_ptr_new->getData()<node_ptr_new->getParent()->getData())
 					{
 						node_ptr_new->getParent()->setleft(NULL);
 						node_ptr->setdata(node_ptr_new->getData());
 						delete node_ptr_new;
 						return true;
 					}
 					else
 					{
 						node_ptr_new->getParent()->setright(NULL);
 						node_ptr->setdata(node_ptr_new->getData());
 						delete node_ptr_new;
 						return true;
 					}
 					
 				}

 		}
 		else
 		{
 			//1 leaf
 				if (node_ptr->getLeftChild()==NULL && node_ptr->getRightChild()==NULL)
 				{
 					if (node_ptr->getData()<node_ptr->getParent()->getData())
 					{
 						node_ptr->getParent()->setleft(NULL);
 						delete node_ptr;
 						return true;
 					}
 					else
 					{
 						node_ptr->getParent()->setright(NULL);
 						delete node_ptr;
 						return true;
 					}
 				}
 			//2 no left-side
 				if (node_ptr->getLeftChild()==NULL)
 				{
 					if (node_ptr->getData()<node_ptr->getParent()->getData())
 					{
 						node_ptr->getParent()->setleft(node_ptr->getRightChild());
 						node_ptr->getRightChild()->setparent(node_ptr->getParent());
 						delete node_ptr;
 						return true;
 					}
 					else
 					{
 						node_ptr->getParent()->setright(node_ptr->getRightChild());
 						node_ptr->getRightChild()->setparent(node_ptr->getParent());
 						delete node_ptr;
 						return true;
 					}
 				}

 			//3 left with no rights
 				Node* node_ptr_new=node_ptr->getLeftChild();
 				if (node_ptr_new->getRightChild()==NULL)
 				{
 					node_ptr->setleft(node_ptr_new->getLeftChild());
 					node_ptr->setdata(node_ptr_new->getData());
 					if (node_ptr_new->getLeftChild()!=NULL)
 					node_ptr_new->getLeftChild()->setparent(node_ptr);
 					delete node_ptr_new;
 					return true;
 				}

 			//4 left all right with left leaf
 				else
 				{
 					while (node_ptr_new->getRightChild()!=NULL)
 						node_ptr_new=node_ptr_new->getRightChild();
 				}
 				if (node_ptr_new->getLeftChild()!=NULL)
 				{

 				}
 			//5 normal left all right
 				else
 				{
 					if (node_ptr_new->getData()<node_ptr_new->getParent()->getData())
 					{
 						node_ptr_new->getParent()->setleft(NULL);
 						node_ptr->setdata(node_ptr_new->getData());
 						delete node_ptr_new;
 						return true;
 					}
 					else
 					{
 						node_ptr_new->getParent()->setright(NULL);
 						node_ptr->setdata(node_ptr_new->getData());
 						delete node_ptr_new;
 						return true;
 					}
 					
 				}

 		}
 	}
 	else if (data<node_ptr->getData())
 	{
 		if (node_ptr->getLeftChild()!=NULL)
 		{
 			if (rec_remove(data,node_ptr->getLeftChild()))
 			return true;
 			else
 				return false;
 		}
 		else return false;
 	}
 	else 
 	{
 		if (node_ptr->getRightChild()!=NULL)
 		{
 			if (rec_remove(data,node_ptr->getRightChild()))
 			return true;
 			else 
 				return false;
 		}
 		else return false;
 	}
 		
 }

 /*
 * ---------------------------------------------------------------------
 */
	bool BST::add(int data)
	{
		Node* node_ptr=rootNode;
		if (rootNode==NULL)
		{
			rootNode=new Node(data,NULL,NULL,NULL);
			return true;
		}
		else
		{
			return rec_add(data,node_ptr);
		}
	}

/*
 *-----------------------------------------------------------------------
 */

bool BST::rec_clear(Node* node_ptr)
{

	if (node_ptr->getLeftChild()!=NULL)
	{
		rec_clear(node_ptr->getLeftChild());
		node_ptr->setleft(NULL);
	}
	if (node_ptr->getRightChild()!=NULL)
	{  
		rec_clear(node_ptr->getRightChild());
		node_ptr->setright(NULL);
	}
	if (node_ptr->getLeftChild()==NULL && node_ptr->getRightChild()==NULL)
	{
		delete node_ptr;
	}
	return true;
}

 /*
 *-----------------------------------------------------------------------
 */
	bool BST::remove(int data)
	{
		Node* node_ptr=rootNode;
		if (rootNode==NULL)
		{
			return false;
		}
		else
		{
			//cout<<"RUNNING REMOVE FUNCTION--Removing"<<data<<"."<<endl<<endl;
			return rec_remove(data, node_ptr);
		}
	}
/*
 * ----------------------------------------------------------------------
 */
	void BST::clear()
	{
		if (rootNode==NULL)
			return;
		if (rootNode->getLeftChild()==NULL&&rootNode->getRightChild()==NULL)
			{
				delete rootNode;
				rootNode=NULL;
			}
		else {
			rec_clear(rootNode);
			rootNode=NULL;
		}
	}