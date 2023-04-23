#ifndef LTYY_HOME_FRAME_H_
#define LTYY_HOME_FRAME_H_

#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "frame_event.h"
#include <memory>
#include <wx/listctrl.h>
#include "home_controller.h"
#include "bitmap_btn_panel.h"

enum
{
    ID_Hello = 1
};

class HomeFrame : public wxFrame,
                  public FramePositionEvent {
public:
    HomeFrame();
    HomeController* GetController();
    void RefreshSectionStatus();


private:
    
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    // FramePositionEvent
    void OnActiveEvent(wxEvent& event) override;

    void OnCustomerDashBoard(wxCommandEvent& event);

    void OnPaint(wxPaintEvent& WXUNUSED(event));
private:
    std::unique_ptr<HomeController> controller_;
    std::vector<BitmapBtnPanel*> sections_; 

};

#endif // LTYY_HOME_FRAME_H_