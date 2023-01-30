#ifndef LTYY_HOME_FRAME_H_
#define LTYY_HOME_FRAME_H_

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "frame_event.h"

enum
{
    ID_Hello = 1
};

class HomeFrame : public wxFrame,
                  public FramePositionEvent {
public:
    HomeFrame();
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    // FramePositionEvent
    void OnActiveEvent(wxEvent& event) override;

    void OnCustomerDashBoard(wxCommandEvent& event);
};

#endif // LTYY_HOME_FRAME_H_