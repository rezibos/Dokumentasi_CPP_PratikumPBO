#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"
using namespace std;

int main()
{
    SiswaModel *siswa = new SiswaModel("Andi", 16);
    IView *view = new SiswaView();
    IController *controller = new SiswaController(siswa, view);

    controller->tampilkan();

    controller->updateNama("Budi");
    controller->updateUmur(18);

   cout << "\nSetelah diperbarui:\n";
    controller->tampilkan();

    delete controller;
    delete view;
    delete siswa;

    return 0;
}
