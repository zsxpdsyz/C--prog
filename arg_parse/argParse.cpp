/*
解析C++文件中的命令行参数
*/
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <getopt.h>
#include <string>

using namespace std;
// 外部变量用于默认的提取参数
extern char *optarg;

// optind:存放下一个要处理的字符串在argv中的下标
// opterr：如果发生错误会打印出错误消息
// optopt：选项处理发生错误会指向导致出错的字符串
extern int optind, opterr, optopt;

// 初始化一个option类型的结构体，用于给getopt_long传递参数
// 第1个参数 name="-name"表示长选项的名称
// 第2个参数 has_arg="required_argument"表示选项后面是否带参数
// 第3个参数 flag如果为NULL，则返回第4个参数val，否则的话返回0
// 第4个参数为匹配后返回的值
static struct option long_options[]
{
    {"name", required_argument, NULL, 'n'},
    {"age", required_argument, NULL, 'age'}
};


int main(int argc, char* argv[]) {
    for(int i = 0; i < argc; i++) {
        cout << "Input argument is " << argv[i] << endl;
    }

    int c;
    int index = 0;
// 前2个参数为main函数的输入参数，第3个为短选项的字符串
// 第4个为定义的结构体
    while((c = getopt_long(argc, argv, "hvn:", long_options, &index)) != EOF) {
        switch (c)
        {
        // case后面只能跟整型或字符型，因此该变量不能加双引号，字符型也会自动帮你转换为整型
        case 'n':
            cout << "we get option -n " << optarg << endl;
            break;

        case 'age':
        // -12是为了可以打印出前面的姓名
            cout << optarg - 12 << " 's age is " << optarg << endl;
            break;

        default:
            break;
        }
    }

    return 0;
}