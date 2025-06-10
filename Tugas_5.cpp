#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <shlobj.h>
#include <string>
#include <windows.h>
using namespace std;

string RESET = "\033[0m";
string RED = "\033[31m";
string GREEN = "\033[32m";

void playGameSoundDirect() {
    string soundPath = "C:\\Users\\asus\\Downloads\\lgg.wav";
    if(GetFileAttributesA(soundPath.c_str()) == INVALID_FILE_ATTRIBUTES) {
        cerr << "File suara tidak ditemukan di: " << soundPath << endl;
        return;
    }
    string command = "powershell -c \"(New-Object Media.SoundPlayer '" + soundPath + "').PlaySync()\"";
    int result = system(command.c_str());
}

void playDanaSound() {
    string soundPath = "C:\\Users\\asus\\Downloads\\notif_dana.wav";
    if(GetFileAttributesA(soundPath.c_str()) == INVALID_FILE_ATTRIBUTES) {
        cerr << "File suara tidak ditemukan di: " << soundPath << endl;
        return;
    }
    string command = "powershell -c \"(New-Object Media.SoundPlayer '" + soundPath + "').PlaySync()\"";
    int result = system(command.c_str());
}

void kirimNotifikasiDiscord(string message) {
    string webhook = "https://discord.com/api/webhooks/1378743623050461394/qmi_ZubELDAkIS1YivCOdDMyz8W-YKE3EPTIDgHwVmZ6BJffRjtUJmXx88vU_g5LgR-n";
    string payload = "curl -H \"Content-Type: application/json\" -X POST -d \"{\\\"content\\\":\\\"" + message + "\\\"}\" \"" + webhook + "\"";
    system(payload.c_str());
}

bool tampilkanQRPembayaran(int jumlah) {
    string qrPath = "C:\\Users\\asus\\Downloads\\qr.jpg";
    
    if(GetFileAttributesA(qrPath.c_str()) == INVALID_FILE_ATTRIBUTES) {
        string errorCmd = "powershell -command \"[System.Reflection.Assembly]::LoadWithPartialName('System.Windows.Forms'); "
                        "[System.Windows.Forms.MessageBox]::Show('File QR code tidak ditemukan!', 'Error')\"";
        system(errorCmd.c_str());
        return false;
    }
    
    string command = 
        "powershell -command \""
        "Add-Type -AssemblyName System.Windows.Forms; "
        "$form = New-Object Windows.Forms.Form; "
        "$form.Text = 'Pembayaran Rp" + to_string(jumlah) + "'; "
        "$form.StartPosition = 'CenterScreen'; "
        "$form.Width = 500; "
        "$form.Height = 600; "
        "$form.FormBorderStyle = 'FixedDialog'; "
        "$form.MaximizeBox = $false; "
        
        // Tambahkan gambar QR code
        "$pictureBox = New-Object Windows.Forms.PictureBox; "
        "$pictureBox.Width = 450; "
        "$pictureBox.Height = 450; "
        "$pictureBox.Location = New-Object System.Drawing.Point(20,20); "
        "$pictureBox.SizeMode = [System.Windows.Forms.PictureBoxSizeMode]::Zoom; "
        "$image = [System.Drawing.Image]::FromFile('" + qrPath + "'); "
        "$pictureBox.Image = $image; "
        "$form.Controls.Add($pictureBox); "
        
        // Tambahkan label instruksi
        "$label = New-Object Windows.Forms.Label; "
        "$label.Text = 'Silakan scan QR code di atas untuk melakukan pembayaran Rp" + to_string(jumlah) + "'; "
        "$label.Location = New-Object System.Drawing.Point(20,480); "
        "$label.Width = 450; "
        "$label.Height = 30; "
        "$form.Controls.Add($label); "
        
        // Tambahkan tombol Pembayaran Selesai
        "$button = New-Object Windows.Forms.Button; "
        "$button.Text = 'Pembayaran Selesai'; "
        "$button.Location = New-Object System.Drawing.Point(180,520); "
        "$button.Width = 150; "
        "$button.Height = 30; "
        "$button.DialogResult = [System.Windows.Forms.DialogResult]::OK; "
        "$form.AcceptButton = $button; "
        "$form.Controls.Add($button); "
        
        // Tampilkan form dan tangkap hasilnya
        "if ($form.ShowDialog() -eq 'OK') { "
        "    [System.Windows.Forms.MessageBox]::Show('Pembayaran Rp" + to_string(jumlah) + " berhasil dikonfirmasi!', 'Sukses'); "
        "    exit 0 "
        "} else { "
        "    exit 1 "
        "}\"";
    
    int result = system(command.c_str());
    return (result == 0);
}

class Permainan {
protected:
    string namaPemain;
    int saldo;

public:
    Permainan(string nama, int saldoAwal) : namaPemain(nama), saldo(saldoAwal) {}

    virtual void mainkan() {};

    int getSaldo() {
        return saldo;
    }
};

class MesinSlot : public Permainan {
private:
    int taruhan, opsi, kerugian, totalTaruhan, saldoSebelum, totalKerugian;
    int jumlahSpin = 0;
    int totalMenang = 0;
    char lanjut;
    string simbols[6] = {"🤑", "👾", "🔥", "⭐", "💎", "🚀"};

public:
    MesinSlot(string nama, int saldo) : Permainan(nama, saldo) {}

    void mainkan() override {
        while (true) {
            system("cls");
            cout << "============== MENU KASINO ==============\n";
            cout << "Selamat datang di Mesin Slot, " << namaPemain << "!\n";
            cout << "Saldo Anda : Rp" << saldo << endl;
            cout << "=========================================\n";
            cout << "1. Spin 1x                               \n";
            cout << "2. Spin 10x                              \n";
            cout << "3. Spin 20x                              \n";
            cout << "4. Spin 30x                              \n";
            cout << "5. Keluar                                \n";
            cout << "=========================================\n";
            cout << "Pilih opsi : ";
            cin >> opsi;

            if (opsi == 5){
                cout << "\nAnda keluar menu mesin slot\n";
                break;
            } else if (opsi < 1 || opsi > 5) {
                cout << "\nPilihan tidak valid.\n";
                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
                continue;
            }

            system("cls");
            cout << "Masukkan taruhan per sekali spin : ";
            cin >> taruhan;

            if (taruhan <= 0) {
                cout << "\nTaruhan tidak valid.\n";
                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
                continue;
            }

            cout << "\nTekan tombol apa pun untuk melanjutkan : ";
            system("pause > nul");

            switch (opsi) {
                case 1: jumlahSpin = 1; 
                        break;
                case 2: jumlahSpin = 10; 
                        break;
                case 3: jumlahSpin = 20; 
                        break;
                case 4: jumlahSpin = 30; 
                        break;
                default:
                    cout << "Opsi tidak tersedia.\n";
                    cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                    system("pause > nul");
                    continue;
            }

            totalTaruhan = taruhan * jumlahSpin;

            if (totalTaruhan > saldo) {
                system("cls");
                cout << "Saldo tidak mencukupi untuk " << jumlahSpin << " spin.\n";
                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
                continue;
            }

            system("cls");
            cout << "========== Lets Go Gambling ==========\n";
            playGameSoundDirect();

            totalMenang = 0;
            saldoSebelum = saldo;

            for (int i = 0; i < jumlahSpin; i++) {
                int idx1 = rand() % 6;
                int idx2 = rand() % 6;
                int idx3 = rand() % 6;

                string g1 = simbols[idx1];
                string g2 = simbols[idx2];
                string g3 = simbols[idx3];

                cout << "\nSpin " << (i + 1) << " : " << g1 << " " << g2 << " " << g3;

                if (g1 == g2 && g2 == g3) {
                    int menang = taruhan * 10;
                    cout << "  => Menang Rp " << GREEN << "+" << menang << RESET << endl;
                    totalMenang += menang;
                } else {
                    cout << "  => Kalah Rp " << RED << "-" << taruhan << RESET << endl;
                }
            }

            cout << "\n=====================================\n";
            cout << "\nTekan tombol apa pun untuk melanjutkan : ";
            system("pause > nul");

            system("cls");
            saldo -= totalTaruhan;
            saldo += totalMenang;
            totalKerugian = saldoSebelum - saldo;

            cout << "============= Hasil Permainan =============\n";
            cout << "Total taruhan  : Rp" << totalTaruhan << endl;
            cout << "Total kemenang : Rp" << GREEN << "+" << totalMenang << RESET << endl;
            cout << "Total kerugian : Rp" << RED << "-" << totalKerugian << RESET << endl;
            cout << "Saldo sekarang : Rp" << saldo << endl;
            cout << "===========================================\n";

            kerugian = saldoSebelum - saldo;
            if (kerugian > 0) {
                string pesan = "Pemain " + namaPemain + " mengalami kerugian sebesar Rp" + to_string(kerugian) + " di Mesin Slot.";
                kirimNotifikasiDiscord(pesan);
            }

            if (saldo <= 0) {
                cout << "\nSaldo Anda habis. Permainan berakhir.\n";
                break;
            }

            cout << "\nMain lagi (y/n) : ";
            cin >> lanjut;

            if (lanjut != 'y' && lanjut != 'Y'){
                break;
            }
        }
    }
};

class Dadu : public Permainan {
private:
    int taruhan, opsi, totalTaruhan, jumlahLempar, saldoSebelum;
    int totalKerugian = 0, totalKemenangan = 0;
    char lanjut;

public:
    Dadu(string nama, int saldo) : Permainan(nama, saldo) {}

    void mainkan() override {
        while (true) {
            totalKerugian = 0;
            totalKemenangan = 0;

            system("cls");
            cout << "============== MENU KASINO ==============\n";
            cout << "Selamat datang di Permainan Dadu, " << namaPemain << "!\n";
            cout << "Saldo Anda : Rp" << saldo << endl;
            cout << "=========================================\n";
            cout << "1. Lempar 1x                             \n";
            cout << "2. Lempar 5x                             \n";
            cout << "3. Lempar 10x                            \n";
            cout << "4. Lempar 20x                            \n";
            cout << "5. Keluar                                \n";
            cout << "=========================================\n";
            cout << "Pilih opsi : ";
            cin >> opsi;

            if (opsi == 5) {
                cout << "\nAnda keluar menu permainan dadu\n";
                break;
            } else if (opsi < 1 || opsi > 5) {
                cout << "\nPilihan tidak valid.\n";
                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
                continue;
            }

            system("cls");
            cout << "Masukkan taruhan per lemparan : ";
            cin >> taruhan;

            if (taruhan <= 0) {
                cout << "\nTaruhan tidak valid.\n";
                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
                continue;
            }

            cout << "\nTekan tombol apa pun untuk melanjutkan : ";
            system("pause > nul");

            switch (opsi) {
                case 1: jumlahLempar = 1; 
                        break;
                case 2: jumlahLempar = 5; 
                        break;
                case 3: jumlahLempar = 10; 
                        break;
                case 4: jumlahLempar = 20; 
                        break;
                default:
                    cout << "Opsi tidak tersedia.\n";
                    cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                    system("pause > nul");
                    continue;
            }

            totalTaruhan = taruhan * jumlahLempar;

            if (totalTaruhan > saldo) {
                system("cls");
                cout << "Saldo tidak mencukupi untuk " << jumlahLempar << " lemparan.\n";
                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
                continue;
            }

            system("cls");
            cout << "========== Lets Go Gambling ==========\n";
            playGameSoundDirect();
            
            saldoSebelum = saldo;

            for (int i = 0; i < jumlahLempar; i++) {
                int daduPemain = rand() % 6 + 1;
                int daduKasino = rand() % 6 + 1;

                cout << "\nLemparan " << i + 1 << " : ";
                cout << "Anda: " << daduPemain << " | Kasino: " << daduKasino;

                if (daduPemain > daduKasino) {
                    cout << " => Menang Rp " << GREEN << "+" << taruhan << RESET;
                    saldo += taruhan;
                    totalKemenangan += taruhan;
                } else if (daduPemain < daduKasino) {
                    cout << " => Kalah Rp " << RED << "-" << taruhan << RESET;
                    saldo -= taruhan;
                    totalKerugian += taruhan;
                } else {
                    cout << " => Seri";
                }
                cout << endl;
            }

            cout << "\n=====================================\n";
            cout << "\nTekan tombol apa pun untuk melanjutkan : ";
            system("pause > nul");

            system("cls");
            cout << "============= Hasil Permainan =============\n";
            cout << "Total taruhan    : Rp" << totalTaruhan << endl;
            cout << "Total kemenangan : Rp" << GREEN << "+" << totalKemenangan << RESET << endl;
            cout << "Total kerugian   : Rp" << RED << "-" << totalKerugian << RESET << endl;
            cout << "Saldo sekarang   : Rp" << saldo << endl;
            cout << "===========================================\n";

            if (totalKerugian > 0) {
                string pesan = "Pemain " + namaPemain + " mengalami kerugian sebesar Rp" + to_string(totalKerugian) + " di permainan Dadu.";
                kirimNotifikasiDiscord(pesan);
            }

            if (saldo <= 0) {
                cout << "\nSaldo Anda habis. Permainan berakhir.\n";
                break;
            }

            cout << "\nMain lagi (y/n) : ";
            cin >> lanjut;
            if (lanjut != 'y' && lanjut != 'Y') {
                break;
            }
        }
    }
};

int main() {
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8);
    string nama;
    int saldoAwal, pilihan, tambahSaldo;

    system("cls");
    cout << "============ MENU AKUN ============\n";
    cout << "Masukkan nama Anda : ";
    cin >> nama;
    cout << "Masukkan saldo awal (Rp) : ";
    cin >> saldoAwal;
    cout << "===================================\n";
    cout << "\nTekan tombol apa pun untuk melanjutkan : ";
    system("pause > nul");

    Permainan* permainan = nullptr;

    do {
        system("cls");
        cout << "===== MENU KASINO =====\n";
        cout << "1. Main Mesin Slot     \n";
        cout << "2. Main Dadu           \n";
        cout << "3. Isi Saldo           \n";
        cout << "4. Keluar              \n";
        cout << "=======================\n";
        cout << "Pilih permainan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                system("cls");
                permainan = new MesinSlot(nama, saldoAwal);
                permainan->mainkan();
                saldoAwal = permainan->getSaldo();
                delete permainan;
                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
                break;

            case 2:
                system("cls");
                permainan = new Dadu(nama, saldoAwal);
                permainan->mainkan();
                saldoAwal = permainan->getSaldo();
                delete permainan;
                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
                break;

            case 3:
                system("cls");
                cout << "=========== MENU ISI DANA ===========\n";
                cout << "Saldo Anda saat ini : Rp" << saldoAwal << endl;
                cout << "=====================================\n";
                cout << "Masukkan jumlah saldo yang ingin ditambahkan : ";
                cin >> tambahSaldo;
                cout << endl;

                if (tambahSaldo > 0) {
                    if (tampilkanQRPembayaran(tambahSaldo)) {
                        playDanaSound();
                        cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                        system("pause > nul");
                        system("cls");
                        saldoAwal += tambahSaldo;
                        cout << "=============== HASIL TRANSAKSI ===============\n";
                        cout << "Saldo berhasil ditambahkan Rp" << GREEN << "+" << tambahSaldo << RESET << endl;
                        cout << "Saldo Anda sekarang: Rp" << saldoAwal << endl;
                        cout << "===============================================\n";
                    } else {
                        cout << "\nPembayaran dibatalkan atau gagal.\n";
                    }
                } else {
                    cout << "Jumlah saldo tidak valid." << endl;
                }

                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
                break;

            case 4:
                system("cls");
                cout << "Terima kasih telah bermain di kasino.\n";
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
                cout << "\nTekan tombol apa pun untuk melanjutkan : ";
                system("pause > nul");
        }
    } while (pilihan != 4);
}