
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;    using std::cin;
using std::endl;    using std::string;
using std::vector;  using std::ostream;

struct Point {
    /* data */
    int x;
    int y;

    bool operator== (const Point& rhs) {
        return this->x == rhs.x && this->y == rhs.y;
    }
};

ostream& operator<< (ostream& os, vector<int> x) {
    os << "{";
    for(auto i : x) {
        os << i << " ";
    }
    os << "}";
    return os;
}

bool operator<(const Point& lhs, const Point& rhs) {
    return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
}

int main() {
    vector<int> v{3, 1, 4, 1, 5, 9};
    cout << v << endl;

    Point p1{3, 1};
    Point p2{1, 0};
    Point p3{3, 1};

    if(p2 < p1)
        cout << "P2 less than P1" << endl;
    return 0;
}
