#ifndef LTYY_HOME_MODEL_H_
#define LTYY_HOME_MODEL_H_

#include "side_tab_switcher.h"
#include <memory>

class HomeModel {
public:
    HomeModel(const HomeModel&) = delete;
    HomeModel& operator=(const HomeModel&) = delete;

    HomeModel();
    ~HomeModel() = default;

    SideTabSwitcher* GetSideTabSwitcher();
private:
    std::unique_ptr<SideTabSwitcher> side_tab_switcher_;
};

#endif // LTYY_HOME_MODEL_H_