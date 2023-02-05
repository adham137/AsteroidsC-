
#include  <time.h>
#include <Windows.h>
#include <iostream>
#include <map>
using namespace std;
class keymap {
private:
	map<string, bool> map;

public:
	keymap() {
		map["Up"] = false;
		map["Left"] = false;
		map["Right"] = false;
		map["Space"] = false;
	}
	void listen() {
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

		if (GetKeyState(VK_SPACE)) {
			map["Space"] = true;
		}
		else {
			map["Space"] = false;
		}
	}
	bool getUp() {
		return map["Up"];
	}
	bool getLeft() {
		return map["Left"];
	}
	bool getRight() {
		return map["Right"];
	}
	bool getSpace() {
		return map["Space"];
	}


};

int main() {
	keymap m;
	while (true) {
		m.listen();
		cout << m.getSpace();
	}
	return 0;
}

