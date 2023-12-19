//
// Created by cappe on 13/12/23.
//

#include "Control.h"

//wxBEGIN_EVENT_TABLE(Frame, wxFrame)
//                EVT_BUTTON(ID_AddTaskButton, Model::addTask)
//                EVT_BUTTON(ID_RemoveTaskButton, Model::removeTask)
//                EVT_BUTTON(ID_SearchTaskButton, Model::searchTask)
//wxEND_EVENT_TABLE()

Control::Control(ToDoList model, View view) {
    view.show();

//    Bind(wxEVT_BUTTON, &Control::addTask, this, ID_AddTaskButton);
//    Bind(wxEVT_BUTTON, &Control::removeTask, this, ID_RemoveTaskButton);

}

void Control::addTask() {

}

void Control::removeTask() {

}

void Control::searchTask() {

}

void Control::markAsCompleted() {

}

void Control::updateView() {

}
