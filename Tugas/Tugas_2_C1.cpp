#include <iostream>
#include <string>
using namespace std;

class Pesawat{
    public :
        string roda_pesawat, sayap_pesawat, kapasitas_penumpang;
        string rt_penerbangan;

    void ukuran (){
        cout << "Masukan Ukuran Roda Pesawat : ";
        cin >> roda_pesawat;
        cout << "Masukan Ukuran Sayap Pesawat : ";
        cin >> sayap_pesawat;
        cout << "Masukan Ukuran Kapasitas Penumpang : ";
        cin >> kapasitas_penumpang;

        cout << "Ukuran Roda Pesawat : " << roda_pesawat << endl;
        cout << "Ukuran Sayap Pesawat : " << sayap_pesawat << endl;
        cout << "Ukuran Kapasitas Penumpang : " << kapasitas_penumpang << endl << endl;
    }

    void rute(int RutePesawat){
        if(RutePesawat = 1){
            cout << "Bandung - Jakarta \n";
        } else if(RutePesawat = 2){
            cout << "Batam - Jakarta \n";
        } else if(RutePesawat = 3){
            cout << "Pekanbaru - Batam \n";
        } else if(RutePesawat = 4){
            cout << "TanjungPinang - Jakarta \n";
        } else if(RutePesawat = 5){
            cout << "Papua - Bandung \n";
        } else {
            cout << "Tidak Ada Rute \n";
        }
    }
};

struct JenisPesawat
{
    public:
    void vip();
};

void JenisPesawat::vip(){
    cout << "Pesawat Lion Air \n";
    cout << "Pesawat Garuda \n";
    cout << "Pesawat Pokemon \n";
}

int main()
{
    Pesawat MenuP;
    JenisPesawat jenis;
    int pilihan;
    int RutePesawat;

    do{
        cout << "1. Menu Ukuran Pesawat \n";
        cout << "2. Menu Rute \n";
        cout << "3. Menu Jenis Pesawat \n";
        cout << "4. Keluar \n";
        cout << "Masukan Pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1 :MenuP.ukuran();
                break;
        case 2 : cout << "Masukan Rute (1-5) : "; cin >> RutePesawat;
                MenuP.rute(RutePesawat);
                break;
        case 3 :jenis.vip();
                break;
        default :cout << "Pilihan Tidak Di Temukan \n";
                break;
        }
    } while (pilihan != 4);

    cout << "Terimakasih Dan Datang Kembali" << endl;
    
}