#include "model.h"
#include "view.h"
#include "controller.h"

int main() {
    // Buat variabel string terlebih dahulu karena konstruktor butuh string&
    string initialName = "Rezi Reziee";

    // Buat objek model dan view
    StudentModel model(initialName, 20);
    StudentView view;

    // Buat controller
    StudentController controller(&model, &view);

    // Tampilkan awal
    controller.updateView();

    // Update data via controller
    string updatedName = "Andi Saputra";
    controller.setStudentName(updatedName);
    controller.setStudentAge(22);

    cout << "\nSetelah update:\n";
    controller.updateView();

    return 0;
}
