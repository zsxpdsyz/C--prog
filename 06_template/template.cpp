#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;

template <typename Tz>
Tz min(Tz a, Tz b) {
    return (a < b) ? a : b;
}

int main() {
    cout << min(3, 5) << endl;
    return 0;
}