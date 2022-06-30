#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;    using std::cin;
using std::endl;    using std::string;
using std::vector;  using std::ostream;

class AddNum {
public:

    AddNum(int inp) {
        startNum = inp;
    }
    int operator()(int x);
    

private:
    int startNum;
};
int AddNum::operator()(int x) {
        return x + this->startNum;
    }


int main() {
    // Construct functor with initial value of 5.
    AddNum a(5);
    // 一旦初始化不能访问
    // a.startNum = 7;

    // Calling as function adds value originally passed
    // into constructor to paramter.
    cout << a(4) << endl;

    return 0;
}

