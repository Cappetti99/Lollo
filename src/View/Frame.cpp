//
// Created by cappe on 14/12/23.
//

#include "Frame.h"
#include "../Control/Control.h"

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
                EVT_BUTTON(ID_AddTaskButton, Frame::addTaskButton)
                EVT_BUTTON(ID_RemoveTaskButton, Frame::removeTaskButton)
                EVT_BUTTON(ID_SearchTaskButton, Frame::searchTaskButton)
wxEND_EVENT_TABLE()

//potrei fare che nel costruttore rimanda a delle funzioni che creano bottoni e gestiscono la cosa mandandola al controller


Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) {

    std::cout << "Frame created" << std::endl;

    auto buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    taskTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                       wxTE_PROCESS_ENTER);

    auto taskListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);

    //bottoni
    auto addButton = new wxButton(this, ID_AddTaskButton, "Add Task");
    auto removeButton = new wxButton(this, ID_RemoveTaskButton, "Remove Task");
    auto searchButton = new wxButton(this, ID_SearchTaskButton, "Search Tasks");
    //auto sortButton = new wxButton(this, wxID_ANY, "Sort Tasks");


    buttonsSizer->Add(addButton, 5, wxALL, 10);
    buttonsSizer->Add(removeButton, 5, wxALL, 10);
    buttonsSizer->Add(searchButton, 5, wxALL, 10);
    //buttonsSizer->Add(sortButton, 5, wxALL, 10); sort?

    auto mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(buttonsSizer, 0, wxALIGN_CENTER | wxTOP, 20);
    mainSizer->Add(taskTextCtrl, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(taskListBox, 1, wxEXPAND | wxALL, 10);

    SetSizerAndFit(mainSizer);

    SetSize(wxSize(800, 600));
}

void Frame::addTaskButton(wxCommandEvent &event) {
    std::cout << "addTaskButton" << std::endl;
    wxString name = taskTextCtrl->GetValue();

    Control::addTask(name);
}

void Frame::removeTaskButton(wxCommandEvent &event) {

    std::cout << "removeTaskButton" << std::endl;
    Control::removeTask();
}

void Frame::searchTaskButton(wxCommandEvent &event) {

    std::cout << "searchTaskButton" << std::endl;
    Control::searchTask();
}

