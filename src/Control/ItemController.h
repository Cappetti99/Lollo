//
// Created by cappe on 18/12/23.
//

#ifndef LOLLO_ITEMCONTROLLER_H
#define LOLLO_ITEMCONTROLLER_H

#include <wx/wx.h>

class ItemController {

public:
    ItemController();
    void addItem(wxString name, wxDateTime date);
    void removeItem();
    void markItemAsCompleted();
    void searchItem();

};


#endif //LOLLO_ITEMCONTROLLER_H
