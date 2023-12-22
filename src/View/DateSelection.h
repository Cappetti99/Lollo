//
// Created by cappe on 22/12/23.
//

#ifndef LOLLO_DATESELECTION_H
#define LOLLO_DATESELECTION_H

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>


class DateSelection : public wxDialog {

public:
    DateSelection(wxWindow* parent, wxWindowID id = wxID_ANY, const wxDateTime& dt = wxDefaultDateTime,
    const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDP_DEFAULT);


};


#endif //LOLLO_DATESELECTION_H
