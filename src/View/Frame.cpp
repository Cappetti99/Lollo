//
// Created by cappe on 14/12/23.
//

#include "Frame.h"


wxBEGIN_EVENT_TABLE(Frame, wxFrame
)
EVT_BUTTON(ID_AddTaskButton, Frame::addTaskButton
)
EVT_BUTTON(ID_RemoveTaskButton, Frame::removeTaskButton
)
EVT_BUTTON(ID_SearchTaskButton, Frame::searchTaskButton
)

//EVT_BUTTON(ID_SortTaskButton, Frame::sortTaskButton)
wxEND_EVENT_TABLE()


Frame::Frame(const wxString &title, const wxPoint &pos, const wxSize &size, ItemControllerObserver *observer)
        : wxFrame(NULL, wxID_ANY, title, pos, size), observer(observer) {

    std::cout << "Frame created" << std::endl;


    auto buttonsSizer = new wxBoxSizer(wxHORIZONTAL);

    taskTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize,
                                  wxTE_PROCESS_ENTER);

    taskListBox = new wxCheckListBox(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE);

    //bottoni
    auto addButton = new wxButton(this, ID_AddTaskButton, "Add Task");
    auto removeButton = new wxButton(this, ID_RemoveTaskButton, "Remove Task");
    auto searchButton = new wxButton(this, ID_SearchTaskButton, "Search Tasks");
    //auto sortButton = new wxButton(this, wxID_ANY, "Sort Tasks");

    searchInput = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

    buttonsSizer->Add(addButton, 5, wxALL, 10);
    buttonsSizer->Add(removeButton, 5, wxALL, 10);
    buttonsSizer->Add(searchButton, 5, wxALL, 10);
    //buttonsSizer->Add(sortButton, 5, wxALL, 10); sort?
    buttonsSizer->Add(searchInput, 5, wxALL, 10);

    auto mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(buttonsSizer, 0, wxALIGN_CENTER | wxTOP, 20);
    mainSizer->Add(taskTextCtrl, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(taskListBox, 1, wxEXPAND | wxALL, 10);

    SetSizerAndFit(mainSizer);

    SetSize(wxSize(800, 600));


}

void Frame::addTaskButton(wxCommandEvent &event) { //fixme c'è da sistemare delle casistiche
//    std::cout << "addTaskButton" << std::endl;
    //controllo che non sia vuoto
    if (taskTextCtrl->IsEmpty()) {
        wxMessageBox("Inserisci un task!");
        return;
    }

    wxString name = taskTextCtrl->GetValue();
    DateSelection dateSelection(this, "Select expiration date:");
    if (!name.IsEmpty()) {
        if (dateSelection.ShowModal() == wxID_OK) {
            wxDateTime dateTime = dateSelection.getDatePicker()->GetValue();
            //fai un controllo in modo che non abbia una data passata
            if (dateTime.IsEarlierThan(wxDateTime::Now() - wxTimeSpan::Days(1))) {
                //tolgo un giorno perche' sennò da problemi con oggi
                wxMessageBox("Hai inserito una data passata!");
                return;
            } //gestire il cancel

            PrioritySelection prioritySelection(this, "Select priority:");
            if (prioritySelection.ShowModal() == wxID_OK) {
                Priority priority = prioritySelection.getSelectedPriority();
                if (priority == Priority::None) {
                    wxMessageBox("Inserisci una priorità!");
                    return;
                }

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

    int selectedIndex = taskListBox->GetSelection();
    if (selectedIndex != wxNOT_FOUND) {
        wxMessageDialog confirmDialog(this,
                                      "Sei sicuro di volerla eliminare?", "Conferma eliminazione",
                                      wxYES_NO | wxICON_QUESTION);

        int response = confirmDialog.ShowModal();

        if (response == wxID_YES) {
            if (observer) {
                observer->onRemoveTaskButtonClicked(selectedIndex);
            }
        }
    }
}

void Frame::searchTaskButton(wxCommandEvent &event) {

//    std::cout << "searchTaskButton" << std::endl;

    wxString searchKeyword = searchInput->GetValue();

//    if (searchKeyword.IsEmpty() || searchKeyword == " ") {
//        wxMessageBox("Inserisci una parola chiave!");
//        return;
//    } //l'ho tolta perchè si visualizzano tutte senza scrivere niente sulla barra

    if (observer) {
        observer->onSearchTaskButtonClicked(searchKeyword);
    }

}

wxString Frame::getNames() {

    wxString name;
    if (!names.empty()) {
        name = names.back();
    }
    return name;
}

wxDateTime Frame::getDates() {
    wxDateTime date;
    if (!dates.empty()) {
        date = dates.back();
    }
    return date;
}

Priority Frame::getPriorities() {
    Priority priority;
    if (!priorities.empty()) {
        priority = priorities.back();
    }
    return priority;
}

void Frame::showTaskFrame(wxString name, wxDateTime date, Priority priority) {

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

void Frame::ClearFrame() {
    taskListBox->Clear();
}

void Frame::showSearchFrame(wxString name, wxDateTime date, Priority priority) {

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

void Frame::removeTaskFrame(int index) {

//    std::cout << "Frame::removeTaskFrame()" << std::endl;

    names.erase(names.begin() + index);
    dates.erase(dates.begin() + index);
    priorities.erase(priorities.begin() + index);

//    std::cout << "names.size() = " << names.size() << std::endl;


    refreshTaskFrame();

}

void Frame::refreshTaskFrame() {

//    std::cout << "Frame::refreshTaskFrame()" << std::endl;

    ClearFrame();
    for (int i = 0; i < names.size(); i++) {
        showTaskFrame(names[i], dates[i], priorities[i]);
    }
}
