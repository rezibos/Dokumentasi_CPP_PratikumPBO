#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

using namespace std;

int main() 
{
    MahasiswaModel mhsModel;
    mhsModel.setData("Budi Santoso", 123456, 1);
    
    Buku bukuMhs;
    MahasiswaView mhsView;
    MahasiswaController mhsController(&mhsModel, &mhsView, &bukuMhs);
    
    mhsController.inputBuku();
    mhsController.tampilkan();
    
    
    DosenModel dosenModel;
    dosenModel.setData("Dr. Ahmad Wijaya", 987654, 1);
    
    Buku bukuDosen;
    DosenView dosenView;
    DosenController dosenController(&dosenModel, &dosenView, &bukuDosen);
    
    dosenController.inputBuku();
    dosenController.tampilkan();
}