//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_TODOITEM_H
#define LOLLO_TODOITEM_H

#include <wx/wx.h>


class ToDoItem {

private:
    wxString name;
    wxString description;
    wxString date;
    bool isCompleted;
    int priority; // 0 = low, 1 = medium, 2 = high
    int index;

public:
    ToDoItem(wxString name, wxString description, int priority);
    wxString getName();
    wxString getDescription();
    int getPriority();
    bool getIsCompleted();
    void setIsCompleted(bool isCompleted);
    void setName(wxString name);
    void setDescription(wxString description);
    void setPriority(int priority);

    wxString getDate();
    void setDate(wxString date);

};


#endif //LOLLO_TODOITEM_H
