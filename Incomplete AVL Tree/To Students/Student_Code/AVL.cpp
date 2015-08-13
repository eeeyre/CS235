#include "AVL.h"
#include "Nodes.h"
#include <iostream>

AVL::~AVL()
{
	while (rootNode!=NULL)
	{
		remove(rootNode->getData());
	}
}
//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
 NodeInterface * AVL::getRootNode()
 {
 	return rootNode;
 }

/*
 * Attempts to add the given int to the AVL tree
 * Rebalances the tree if data is successfully added
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
 bool AVL::add(int data)
 {
	////cout<<"Data: "<<data<<endl;
 	bool returnvalue;
 	Node* node_ptr=rootNode;
 	if (rootNode==NULL)
 	{
 		rootNode=new Node(data,NULL,NULL,NULL);
 		set_heights(rootNode);
 		checkbalance(rootNode);
 		return true;
 	}
 	else
 	{
 		returnvalue= rec_add(data,node_ptr);
 		set_heights(rootNode);
 		checkbalance(rootNode);
 		return returnvalue;
 	}
 } 

/*
 * Attempts to remove the given int from the AVL tree
 * Rebalances the tree if data is successfully removed
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
 bool AVL::remove(int data)
 {
	////cout<<"Remove Value: "<<data<<endl;
 	bool returnvalue;
 	Node* node_ptr=rootNode;
 	if (rootNode==NULL)
 	{
 		return false;
 	}
 	else
 	{
 		cout<<"RUNNING REMOVE FUNCTION--Removing"<<data<<"."<<endl<<endl;
 		returnvalue=rec_remove(data, node_ptr);
		////////cout<<"remove setheight function reached\n";

 		set_heights(rootNode);
		////////cout<<"remove checkbalance function reached\n";


 		checkbalance(rootNode);

 		return returnvalue;

 	}
 }

/*
 * ROTATIONS:
 * 			LEFT
 *
 * 				IDENTIFY NODES TO ROTATE
 *
 * 				ROT.RIGHT=CUR.LEFT
 * 				CUR.LEFT=ROT
 * 				CUR=ROT
 *
 *
 *
 *
 * 			RIGHT
 *
 *
 *
 */
 bool AVL::rec_add(int data, Node* node_ptr)
 {
	////////cout<<"rec_add : "<<data<<endl;

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
 		else{

 			return false;}
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
 			else{

 				return false;}
 			} 

 		}


/*
* ---------------------------------------------------------------------
*/
bool AVL::rec_remove(int data, Node* node_ptr)
{
	 	//////////cout<<"node parent = "<<node_ptr->getParent()<<endl;

 	////////cout<<"rec_remove : "<<node_ptr->getData()<<endl;
	if (data==node_ptr->getData())
	{
		Node* node_ptr_new=node_ptr->getLeftChild();
		if (node_ptr==rootNode)//-----------------------------------------------------------------------------------------------------
		{
 			//////////cout<<"removing rootNode\n";

 			//1 leaf
			if (node_ptr->getLeftChild()==NULL && node_ptr->getRightChild()==NULL)
			{
 					////////cout<<"caseleaf:root--->start------>";
				delete node_ptr;
				node_ptr=NULL;
 					//////////cout<<"finished\n";
				rootNode=NULL;
				return true;
			}
 			//2 no left-side
			else if (node_ptr->getLeftChild()==NULL)
			{
				rootNode=rootNode->getRightChild();
				rootNode->setparent(NULL);
 					////////cout<<"case no left side:root--->start------>";
				delete node_ptr;
				node_ptr=NULL;
 					//////////cout<<"finished\n";
				return true;
			}

 			//3 left with no rights

			else if (node_ptr_new->getRightChild()==NULL)
			{
				node_ptr_new->setright(node_ptr->getRightChild());
				node_ptr_new->setparent(NULL);
				rootNode=node_ptr_new;
				node_ptr->getRightChild()->setparent(rootNode);
 					////////cout<<"case left no right :root--->start------>";
				delete node_ptr;
				node_ptr=NULL;
 					//////////cout<<"finished\n";
				return true;
			}

 			//4 left all right with left leaf
			else
			{
				while (node_ptr_new->getRightChild()!=NULL)
					node_ptr_new=node_ptr_new->getRightChild();

				if (node_ptr_new->getLeftChild()!=NULL)
				{
					node_ptr_new->getLeftChild()->setparent(node_ptr_new->getParent());
					node_ptr_new->getParent()->setright(node_ptr_new->getLeftChild());
					node_ptr->setdata(node_ptr_new->getData());
	 					////////cout<<"caseleft all right:root--->start------>";
					delete node_ptr_new;
					node_ptr_new=NULL;
	 					//////////cout<<"finished\n";
					return true;
				}
	 			//5 normal left all right
				else
				{
					if (node_ptr_new->getData()<node_ptr_new->getParent()->getData())
					{
						node_ptr_new->getParent()->setleft(NULL);
						node_ptr->setdata(node_ptr_new->getData());
	 					////////cout<<"case normal:root--->start------>";
						delete node_ptr_new;
						node_ptr_new=NULL;
	 					//////////cout<<"finished\n";
						return true;
					}
					else
					{
						node_ptr_new->getParent()->setright(NULL);
						node_ptr->setdata(node_ptr_new->getData());
	 					////////cout<<"case normal2:root--->start------>";
						delete node_ptr_new;
						node_ptr_new=NULL;
	 					//////////cout<<"finished\n";
						return true;
					}

				}
			}

		}
		else//---------------------------------------------------------------------------------------------------------------------
		{
 			//1 leaf
			if (node_ptr->getLeftChild()==NULL && node_ptr->getRightChild()==NULL)
			{
				if (node_ptr->getData()<node_ptr->getParent()->getData())
				{
					node_ptr->getParent()->setleft(NULL);
 						cout<<"case leaf:nonroot----------->start---------->";
					delete node_ptr;
					node_ptr=NULL;
 						//cout<<"finished\n";
					return true;
				}
				else
				{
					node_ptr->getParent()->setright(NULL);
 						cout<<"case leaf 2:nonroot----------->start---------->";
					delete node_ptr;
					node_ptr=NULL;
 						//cout<<"finished\n";
					return true;
				}
			}
 			//2 no left-side
			else if (node_ptr->getLeftChild()==NULL)
			{
				if (node_ptr->getData()<node_ptr->getParent()->getData())
				{
					node_ptr->getParent()->setleft(node_ptr->getRightChild());
					node_ptr->getRightChild()->setparent(node_ptr->getParent());
 						cout<<"case no left:nonroot----------->start---------->";
					delete node_ptr;
					node_ptr=NULL;
 						//////////cout<<"finished\n";
					return true;
				}
				else
				{
					node_ptr->getParent()->setright(node_ptr->getRightChild());
					node_ptr->getRightChild()->setparent(node_ptr->getParent());
 						cout<<"case no left 2:nonroot----------->start---------->";
					delete node_ptr;
					node_ptr=NULL;
 						//////////cout<<"finished\n";
					return true;
				}
			}

 			//3 left with no rights

			else if (node_ptr_new->getRightChild()==NULL)
			{
				node_ptr->setleft(node_ptr_new->getLeftChild());
				node_ptr->setdata(node_ptr_new->getData());
				if (node_ptr_new->getLeftChild()!=NULL)
					node_ptr_new->getLeftChild()->setparent(node_ptr);
 					cout<<"case left no right:nonroot----------->start---------->";
				delete node_ptr_new;
				node_ptr_new=NULL;
 				//cout<<"finished\n";
				return true;
			}

 			//4 left all right with left leaf
			else
			{
				cout<<endl<<"case nonroot: left-right"<<endl;
				while (node_ptr_new->getRightChild()!=NULL){
					node_ptr_new=node_ptr_new->getRightChild();
				}
				node_ptr_new->getParent()->setright(node_ptr_new->getLeftChild());
				if (node_ptr_new->getLeftChild()!=NULL)
					node_ptr_new->getLeftChild()->setparent(node_ptr_new->getParent());
				node_ptr_new->setparent(node_ptr->getParent());
				if (node_ptr->getParent()->getData()>node_ptr_new->getData())
					node_ptr->getParent()->setleft(node_ptr_new);
				else
					node_ptr->getParent()->setright(node_ptr_new);
				node_ptr_new->setright(node_ptr->getRightChild());
				if (node_ptr_new->getRightChild()!=NULL)
					node_ptr_new->getRightChild()->setparent(node_ptr_new);
				node_ptr->getLeftChild()->setparent(node_ptr_new);
				node_ptr_new->setleft(node_ptr->getLeftChild());
				delete node_ptr;
				return true;

				
			}
		}
	}
	else if (data<node_ptr->getData())
	{
 		//////////cout<<"testing where the program fails\n";
		if (node_ptr->getLeftChild()!=NULL)
		{
 			if (rec_remove(data,node_ptr->getLeftChild())){ //////////cout<<"return true\n";
 			return true;}
 			else
 				return false;
 		}
 		else return false;
 	}
 	else 
 	{
 		if (node_ptr->getRightChild()!=NULL)
 		{
 			if (rec_remove(data,node_ptr->getRightChild())){ //////////cout<<"return true\n";
 			return true;}
 			else 
 				return false;
 		}
 		else return false;
 	}
 }
 int AVL::set_heights(Node* node_ptr)
 {
 	int node_left=0;
 	int node_right=0;
 	if (node_ptr==NULL)
 		return 0;
 	else{
 		if (node_ptr->getLeftChild()==NULL)
 		{
 			node_left=0;
 		} else {
 			set_heights(node_ptr->getLeftChild());
 			node_left=node_ptr->getLeftChild()->getHeight();
 		}
 		if (node_ptr->getRightChild()==NULL)
 		{
 			node_right=0;
 		} else {
 			set_heights(node_ptr->getRightChild());
 			node_right=node_ptr->getRightChild()->getHeight();
 		}
 		if (node_left<node_right)
 		{
 			node_ptr->setheight(node_right+1);
		////cout<<"data="<<node_ptr->getData()<<" | height="<<node_ptr->getHeight()<<endl;

 		} else 
 		{
 			node_ptr->setheight(node_left+1);
		////cout<<"data="<<node_ptr->getData()<<" | height="<<node_ptr->getHeight()<<endl;

 		}
 	}	
 }
 
 void AVL::checkbalance(Node* node_ptr)
 {
 	if (node_ptr==NULL)
 		return;
 	int left=0;
 	int right=0;
 	if (node_ptr->getLeftChild()!=NULL)
 	{
 		checkbalance(node_ptr->getLeftChild());
 	} 
 	if (node_ptr->getRightChild()!=NULL)
 	{
 		checkbalance(node_ptr->getRightChild());
 	}
//////cout<<node_ptr->getData()<<" | "<<node_ptr->getHeight()<<endl;
 	int leftleft=0;
 	int leftright=0;
 	int rightright=0;
 	int rightleft=0;
 	string direction="";
 	if (node_ptr->getLeftChild()!=NULL)
 	{
 		left=node_ptr->getLeftChild()->getHeight();
 		if (node_ptr->getLeftChild()!=NULL&&node_ptr->getLeftChild()->getLeftChild()!=NULL)
 		{
 			leftleft=node_ptr->getLeftChild()->getLeftChild()->getHeight();
 		}
 		if (node_ptr->getLeftChild()!=NULL&&node_ptr->getLeftChild()->getRightChild()!=NULL)
 		{

 			leftright=node_ptr->getLeftChild()->getRightChild()->getHeight();
 		}
 	}
 	if (node_ptr->getRightChild()!=NULL)
 	{
 		right=node_ptr->getRightChild()->getHeight();
 		if (node_ptr->getRightChild()!=NULL&&node_ptr->getRightChild()->getRightChild()!=NULL)
 		{
 			rightright=node_ptr->getRightChild()->getRightChild()->getHeight();
 		}
 		if (node_ptr->getRightChild()!=NULL&&node_ptr->getRightChild()->getLeftChild()!=NULL)
 		{
 			rightleft=node_ptr->getRightChild()->getLeftChild()->getHeight();
 		}
 	}
 	if (right-left==2&&rightright<rightleft)
 		direction="rightleft";
 	if (right-left==-2&&leftright>leftleft)
 		direction="leftright";
 	if (right-left==-2&&leftright<=leftleft)
 		direction="leftleft";
 	if (right-left==2&&rightright>=rightleft)
 		direction="rightright";

 	if (direction!="")
 	{
	////cout<<"leftHeight: "<<left<<" | rightHeight: "<<right<<endl;
 		balance(node_ptr,direction);
	////cout<<"Balanced successfully\n";
 		set_heights(rootNode);
 	}

 }
 void AVL::balance(Node* unbal_node, string direction)
 {

	cout<<unbal_node->getData()<<" | "<<direction<<endl;
	//checkbalance(unbal_node);
 	if (direction=="rightright")
 	{

 		if (unbal_node->getRightChild()!=NULL&&unbal_node->getRightChild()->getRightChild()!=NULL)
 		{
		//right right case
		////////cout<<"right right case\n\n";
 			Node* a = unbal_node;
 			Node* b = unbal_node->getRightChild();
 			Node* c = unbal_node->getRightChild()->getRightChild();
 			b->setparent(a->getParent());
 			if (a->getParent()!=NULL)
 			{
 				if (a->getParent()->getData()<a->getData())
 					a->getParent()->setright(b);
 				else 
 					a->getParent()->setleft(b);
 			}
 			else rootNode=b;
 			a->setright(b->getLeftChild());
 			if (b->getLeftChild()!=NULL)
 				b->getLeftChild()->setparent(a);
 			b->setleft(a);
 			b->setright(c);
 			a->setparent(b);
		c->setparent(b);//*/


 		}
 	}
 	else if(direction=="rightleft")
 	{
 		if (unbal_node->getRightChild()!=NULL&&unbal_node->getRightChild()->getLeftChild()!=NULL)
 		{
		//right left case
		//cout<<"right left case\n";
 			Node* a = unbal_node;
 			Node* b = unbal_node->getRightChild();
 			Node* c = unbal_node->getRightChild()->getLeftChild();
 			c->setparent(a->getParent());
 			if (a->getParent()!=NULL){
 				if (a->getParent()->getData()<a->getData())
 					a->getParent()->setright(c);
 				else 
 					a->getParent()->setleft(c);}
 				else rootNode=c;
 				a->setright(c->getLeftChild());
 				if (c->getRightChild()!=NULL)
 					c->getRightChild()->setparent(a);
 				b->setleft(c->getRightChild());
 				if (b->getLeftChild()!=NULL)
 					b->getLeftChild()->setparent(b);

 				c->setright(b);
 				c->setleft(a);
 				a->setparent(c);
 				b->setparent(c);


	}//

} else if (direction=="leftleft")
{
	
	if (unbal_node->getLeftChild()!=NULL&&unbal_node->getLeftChild()->getLeftChild()!=NULL)
	{
		//left left case
		////cout<<"left left case";
		Node* a = unbal_node;
		Node* b = unbal_node->getLeftChild();
		Node* c = unbal_node->getLeftChild()->getLeftChild();
		b->setparent(a->getParent());
		if (a->getParent()!=NULL)
		{
			if (a->getParent()->getData()<a->getData())
				a->getParent()->setright(b);
			else 
				a->getParent()->setleft(b);
		} 
		else rootNode=b;
		a->setleft(b->getRightChild());
		if (b->getRightChild()!=NULL)
			b->getRightChild()->setparent(a);
		b->setleft(c);
		b->setright(a);
		a->setparent(b);
		c->setparent(b);

	}
}
else if (direction=="leftright"){	
	if (unbal_node->getLeftChild()!=NULL&&unbal_node->getLeftChild()->getRightChild()!=NULL)
	{
		//left right case
		//cout<<"left right case | "<<unbal_node->getData()<<endl;
		Node* a = unbal_node;
		Node* b = unbal_node->getLeftChild();
		Node* c = unbal_node->getLeftChild()->getRightChild();

		c->setparent(a->getParent());
		if (a->getParent()!=NULL){
			if (a->getParent()->getData()<a->getData())
				a->getParent()->setright(c);
			else 
				a->getParent()->setleft(c);}
			else rootNode=c;
			b->setparent(c);
			a->setparent(c);

			b->setright(c->getLeftChild());
			if (b->getRightChild()!=NULL)
				b->getRightChild()->setparent(b);
			a->setleft(c->getRightChild());
			if (a->getLeftChild()!=NULL)
				a->getLeftChild()->setparent(a);
			c->setleft(b);
			c->setright(a);

		//*/
		}
	}

//set_heights(rootNode);


}