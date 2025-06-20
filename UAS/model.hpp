#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <string>

using namespace std;

class IMODEL {
public:
    virtual string getInfo() const = 0;
    virtual void setData(const string &n, int id, int jbm) = 0;
    virtual void getData(string &n, int id, int jbm) const = 0;
    virtual bool cekNotifikasi() const = 0;
    virtual ~IMODEL() {}
};

class Buku {
private:
    string judul;
    string penulis;
    int tahun_terbit;

public:
    string getJudul(){
        return judul;
    }

    string getPenulis(){
        return penulis;
    }

    int getTahunTerbit(){
        return tahun_terbit;
    }

    void setJudul(const string& j) {
        judul = j;
    }

    void setPenulis(const string& p) {
        penulis = p;
    }

    void setTahunTerbit(int t) {
        tahun_terbit = t;
    }
};

class MahasiswaModel : public IMODEL {
private:
    string nama_mahasiswa;
    int nomor_identitas_mahasiswa;
    int jumlah_buku_mahasiswa = 0;

public:
    MahasiswaModel(const string &n = "", int id = 0, int jbm = 0) : nama_mahasiswa(n), nomor_identitas_mahasiswa(id), jumlah_buku_mahasiswa(jbm) {}

    void setData(const string &n, int id, int jbm) override {
        nama_mahasiswa = n;
        nomor_identitas_mahasiswa = id;
        
        if (jbm > 3) {
            cout << "Jumlah Buku Mencapai Batas." << endl;
            jumlah_buku_mahasiswa = 3;
        } else {
            jumlah_buku_mahasiswa = jbm;
        }
    }

    void getData(string &n, int id, int jbm) const override {
        n = nama_mahasiswa;
        id = nomor_identitas_mahasiswa;
        jbm = jumlah_buku_mahasiswa;
    }

    bool cekNotifikasi() const override {
        return jumlah_buku_mahasiswa == 3;
    }

    string getInfo() const override {
        return "Siswa: " + nama_mahasiswa + ", Nomor identitas: " + to_string(nomor_identitas_mahasiswa) + ", Jumlah Buku: " + to_string(jumlah_buku_mahasiswa);
    }
};

class DosenModel : public IMODEL {
private:
    string nama_dosen;
    int nomor_identitas_dosen;
    int jumlah_buku_dosen = 0;

public:
    DosenModel(const string &n = "", int id = 0, int jbm = 0) : nama_dosen(n), nomor_identitas_dosen(id), jumlah_buku_dosen(jbm) {}

    void setData(const string &n, int id, int jbm) override {
        nama_dosen = n;
        nomor_identitas_dosen = id;
        
        if (jbm > 3) {
            cout << "Jumlah Buku Mencapai Batas" << endl;
            jumlah_buku_dosen = 3;
            return;
        } else {
            jumlah_buku_dosen = jbm;
        }
    }

    void getData(string &n, int id, int jbm) const override {
        n = nama_dosen;
        id = nomor_identitas_dosen;
        jbm = jumlah_buku_dosen;
    }

    bool cekNotifikasi() const override {
        return jumlah_buku_dosen == 3;
    }

    string getInfo() const override {
        return "Dosen: " + nama_dosen + ", Nomor identitas: " + to_string(nomor_identitas_dosen) + ", Jumlah Buku: " + to_string(jumlah_buku_dosen);
    }
};

#endif