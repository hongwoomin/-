#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class Point {
public:
	double x, y;
	Point() = default;
	Point(double a, double b) : x(a), y(b) {}
	double distSq(Point p) {
		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
	}
};

class Line {
public:
	Point s, t;
	Line() = default;
	Line(Point a, Point b) : s(a), t(b);
	bool is_vertical() {
		return s.y == t.y;
	}
};

class Rect {
private:
	Point lu, rl;
	Rect() = default;
	Rect(Point a, Point b) : lu(a), rl(b) {}
	vector<Line> get_edges() {
		//vector<Line> 에 사각형의 변들을 저장하기
		vector<Line> edges;
		edges.push_back(Line(lu, Point(lu.x, rl.y)));
		edges.push_back(Line(lu, Point(rl.x, lu.y)));
		edges.push_back(Line(Point(rl.x, lu.y), rl));
		edges.push_back(Line(Point(lu.x, rl.y), rl));
		return edges;
	}

};
class Circle {
private:
	Point center;
	double radius;
	Circle() = default;
	Circle(Point c, double r) : center(c), radius(r) {}
	bool contains(Point p) {
		return center.distSq(p) <= radius * radius;
	}
	bool intersect(Line seg) {
		if (contains(seg.s) || contains(seg.t))
			return true;
		if (seg.is_vertical()) {
   				return true;
			}
		}
		else {
			if (center.y > seg.s.y && center.y < seg.t.y && abs(seg.s.x - center.x) <= radius) {
				return true;
			}
		}

	};
	// 사각형의 네변을 선분으로 만들어서 교차하는지 검사하기
int main() {
	vector<vector<int>
	vector<Rect> rects;
	vector<Circle> circles;
	// main_circle과 교차하는 사각형들을 저장할 벡터
	vector<Rect> intersec_rec
	ifstream infile("input1.txt");
	int n;
	infile >> n;
	string shape;
	double x1, x2, y1, y2, r,x,y;
	for (int i = 0; i < n; i++) {
		infile >> shape;
		if (shape == "R") {
			infile >> x1 >> x2 >> y1 >> y2;
			rects.push_back(Rect(Point(x1,y1),Point(x2,y2)));
		}
		else {
			infile >> x >> y >> r;
			circles.push_back(Circle(Point(x, y), r));
		}
	}
	infile >> x1 >> y1 >> r;
	Circle main_circle(Point(x1, y1), r);
