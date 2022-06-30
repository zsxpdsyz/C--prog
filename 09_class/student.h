#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using std::string;

class Student
{
private:
    /* data */
    std::string name;
    std::string suid;
    int numUnits;
public:
    Student(string inpName, string inpSuid, int inpUnits);
    string getName();
    string getSuid();
    int getUnits();
    string classLevel();

    ~Student();
    // 双目运算符应该定义在类外，因为其参数中默认包含了this指针，因此会报错参数过多
    // bool operator== (Student left, Student right) {
    //     return left.getSuid() == right.getSuid();
    // }
};

Student::Student(string inpName, string inpSuid, int inpUnits)
{
    this->name = inpName;
    suid = inpSuid;
    numUnits = inpUnits;
}

string Student::getSuid() {
    return suid;
}

string Student::getName() {
    return name;
}

int Student::getUnits() {
    return numUnits;
}

bool operator== (Student left, Student right) {
    return left.getSuid() == right.getSuid();
}

string Student::classLevel() {
    if(numUnits <= 45)
        return "freshman";
    else if(numUnits <= 90)
        return "sophomore";
    else if(numUnits <= 135)
        return "junior";
    else
        return "senior";
}

Student::~Student()
{
}


#endif