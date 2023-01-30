#ifndef LTYY_CUSTOMER_FRAME_H_
#define LTYY_CUSTOMER_FRAME_H_

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "frame_event.h"

class CustomerFrame : public wxFrame,
                      public FramePositionEvent {
public:
    CustomerFrame();

    // FramePositionEvent
    void OnActiveEvent(wxEvent& event) override;
};

#endif // LTYY_CUSTOMER_FRAME_H_