#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"
using namespace std;

int main()
{
    string awal = "Andi";
    SiswaModel *siswa = new SiswaModel(awal, 16);
    IView *view = new SiswaView();
    IController *controller = new SiswaController(siswa, view);

    controller->tampilkan();

    string baru = "Budi";
    controller->updateNama(baru);
    controller->updateUmur(18);

    cout << "\nSetelah diperbarui:\n";
    controller->tampilkan();

    delete controller;
    delete view;
    delete siswa;
}

