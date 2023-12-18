//
// Created by cappe on 13/12/23.
//

#include "ToDoItem.h"

ToDoItem::ToDoItem(wxString name, wxString description, int priority) {
    this->name = name;
    this->description = description;
    this->priority = priority;
    this->isCompleted = false;
}

wxString ToDoItem::getName() {
    return this->name;
}

wxString ToDoItem::getDescription() {
    return this->description;
}

int ToDoItem::getPriority() {
    return this->priority;
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

void ToDoItem::setDescription(wxString description) {
    this->description = description;
}

void ToDoItem::setPriority(int priority) {
    this->priority = priority;
}

wxString ToDoItem::getDate() {
    return this->date;
}

void ToDoItem::setDate(wxString date) {
    this->date = date;
}
