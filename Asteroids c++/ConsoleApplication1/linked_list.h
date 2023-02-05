#pragma once
#include <stdio.h>
#include <ostream>
#include <istream>
#include <iostream>
#include "sSpaceObject.h"

using namespace std;
typedef sSpaceObject X;


class LinkedList {

private:
	class Node {
	public:
		// ******** NODE DATA MEMBERS **********
		X data;	// data part of the node
		Node* next;			// node ptr that points to the next node
		Node() : data(), next(0) {}
		Node(X dataValue) : data(dataValue), next(0) {}
		X& getData() {
			return data;
		}
		Node* getNext() {
			return next;
		}
	};
public:
	typedef Node* NodePointer;
	// ******* LINKED LIST DATA MEMBERS **********
private:
	NodePointer first;		// this is the first ptr that points to the first node
	int mySize;				// mySize = size of the list
public:
	LinkedList();		// this initializes the Linked Lists and sets the first = nullptr

	LinkedList(const LinkedList& origList);	// copy constructor

	~LinkedList();		//destructor

	bool isEmpty();		// this check to see if first == nullptr

	void erase(int index); // erase the node at the given index


	void insert(X dataVal, int index); // inserting in any given index

	void push_back(X dataVal); // inserts element at last position of the list

	const LinkedList& operator = (const LinkedList& rightSide); // overriding the = operator

	bool operator > (const LinkedList& rightSide); // overloading the > (greater than operator)
	int getSize();
	NodePointer getFirst();
};


