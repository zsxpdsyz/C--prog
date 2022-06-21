#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

using std::cout;    using std::endl;
using std::vector;  using std::set;

// 二分查找法，upper_bound查找大于目标值的第一个元素
// lower_bound表示的是查找不小于目标值的第一个元素
int findSupernum(const vector<int>& vec, int elem) {
    vector<int>::const_iterator it = std::lower_bound(vec.begin(), vec.end(), elem);
    if(it != vec.end())
        return *it;
    else
        return -1;
}

int main() {
    vector<int> vec{3,1,4,1,5,9,2,6,5,3,12,14};
    std::sort(vec.begin(), vec.end());

    cout << findSupernum(vec, 10) << endl;
    return 0;
}