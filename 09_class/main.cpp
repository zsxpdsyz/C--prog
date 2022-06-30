#include<iostream>
#include "student.h"
#include "stuDatabase.h"

using std::endl;
using std::cout;
using std::string;

int main() {
    Student s("Ali", "malikali", 135);

    cout << s.getName() << endl;

    StudentDatabase* db = new StudentDatabase;
    db->addStudent(s);
    if(db->hasStudent(s)) {
        cout << "Database has student" << endl;
    }

    return 0;
}