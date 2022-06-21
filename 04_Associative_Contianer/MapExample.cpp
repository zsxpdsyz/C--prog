#include "getline.h"
#include<set>
using std::set;

void print_map(const std::map<string, int> & m) {
    // for(auto& [key, value] : m) {
    //     cout << "[key:" << key << "     " << "value:" << value <<"]" << endl;
    // }

    for(std::map<string, int>::const_iterator i = m.begin(); i != m.end(); i++) {
        // iterator可以看做是一个指针，通过*拿到地址的
        cout << i->first << "       " << i->second << endl;
    }
}

int main() {
    // 关于set的实验
    std::set<string> list;
    list.insert("milk");
    // 集合中重复的只保留一个
    list.insert("egg");
    list.insert("egg");
    cout << list.count("egg") << endl;

    // Using map to count the appearances of words
    std::map<string, int> frequenceMap;
    cout << "Enter words" << endl;

    while(true) {
        cout << ">";
        string response = GetLine();
        if(response.empty()) break;
        std::istringstream stream(response);
        string word;
        while(stream >> word) {
            ++frequenceMap[word];
        }
    }
    
    // 打印所有的map中的数据
    print_map(frequenceMap);
}