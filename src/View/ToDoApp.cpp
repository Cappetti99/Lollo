//
// Created by cappe on 13/12/23.
//

#include "ToDoApp.h"
#include "Frame.h"

ToDoApp::ToDoApp() {

}


bool ToDoApp::OnInit() {

    Frame *frame = new Frame( "Hello World", wxPoint(800, 600), wxSize(450, 340) );
    frame->Show( true );
    return true;

//    wxFrame *frame = new wxFrame((wxFrame *) nullptr, -1, wxT("Hello wxWidgets World")); //todo da guardare
//    frame->CreateStatusBar();
//    frame->SetStatusText(wxT("Hello World"));
//
//    frame->Show(true);
//
//    return true;
}

//wxIMPLEMENT_APP(ToDoApp);

