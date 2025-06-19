#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "model.hpp"
#include "view.hpp"
using namespace std;

class IController {
public:
    virtual void updateNama(string &nama) = 0;
    virtual void updateUmur(int umur) = 0;
    virtual void tampilkan() = 0;
    virtual ~IController() {}
};

class SiswaController : public IController {
private:
    SiswaModel *model;
    IView *view;

public:
    SiswaController(SiswaModel *model, IView *view) : model(model), view(view) {}

    void updateNama(string &nama) override {
        model->setNama(nama);
    }

    void updateUmur(int umur) override {
        model->setUmur(umur);
    }

    void tampilkan() override {
        view->tampilkan(*model);
    }
};


#endif