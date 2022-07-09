#include <iostream>
#include <vector>
#include "myvector.h"

using std::cout;    using std::endl;
using std::string;

int main() {
    // 定义对象的时候必须要指定模板类的类型
    MyVector<string> v(5, "yes");

    v.push_back("hello");
    v.push_back("world");

    for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    // does bounds checking
    // 触发边界检查，但是用[]则没有边界检查
    cout << v.at(50) << endl;

    /*
       * This doesn't swork because we have not specified
       * const versions of our accessor methods.
       *
       *    const Vector<string> constV(10, "iamconst");
       *    cout << constV[0] << endl;
       */

    return 0;
}