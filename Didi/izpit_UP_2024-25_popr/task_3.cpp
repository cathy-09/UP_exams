//PLS DAITE MI TAZI ZADACHA

#include <iostream>

struct Point {
    int x;
    int y;
};

int CheckQ(Point p) {
    int x = p.x;
    int y = p.y;

    if (x == 0 && y == 0) {
        return 0;
    }
    
    if (x > 0) {
        if (y > 0) {
            return 1;
        }
        else {
            return 4;
        }
    }
    else {
        if (y > 0) {
            return 2;
        }
        else {
            return 3;
        }
    }
}

int main() {
    Point p1 = { 5, 3 };
    std::cout << "Input: (" << p1.x << ", " << p1.y << ") | Expected: 1 | Actual: " << CheckQ(p1) << std::endl;

    Point p2 = { -4, 2 };
    std::cout << "Input: (" << p2.x << ", " << p2.y << ") | Expected: 2 | Actual: " << CheckQ(p2) << std::endl;

    Point p3 = { -1, -6 };
    std::cout << "Input: (" << p3.x << ", " << p3.y << ") | Expected: 3 | Actual: " << CheckQ(p3) << std::endl;

    Point p4 = { 7, -2 };
    std::cout << "Input: (" << p4.x << ", " << p4.y << ") | Expected: 4 | Actual: " << CheckQ(p4) << std::endl;

    Point p5 = { 0, 0 };
    std::cout << "Input: (" << p5.x << ", " << p5.y << ") | Expected: 0 | Actual: " << CheckQ(p5) << std::endl;

    return 0;
}
