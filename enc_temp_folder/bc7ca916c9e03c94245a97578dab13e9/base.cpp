#include <iostream>
#include <graphics.h>
#include <cmath>

#include "Draw_modified.h"
#include "input.h"
using namespace std;

int main() {
	initgraph(1001, 1001);
	ExMessage msg;
	setbkcolor(WHITE);
	setlinecolor(LIGHTGRAY);
	double x = 0, y = 0, s = 20, h = 200.01, cx = 500, cy = 500;
	cube a = cube(x, y, s);
	bool onoff = 1;
	BeginBatchDraw();
	while (onoff) {
		if (escape()) {
			onoff = 0;
		}
		s += wheel();
		if (zoomin()) {
			--h;
		}
		if (zoomout()) {
			++h;
		}
		a.set_s(s);
		if (left()) {
			--x;
			a.set_x(x);
		}
		if (right()) {
			++x;
			a.set_x(x);
		}
		if (up()) {
			--y;
			a.set_y(y);
		}
		if (down()) {
			++y;
			a.set_y(y);
		}
		if (leftt()) {
			--cx;
		}
		if (rightt()) {
			++cx;
		}
		if (upp()) {
			--cy;
		}
		if (downn()) {
			++cy;
		}
		cleardevice();
		a.draw_cube(h, cx, cy);
		setlinecolor(BLUE);
		settextcolor(BLUE);
		outtextxy(cx + 3, 10, 'V');
		center(cx, cy);
		setlinecolor(RED);
		settextcolor(RED);
		outtextxy(900, 1000 - cy, 'X');
		center(1000 - cx, 1000 - cy);
		FlushBatchDraw();
	}
	EndBatchDraw();
	return 0;
}