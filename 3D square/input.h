#ifndef input
#define input

#include <iostream>
#include <graphics.h>
using namespace std;

inline bool escape() {
	return GetAsyncKeyState(VK_ESCAPE);
}

inline bool space() {
	return GetAsyncKeyState(VK_SPACE);
}

inline bool zoomin() {
	return GetAsyncKeyState(VK_ADD);
}

inline bool zoomout() {
	return GetAsyncKeyState(VK_SUBTRACT);
}

inline bool up() {
	return GetAsyncKeyState(VK_UP);
}

inline bool down() {
	return GetAsyncKeyState(VK_DOWN);
}

inline bool left() {
	return GetAsyncKeyState(VK_LEFT);
}

inline bool right() {
	return GetAsyncKeyState(VK_RIGHT);
}

inline bool upp() {
	return GetAsyncKeyState(VK_NUMPAD8);
}

inline bool downn() {
	return GetAsyncKeyState(VK_NUMPAD2);
}

inline bool leftt() {
	return GetAsyncKeyState(VK_NUMPAD4);
}

inline bool rightt() {
	return GetAsyncKeyState(VK_NUMPAD6);
}

inline int wheel() {
	ExMessage msg;
	if (peekmessage(&msg) && msg.message == WM_MOUSEWHEEL) {
		return msg.wheel / 120;
	}
	return 0;
}

#endif