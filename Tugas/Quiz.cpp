#include <iostream>
using namespace std;

class Kendaraan {
protected:
    string nomor_polisi;
    string merk;
    int tahun_produksi;

public:
    Kendaraan(string np, string mk, int tp) : nomor_polisi(np), merk(mk), tahun_produksi(tp) {}

    virtual void pengecekan() {}

    virtual ~Kendaraan() {}
};

class Mobil : public Kendaraan {
public:
    Mobil(string np, string mk, int tp) : Kendaraan(np, mk, tp) {}

    void pengecekan() override {
        cout << "Mobil Dengan Nomor Polisi : " << nomor_polisi << endl;
        cout << "Merk : " << merk << endl;
        cout << "Tahun kendaraan : " << tahun_produksi << endl;
        cout << "Mobil dalam pengecekan oli mesin dan AC\n";
    }

    ~Mobil() override{
        cout << "\nMobil Selesai Dalam Pengecekan\n";
    }
};

class Motor : public Kendaraan{
public:
    Motor(string np, string mk, int tp) : Kendaraan(np, mk, tp) {}

    void pengecekan() override {
        cout << "Motor Dengan Nomor Polisi : " << nomor_polisi << endl;
        cout << "Merk : " << merk << endl;
        cout << "Tahun kendaraan : " << tahun_produksi << endl;
        cout << "Motor dalam pengecekan oli mesin\n";
    }

    ~Motor() override{
        cout << "\nMotor Selesai Dalam Pengecekan\n";
    }
};

class Truk : public Kendaraan {
public:
    Truk(string np, string mk, int tp) : Kendaraan(np, mk, tp) {}

    void pengecekan() override {
        cout << "Truk Dengan Nomor Polisi : " << nomor_polisi << endl;
        cout << "Merk : " << merk << endl;
        cout << "Tahun kendaraan : " << tahun_produksi << endl;
        cout << "Truk dalam pengecekan oli mesin dan sistem rem tambahan\n";
    }

    ~Truk() override{
        cout << "\nTruk Selesai Dalam Pengecekan\n";
    }
};

int main()
{
    Kendaraan* kendaraan = nullptr;
    string nomorPolisi, merek, jk;
    char yt;
    bool lanjut = true;
    int tahunProduksi;

    while (lanjut) {
        system("cls");
        cout << "============ MENU SHOROOM MOBIL ============\n";
        cout << "Masukkan Nomor Polisi : ";
        cin >> nomorPolisi;
        cout << "Masukkan Merk Kendaran : ";
        cin >> merek;
        cout << "Masukkan Tahun Produksi Kendaran : ";
        cin >> tahunProduksi;
        cout << "Masukan Jenis Kendaraan : ";
        cin >> jk;
        cout << "============================================\n";
        cout << "\nTekan tombol apa pun untuk melanjutkan : ";
        system("pause > nul");
    
        if(jk == "Mobil"){
        kendaraan = new Mobil(nomorPolisi, merek, tahunProduksi);
        } else if(jk == "Motor") {
            kendaraan = new Motor(nomorPolisi, merek, tahunProduksi);
        } else if(jk == "Truk"){
            kendaraan = new Truk(nomorPolisi, merek, tahunProduksi);
        } else {
            cout << "Jenis kendaraan tidak dikenali!\n";
            continue;
        }

        system("cls");
        kendaraan->pengecekan();
        delete kendaraan;
        kendaraan = nullptr;

        cout << "\nTekan tombol apa pun untuk melanjutkan : ";
        system("pause > nul");

        cout << "Apakah Ingin Melakukan Pengecekan Lagi (y/t) : ";
        cin >> yt;
        if(yt == 't' || yt == 'T'){
            lanjut = false;
        }
    }
    
    delete kendaraan;
}
