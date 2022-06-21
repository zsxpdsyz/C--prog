#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using std::endl; using std::cout;
using std::vector;  using std::list;

template<typename InputIterator, typename DataType>
int nameOccurgen(InputIterator start, InputIterator end, DataType elemTocount) {
    int counter = 0;
    InputIterator iter;
    for(iter = start; iter != end; iter++) {
        if(*iter == elemTocount)
            counter++;
    }
    return counter;
}

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 3};
    list<int> l = {2, 7 , 1, 8, 2, 8 , 2};
    
    cout << "vector count: " << nameOccurgen(v.begin(), v.end(), 1) << endl;
    cout << "list count: " << nameOccurgen(l.begin(), l.end(), 2) << endl;
// 使用std标准库实现和我们设计的函数是一样的
    cout << "Count std implement: " << std::count(v.begin(), v.end(), 1) << endl;

    return 0;
}