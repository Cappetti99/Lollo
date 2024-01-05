//
// Created by cappe on 18/12/23.
//

#include "ItemController.h"


ItemController::ItemController() {

    frame = new Frame("ToDoList", wxPoint(800, 600), wxSize(450, 340), this);
    frame->Show(true);

    item = new ToDoItem();

}

void ItemController::onAddTaskButtonClicked() {

    //std::cout << "ItemController::onAddTaskButtonClicked()" << std::endl;

    addItem(frame->getNames(), frame->getDates(), frame->getPriorities());
    //probabilmente potremmo fare tutto qui, senza passare da un'altra funzione

}

void ItemController::addItem(wxString name, wxDateTime date, Priority priority) {

    //std::cout << "ItemController::addItem()" << std::endl;
    item->addTask(name, date, priority);

    showTask(name, date, priority);
}


void ItemController::onRemoveTaskButtonClicked(int index) {

    //std::cout << "ItemController::onRemoveTaskButtonClicked()" << std::endl;

    removeItem(index);

}


void ItemController::removeItem(int index) {

    //std::cout << "ItemController::removeItem()" << std::endl;
    item->removeTask(index);
}

void ItemController::markItemAsCompleted() {

}

void ItemController::searchItem() {

}

void ItemController::showTask(wxString name, wxDateTime date, Priority priority) {

    //farla vedere sul frame
    frame->showTaskFrame(name, date, priority);

}
