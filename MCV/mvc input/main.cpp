#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"
using namespace std;

int main()
{
    // Inisialisasi komponen MVC
    IModel* model = new SiswaModel();
    IView* view = new SiswaView();
    IController* controller = new SiswaController(model, view);

    // Input data pertama
    cout << "=== Input Data Siswa ===" << endl;
    controller->updateData();
    
    // Tampilkan data
    cout << "\n=== Data Siswa ===" << endl;
    controller->tampilkan();

    // Opsi update data
    char pilihan;
    cout << "\nUpdate data? (y/n): ";
    cin >> pilihan;
    cin.ignore();

    if (tolower(pilihan) == 'y') {
        cout << "\n=== Update Data ===" << endl;
        controller->updateData();
        
        cout << "\n=== Data Terupdate ===" << endl;
        controller->tampilkan();
    }

    // Cleanup
    delete controller;
    delete view;
    delete model;

    return 0;
}