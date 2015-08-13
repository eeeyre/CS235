//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once

#include <iostream>
#include "AVLInterface.h"
#include "NodeInterface.h"
#include "Nodes.h"
#include <string>

using namespace std;

class AVL:public AVLInterface {
private:
		Node* rootNode=NULL;
	bool rec_add(int data, Node* node_ptr);
	void checkbalance(Node* node_ptr);
	void balance(Node* unbal_node, string direction);
	int set_heights(Node* node_ptr);
	bool rec_remove(int value, Node* node_ptr);
public:
~AVL();

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	 * Returns the root node for this tree
	 *
	 * @return the root node for this tree.
	 */
	NodeInterface * getRootNode();

	/*
	 * Attempts to add the given int to the AVL tree
	 * Rebalances the tree if data is successfully added
	 *
	 * @return true if added
	 * @return false if unsuccessful (i.e. the int is already in tree)
	 */
	bool add(int data);

	/*
	 * Attempts to remove the given int from the AVL tree
	 * Rebalances the tree if data is successfully removed
	 *
	 * @return true if successfully removed
	 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
	 */
	bool remove(int data);

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
};
