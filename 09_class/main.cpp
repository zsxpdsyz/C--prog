#include<iostream>
#include "student.h"
#include "stuDatabase.h"

using std::endl;
using std::cout;
using std::string;

int main() {
    Student s("Ali", "mike", 135);
    Student s1("zhang", "mike", 135);

    cout << s.getName() << endl;

    StudentDatabase* db = new StudentDatabase;
    db->addStudent(s);
    if(db->hasStudent(s)) {
        cout << "Database has student" << endl;
    }

    if(s == s1)
        cout << "Student s equal s1" << endl;

    return 0;
}