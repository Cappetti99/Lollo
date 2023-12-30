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

//    wxMessageBox(frame->getNames());
//    wxMessageBox(frame->getDates().FormatISODate());

    addItem(frame->getNames(), frame->getDates(), frame->getPriorities());
    //probabilmente potremmo fare tutto qui, senza passare da un'altra funzione

}

void ItemController::addItem(wxString name, wxDateTime date, Priority priority) {

    std::cout << "ItemController::addItem()" << std::endl;

    auto item = new ToDoItem(name, date, priority);
//    if(item->isCompleted()){
//    ci va un controllo per il fatto se è completata o no
//    }
    showTask( name, date, priority );
}

void ItemController::removeItem() {

}

void ItemController::markItemAsCompleted() {

}

void ItemController::searchItem() {

}

void ItemController::showTask(wxString name, wxDateTime date, Priority priority) {

    //farla vedere sul frame
    frame->showTaskFrame(name, date, priority);

}
