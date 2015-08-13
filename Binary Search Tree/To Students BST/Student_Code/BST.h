#pragma once

#include "BSTInterface.h"
#include "Nodes.h"

using namespace std;

class BST : public BSTInterface {
private:
	Node* rootNode=NULL;
	bool rec_add(int data, Node* node_ptr);

	bool rec_remove(int data, Node* node_ptr);

	bool rec_clear(Node* node_ptr);
	
public:
	BST() {}
	virtual ~BST() {clear();}



	/*
	 * ---------------------------------------------------------------------
	 */
	NodeInterface * getRootNode();


	/*
	 * ---------------------------------------------------------------------
	 */
	bool add(int data);

	/*
	 *-----------------------------------------------------------------------
	 */
	bool remove(int data);
	/*
	 * ----------------------------------------------------------------------
	 */
	void clear();
};
