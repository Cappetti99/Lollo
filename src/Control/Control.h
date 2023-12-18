//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_CONTROLL_H
#define LOLLO_CONTROLL_H

#include <wx/wx.h>

#include "../Model/Model.h"
#include "../View/View.h"

class Control {

private:
    Model model;
    View view;

    public:
    Control(ToDoList model, View view);
    void addTask();
    void removeTask();
    void searchTask();
    void markAsCompleted();
    void updateView();
};


#endif //LOLLO_CONTROLL_H
