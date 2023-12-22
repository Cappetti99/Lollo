//
// Created by cappe on 13/12/23.
//

#include "Control.h"
#include "ItemController.h"

Control::Control() {

    std::cout << "Control created" << std::endl;

    auto view = new View();
    view->show();


}

void Control::addTask() {

    std::cout << "Control::addTask()" << std::endl;
    ItemController itemController;
    itemController.addItem();


}

void Control::removeTask() {

    std::cout << "Control::removeTask()" << std::endl;

}

void Control::searchTask() {

    std::cout << "Control::searchTask()" << std::endl;
}

void Control::markAsCompleted() {

    std::cout << "Control::markAsCompleted()" << std::endl;
}

void Control::updateView() {

    std::cout << "Control::updateView()" << std::endl;
}
