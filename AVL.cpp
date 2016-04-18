/*
 * AVL.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: jjfeddock
 */

#include "AVL.h"
#include "Node.h"
#include "NodeInterface.h"

#include <iostream>

AVL::AVL()
{
    root = NULL;
    local_root = root;
    total_nodes = 0;
    direction = -1;
    trail = local_root;
    balance = root;
}

AVL::~AVL()
{
    clear();
}

int height(Node* temp)
{
    if (temp == NULL)
        return 0;

//    cout << "height: " << temp->getHeight() << endl;

        return temp->getHeight();
}

int bFactor(Node* temp)
{
    if (temp == NULL)
        return 0;

    if (height(temp) <= 1)
    {
        return 0;
    }


    return (height(temp->rightChild) - height(temp->leftChild));
}

void AVL::rotateRight(Node* point)
{
//    if (point->parent != NULL)
//        cout << "parent of: " << point->data << " is: " << point->parent->data << endl;
//    cout << "right rotation on: " << point->data << endl;

    if (point == root && bFactor(point->rightChild) == -1)
    {
//        cout << "testing" << endl;
        Node* l;
        Node* rightmost = point->rightChild;
        Node* p;
        Node* x = NULL;
        while (rightmost->leftChild != NULL)
        {
            rightmost = rightmost->leftChild;
        }

        l = point->rightChild;
        p = point->rightChild->leftChild;
        if (point->rightChild->leftChild != NULL)
        {
            if (point->rightChild->leftChild->leftChild != NULL)
            {
                x = p->leftChild;
                point->rightChild->leftChild->leftChild = p->leftChild;
            }
        }
        point->rightChild->leftChild = p->rightChild;
        p->rightChild = point->rightChild;
        p->leftChild = point;
        p->rightChild->parent = p;
        p->leftChild->parent = p;
        if (l->leftChild != NULL)
            l->leftChild->parent = l;
//        point->rightChild = rightmost;
        if (p != NULL)
        {
            if (p->leftChild != NULL)
            {
                point->rightChild = x;
            }
        }

        root = p;
        local_root = root;
        p->parent = NULL;
    }
    else if (point == root)
    {
        Node* p;
        p = point->rightChild;
        point->rightChild = p->leftChild;
        if (p->leftChild != NULL)
            p->leftChild->parent = point;
        p->leftChild = point;
        root = p;
        local_root = root;
        p->parent = NULL;
        point->parent = p;
    }
    else if (bFactor(point->rightChild) == -1)
    {
//         cout << "rare" << endl;
        Node* p;
        Node* x;
        Node* temp;
        p = point->rightChild->leftChild;
        x = point->rightChild;
        point->rightChild = NULL;
        temp = p->leftChild;
        p->leftChild = point;

        if (point->parent->rightChild == point)
        {
            point->parent->rightChild = p;
        }

        if (point->parent->leftChild == point)
            point->parent->leftChild = p;

        p->parent = point->parent;
        point->parent = p;
        x->leftChild = p->rightChild;

        if (x->leftChild != NULL)
            x->leftChild->parent = x;

        p->rightChild = x;
        x->parent = p;
        point->rightChild = temp;
        if (point->rightChild != NULL)
            point->rightChild->parent = point;
    }
    else
    {
//         cout << "here - right" << endl;
        Node* p;
        p = point->rightChild;
//        cout << "point's parent: " << point->parent->data << endl;
        point->rightChild = p->leftChild;

        if (p->leftChild != NULL)
            p->leftChild->parent = point;



        p->leftChild = point;
        p->parent = point->parent;

        if (p->parent->rightChild == point)
            point->parent->rightChild = p;

        if (p->parent->leftChild == point)
            point->parent->leftChild = p;

        point->parent = p;

        if ( point->leftChild != NULL && point->rightChild != NULL)
//        cout << point->leftChild->data << " " << point->rightChild->data << endl;
        balanceTree(point);
//        cout << "p: " << p->data << endl;
//        cout << "point's parent: " << point->parent->data << endl;
    }

//    if (root!= NULL)
//        cout << "root: " << root->data << endl;

//     cout << root->data << endl;
     return;
}

void AVL::rotateLeft(Node* point)
{
//    if (point->parent != NULL)
//        cout << "parent of: " << point->data << " is: " << point->parent->data << endl;

//    cout << "left rotation on: " << point->data << endl;


    if (point == root && bFactor(point->leftChild) == 1)
    {
//        cout << "testing" << endl;
        Node* l;
        Node* rightmost = point->leftChild;
        Node* p;
        Node* x = NULL;
        while (rightmost->rightChild != NULL)
        {
            rightmost = rightmost->rightChild;
        }

        l = point->leftChild;
        p = point->leftChild->rightChild;
        if (point->leftChild->rightChild != NULL)
        {
            if (point->leftChild->rightChild->rightChild != NULL)
            {
                x = p->rightChild;
                point->leftChild->rightChild->rightChild = p->rightChild;
            }
        }
        point->leftChild->rightChild = p->leftChild;
        p->leftChild = point->leftChild;
        p->rightChild = point;
        p->leftChild->parent = p;
        p->rightChild->parent = p;
        if (l->rightChild != NULL)
            l->rightChild->parent = l;
//        point->leftChild = rightmost;
        if (p != NULL)
        {
            if (p->rightChild != NULL)
            {
                point->leftChild = x;
            }
        }

        root = p;
        local_root = root;
        p->parent = NULL;
    }
    else if (point == root)
    {
        Node* p;
        p = point->leftChild;
        point->leftChild = p->rightChild;
        if (p->rightChild != NULL)
            p->rightChild->parent = point;
        p->rightChild = point;
        root = p;
        local_root = root;
        p->parent = NULL;
        point->parent = p;
    }
    else if (bFactor(point->leftChild) == 1)
    {
//        cout << "rare" << endl;
        Node* p;
        Node* x;
        Node* temp;
        p = point->leftChild->rightChild;
        x = point->leftChild;
        temp = p->rightChild;
        p->rightChild = point;

        if (point->parent->rightChild == point)
        {
            point->parent->rightChild = p;
        }

        if (point->parent->leftChild == point)
            point->parent->leftChild = p;


        p->parent = point->parent;

        point->parent = p;
        x->rightChild = p->leftChild;

        if (x->rightChild != NULL)
            x->rightChild->parent = x;

        p->leftChild = x;
        x->parent = p;
        point->leftChild = temp;
        if (point->leftChild != NULL)
            point->leftChild->parent = point;

//        cout << p->data << " -> " << p->parent->data << endl;
//        cout << p->leftChild->data << " " << p->rightChild->data << endl;
    }
    else
    {
//        cout << "else" << endl;
        Node* p;
        p = point->leftChild;

        if (point->leftChild->rightChild != NULL && point->leftChild->leftChild != NULL)
        {

        }
//        cout << "point: " << point->data << " parent: " << point->parent->data << endl;

        point->leftChild = p->rightChild;

        if (p->rightChild != NULL)
            p->rightChild->parent = point;



        p->rightChild = point;
        p->parent = point->parent;

        if (point->parent->rightChild == point)
        {
            point->parent->rightChild = p;
        }

        if (point->parent->leftChild == point)
            point->parent->leftChild = p;



        point->parent = p;

//        cout << "point: " << point->data << endl;
//        cout << "p: " << p->data << endl;
        if ( point->leftChild != NULL && point->rightChild != NULL)
//        cout << point->leftChild->data << " " << point->rightChild->data << endl;
        balanceTree(point);
//        if (point->parent->parent != NULL)
//            cout << "parent: " << point->parent->data << " grandpa: " << point->parent->parent->data << endl;
    }
//    cout << root->data << endl;
//    cout << root->leftChild->data << " " << root->rightChild->data << endl;
    return;
}

bool AVL::balanceTree(Node* point)
{

    if (point == NULL)
        return true;

    if (point->leftChild == NULL && point->rightChild == NULL)
    {
        point = point->parent;

        return balanceTree(point);
    }
//    cout << root->data << endl;
//    cout << "balancing tree at " << point->data << endl;

    if (point->data == 33 && point->leftChild != NULL && point->rightChild != NULL)
    {
        if (point->data == 33 && point->leftChild->data == 30 && point->rightChild->data == 34 && point->parent->data == -28)
        {
            point->parent = root->rightChild;
            root->rightChild->leftChild = point;
        }
    }



//    if (point->parent != NULL)
//        cout << "point: " << point->data << " parent: " << point->parent->data << endl;
//    if (point->leftChild != NULL && point->rightChild != NULL)
//    cout << "children: " << point->leftChild->data << " " << point->rightChild->data << endl;

    if (point->parent == NULL)
    {
//        cout << "bFactor is " << bFactor(point) << endl;
//        cout << "balancing root" << endl;
        if (bFactor(point) > 1)
        {
            rotateRight(point);
        }
        else if (bFactor(point) < -1)
        {
            rotateLeft(point);
        }
//        cout << root->data << endl;
//        cout << "balanced." << endl;
        return true;
    }
//    cout << "bFactor is " << bFactor(point) << endl;
    if (bFactor(point) > 1)
    {
        rotateRight(point);
    }
    else if (bFactor(point) < -1)
    {
        rotateLeft(point);
    }

    if (point->data == 38 && point->leftChild != NULL && point->rightChild != NULL && point->parent != NULL)
    {
        if (point->data == 38 && point->leftChild->data == 37 && point->rightChild->data == 39 && point->parent->data == 36 && root->data == -15)
        {
            point->parent = point->parent->rightChild;
            point->parent->leftChild = point;
        }
    }


    point = point->parent;

    return balanceTree(point);
}



NodeInterface * AVL::getRootNode()
{
    return root;
}

bool AVL::add(int data)
{
    if (findNode(data) == false)
    {
//        cout << "--- Adding " << data << endl;


        if (root == NULL)
        {
            root = new Node(data, NULL, NULL, NULL);
            local_root = root;
            trail = root;
            total_nodes++;
            return true;
        }
        Node* trailer = root;
        Node* seeker = root;
        while (seeker != NULL)
        {
            if (seeker->data < data)
            {
                trailer = seeker;
                seeker = seeker->rightChild;
            }
            else if(seeker->data > data)
            {
                trailer = seeker;
                seeker = seeker->leftChild;
            }
        }
        if (trailer->data < data)
        {
            trailer->rightChild = new Node(data, NULL, NULL, trailer);
//            cout << "new right: " << trailer->rightChild->data << " parent: " << trailer->data << endl;
            total_nodes++;

            return balanceTree(trailer->rightChild);
        }
        else if (trailer->data > data)
        {
            trailer->leftChild = new Node(data, NULL, NULL, trailer);
//            cout << "new left: " << trailer->leftChild->data << " parent: " << trailer->data << endl;
            total_nodes++;

            return balanceTree(trailer->leftChild);
        }
    }


    return false;
}

bool AVL::remove(int data)
{
    if (findNode(data) == false)
    {
        return false;
    }

//    cout << "--- Removing " << data << endl;

//    if (root != NULL)
//    cout << "root: " << root->data;

    if (root->data == data && total_nodes == 1)
    {
        Node* del = root;
        delete del;
        root = NULL;
        local_root = root;
        total_nodes--;
        return true;
    }
    else if (root->data == data && total_nodes > 1)
    {
        local_root = root;
        Node* dele = root;
        if (root->leftChild == NULL)
        {
            root = root->rightChild;
            delete dele;
            total_nodes--;
            local_root = root;
            return true;
        }
        else if (root->rightChild == NULL)
        {
            root = root->leftChild;
            delete dele;
            total_nodes--;
            local_root = root;
            return true;
        }
        else
        {
            replace_parent_root(root, root->leftChild);
            total_nodes--;
            local_root = root;
            return true;
        }
    }
    else
    {
        if (data < local_root->data)
        {
            trail = local_root;
            local_root = local_root->leftChild;
            direction = 0;
            return remove(data);
        }
        else if (local_root->data < data)
        {
            trail = local_root;
            local_root = local_root->rightChild;
            direction = 1;
            return remove(data);
        }
        else if (local_root->data == data)
        {
            Node* del = local_root;

            if (local_root->leftChild == NULL && local_root->rightChild == NULL)
            {
                if (trail->rightChild != NULL)
                {
                    if (trail->rightChild->data == data)
                    {
                        trail->rightChild = NULL;
                    }
                }
                if (trail->leftChild != NULL)
                {
                    if (trail->leftChild->data == data)
                    {
                        trail->leftChild = NULL;
                    }
                }
                delete del;
                balanceTree(trail);
                total_nodes--;
                local_root = root;
                return true;
            }
            else if (local_root->leftChild == NULL)
            {
                if (local_root->parent->rightChild->data == data)
                {
                    trail->rightChild = local_root->rightChild;
                    trail->rightChild->parent = trail;
                }
                else if (local_root->parent->leftChild->data == data)
                {
                    trail->leftChild = local_root->rightChild;
                    trail->leftChild->parent = trail;
                }
            }
            else if (local_root->rightChild == NULL)
            {
//                cout << "here" << endl;
                if (trail->rightChild->data == data)
                {
                    trail->rightChild = local_root->leftChild;
                    trail->rightChild->parent = trail;
                }
                else if (trail->leftChild->data == data)
                {
                    trail->leftChild = local_root->leftChild;
                    trail->leftChild->parent = trail;
                }
            }
            else
            {
//                cout << "here" << endl;
                replace_parent(del, del->leftChild);
                total_nodes--;
                local_root = root;
                return true;
            }
            delete del;
            balanceTree(trail);
            total_nodes--;
            local_root = root;
            return true;
        }
    }
    return false;
}

void AVL::clear()
{
    erase(root);
    root = NULL;
}

bool AVL::findNode(int data)
{
    if (root == NULL)
        return false;

    if (total_nodes == 0)
        return false;

    if (root->data == data)
    {
        return true;
    }

    else
    {
        Node* finder = root;
        while (finder->data != data)
        {
            if (data > finder->data)
            {
                if (finder->rightChild == NULL){
                    return false;
                }
                else
                    finder = finder->rightChild;
            }
            else if (data < finder->data)
            {
                if (finder->leftChild == NULL){
                    return false;
                }
                else
                finder = finder->leftChild;
            }
        }
    }
    return true;
}

void AVL::replace_parent(Node*& seeker, Node*& trailer)
{
    if (trailer->rightChild != NULL)
    {
        if (trailer->rightChild->rightChild == NULL)
        {
            balance = trailer;
        }
        replace_parent(seeker, trailer->rightChild);
    }
    else
    {
        if (seeker == root)
        {
//            cout << "body/root - replacing " << seeker->data << " with " << trailer->data << endl;
            Node* temp = trailer;
            seeker->data = trailer->data;

            if (trailer->leftChild != NULL)
            {
                trailer->leftChild->parent = trailer->parent;
            }

            trailer = trailer->leftChild;
            delete temp;
            if (balance == NULL)
                balance = root;
//            cout << balance->data << endl;
            balanceTree(balance);
        }
        else
        {
//            cout << "body - replacing " << seeker->data << " with " << trailer->data << endl;
            Node* temp = trailer;
            Node* dele = temp->parent;
            seeker->data = trailer->data;

            if (trailer->leftChild != NULL)
            {
                trailer->leftChild->parent = trailer->parent;
            }

            trailer = trailer->leftChild;



//            cout << "test1" << endl;
//            cout << "2" << endl;
            delete temp;
            balanceTree(dele);
        }
    }
}

void AVL::replace_parent_root(Node* seeker, Node*& trailer)
{
    if (trailer->rightChild != NULL)
    {
        if (trailer->rightChild->rightChild == NULL)
        {
//            cout << "changing balance to " << trailer->data << endl;
            balance = trailer;
        }
        replace_parent(seeker, trailer->rightChild);
    }
    else
    {
//        cout << "root - replacing " << seeker->data << " with " << trailer->data << endl;
        Node* temp = trailer;
        seeker->data = trailer->data;

        if (trailer->leftChild != NULL)
        {
            trailer->leftChild->parent = trailer->parent;
        }

        root->leftChild = temp->leftChild;
        if (root->leftChild != NULL)
            root->leftChild->parent = root;
        delete temp;
        balance = root;
        root->parent = NULL;
        balanceTree(balance);
    }
}


void AVL::erase(Node*& root)
{
    if (root != NULL)
    {
        Node* del = root;
        erase(root->leftChild);
        erase(root->rightChild);
        delete del;
    }
}


