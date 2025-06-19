#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <string>

using namespace std;

class IModel {
public:
    virtual string getInfo() const = 0;
    virtual void setData(const string& nama, int umur) = 0;
    virtual void getData(string& nama, int& umur) const = 0;
    virtual ~IModel() {}
};

class SiswaModel : public IModel {
private:
    string nama;
    int umur;

public:
    SiswaModel(const string &n = "", int u = 0) : nama(n), umur(u) {}

    void setData(const string& n, int u) override {
        nama = n;
        umur = u;
    }

    void getData(string& n, int& u) const override {
        n = nama;
        u = umur;
    }

    string getInfo() const override {
        return "Siswa: " + nama + ", Umur: " + to_string(umur);
    }
};

#endif