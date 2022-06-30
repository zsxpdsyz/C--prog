#ifndef STUDATABASE_H
#define STUDATABASE_H

#include<vector>
#include "student.h"
// 创建一个基于学生类的数据库

class StudentDatabase
{
public:
    void addStudent(const Student& s);
    bool hasStudent(Student toFind);
    int size();
    bool empty();

private:
    std::vector<Student> db;
};

void StudentDatabase::addStudent(const Student& s) {
    db.push_back(s);
}

bool StudentDatabase::hasStudent(Student toFind) {
    for(auto& student : db) {
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

#endif