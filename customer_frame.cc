#include "customer_frame.h"
#include "preference.h"
#include <wx/gdicmn.h>
#include "frame_displayer.h"

CustomerFrame::CustomerFrame() : wxFrame(
    nullptr,
    wxID_ANY,
    "顾客信息操作面板",
    FrameDisplayer::Get().GetNextPosition(),
    wxSize(Preference::Get().GetSize().width,Preference::Get().GetSize().height)) {
    Bind(wxEVT_ACTIVATE,&CustomerFrame::OnActiveEvent, this);
}

// FramePositionEvent
void CustomerFrame::OnActiveEvent(wxEvent& event){
    wxPoint point = this->GetPosition();
    FrameDisplayer::Get().SetCurrentActivePosition(point);
}
