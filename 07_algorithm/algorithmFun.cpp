#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<numeric>

using namespace std;

// Simple function to print element of a vector
void printVector(vector<int>& nums) {
    cout << "{";
    for(auto i : nums) {
        cout << i << ",";
    }
    cout << "}" << endl;
}

void vectorFun(vector<int> nums) {
    // 使用stl计算平均数
    double total = std::accumulate(nums.begin(), nums.end(), 0.0);
    double average = total / nums.size();
    cout << "Average is " << average << endl;

    // 下面是计算中位数的程序，正常可以直接排序找到中位数，但这样效率比较低。
    // nth_element是一个轻微排序程序，可以保证n放在正确排序的位置上。
    // 即n左边的必然小于n，n右边的必然大于n。
    std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    //TODO 尝试指针解引用的方式
    int median = *(nums.begin() + nums.size() / 2);
    cout << "Median: " << median << endl;
    printVector(nums);
}

// 创建一个随机向量
vector<int> createRandomVec(size_t sz) {
    srand(time(NULL));
    vector<int> nums;
    for(int i = 0; i < sz; i++) {
        nums.push_back(rand() % 500);
    }
    return nums;
}

int main() {
    //TODO 尝试使用引用的方式改写
    vector<int> nums = createRandomVec(20);
    vectorFun(nums);

    return 0;
}