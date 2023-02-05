#pragma once
#include  <time.h>
#include <Windows.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;
class keymap {
private:
	// ******** BinarySearchTree DATA MEMBERS **********

	map<string, bool> map;

	double random;

	double rate; //rate of which the bullets is shot with , initialized to 5%
public:
	keymap(); //initialize the map contiaing the keyboard keys as keys and whether it's pressed or not as values

	void listen(); //called within the application , if a key is pressed it updates its value

	bool getUp(); //get value of up key

	bool getLeft(); //get value of left key

	bool getRight(); //get value of right key

	bool getSpace(); //get value of space key
	
	void increaseRate(int score); //increase rate if score increases to a specific value


};
