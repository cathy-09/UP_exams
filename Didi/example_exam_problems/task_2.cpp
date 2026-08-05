//Ebahti prokletite otsechki i ebahti smotanoto uslovie.....
#include <iostream>

struct Point {
    int x;
    int y;
};

struct Segment {
    Point start;
    Point end;
};

int findDistanceOfSegments(Segment first, Segment second) {

    int maxStart = 0;
    int minEnd = 0;

    if (first.start.x == first.end.x && second.start.x == second.end.x && first.start.x == second.start.x) {
        maxStart = first.start.y > second.start.y ? first.start.y : second.start.y;
        minEnd = first.end.y < second.end.y ? first.end.y : second.end.y;

        if (maxStart > minEnd) {
            return 0;
        }

        return minEnd - maxStart;
    }

    if (first.start.y == first.end.y && second.start.y == second.end.y && first.start.y == second.start.y) {
        maxStart = first.start.x > second.start.x ? first.start.x : second.start.x;
        minEnd = first.end.x < second.end.x ? first.end.x : second.end.x;

        if (maxStart > minEnd) {
            return 0;
        }

        return minEnd - maxStart;
    }

    return -1;
}

int main() {
    // Test 1: Horizontal segments, partial overlap
    // Segment 1: from x=2 to x=8 (y=5). Segment 2: from x=6 to x=10 (y=5).
    Segment h1 = { {2, 5}, {8, 5} };
    Segment h2 = { {6, 5}, {10, 5} };
    std::cout << "Test 1 (Horizontal partial overlap): " << findDistanceOfSegments(h1, h2) << "\n";
    // Expected output: 2

    // Test 2: Vertical segments, one fully inside the other
    // Segment 1: from y=0 to y=10 (x=3). Segment 2: from y=4 to y=6 (x=3).
    Segment v1 = { {3, 0}, {3, 10} };
    Segment v2 = { {3, 4}, {3, 6} };
    std::cout << "Test 2 (Vertical fully inside): " << findDistanceOfSegments(v1, v2) << "\n";
    // Expected output: 2

    // Test 3: Horizontal segments, NO overlap
    // Segment 1: from x=0 to x=3 (y=1). Segment 2: from x=5 to x=9 (y=1).
    Segment no_over1 = { {0, 1}, {3, 1} };
    Segment no_over2 = { {5, 1}, {9, 1} };
    std::cout << "Test 3 (Horizontal NO overlap): " << findDistanceOfSegments(no_over1, no_over2) << "\n";
    // Expected output: 0

    // Test 4: Segments on different horizontal lines (parallel, but not the same line)
    Segment diff_line1 = { {2, 3}, {8, 3} };
    Segment diff_line2 = { {2, 4}, {8, 4} };
    std::cout << "Test 4 (Different parallel lines): " << findDistanceOfSegments(diff_line1, diff_line2) << "\n";
    // Expected output: -1

    // Test 5: Diagonal segments
    Segment diag1 = { {0, 0}, {5, 5} };
    Segment diag2 = { {2, 2}, {8, 8} };
    std::cout << "Test 5 (Diagonal segments): " << findDistanceOfSegments(diag1, diag2) << "\n";
    // Expected output: -1

    // Test 6: One horizontal and one vertical segment (intersecting at one point)
    Segment cross1 = { {0, 5}, {10, 5} }; // Horizontal
    Segment cross2 = { {5, 0}, {5, 10} }; // Vertical
    std::cout << "Test 6 (Crossing segments): " << findDistanceOfSegments(cross1, cross2) << "\n";
    // Expected output: -1

    return 0;
}
