//
// Created by cappe on 14/12/23.
//

#ifndef LOLLO_FRAME_H
#define LOLLO_FRAME_H

#include <wx/wx.h>

class Frame : public wxFrame{
public:
    Frame(const wxString& title, const wxPoint& pos, const wxSize& size);

wxDECLARE_EVENT_TABLE();

private:
    //gestione bottoni
    void addTaskButton(wxCommandEvent& event);
    void removeTaskButton(wxCommandEvent& event);
    void searchTaskButton(wxCommandEvent& event);


};


enum{
    ID_AddTaskButton = 1,
    ID_RemoveTaskButton = 2,
    ID_SearchTaskButton = 3,
    ID_SortTaskButton = 4
};

#endif //LOLLO_FRAME_H
