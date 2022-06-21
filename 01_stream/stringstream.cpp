#include <sstream>
#include <iostream>

using namespace std;

int main(){
    // 该类的对象使用string buffer存储一串字符
    // 该字符可以直接使用str成员访问
    // 主要用于输出流
    ostringstream oss("Ito En Green Tea");
    cout << oss.str() << endl;
    // 相当于是一个指针移动在写入，因此刚开始写的时候会发生覆盖的现象
    // 然后继续往里写就不会被覆盖了，因为指针是不断的往后移动的
    double size = 16.9;
    // oss << size <<" Ounce ";
    cout << size << endl;

    oss << "(Pack of " << 12 << ")";
    cout << oss.str() << endl;

    return 0;
}