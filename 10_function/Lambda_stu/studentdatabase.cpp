#include "studentdatabase.h"
#include<algorithm>
#include<iostream>

using std::vector;
using std::string;

void StudentDatabase::addStudent(const Student& s) {
    db.push_back(s);
}

bool StudentDatabase::hasStudent(Student toFind) {
    for(auto student : db) {
        if(student == toFind)
            return true;
    }
    return false;
}


int StudentDatabase::size() {
    return db.size();
}


bool StudentDatabase::empty() {
    return db.empty();
}


class InYearPred {
public:
    InYearPred(const string& inp) {
        yearToFind = inp;
    }
// 重载操作符，相当于在每次复制元素的时候必然会用每个Student带入该函数去验证
// 因此需要重载括号操作符
    bool operator()(Student s) {
        return s.classLevel() == yearToFind;
    }

private:
    string yearToFind;

};

std::vector<Student> StudentDatabase::studentsInYear(std::string yearToFind) {
    vector<Student> ret;

    InYearPred pred(yearToFind);
    // 拷贝满足pred判断条件的元素
    // [捕获列表]，可以引用捕获或者值捕获，即通过引用或者通过值来操作外部的变量
    std::copy_if(db.begin(), db.end(),  std::back_inserter(ret), [&yearToFind](Student s) -> bool {
        return s.classLevel() == yearToFind;
    });
    // 等价于上面的写法
    // std::copy_if(db.begin(), db.end(),  std::back_inserter(ret), pred);

// We'll settle for a for-loop
//    for(auto student : db) {
//        if(student.classLevel() == yearToFind) {
//            ret.push_back(student);
//        }
//    }

// 此处为重载操作符的验证
    std::cout << pred(*(db.begin()+1)) << std::endl;
    return ret;
}







