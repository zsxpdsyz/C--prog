#include<iostream>
#include<fstream>

using std::cout;
using std::endl;

// 定义通用的写入函数，传入stream类型的引用
void writeToSteam(std::ostream& anyOutputStream, int myfavouritenumber){
    anyOutputStream << "Write to stream " 
        << myfavouritenumber << endl;
}
// 输出语句

int main(){
    cout << "hello world" << endl;

    int favouriteNumber = 90;
    std::ofstream outputFile("out.txt");
    outputFile << "my favourite number is " << favouriteNumber 
    << "\n sljflsdjf" << endl;

    // 接下来可以定义一个函数可以控制他输出到任何地方
    writeToSteam(outputFile, 88);
    return 0;
}