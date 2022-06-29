#include<iostream>
#include "student.h"

using std::endl;
using std::cout;
using std::string;

int main() {
    Student s("Ali", "malikali", 135);

    cout << s.getName() << endl;
    return 0;
}