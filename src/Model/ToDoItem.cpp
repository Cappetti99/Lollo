//
// Created by cappe on 13/12/23.
//

#include "ToDoItem.h"

ToDoItem::ToDoItem( wxString name, wxDateTime date, Priority priority /*, int priority*/ ) {
    this->name = name;
    this->date = date;

//    this->description = description;
//    this->priority = priority;
//    this->isCompleted = false;

    std::cout << "item created" << std::endl;
    wxMessageBox(name);
    //wxMessageBox(date);


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


