#include <iostream>
#include <cstdlib>
using namespace std;

struct Waktu{
    int jam;
};

class Kendaraan {
private:
    string nomor_kendaraan;
    string jenis_kendaraan;
    Waktu classWaktuMasuk;

public:
    Kendaraan(string plat, string jns, Waktu waktu){
        nomor_kendaraan = plat;
        jenis_kendaraan = jns;
        classWaktuMasuk = waktu;
        cout << "\n\033[32mKendaraan dengan nomor kendaraan " << nomor_kendaraan << " masuk.\033[0m\n";
    }

    void tampikan(){
        cout << "\nNomor Kendaraan : " << nomor_kendaraan << endl;
        cout << "Jenis Kendaraan : " << jenis_kendaraan << endl;
        cout << "Waktu Masuk Kendaraan : " << classWaktuMasuk.jam << " jam\n"<< endl;
    }

    ~Kendaraan() {
        cout << "\n\033[34mData kendaraan dengan nomor kendaraan " <<  nomor_kendaraan << " dihapus.\033[0m\n";
    }
};

int main()
{
    while (true) {
        system("cls");
        string bp, jk, yt;
        int wktk;
    
        cout << "Masukan Nomor Kendaraan : ";
        cin >> bp;
        cout << "Masukan Jenis Kendaraan : ";
        cin >> jk;
    
        Waktu waktumasuk = {rand() % 6};
        Kendaraan dataKendaraan(bp, jk, waktumasuk);
    
        cout << "\nApakah Mau menampilkan info kendaraan yang masuk (y/t) : ";
        cin >> yt;
    
        if(yt == "y"){
            dataKendaraan.tampikan();
            cout << "\033[33mAnda Keluar Dari Aplikasi Parkir\n\033[0m";
            system("pause");
            break;
        } else {
            cout << "\033[33m\nAnda Keluar Dari Aplikasi Parkir\n\033[0m";
            system("pause");
            break;
        }
    }
}
