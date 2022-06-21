#include<iostream>
#include<vector>
#include<istream>
#include<sstream>
#include<algorithm>

 // 表示一个无符号整型，通过stl库定义的好处是不同C++标准可以通用
using vecsz_t = std::vector<int>::size_type;
using std::vector;  using std::cin;
using std::cout;    using std::string;
using std::endl;

int getInteger() {
    int result;
    // 不使用清空缓冲区的方法，先接受再进行类型转换
    while(true) {
        string line;
        std::getline(cin, line);
        if(std::istringstream(line) >> result) {
            return result;
        } else
            cout << "Not a valid number" << endl;
    }

/*
// 使用此种方法需要每次清空cin的缓冲区，容易造成错误
// 因此可以使用stringstream的方法先把输入流通过字符串的方式接收进来，
// 然后再进行下一步的转换判断
    while(true) {   
        cin >> result;
        if(cin.fail()) {
            cout << "Invalid input!" << endl;
            cin.clear();
            // cin.sync();
            cin.ignore(1024, '\n');
        }
        else 
            return result;
    }
*/
}

void printVector(const vector<int>& data) {
    for(vecsz_t i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    const int kNumInts = 4;
    vector<int> data;
    // 获得数据并加入到向量中
    for(int i = 0; i < kNumInts; i++) {
        cout << "Enter value (" << kNumInts - i << " left):" << endl;
        int curr = getInteger();
        data.push_back(curr);
    }

    vecsz_t size = data.size();
    // 使用algorithm头文件
    std::sort(data.begin(), data.end());
    printVector(data);
    vecsz_t mid = kNumInts / 2;
    if(data.size() % 2 == 0)
        cout << (data[mid] + data[mid-1]) / 2.0 << endl;
    else
        cout << data[mid] << endl;
}