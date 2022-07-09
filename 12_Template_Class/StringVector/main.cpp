#include <iostream>
#include <vector>
#include "strvector.h"

using std::cout;    using std::endl;
using std::string;

void printVec(StrVector& v) {
    for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main() {
// 通过new一个string类型的空间，然后用指针来计数
    StrVector v(4, "yes");
    v.push_back("hello");
    v.push_back("world");

    printVec(v);
    return 0;
}