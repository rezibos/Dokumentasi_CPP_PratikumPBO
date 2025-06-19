#include <iostream>
using namespace std;

class Gedung
{
    private:
        double ukuran, kp;
        int pilihan;

    public:

    void menara(){
        system("cls");
        cout << "Masukan Ukuran Menara : ";
        cin >> ukuran;

        cout << "Jadi Ukuran Menara Dubai adalah : " << ukuran << " m \n";
    }

    void kapasitasPengunjung(){
        system("cls");
        cout << "Masukan Kapasitas Pengunjung : ";
        cin >> kp;

        cout << "Jadi Kapasitas Pengunjung : " << kp << endl; 
    }

    Gedung(){
        cout << "Menu Ibu Kota \n";
        cout << "1. Menentukan Ukuran Menara \n";
        cout << "2. Menetukan Kapasitas Pengunjung \n";
        cout << "Pilihan (1/2) : "; 
        cin >> pilihan;

        switch (pilihan)
        {
        case 1 :menara();
                break;
        case 2 :kapasitasPengunjung();
                break;
        default:cout << "Pilihan Tidak Di Temukan" << endl;
                break;
        }
    }
};

struct Dubai
{
    int jumlah;
    void penduduk();
}mainDubai;

void Dubai::penduduk(){
    system("cls");
    cout << "Masukan Jumlah Penduduk Dubai : ";
    cin >> jumlah;

    cout << "Jumlah Penduduk Dubai Adalah : " << jumlah << endl;
}

int main()
{
    int pilihan;
    
    do{
        cout << "Silahkan Pilih Menu \n";
        cout << "1. Gedung \n";
        cout << "2. Dubai \n";
        cout << "3. Keluar \n";
        cout << "Masukan Pilihan : ";
        cin >> pilihan;
        
        switch (pilihan)
        {
        case 1 :{
                system("cls");
                Gedung gedung;
                break;
        }
        case 2 :system("cls");
                mainDubai.penduduk();
                break;
        default:cout << "Pilihan Tidak Tersedia \n";
                break;
        }

    }while(pilihan != 3);

    cout << "Terimakasih Sudah Menggunakan Program Ini \n";
}