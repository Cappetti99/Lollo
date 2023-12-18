//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_VIEW_H
#define LOLLO_VIEW_H

#include <wx/wx.h>
#include <wx/wxprec.h>
#include <vector>
#include <wx/listctrl.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/colour.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/checklst.h>
#include <wx/datectrl.h>

#include "../View/ToDoApp.h" //così ho sia ToDoApp che Frame


class View {

public:
    View();
    void show();
    void displayItem(); //cosa fa vedere? serve?


};


#endif //LOLLO_VIEW_H
