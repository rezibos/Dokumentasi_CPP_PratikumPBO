#ifndef controller_h
#define controller_h

#include "model.h"
#include "view.h"

class StudentController {
private:
    StudentModel* model;
    StudentView* view;

public:
    StudentController(StudentModel* model, StudentView* view) : model(model), view(view) {}

    void setStudentName(string& name) {
        model->setName(name);
    }

    void setStudentAge(int age) {
        model->setAge(age);
    }

    string getStudentName() {
        return model->getName();
    }

    int getStudentAge() {
        return model->getAge();
    }

    void updateView() {
        string tempName = model->getName();
        view->displayStudentDetails(tempName, model->getAge());
    }
};

#endif
