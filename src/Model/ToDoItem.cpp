//
// Created by cappe on 13/12/23.
//

#include "ToDoItem.h"

//todo da pensare come collegare la task qui con quella che facciamo vedere nel frame


ToDoItem::ToDoItem(wxString name, wxDateTime date, Priority priority /*, int priority*/ ) {
    this->name = name;
    this->date = date;
    this->priority = priority;
    this->isCompleted = false;

    //std::cout << "item created" << std::endl;

    auto task = new Task(name, priority, isCompleted, date);
//todo da pensare come pushare il task nella lista
}

wxString ToDoItem::getName() {
    return this->name;
}

bool ToDoItem::getIsCompleted() {
    return this->isCompleted;
}

void ToDoItem::setIsCompleted(bool isCompleted) {
    this->isCompleted = isCompleted;
}

void ToDoItem::setName(wxString name) {
    this->name = name;
}

Task ToDoItem::getTask() {
    return Task(name, priority, isCompleted, date);
}

