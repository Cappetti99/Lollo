//
// Created by cappe on 18/12/23.
//

#ifndef LOLLO_ITEMCONTROLLER_H
#define LOLLO_ITEMCONTROLLER_H

#include <wx/wx.h>
#include <iostream>

#include "../Model/ToDoItem.h"
#include "../View/Frame.h"
#include "ItemControllerObserver.h"


class ItemController : public ItemControllerObserver {

public:
    ItemController();

    void addItem(wxString name, wxDateTime date, Priority priority);

    void removeItem();

    void markItemAsCompleted();

    void searchItem();

    virtual void onAddTaskButtonClicked() override;

    void showTask(wxString name, wxDateTime date, Priority priority);

private:
    Frame *frame;

};


#endif //LOLLO_ITEMCONTROLLER_H
