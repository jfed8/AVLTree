/*
 * AVL.h
 *
 *  Created on: Mar 31, 2016
 *      Author: jjfeddock
 */

#ifndef AVL_H_
#define AVL_H_

#include "NodeInterface.h"
#include "AVLInterface.h"
#include "Node.h"

class AVL : public AVLInterface
{
public:
	AVL();
	~AVL();
	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	 * Returns the root node for this tree
	 *
	 * @return the root node for this tree.
	 */
	virtual NodeInterface * getRootNode();

	/*
	 * Attempts to add the given int to the AVL tree
	 * Rebalances the tree if data is successfully added
	 *
	 * @return true if added
	 * @return false if unsuccessful (i.e. the int is already in tree)
	 */
	virtual bool add(int data);

	/*
	 * Attempts to remove the given int from the AVL tree
	 * Rebalances the tree if data is successfully removed
	 *
	 * @return true if successfully removed
	 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
	 */
	virtual bool remove(int data);
	bool balanceTree(Node* point);
	bool findNode(int data);
	void replace_parent(Node*& seeker, Node*& trailer);
        void clear();
	void replace_parent_root(Node* seeker, Node*& trailer);
        void erase(Node*& root);
        void rotateRight(Node* point);
        void rotateLeft(Node * point);

private:
	Node* root;
	int total_nodes;
	Node* local_root;
        int direction;
        Node* trail;
        Node* balance;
};



#endif /* AVL_H_ */
