#include <iostream>
#include <sstream>
#include <vector>
#include <istream>

using std::cout;    using std::endl;
using std::cin;     using std::string;
using std::vector;

int getInteger() {
    int result;
    while(true) {
        string line;
        getline(cin, line);
        if(std::istringstream(line) >> result)
            return result;
        else
            cout << "Not a valid number" << endl;
    }
}

template <typename DateType>
DateType getType() {
    DateType result;
    while(true) {
        string line;
        std::getline(cin, line);
        // 常见的用string流接受字符串
        if(std::istringstream(line) >> result) {
            return result;
        }
        else {
            cout << "Not a valid input" << endl;
        }
    }
}

int main() {
    cout << "Input integer: " << endl;
    // 此处必须有尖括号包含的类型，不然的话编译器无法从中推断出模板的类型
    int a = getType<int>();
    double b = getType<double>();

    cout << "Int : " << a << endl;
    cout << "Double : " << b << endl;
    return 0;
}