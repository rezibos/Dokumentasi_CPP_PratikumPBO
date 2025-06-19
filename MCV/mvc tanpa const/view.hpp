#ifndef view_HPP
#define view_HPP

#include "model.hpp"
using namespace std;

class IView {
public:
    virtual void tampilkan(IModel &model) = 0;
    virtual ~IView() {}
};

class SiswaView : public IView {
public:
    void tampilkan(IModel &model) override {
        cout << model.getInfo() << endl;
    }
};

#endif
