#include<iostream>
#include<fstream>

using std::cout;
using std::endl;
using std::cin;     using std::string;

// 创建一个读取文件夹中数字的函数
void readNumbers() {
    std::ifstream inputFile("number.txt");
    int number;
    // 不断的做循环读取，直到文件中没有剩余的数据
    while(true) {
        inputFile >> number;
        // 将所有的数据打印出来
        
        if(inputFile.fail())
            break;
        cout << "Read number is " << number << endl;
    }   
}
//  创建读取整行的函数
void readHaikuLine() {
    std::ifstream input("Haiku.txt");
    string line1;

    while(true) {
        std::getline(input, line1);
        if(input.fail())
            break;
        cout << line1 << endl;
    }
}

int main(){
    int value;
    string value2;
    // 常规在命令行输入数据,cin中间有空格或者换行符都表示输入完毕
    cout << "Input some value or string" << endl;
    // cin >> value >> value2;
    // cout << "Input value is " << value << value2<< endl;

    string fullName;
    // getline已经可以开始接收了，不需要下面再写cin了
    std::getline(cin, fullName);
    // cin >> fullName;
    cout << "Input name is " << fullName <<endl;

    // readNumbers();
    // cout << "=============" << endl;
    // cout << 45.6*2 << endl;
    // readHaikuLine();
    return 0;
}