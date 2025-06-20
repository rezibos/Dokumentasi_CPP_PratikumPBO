#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "model.hpp"
#include "view.hpp"

using namespace std;

class ICONTROLLER {
public:
    virtual ~ICONTROLLER() {}
    virtual void tampilkan() = 0;
    virtual void inputBuku() = 0;
};

class MahasiswaController : public ICONTROLLER {
private:
    IMODEL* model;
    IVIEW* view;
    Buku* buku;

public:
    MahasiswaController(IMODEL* m, IVIEW* v, Buku* b) : model(m), view(v), buku(b) {}

    void tampilkan() override {
        view->tampilkan(*model, *buku);
    }
    
    void inputBuku() override {
        view->dapatkanInput(*model, *buku);
    }
};

class DosenController : public ICONTROLLER {
private:
    IMODEL* model;
    IVIEW* view;
    Buku* buku;

public:
    DosenController(IMODEL* m, IVIEW* v, Buku* b) : model(m), view(v), buku(b) {}

    void tampilkan() override {
        view->tampilkan(*model, *buku);
    }
    
    void inputBuku() override {
        view->dapatkanInput(*model, *buku);
    }
};

#endif