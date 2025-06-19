#ifndef view_h
#define view_h

#include <iostream>
#include <string>
using namespace std;

class StudentView {
public:
    void displayStudentDetails(string& name, int age) {
        cout << "== Data Mahasiswa ==\n";
        cout << "Nama: " << name << "\n";
        cout << "Umur: " << age << " tahun\n";
    }
};

#endif
