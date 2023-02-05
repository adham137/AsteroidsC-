/*-- BinarySearchTree.h -------------------------------------------------------------

 This header file defines a BinarySearchTree data type.
 Basic operations:
 Constructor:     Constructs an empty BST
 insert:          Modifies a BST by adding a value at the appropriate place
 erase:           Modifies a BST by removing the value 
 display:		  Display values of BST using different ways : "in-order" or "pre-order" or "post-order"
 getmax:		  get maximum item of BST
 ---------------------------------------------------------------------------*/

#pragma once
#include<string>
using namespace std;


//implementation of a BST class 
class BinarySearchTree {
private:
	class Node {
	public:
		// ******** NODE DATA MEMBERS **********

		long data; //data part of the node
		Node* right; //ptr to the node to the right
		Node* left; //ptr to the node to the left
		Node(long value) {
			data = value;
			right = left = 0;
		}
	};

	// ******** BinarySearchTree DATA MEMBERS **********

	Node* root; //pointer to the root node
public:
	BinarySearchTree(); 
	/*-----------------------------------------------------------------------
	 Construct a BinarySearchTree object.

	 Precondition:  None.
	 Postcondition: An empty BinarySearchTree object has been constructed.
	 root node is value is set to zero
	 -----------------------------------------------------------------------*/

	BinarySearchTree(long value); 
	/*-----------------------------------------------------------------------
	 Construct a BinarySearchTree object.

	 Precondition:  None.
	 Postcondition: An empty BinarySearchTree object has been constructed.
	 root node is value is set to value
	 -----------------------------------------------------------------------*/

	void insert(long item); 
	/*-----------------------------------------------------------------------
	 insert into a BinarySearchTree object.

	 Precondition:  check whether BST is empty.
	 Postcondition: Node object of given value is inserted into BST at 
					appropriate place.
	 -----------------------------------------------------------------------*/

	long getMax(); 
	/*-----------------------------------------------------------------------
	 get maximum value at a BinarySearchTree object.

	 Precondition:  none.
	 Postcondition: maximum value of BinarySearchTree object is returned.
	 -----------------------------------------------------------------------*/

	void display(string order = "in order"); 
	/*-----------------------------------------------------------------------
	 display values of a BinarySearchTree object.

	 Precondition:  none.
	 Postcondition: display all values according to desired order.
	 -----------------------------------------------------------------------*/

	void erase(long item); 
	/*-----------------------------------------------------------------------
	 erase from a BinarySearchTree object.

	 Precondition:  BinarySearchTree object is not empty.
	 Postcondition: Node object containing item is removed from BinarySearchTree object.
	 -----------------------------------------------------------------------*/

private:

	void display1(Node* ptr);
	/*-----------------------------------------------------------------------
	 display values of a BinarySearchTree object in-order (LNR).
	 -----------------------------------------------------------------------*/
	
	void display2(Node* ptr);
	/*-----------------------------------------------------------------------
	 display values of a BinarySearchTree object pre-order (NLR).
	 -----------------------------------------------------------------------*/

	void display3(Node* ptr);
	/*-----------------------------------------------------------------------
	 display values of a BinarySearchTree object post-order (LRN).
	 -----------------------------------------------------------------------*/
};
