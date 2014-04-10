/*

Definitions:
1. A tree consists of a fin8ite set of elements called nodes or vertices
and finite set of directed area that connect pairs of nodes.

2.  If a tree is nonempth, then one of the nodes, called the root, has no incoming arcs,
but every other node in the tree can  be reached from it by follwing a unique path,
which is a sequence of consecutive arcs.

3.  Nodes that are directly accessible from a given node (by using only one directed arc) are
called the children ofthat node, and a node is said to be the parent of its children.

a. leaves are nodes without children. (left and right child pointers are null)

b.  parent is a node with at most children

c.  sibling of a node has the same parent

d. descendants of node can be reached by follwoing a path from it; this node is also
the ancestor of the nodes on that path

e. subtree is a tree. For each node in a tree, a subtree of that node is formed by
selecting one of its children and all descendants of that child.

f. decision trees, expert system see pgs 654-655

Array Implementation

Complete Binary Tree -a tree in which each level of the tree is completely filled, except possibly the
bottom level, but there the node are in the leftmost positions.

The height of a tree is the longest path from the root.
How do you determine the height of a tree?  Count the number of edges (arcs) in the longest path.


Balanced Tree
A balance binary tree is a tree in which the height of its left subtree and the height of its
right subtree differ by at most 1.



Linked Representation of Binary Trees



Binary Trees as Recursive Data Structures
Why?
A binary tree either is empty (represents the base or anchor case)
or consists of a node called a root which has pointers to two disjoint
binary subtrees called the left substree and right subtree (represent inductive step)
(see pgs 660-661)


Traversals

Example of a simple recursive scheme to traverse a binary tree is as follows:

1.  Visit the root and process its contents
2.  Traverse the left subtree
3.  Traverse the right subtree

Inorder (LVR), Preorder (VLR), Postorder (LRV)   -- see pg 664

Expression tree - binary tree used to represent the arithmetic expression

see examples on pgs 665-666

Binary Serach Trees (BST)
Def - A BST is a binary tree that satisfies the BST property which is for each node x, values in the left substree of x
are less than x and the values in the right subtree of x are greater than x.  note :
x is the root of the tree.

BST ADT

Data:
A binary tree that satisfies the BST property:  For each node x,
values in left subtree of x< value in x < values in right subtree of x.

Operations:
*Construct an empty BST
*Determine if the BST is empty
*Search the BST for a given item
*Insert a new item in the BST and maintain the BST property
*Delete an item from the BST and maintain the BST property
*Traverse the BST visiting each node expactly one.
at least one of the traversals (inorder traversal) must visit the values in
nodes in ascending order
*Print the BST in preorder, inorder or postorder
*Find the inorder successor
*Find the inorder predecessor
*destructor

Implementing the BST

1. Define a BST node
2. Define the BST class
3. Implement the Default constructor
4. Implement Is_Empty
5. Implement Insert
5. Implement Search
6. Implement Print_Inorder
7. Implement Inorder_Successor
8. Implement Remove
9. Implement destructor



*/

#include "BST.h"

btree::~btree()
{
	cout << "Destructor has been called\n";
	Delete_Tree(root);
}

void btree::Delete_Tree(bnode *& loc_ptr)
{
	if (loc_ptr != 0)
	{
		Delete_Tree(loc_ptr->lchild);
		Delete_Tree(loc_ptr->rchild);
		delete loc_ptr;
	}
}

bnode * btree::Search(const string & key)
{
	return Aux_Search(root, key);
}

bnode * btree::Aux_Search(bnode *& loc_ptr, const string & key)
{
	if (loc_ptr == 0)
	{
		return 0;
	}
	else if (key < loc_ptr->name)
	{
		return Aux_Search(loc_ptr->lchild, key);
	}
	else if (key > loc_ptr->name)
	{
		return Aux_Search(loc_ptr->rchild, key);
	}
	else
	{
		return loc_ptr;
	}
}


inline bool btree::Is_Empty()
{
	return root == 0;
}

void btree::Insert()
{
	
}

void btree::Aux_Insert()
{

}

void btree::Print(bnode * loc_ptr)
{
	if (loc_ptr != 0)
	{
		Print(loc_ptr->lchild);
		cout << loc_ptr->name << endl;
		Print(loc_ptr->rchild);
	}
}

void btree::Print() //inorder
{
	Print(root);
}




bnode *  btree::Inorder_Successor(bnode * loc_ptr)
{
	bnode *succ = 0;

	if (loc_ptr == 0)
	{
		return succ;
	}
	else
	{
		succ = loc_ptr->rchild;
		loc_ptr = loc_ptr->rchild;
		while (loc_ptr != 0)
		{
			succ = loc_ptr;
			loc_ptr = loc_ptr->lchild;
		}
		return succ;
	}


}


void btree::Remove(const string & item)
{
	Remove(root, item);
}

void btree::Remove(bnode * & loc_ptr, const string & item)
{

	if (loc_ptr == 0)
		cout << "item not in tree\n";

	else if (loc_ptr->name > item)
		Remove(loc_ptr->lchild, item);

	else if (loc_ptr->name < item)
		Remove(loc_ptr->rchild, item);

	else
	{
		bnode * ptr;

		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = Inorder_Successor(loc_ptr);
			loc_ptr->name = ptr->name;
			Remove(loc_ptr->rchild, ptr->name);
		}
	}

}





