#include <iostream>
#include <cstdlib>
using namespace std;

struct DataDivisi {
    string divisi;
    int ruangan;
    int maxruangan = (rand() % 20);
};

class Pegawai {
    DataDivisi divisiData;
    private:
    string gajibulanan, NIP;
    
    public:
    string nama;
    
    public:
    Pegawai(string nama, string NIP, string gb, string d, int r){
        Pegawai::nama = nama;
        Pegawai::NIP = NIP;
        Pegawai::gajibulanan = gb;
        divisiData.divisi = d;
        divisiData.ruangan = r;
    }
    
    void viewPegawai(){
        cout << "Nama Pegawai         : " << Pegawai::nama << endl;
        cout << "NIP Pegawai          : " << Pegawai::NIP << endl;
        cout << "Gaji Bulanan Pegawai : " << Pegawai::gajibulanan << endl;
        cout << "Divisi Pegawai       : " << divisiData.divisi << endl;
        cout << "Ruangan Pegawai      : " << divisiData.ruangan << endl;
        cout << "Jumlah Max Pegawai   : " << divisiData.maxruangan << endl;
    }
    
    string getDivisi() {
        return divisiData.divisi;
    }
    
    ~Pegawai(){
        cout << "Data Pegawai " << Pegawai::nama <<" telah dihapus Dari Sistem\n";
    }
};

int main()
{
    srand(time(NULL));
    Pegawai pegawai1("Fira", "2401020004", "10.000.00", "IT", 1);
    Pegawai pegawai2("Rezi", "2401020010", "20.000.00", "HR", 2);
    Pegawai pegawai3("Haikal", "2401020000", "10.000.00", "Keuangan", 3);
    
    int pilihan;
    
    do{
        system("cls");
        cout << "============ Menu Pegawai ========\n";
        cout << "1. Tampilkan Semua Data Pegawai \n";
        cout << "2. Tampilkan Divisi Pegawai \n";
        cout << "3. Keluar \n";
        cout << "=====================================\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls");
            cout << "Data Ke - 1\n";
            pegawai1.viewPegawai();

            cout << "\nData Ke - 2\n";
            pegawai2.viewPegawai();

            cout << "\nData Ke - 3\n";
            pegawai3.viewPegawai();

            cout << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "Divisi Ke - 1 \n";
            cout << "Nama Pegawai    : " << pegawai1.nama << endl;
            cout << "Divisi Pegawai  : " << pegawai1.getDivisi()  << endl;

            cout << "\nDivisi Ke - 2 \n";
            cout << "Nama Pegawai   : " << pegawai2.nama << endl;
            cout << "Divisi Pegawai : " << pegawai2.getDivisi()  << endl;

            cout << "\nDivisi Ke - 3 \n";
            cout << "Nama Pegawai   : " << pegawai3.nama << endl;
            cout << "Divisi Pegawai : " << pegawai3.getDivisi()  << endl << endl;

            system("pause");
            break;

        default:
            cout << "Pilihan Tidak Valid \n" << endl; 
            break;
        }
    } while (pilihan != 3);
    system("cls");
}
