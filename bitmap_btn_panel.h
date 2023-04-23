#ifndef LTYY_BITMAP_BTN_PANEL_H_
#define LTYY_BITMAP_BTN_PANEL_H_

#include <wx/wx.h>
#include <wx/sizer.h>
#include "side_tab_switcher.h"

class BitmapBtnPanel : public wxPanel {
public:
    BitmapBtnPanel(wxFrame* parent, wxString file, wxBitmapType format, wxSize size, wxString text,SideTabSwitcher::Section section);
    void PaintEvent(wxPaintEvent & evt);
    void PaintNow();
    void Render(wxDC& dc);

    void MouseDown(wxMouseEvent& event);
    DECLARE_EVENT_TABLE()

private:
    wxBitmap image_;
    wxString text_;
    wxSize size_;
    SideTabSwitcher::Section section_;

    wxFrame* parent_;

    // some useful events
    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */
    
};





#endif // LTYY_BITMAP_BTN_PANEL_H_