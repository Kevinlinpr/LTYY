#include "home_frame.h"
#include "preference.h"
#include "customer.h"
#include "beautician.h"
#include "product.h"
#include "project.h"
#include "activity.h"
#include "order.h"
#include "log.h"
#include "customer_frame.h"
#include "menu_id.h"
#include "frame_displayer.h"
#include "wx/image.h"
#include "wx/file.h"
#include "bitmap_btn_panel.h"

HomeFrame::HomeFrame() : wxFrame(
    nullptr, 
    wxID_ANY, 
    "岚婷雅媛管理系统",
    wxDefaultPosition,
    wxSize(Preference::Get().GetSize().width,Preference::Get().GetSize().height)),
    controller_(new HomeController()) {

    wxInitAllImageHandlers();

    // wxPanel* left_tab = new wxPanel(this, wxID_ANY,wxDefaultPosition,wxSize(100,Preference::Get().GetSize().height));
    // left_tab->SetBackgroundColour(wxColor("#181818"));
    SetBackgroundColour(wxColor("#181818"));

    wxPanel* right_content = new wxPanel(this, wxID_ANY,wxDefaultPosition,wxSize(Preference::Get().GetSize().width,Preference::Get().GetSize().height));
    right_content->SetBackgroundColour(wxColor("#212121"));

    BitmapBtnPanel* customer_icon = new BitmapBtnPanel(this, wxString("/Users/kevinlinpr/LTYY/icon/customer.png"), wxBITMAP_TYPE_PNG, wxSize(26,26),wxString("顾客"),SideTabSwitcher::Section::CUSTOMER);
    BitmapBtnPanel* beautician_icon = new BitmapBtnPanel(this, wxString("/Users/kevinlinpr/LTYY/icon/beautician.png"), wxBITMAP_TYPE_PNG, wxSize(26,26),wxString("美容师"),SideTabSwitcher::Section::BEAUTICIAN);
    BitmapBtnPanel* product_icon = new BitmapBtnPanel(this, wxString("/Users/kevinlinpr/LTYY/icon/product.png"), wxBITMAP_TYPE_PNG, wxSize(26,26),wxString("产品"),SideTabSwitcher::Section::PRODUCT);
    BitmapBtnPanel* project_icon = new BitmapBtnPanel(this, wxString("/Users/kevinlinpr/LTYY/icon/project.png"), wxBITMAP_TYPE_PNG, wxSize(26,26),wxString("项目"),SideTabSwitcher::Section::PROJECT);
    BitmapBtnPanel* activity_icon = new BitmapBtnPanel(this, wxString("/Users/kevinlinpr/LTYY/icon/activity.png"), wxBITMAP_TYPE_PNG, wxSize(26,26),wxString("活动"),SideTabSwitcher::Section::ACTIVITY);
    BitmapBtnPanel* order_icon = new BitmapBtnPanel(this, wxString("/Users/kevinlinpr/LTYY/icon/order.png"), wxBITMAP_TYPE_PNG, wxSize(26,26),wxString("订单"),SideTabSwitcher::Section::ORDER);
    BitmapBtnPanel* log_icon = new BitmapBtnPanel(this, wxString("/Users/kevinlinpr/LTYY/icon/log.png"), wxBITMAP_TYPE_PNG, wxSize(26,26),wxString("日志"),SideTabSwitcher::Section::LOG);
    wxBoxSizer* home_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* left_sizer = new wxBoxSizer(wxVERTICAL);
    left_sizer->Add(customer_icon, 0,wxEXPAND | wxTOP,0);
    left_sizer->Add(beautician_icon, 0,wxEXPAND | wxTOP,0);
    left_sizer->Add(product_icon, 0,wxEXPAND | wxTOP,0);
    left_sizer->Add(project_icon, 0,wxEXPAND | wxTOP,0);
    left_sizer->Add(activity_icon, 0,wxEXPAND | wxTOP,0);
    left_sizer->Add(order_icon, 0,wxEXPAND | wxTOP, 0);
    left_sizer->Add(log_icon, 0,wxEXPAND | wxTOP,0);
    home_sizer->Add(left_sizer);
    home_sizer->Add(right_content, 1,wxEXPAND | wxALL,0);

    sections_.push_back(customer_icon);
    sections_.push_back(beautician_icon);
    sections_.push_back(product_icon);
    sections_.push_back(project_icon);
    sections_.push_back(activity_icon);
    sections_.push_back(order_icon);
    sections_.push_back(log_icon);

    this->SetSizerAndFit(home_sizer);

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    // 顾客
    wxMenu *menuCustomerDashBoard = new wxMenu;
    menuCustomerDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Customer_Detail),"&详情面板");
    menuCustomerDashBoard->AppendSeparator();
    menuCustomerDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Customer_Add),"&注册");
    menuBar->Append(menuCustomerDashBoard, "&顾客");


    // 美容师
    wxMenu *menuBeauticianDashBoard = new wxMenu;
    menuBeauticianDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Beautician_Detail),"&详情面板");
    menuBeauticianDashBoard->AppendSeparator();
    menuBeauticianDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Beautician_Add),"&注册");
    menuBar->Append(menuBeauticianDashBoard, "&美容师");

    // 产品
    wxMenu *menuProductDashBoard = new wxMenu;
    menuProductDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Product_Detail),"&详情面板");
    menuProductDashBoard->AppendSeparator();
    menuProductDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Product_Add),"&录入");
    menuBar->Append(menuProductDashBoard, "&产品");

    // 项目
    wxMenu *menuProjectDashBoard = new wxMenu;
    menuProjectDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Project_Detail),"&详情面板");
    menuProjectDashBoard->AppendSeparator();
    menuProjectDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Project_Add),"&创建");
    menuBar->Append(menuProjectDashBoard, "&项目");

    // 活动
    wxMenu *menuActivityDashBoard = new wxMenu;
    menuActivityDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Activity_Detail),"&详情面板");
    menuActivityDashBoard->AppendSeparator();
    menuActivityDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Activity_Add),"&创建");
    menuBar->Append(menuActivityDashBoard, "&活动");

    // 订单
    wxMenu *menuOrderDashBoard = new wxMenu;
    menuOrderDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Order_Detail),"&详情面板");
    menuOrderDashBoard->AppendSeparator();
    menuOrderDashBoard->Append(static_cast<int>(menu::UI_ID::ID_Order_Add),"&创建");
    menuBar->Append(menuOrderDashBoard, "&订单");


    // 日志
    wxMenu *menuLogDashBoard = new wxMenu;
    menuLogDashBoard->Append(static_cast<int>(menu::UI_ID::ID_LOG_Detail),"&详情面板");
    menuLogDashBoard->AppendSeparator();
    menuLogDashBoard->Append(static_cast<int>(menu::UI_ID::ID_LOG_Output),"&导出");
    menuBar->Append(menuLogDashBoard, "&日志");
    
 
    SetMenuBar( menuBar );
 
    CreateStatusBar();
    SetStatusText("岚婷雅媛管理系统     版本号 v1.0.0.001");
 
    Bind(wxEVT_MENU, &HomeFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &HomeFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &HomeFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &HomeFrame::OnCustomerDashBoard, this, static_cast<int>(menu::UI_ID::ID_Customer_Detail));
    Bind(wxEVT_ACTIVATE,&HomeFrame::OnActiveEvent, this);

}


void HomeFrame::OnPaint(wxPaintEvent& WXUNUSED(event)){

}

void HomeFrame::OnExit(wxCommandEvent& event){
    Close(true);
}
 
void HomeFrame::OnAbout(wxCommandEvent& event){
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
 
void HomeFrame::OnHello(wxCommandEvent& event){
    wxLogMessage("Hello world from wxWidgets!");
}


// FramePositionEvent
void HomeFrame::OnActiveEvent(wxEvent& event){
    wxPoint point = this->GetPosition();
    FrameDisplayer::Get().SetCurrentActivePosition(point);
}

void HomeFrame::OnCustomerDashBoard(wxCommandEvent& event){
    CustomerFrame* customer_frame = new CustomerFrame();
    customer_frame->Show(true);
}

HomeController* HomeFrame::GetController() {
    return controller_.get();
}

void HomeFrame::RefreshSectionStatus(){
    for(BitmapBtnPanel* section : sections_){
        section->PaintNow();
    }
}