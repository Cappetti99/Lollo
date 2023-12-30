//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_TODOITEM_H
#define LOLLO_TODOITEM_H

#include <wx/wx.h>
#include "../View/Priority.h"
#include "Task.h"


class ToDoItem {

private:
    wxString name;
    wxDateTime date;
    bool isCompleted;
    Priority priority;
    //int priority; // 0 = low, 1 = medium, 2 = high
    int index;

public:
    ToDoItem( wxString name, wxDateTime date, Priority priority );
    wxString getName();
    int getPriority();
    bool getIsCompleted();
    void setIsCompleted(bool isCompleted);
    void setName(wxString name);
    void setPriority(int priority);


};


#endif //LOLLO_TODOITEM_H
