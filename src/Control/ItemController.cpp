//
// Created by cappe on 18/12/23.
//

#include <iostream>
#include "ItemController.h"
#include "../Model/ToDoItem.h"

ItemController::ItemController() {

}

void ItemController::addItem(wxString name, wxDateTime date) {

    std::cout << "ItemController::addItem()" << std::endl;


    auto item = new ToDoItem(name, date);
}

void ItemController::removeItem() {

}

void ItemController::markItemAsCompleted() {

}

void ItemController::searchItem() {

}
