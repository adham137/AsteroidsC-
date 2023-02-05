#include <iostream>
#include <ostream>
#include <istream>
#include "linked_list.h"
using namespace std;

LinkedList::LinkedList() : first(0), mySize(0) {} // this initializes the Linked Lists and sets the first = nullptr		

LinkedList::LinkedList(const LinkedList& origList)
	: first(0), mySize(origList.mySize)
{

	if (mySize == 0) return;
	LinkedList::NodePointer origPtr, newPtr;	//origPtr is always one step ahead of newPtr
	this->first = new Node(origList.first->data);
	newPtr = this->first;
	origPtr = origList.first->next;
	while (origPtr != nullptr) {
		newPtr->next = new Node(origPtr->data);
		newPtr = newPtr->next;
		origPtr = origPtr->next;
	}
}

LinkedList::~LinkedList()		//destructor
{
	LinkedList::NodePointer prev = this->first, next;
	while (prev != nullptr)
	{
		next = prev->next;
		delete prev;
		prev = next;
	}
	this->first = nullptr;		// setting first to NULL and mySize to 0 after deleting all the nodes
	mySize = 0;
}

int LinkedList::getSize()
{
	return mySize;
}

LinkedList::NodePointer LinkedList::getFirst()
{
	return first;
}

bool LinkedList::isEmpty()		// this check to see if first == nullptr
{
	return first == NULL;
}


void LinkedList::erase(int index)	// erase the node at the given index

{
	if (index < 0 || index > mySize)
	{
		cerr << "******* Invalid index entered ******* " << index << endl;
		return;
	}

	mySize--;
	LinkedList::NodePointer nPtr, predPtr = this->first;
	if (index == 0)
	{
		nPtr = this->first;
		this->first = nPtr->next;
		delete nPtr;
	}
	else
	{
		for (int i = 1; i < index; i++)
		{
			predPtr = predPtr->next;
		}
		nPtr = predPtr->next;
		if (nPtr == 0) return;
		predPtr->next = nPtr->next;
		delete nPtr;
	}
}



void LinkedList::insert(X dataVal, int index)

{
	if (index < 0 || index > mySize)
	{
		cerr << "******* Invalid index entered ******* " << index << endl;
		return;
	}

	mySize++;
	LinkedList::NodePointer newPtr = new Node(dataVal), predPtr = this->first;

	if (index == 0)
	{
		newPtr->next = this->first;
		this->first = newPtr;
	}
	else
	{
		for (int i = 1; i < index; i++)
		{
			predPtr = predPtr->next;
		}
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}
}											// inserting in any given index

void LinkedList::push_back(X dataVal)			// inserts element at last position of the list
{
	NodePointer tempPtr = first, lastPtr;
	lastPtr = tempPtr;
	while (tempPtr != 0)
	{
		lastPtr = tempPtr;
		tempPtr = tempPtr->next;
	}
	if (isEmpty())
	{
		first = new Node(dataVal);
		lastPtr = first;
		mySize++;
		return;
	}
	else
	{
		NodePointer nPtr = new Node(dataVal);
		lastPtr->next = nPtr;
		mySize++;
	}

}

const LinkedList& LinkedList :: operator = (const LinkedList& rightSide)
{
	this->mySize = rightSide.mySize;

	if (this->mySize == 0)
	{
		this->~LinkedList();
		return *this;
	}

	if (this != &rightSide)
	{
		this->~LinkedList();	// this deletes the old lists totally
		LinkedList::NodePointer lhsPtr, rhsPtr;
		this->first = new Node(rightSide.first->data);
		lhsPtr = this->first;
		rhsPtr = rightSide.first->next;

		while (rhsPtr != nullptr)
		{
			lhsPtr->next = new Node(rhsPtr->data);
			lhsPtr = lhsPtr->next;
			rhsPtr = rhsPtr->next;
		}
	}
	return *this;
}		// overriding the = operator


bool LinkedList:: operator > (const LinkedList& rightSide) // overloading the > (greater than operator)
{
	return this->mySize > rightSide.mySize;
}





