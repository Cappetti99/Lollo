//
// Created by cappe on 13/12/23.
//

#ifndef LOLLO_TODOAPP_H
#define LOLLO_TODOAPP_H

#include <wx/wx.h>
#include "Frame.h"

class ToDoApp : public wxApp{

public:
    ToDoApp();

    virtual bool OnInit();

private:
    wxFrame *frame;

};


#endif //LOLLO_TODOAPP_H
