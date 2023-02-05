#include "KeyMapClass.h"
#include  <time.h>
#include <Windows.h>
#include <iostream>
#include <map>
using namespace std;




	keymap::keymap() {
		rate = 0.05;
		random = 0;
		map["Up"] = false;
		map["Left"] = false;
		map["Right"] = false;
		map["Space"] = false;
	}
	void keymap::listen() {
		random = (double)rand() / (RAND_MAX);
			if (GetKeyState(VK_UP) & 0x8000) {
				map["Up"] = true;
			}
			else {
				map["Up"] = false;
			}

			if (GetKeyState(VK_LEFT) & 0x8000) {
				map["Left"] = true;
			}
			else {
				map["Left"] = false;
			}

			if (GetKeyState(VK_RIGHT) & 0x8000) {
				map["Right"] = true;
			}
			else {
				map["Right"] = false;
			}

			if (GetKeyState(VK_SPACE) & 0x8000) {
				map["Space"] = true;
			}
			else {
				map["Space"] = false;
			}
	}
	bool keymap::getUp() {
		return map["Up"];
	}
	bool keymap::getLeft() {
		return map["Left"];
	}
	bool keymap::getRight() {
		return map["Right"];
	}
	bool keymap::getSpace() {
		if (random <= rate) {
			return map["Space"];
		}
		return false;

	}
	void keymap::increaseRate(int score) {
		if (score % 1000 == 0 && score !=0) {
			rate += 0.001;
		}
	}
	
	




