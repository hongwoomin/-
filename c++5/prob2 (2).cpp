#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <algorithm>
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
    Line(Point a, Point b) : s(a), t(b) {};
    bool is_vertical() {
        return s.y == t.y;
    }
};

class Rect{
private:
    Point* lu;
    Point* rl;
public:
    Rect() = default;
    Rect(Point a, Point b) : lu(new Point(a)), rl(new Point(b)) {}

    vector<Line> get_edges(){
        vector<Line> edges;
        edges.push_back(Line(*lu, Point(lu->x, rl->y)));
        edges.push_back(Line(*lu, Point(rl->x, lu->y)));
        edges.push_back(Line(Point(rl->x, lu->y), *rl));
        edges.push_back(Line(Point(lu->x, rl->y), *rl));
        return edges;
    }

    Point get_lu() { return *lu; }
    Point get_rl() { return *rl; }
};

class Circle {
private:
    Point* center;
    double radius;
public:
    Circle() = default;
    Circle(Point c, double r) : center(new Point(c)), radius(r) {}
    bool contains(Point p) {
        return center->distSq(p) <= radius * radius;
    }
    bool intersect(Line seg) {
        if (contains(seg.s) || contains(seg.t)) {
            return true;
        }
        if (seg.is_vertical()) {
            if (center->x > seg.s.x && center->x < seg.t.x && abs(seg.s.y - center->y) <= radius) {
                return true;
            }
        }
        else {
            if (center->y > seg.s.y && center->y < seg.t.y && abs(seg.s.x - center->x) <= radius) {
                return true;
            }
        }
        return false;
    }
    bool circle_dis(Point p, double r) {
        return center->distSq(p) <= pow(radius + r, 2);
    }
    Point get_center() { return *center; }
    double get_radius() { return radius; }
};

double get_area(vector<double> a) {
    if (a.size() == 3) {
        return a[2] * a[2] * 3.14;
    }
    else {
        return (a[1] - a[0]) * (a[3] - a[2]);
    }
}
vector<vector<double>> get_result(vector<vector<double>>& intersect_shape, Circle* main_circle) {
    vector<vector<double>> result;
    for (auto& shape : intersect_shape) {
        if (shape.size() == 4) {
            Rect* rect = new Rect(Point(shape[0], shape[2]), Point(shape[1], shape[3]));
            bool intersected = false;
            for (auto i : rect->get_edges()) {
                if (main_circle->intersect(i)) {
                    intersected = true;
                    break;
                }
            }
            if (intersected) {
                result.push_back(shape);
            }
        }
        else if (shape.size() == 3) {
            Circle* circle = new Circle(Point(shape[0], shape[1]), shape[2]);
            if (main_circle->circle_dis(circle->get_center(), circle->get_radius())) {
                result.push_back(shape);
            }
        }
    }
    return result;
}
void sort(vector<vector<double>>& result) {
    for (int i = result.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (get_area(result[j]) > get_area(result[j + 1])) {
                swap(result[j], result[j + 1]);
            }
        }
    }
}
void print_result(vector<vector<double>>& result) {
    for (auto& shape : result) {
        if (shape.size() == 4) {
            cout << "R " << shape[0] << " " << shape[1] << " " << shape[2] << " " << shape[3] << endl;
        }
        else if (shape.size() == 3) {
            cout << "C " << shape[0] << " " << shape[1] << " " << shape[2] << endl;
        }
    }
}
int main() {
    vector<vector<double>> intersect_shape;
    ifstream infile("input1.txt");
    int n;
    infile >> n;
    string shape;
    double x1, x2, y1, y2, r, x, y;

    for (int i = 0; i < n; i++) {
        infile >> shape;
        if (shape == "R") {
            infile >> x1 >> x2 >> y1 >> y2; 
            vector<double> a = { x1, x2, y1, y2 };
            intersect_shape.push_back(a);
        }
        else {
            infile >> x >> y >> r;
            vector<double> b = { x, y, r };
            intersect_shape.push_back(b);
        }
    }
    infile >> x1 >> y1 >> r;
    Circle* main_circle = new Circle(Point(x1, y1), r);

    vector<vector<double>> result = get_result(intersect_shape, main_circle);
    sort(result);
    print_result(result);
    return 0;
}

