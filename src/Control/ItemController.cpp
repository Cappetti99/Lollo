//
// Created by cappe on 18/12/23.
//

#include "ItemController.h"

ItemController::ItemController() {

}

void ItemController::addItem(wxString name, wxDateTime date, Priority priority) {

    std::cout << "ItemController::addItem()" << std::endl;

    auto item = new ToDoItem(name, date, priority);
}

void ItemController::removeItem() {

}

void ItemController::markItemAsCompleted() {

}

void ItemController::searchItem() {

}
