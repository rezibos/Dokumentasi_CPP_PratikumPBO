#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "model.hpp"
#include "view.hpp"

using namespace std;

class IController {
public:
    virtual void updateData() = 0;
    virtual void tampilkan() = 0;
    virtual ~IController() {}
};

class SiswaController : public IController {
private:
    IModel* model;
    IView* view;

public:
    SiswaController(IModel* m, IView* v) : model(m), view(v) {}

    void updateData() override {
        view->dapatkanInput(*model);
    }

    void tampilkan() override {
        view->tampilkan(*model);
    }
};

#endif