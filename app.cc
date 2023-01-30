#include "app.h"
#include "home_frame.h"
#include "preference.h"

bool LTYYApp::OnInit(){
    HomeFrame* home = new HomeFrame();
    home->Show(true);
    return true;
}