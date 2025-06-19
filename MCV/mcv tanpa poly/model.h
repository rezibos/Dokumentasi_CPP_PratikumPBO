#ifndef model_h
#define model_h

#include <string>
using namespace std;

class StudentModel {
private:
    string name;
    int age;

public:
    StudentModel(string& name, int age) : name(name), age(age) {}

    string getName() { return name; }
    int getAge() { return age; }

    void setName(string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
};

#endif
