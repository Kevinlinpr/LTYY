#include "bitmap_btn_panel.h"
#include "preference.h"
#include <iostream>
#include "home_frame.h"

BEGIN_EVENT_TABLE(BitmapBtnPanel, wxPanel)
// some useful events
/*
 EVT_MOTION(wxImagePanel::mouseMoved)
 EVT_LEFT_DOWN(wxImagePanel::mouseDown)
 EVT_LEFT_UP(wxImagePanel::mouseReleased)
 EVT_RIGHT_DOWN(wxImagePanel::rightClick)
 EVT_LEAVE_WINDOW(wxImagePanel::mouseLeftWindow)
 EVT_KEY_DOWN(wxImagePanel::keyPressed)
 EVT_KEY_UP(wxImagePanel::keyReleased)
 EVT_MOUSEWHEEL(wxImagePanel::mouseWheelMoved)
 */

// catch paint events
EVT_LEFT_DOWN(BitmapBtnPanel::MouseDown)

EVT_PAINT(BitmapBtnPanel::PaintEvent)

END_EVENT_TABLE()

BitmapBtnPanel::BitmapBtnPanel(wxFrame* parent, wxString file, wxBitmapType format, wxSize size, wxString text,SideTabSwitcher::Section section) 
    : wxPanel(parent, wxID_ANY,wxDefaultPosition,wxSize(100,size.GetHeight() + 20)),
      size_(size),
      text_(text),
      parent_(parent),
      section_(section) {
    image_.LoadFile(file, format);
    wxImage tmp = image_.ConvertToImage();

    tmp.Rescale(size.GetWidth(), size.GetHeight(),wxIMAGE_QUALITY_BICUBIC);
    image_ = wxBitmap(tmp);
    if(static_cast<HomeFrame*>(parent_)->GetController()->GetModel()
        ->GetSideTabSwitcher()->GetSection() == section_){
        SetBackgroundColour(wxColour("#000000"));
    }else{
        SetBackgroundColour(wxColour("#181818"));
    }
}

void BitmapBtnPanel::PaintEvent(wxPaintEvent &evt)
{
    wxPaintDC dc(this);
    Render(dc);
}

void BitmapBtnPanel::PaintNow(){
    wxClientDC dc(this);
    HomeFrame* parent = static_cast<HomeFrame*>(parent_);
    if(parent->GetController()->GetModel()
        ->GetSideTabSwitcher()->GetSection() == section_){
        SetBackgroundColour(wxColour("#000000"));
    }else{
        SetBackgroundColour(wxColour("#181818"));
    }
    Render(dc);
}

void BitmapBtnPanel::Render(wxDC& dc){
    dc.DrawBitmap( image_, 16, 8, false );
    dc.DrawText(text_,wxPoint(size_.GetWidth() + 20,13));
}

void BitmapBtnPanel::MouseDown(wxMouseEvent& event) {
    HomeFrame* parent = static_cast<HomeFrame*>(parent_);
    parent->GetController()->GetModel()
        ->GetSideTabSwitcher()->SetSection(section_);
    parent->RefreshSectionStatus();
}