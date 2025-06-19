#ifndef VIEW_HPP
#define VIEW_HPP

#include "model.hpp"

using namespace std;

class IView {
public:
    virtual void tampilkan(const IModel &model) = 0;
    virtual void dapatkanInput(IModel &model) = 0;
    virtual ~IView() {}
};

class SiswaView : public IView {
public:
    void tampilkan(const IModel &model) override {
        cout << model.getInfo() << endl;
    }

    void dapatkanInput(IModel &model) override {
        string nama;
        int umur;

        cout << "Masukkan nama siswa: ";
        getline(cin, nama);

        cout << "Masukkan umur siswa: ";
        cin >> umur;
        cin.ignore();

        model.setData(nama, umur); // Menggunakan method Model
    }
};

#endif