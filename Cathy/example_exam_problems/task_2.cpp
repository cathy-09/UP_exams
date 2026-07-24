#include <iostream>
using namespace std;
struct Point
{
    double x;
    double y;
};
struct Segment
{
    Point p1;
    Point p2;
};
double segmentIntersectionLength(Segment s1, Segment s2);
double myMin(double a, double b);
double myMax(double a, double b);


int main()
{
    Segment s1 = { {0, 2}, {10, 2} };
    Segment s2 = { {4, 2}, {12, 2} };
    cout << "Length: " << segmentIntersectionLength(s1, s2) << " (Expected: 6)" << endl << endl;
}

double myMin(double a, double b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}
double myMax(double a, double b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

double segmentIntersectionLength(Segment s1, Segment s2)
{
    bool s1_horizontal = (s1.p1.y == s1.p2.y);
    bool s1_vertical = (s1.p1.x == s1.p2.x);
    bool s2_horizontal = (s2.p1.y == s2.p2.y);
    bool s2_vertical = (s2.p1.x == s2.p2.x);
    if ((!s1_horizontal && !s1_vertical) || (!s2_horizontal && !s2_vertical))
    {
        return -1.0;
    }
    if (s1_horizontal && s2_horizontal && s1.p1.y == s2.p1.y)
    {
        double minA = myMin(s1.p1.x, s1.p2.x);
        double maxA = myMax(s1.p1.x, s1.p2.x);
        double minB = myMin(s2.p1.x, s2.p2.x);
        double maxB = myMax(s2.p1.x, s2.p2.x);
        double overlapStart = myMax(minA, minB);
        double overlapEnd = myMin(maxA, maxB);
        if (overlapStart < overlapEnd)
        {
            return overlapEnd - overlapStart;
        }
        return 0.0;
    }
    if (s1_vertical && s2_vertical && s1.p1.x == s2.p1.x)
    {
        double minA = myMin(s1.p1.y, s1.p2.y);
        double maxA = myMax(s1.p1.y, s1.p2.y);
        double minB = myMin(s2.p1.y, s2.p2.y);
        double maxB = myMax(s2.p1.y, s2.p2.y);
        double overlapStart = myMax(minA, minB);
        double overlapEnd = myMin(maxA, maxB);
        if (overlapStart < overlapEnd)
        {
            return overlapEnd - overlapStart;
        }
        return 0.0;
    }
    return -1.0;
}
