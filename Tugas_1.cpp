#include <iostream>
#include <string>

using namespace std;

class MataKuliah
{
private :

    string nama_mk, nomor_mk, ruang, dosen;
    int sks, hari;

public :
    void belajar(){
        nama_mk = "Praktikum Pemograman Berorientasi Objek";
        nomor_mk = "01010101010";
        sks = 12;
        ruang = "Labor Pratikum";

        cout << nama_mk << endl;
        cout << nomor_mk << endl;
        cout << sks << endl;
        cout << ruang << endl;
    }

    void evaluasi(){
        dosen = "Pak Berta";

        cout << dosen << endl;
    }
};


int main()
{
    MataKuliah mk;

    mk.belajar();
    mk.evaluasi();
}
