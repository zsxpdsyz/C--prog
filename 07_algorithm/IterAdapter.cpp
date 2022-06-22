#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void printVector(vector<int>& nums) {
    cout << "{";
    for (auto elem : nums) {
        cout << elem << ", ";
    }
    cout << "}" << endl;
}

int main() {
    std::ostream_iterator<int> iter(cout, ",");
    *iter = 15;
    // ++iter;
    *iter = 3;
    cout << endl;

    vector<int> vec{3,1,4,1,5,9,2,6,5,3};

    printVector(vec);

    auto it = std::back_inserter(vec);
    *it = 8;
    // ++it;
    *it = 89;
    printVector(vec);
    
// 使用后插入的迭代器拷贝数据
    vector<int> copyVec;
    std::copy(vec.begin(), vec.end(), back_inserter(copyVec));
    printVector(copyVec);

    return 0;
}