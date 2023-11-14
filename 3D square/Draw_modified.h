#ifndef Draw_modified
#define Draw_modified

#include <iostream>
#include <graphics.h>
using namespace std;

struct coordinate {
	int x, y;
};

inline void square(double x, double y, double s) {
	line(x, y, x, y + s);
	line(x, y, x + s, y);
	line(x, y + s, x + s, y + s);
	line(x + s, y, x + s, y + s);
}

inline void center(int x, int y) {
	line(x, 0, x, 1000);
	line(0, y, 1000, y);
}

class cube{
	private:
		double x, y, s;
	public:
		inline cube(double, double, double);
		inline void set_x(double);
		inline void set_y(double);
		inline void set_s(double);
		inline double get_x();
		inline double get_y();
		inline double get_s();
		inline void draw_cube(double, double, double);
};

inline cube::cube(double _x, double _y, double _s) {
	x = _x;
	y = _y;
	s = _s;
}

inline void cube::set_x(double _x) {
	x = _x;
}

inline void cube::set_y(double _y) {
	y = _y;
}

inline void cube::set_s(double _s) {
	s = _s;
}

inline double cube::get_x() {
	return x;
}

inline double cube::get_y() {
	return y;
}

inline double cube::get_s() {
	return s;
}

inline void cube::draw_cube(double h, double cx, double cy) {
	//base
	setlinecolor(BLACK);
	double nx = x + 1000 - cx, ny = y + 1000 - cy;
	square(nx, ny, s);
	if (h != s) {
		double ratio = (h + s) / (h - s);
		double tx = (nx - cx) * ratio + cx;
		double ty = (ny - cy) * ratio + cy;
		double ts = fabs(((nx - cx + s) * ratio + cx) - tx);
		setlinecolor(LIGHTGRAY);
		square(tx, ty, ts);
		setlinecolor(DARKGRAY);
		line(nx, ny, tx, ty);
		line(nx + s, ny, tx + ts, ty);
		line(nx, ny + s, tx, ty + ts);
		line(nx + s, ny + s, tx + ts, ty + ts);
	}
}

#endif