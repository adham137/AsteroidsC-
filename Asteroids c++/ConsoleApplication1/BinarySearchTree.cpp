#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

	
	BinarySearchTree::BinarySearchTree() {
		root = nullptr;
	}

	BinarySearchTree::BinarySearchTree(long value) {
		root = new Node(value);
	}

	void BinarySearchTree::insert(long item) {
		if (root == nullptr) {
			root = new Node(item);
			return;
		}

		Node* ptr = root;
		Node* pred = 0;
		while (ptr) {
			pred = ptr;

			if (item == ptr->data) {
				return;
			}
			if (item > ptr->data) {
				ptr = ptr->right;
				continue;
			}
			if (item < ptr->data) {
				ptr = ptr->left;
				continue;
			}
		}
		ptr = new Node(item);
		if (pred->data < item) {
			pred->right = ptr;
			return;
		}
		else {
			pred->left = ptr;
		}
	}

	long BinarySearchTree::getMax() {
		Node* ptr = root;
		while (ptr->right) {
			ptr = ptr->right;
		}
		return ptr->data;
	}

	void BinarySearchTree::display(string order) {
		if(order == "in order") display1(root);
		else if (order == "pre order") display2(root);
		else if (order == "post order") display3(root);
		
	}

	void BinarySearchTree::erase(long item) {
		Node* ptr = root;
		Node* parent = 0;
		bool found = false;

		//searching for intended node
		while (ptr) {
			
			if (ptr->data == item) {
				found = true;
				break;
			}
			if (ptr->data > item) {
				parent = ptr;
				ptr = ptr->left;
				continue;
			}
			if (ptr->data < item) {
				parent = ptr;
				ptr = ptr->right;
				continue;
			}
		}
		if (!found) {
			cerr << "item not found"<<endl;
			return;
		}
		
		//2 children
		if ((ptr->left) && (ptr->right)) {
			//getting right leftmost
			Node* rightleftmost = ptr->right;
			while ((rightleftmost->left) != 0) {
				parent = rightleftmost;
				rightleftmost = rightleftmost->left;
			}
			ptr->data = rightleftmost->data;
			ptr = rightleftmost;
		}
		
		
		// 0 or 1 children
		Node* subtree = ptr->left;
		if (subtree == 0) {
			subtree = ptr->right;
		}
		if (parent == 0) {
			root = subtree;
			return;
		}
		if (parent->left == ptr) {
			parent->left = subtree;
			return;
		}
		if (parent->right == ptr) {
			parent->right = subtree;
			return;
		}
	}

	//displaying inorder (LNR)
	void BinarySearchTree::display1(Node* ptr) {

		if (ptr == 0) return;
		display1(ptr->left);
		cout << ptr->data<<" ";
		display1(ptr->right);
	}

	//displaying pre-order (NLR)
	void BinarySearchTree::display2(Node* ptr) {

		if (ptr == 0) return;
		cout << ptr->data << " ";
		display2(ptr->left);
		display2(ptr->right);
	}

	//displaying post-order (LRN)
	void BinarySearchTree::display3(Node* ptr) {

		if (ptr == 0) return;
		display3(ptr->left);
		display3(ptr->right);
		cout << ptr->data << " ";
	}



