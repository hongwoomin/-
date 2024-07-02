#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;
    Point() = default;
    Point(double a, double b) : x(a), y(b) {}
};
double dist(Point& a, Point& b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

class Circle {
public:
    Point center;
    double radius;
    Circle() = default;
    Circle(Point a, double r) : center(a), radius(r) {}
    bool is_inside(Point& p) // 점이 원안에 있는지 확인 
    {
        return dist(center, p) <= radius;
    }
    // 원이 주어진 점들을 포함하는지 확인
    bool is_valid_circle(vector<Point>& P)
    {
        for (Point& p : P)
            if (!is_inside(p))
                return false;
        return true;
    }
};



// 세 점을 지나는 원을 반환
Circle circle3point(Point& a, Point& b, Point& c)
{
    double ab = dist(a, b);
    double ac = dist(a, c);
    double bc = dist(b, c);
    Point center;
    if (ab >= ac && ab >= bc) {
        center.x = (a.x + b.x) / 2.0;
        center.y = (a.y + b.y) / 2.0;
    }
    else if (ac >= ab && ac >= bc) {
        center.x = (a.x + c.x) / 2.0;
        center.y = (a.y + c.y) / 2.0;
    }
    else {
        center.x = (b.x + c.x) / 2.0;
        center.y = (b.y + c.y) / 2.0;
    }

    return Circle(center, dist(center, a));
}
// 두 점을 지나는 원을 반환
Circle circle2point(Point& a, Point& b)
{
    Point center((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
    return Circle(center, dist(a, b) / 2.0);
}


Circle minimun_circle(vector<Point>& p)
{
    Circle min_circle(Point(0, 0), 100000000);

    // 점 두개 외접
    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size(); j++) {
            Circle tmp = circle2point(p[i], p[j]);
            if (tmp.radius < min_circle.radius && tmp.is_valid_circle(p))
                min_circle = tmp;
        }
    }
    //점 3개 외접
    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size(); j++) {
            for (int k = j + 1; k < p.size(); k++) {
                Circle tmp = circle3point(p[i], p[j], p[k]);
                if (tmp.radius < min_circle.radius && tmp.is_valid_circle(p))
                    min_circle = tmp;
            }
        }
    }
    return min_circle;
}

int main()
{
    ifstream infile("input2.txt");
    int N;
    infile >> N;
    vector<Point> points;

    for (int i = 0; i < N; i++) {
        double xmin, xmax, ymin, ymax;
        infile >> xmin >> xmax >> ymin >> ymax;
        points.push_back(Point(xmin, ymin));
        points.push_back(Point(xmin, ymax));
        points.push_back(Point(xmax, ymin));
        points.push_back(Point(xmax, ymax));
    }
    Circle result = minimun_circle(points);

    cout << "중심: " << result.center.x << ", " << result.center.y
        << " 반지름: " << result.radius << endl;

    return 0;
}



		
		
		
