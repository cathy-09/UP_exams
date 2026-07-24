#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

int CheckQ(Point p);

int main()
{
    Point p0 = { 0, 0 };   cout << "(0, 0)   -> : " << CheckQ(p0) << " (: 0)" << endl;
    Point p1 = { 5, 5 };   cout << "(5, 5)   -> : " << CheckQ(p1) << " (: 1)" << endl;
    Point p2 = { -5, 5 };  cout << "(-5, 5)  -> : " << CheckQ(p2) << " (: 2)" << endl;
    Point p3 = { -5, -5 }; cout << "(-5, -5) -> : " << CheckQ(p3) << " (: 3)" << endl;
    Point p4 = { 5, -5 };  cout << "(5, -5)  -> : " << CheckQ(p4) << " (: 4)" << endl;
}

int CheckQ(Point p)
{
    if (p.x == 0 && p.y == 0)
    {
        return 0;
    }

    if (p.x > 0 && p.y > 0)
    {
        return 1;
    }
    if (p.x < 0 && p.y > 0)
    {
        return 2;
    }
    if (p.x < 0 && p.y < 0)
    {
        return 3;
    }
    if (p.x > 0 && p.y < 0)
    {
        return 4;
    }
}
