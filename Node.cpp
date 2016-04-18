/*
 * Node.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: jjfeddock
 */

#include "Node.h"

#include <iostream>

Node::Node(int info, Node* left, Node* right, Node* par)
{
	data = info;
	leftChild = left;
	rightChild = right;
    height = 1;
    parent = par;
}

int Node::getData()
{
	return data;
}

NodeInterface * Node::getLeftChild()
{
	return leftChild;
}

NodeInterface * Node::getRightChild()
{
	return rightChild;
}

int Node::getHeight()
{
    int answer = 1;

    if (getLeftChild() != NULL || getRightChild() != NULL)
    {
       if (getRightChild() == NULL)
       {
           answer = getLeftChild()->getHeight() + 1;
       }
       else if (getLeftChild() == NULL)
       {
           answer = getRightChild()->getHeight() + 1;
       }
       else
       {
           answer = max(getLeftChild()->getHeight(), getRightChild()->getHeight()) + 1;
       }
    }

    return answer;
}

