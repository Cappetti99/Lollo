//
// Created by cappe on 18/12/23.
//

#include "ItemController.h"


ItemController::ItemController() {

    frame = new Frame( "ToDoList", wxPoint(800, 600), wxSize(450, 340), this);
    frame->Show( true );

}

void ItemController::onAddTaskButtonClicked() {

    std::cout << "ItemController::onAddTaskButtonClicked()" << std::endl;

    wxMessageBox(frame->getNames());
    wxMessageBox(frame->getDates().FormatISODate());

}

void ItemController::addItem(wxString name, wxDateTime date, Priority priority) {

//    std::cout << "ItemController::addItem()" << std::endl;
//
//    auto item = new ToDoItem(name, date, priority);
}

void ItemController::removeItem() {

}

void ItemController::markItemAsCompleted() {

}

void ItemController::searchItem() {

}
