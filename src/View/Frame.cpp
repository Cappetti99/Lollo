//
// Created by cappe on 14/12/23.
//

#include "Frame.h"


wxBEGIN_EVENT_TABLE(Frame, wxFrame)
                EVT_BUTTON(ID_AddTaskButton, Frame::addTaskButton)
                EVT_BUTTON(ID_RemoveTaskButton, Frame::removeTaskButton)
                EVT_BUTTON(ID_SearchTaskButton, Frame::searchTaskButton)
wxEND_EVENT_TABLE()

//potrei fare che nel costruttore rimanda a delle funzioni che creano bottoni e gestiscono la cosa mandandola al controller


Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size, ItemControllerObserver *observer)
        : wxFrame(NULL, wxID_ANY, title, pos, size), observer(observer) {

    std::cout << "Frame created" << std::endl;

    auto buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    taskTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                  wxTE_PROCESS_ENTER);

    taskListBox = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);

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
    DateSelection dateSelection(this, "Select expiration date:");
    if (!name.IsEmpty()) {
        if (dateSelection.ShowModal() == wxID_OK) {
            wxDateTime dateTime = dateSelection.getDatePicker()->GetValue();
            PrioritySelection prioritySelection(this, "Select priority:");
            if (prioritySelection.ShowModal() == wxID_OK) {
                Priority priority = prioritySelection.getSelectedPriority();
                names.push_back(name);
                dates.push_back(dateTime);
                priorities.push_back(priority);
                taskTextCtrl->Clear();
            }
        }
    }

    if (observer) {
        observer->onAddTaskButtonClicked();
    }
}


void Frame::removeTaskButton(wxCommandEvent &event) {

    std::cout << "removeTaskButton" << std::endl;
}

void Frame::searchTaskButton(wxCommandEvent &event) {

    std::cout << "searchTaskButton" << std::endl;
}

wxString Frame::getNames() {

    wxString name;
    if (!names.empty()) {
        name = names.back();
        names.pop_back();
    }
    return name;
}

wxDateTime Frame::getDates() {
    wxDateTime date;
    if (!dates.empty()) {
        date = dates.back();
        dates.pop_back();
    }
    return date;
}

Priority Frame::getPriorities() {
    Priority priority;
    if (!priorities.empty()) {
        priority = priorities.back();
        priorities.pop_back();
    }
    return priority;
}

void Frame::showTaskFrame(wxString name, wxDateTime date, Priority priority) {

//    wxString taskString = task.getTitle() + " - Priority: " + priorityStr +
//                          " - " + task.getExpirationDate().Format("%d %B, %Y");
//    taskCheckBox->Append(taskString);

    wxString priorityString;

    if (priority == Priority::High) {
        priorityString = "HIGH";
    } else if (priority == Priority::Medium) {
        priorityString = "MEDIUM";
    } else if (priority == Priority::Low) {
        priorityString = "LOW";
    }

    wxString taskString = name + " - Priority: " + priorityString +
                          " - " + date.Format("%d %B, %Y");

    taskListBox->Append(taskString);

}



