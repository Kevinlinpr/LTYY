#include "home_model.h"

HomeModel::HomeModel() :
    side_tab_switcher_(new SideTabSwitcher()) {}


SideTabSwitcher* HomeModel::GetSideTabSwitcher() {
    return side_tab_switcher_.get();
}