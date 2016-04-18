/*
 * NodeInterface.h
 *
 *  Created on: Mar 31, 2016
 *      Author: jjfeddock
 */

#pragma once
#include<string>

using namespace std;

class NodeInterface {

public:
	NodeInterface() {}
	virtual ~NodeInterface() {}

	/*
	 * Returns the data stored in this node
	 *
	 * @return the data stored in this node.
	 */
	virtual int getData() = 0;

	/*
	 * Returns the left child of this node or null if empty left child.
	 *
	 * @return the left child of this node or null if empty left child.
	 */
	virtual NodeInterface * getLeftChild() = 0;

	/*
	 * Returns the right child of this node or null if empty right child.
	 *
	 * @return the right child of this node or null if empty right child.
	 */
	virtual NodeInterface * getRightChild() = 0;

	/*
	 * Returns the height of this node.
	 *
	 * @return the height of this tree with this node as the local root.
	 */
	virtual int getHeight() = 0;
};
