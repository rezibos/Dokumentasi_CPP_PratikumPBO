#ifndef VIEW_HPP
#define VIEW_HPP

#include "model.hpp"

using namespace std;

class IView
{
public:
    virtual void tampilkan(const IModel &model) = 0;
    virtual ~IView() {}
};

class SiswaView : public IView
{
public:
    void tampilkan(const IModel &model) override
    {
        cout << model.getInfo() << endl;
    }
};

#endif
