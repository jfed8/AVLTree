/*
 * Node.h
 *
 *  Created on: Mar 31, 2016
 *      Author: jjfeddock
 */

#ifndef NODE_H_
#define NODE_H_

#include "NodeInterface.h"

class Node : public NodeInterface
{

public:
	Node(int info, Node* left, Node* right, Node* par);
	~Node() {}
	/*
	 * Returns the data stored in this node
	 *
	 * @return the data stored in this node.
	 */
	virtual int getData();

	/*
	 * Returns the left child of this node or null if empty left child.
	 *
	 * @return the left child of this node or null if empty left child.
	 */
	virtual NodeInterface * getLeftChild();

	/*
	 * Returns the right child of this node or null if empty right child.
	 *
	 * @return the right child of this node or null if empty right child.
	 */
	virtual NodeInterface * getRightChild();

	/*
	 * Returns the height of this node. The height is the number of nodes
	 * along the longest path from this node to a leaf.  While a conventional
	 * interface only gives information on the functionality of a class and does
	 * not comment on how a class should be implemented, this function has been
	 * provided to point you in the right direction for your solution.  For an
	 * example on height, see page 448 of the text book.
	 *
	 * @return the height of this tree with this node as the local root.
	 */
	virtual int getHeight();

	int data;
	Node* leftChild;
	Node* rightChild;
	int height;
        Node* parent;
};



#endif /* NODE_H_ */
