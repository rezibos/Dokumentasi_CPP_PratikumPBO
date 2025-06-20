#ifndef VIEW_HPP
#define VIEW_HPP

#include "model.hpp"

using namespace std;

class IVIEW {
public:
    virtual ~IVIEW() {}
    virtual void tampilkan(const IMODEL& model, Buku& buku) = 0;
    virtual void dapatkanInput(const IMODEL& model, Buku& buku) = 0;
};

class MahasiswaView : public IVIEW {
public:
    void tampilkan(const IMODEL& model, Buku& buku) override {
        system("cls");
        cout << "\n=========== TAMPILAN DATA MAHASISWA ===========" << endl;
        cout << model.getInfo() << endl;
        cout << "Judul Buku: " << buku.getJudul() << endl;
        cout << "Penulis: " << buku.getPenulis() << endl;
        cout << "Tahun Terbit: " << buku.getTahunTerbit() << endl << endl;
        
        if (model.cekNotifikasi()) {
            cout << "Jumlah buku mencapai batas maksimum" << endl;
        }
        system("pause");
    }

    void dapatkanInput(const IMODEL& model, Buku& buku) override {
        string judul, penulis;
        int tahun;

        system("cls");
        cout << "\n=========== INPUT DATA BUKU MAHASISWA ===========" << endl;
        cout << "Masukkan Judul Buku: ";
        getline(cin, judul);
        
        cout << "Masukkan Nama Penulis: ";
        getline(cin, penulis);
        
        cout << "Masukkan Tahun Terbit: ";
        cin >> tahun;
        
        buku.setJudul(judul);
        buku.setPenulis(penulis);
        buku.setTahunTerbit(tahun);
        
        cin.ignore();
        cout << "\nData buku berhasil diinput!" << endl;
        system("pause");
    }
};

class DosenView : public IVIEW {
public:
    void tampilkan(const IMODEL& model, Buku& buku) override {
        system("cls");
        cout << "\n=========== TAMPILAN DATA DOSEN ===========" << endl;
        cout << model.getInfo() << endl;
        cout << "Judul Buku: " << buku.getJudul() << endl;
        cout << "Penulis: " << buku.getPenulis() << endl;
        cout << "Tahun Terbit: " << buku.getTahunTerbit() << endl << endl;
        
        if (model.cekNotifikasi()) {
            cout << "Jumlah buku mencapai batas maksimum" << endl;
        }
        system("pause");
    }

    void dapatkanInput(const IMODEL& model, Buku& buku) override {
        string judul, penulis;
        int tahun;

        system("cls");
        cout << "\n=========== INPUT DATA BUKU DOSEN ===========" << endl;
        cout << "Masukkan Judul Buku: ";
        getline(cin, judul);
        
        cout << "Masukkan Nama Penulis: ";
        getline(cin, penulis);
        
        cout << "Masukkan Tahun Terbit: ";
        cin >> tahun;
        
        buku.setJudul(judul);
        buku.setPenulis(penulis);
        buku.setTahunTerbit(tahun);
        
        cin.ignore();
        cout << "\nData buku berhasil diinput!" << endl;
        system("pause");
    }
};

#endif