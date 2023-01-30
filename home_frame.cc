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

HomeFrame::HomeFrame() : wxFrame(
    nullptr, 
    wxID_ANY, 
    "岚婷雅媛管理系统",
    wxDefaultPosition,
    wxSize(Preference::Get().GetSize().width,Preference::Get().GetSize().height)) {
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
    SetStatusText("欢迎使用岚婷雅媛管理系统!");
 
    Bind(wxEVT_MENU, &HomeFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &HomeFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &HomeFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &HomeFrame::OnCustomerDashBoard, this, static_cast<int>(menu::UI_ID::ID_Customer_Detail));
    Bind(wxEVT_ACTIVATE,&HomeFrame::OnActiveEvent, this);
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