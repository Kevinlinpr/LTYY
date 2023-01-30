#ifndef LTYY_APP_H_
#define LTYY_APP_H_
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class LTYYApp : public wxApp {
public:
    bool OnInit() override;
};

#endif //LTYY_APP_H_