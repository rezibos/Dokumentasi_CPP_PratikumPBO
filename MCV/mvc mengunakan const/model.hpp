#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <iostream>

using namespace std;

// Interface Model
class IModel
{
public:
    virtual string getInfo() const = 0;
    virtual ~IModel() {}
};

// Model turunan
class SiswaModel : public IModel
{
private:
    string nama; // Private = encapsulated
    int umur;

public:
    SiswaModel(const string &n, int u) : nama(n), umur(u) {}

    // Getter dan Setter = bentuk enkapsulasi
    void setNama(const string &n)
    {
        nama = n;
    }
    string getNama() const
    {
        return nama;
    }

    void setUmur(int u)
    {
        umur = u;
    }
    int getUmur() const
    {
        return umur;
    }

    string getInfo() const override
    {
        return "Siswa: " + nama + ", Umur: " + to_string(umur);
    }
};

#endif
