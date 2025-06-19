#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <iostream>

using namespace std;

class IModel {
public:
    virtual string getInfo() = 0;
    virtual ~IModel() {}
};

class SiswaModel : public IModel {
private:
    string nama;
    int umur;

public:
    SiswaModel(string &n, int u) : nama(n), umur(u) {}

    void setNama(string &n) { nama = n; }
    void setUmur(int u) { umur = u; }

    string getNama() { return nama; }
    int getUmur() { return umur; }

    string getInfo() override {
        return "Siswa: " + nama + ", Umur: " + to_string(umur);
    }
};

#endif
