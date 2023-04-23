#ifndef LTYY_HOME_CONTROLLER_H_
#define LTYY_HOME_CONTROLLER_H_

#include <memory>
#include "home_model.h"

class HomeController {
public:
    HomeController(const HomeController&) = delete;
    HomeController& operator=(const HomeController&) = delete;

    HomeController();
    ~HomeController() = default;

    HomeModel* GetModel();

private:

    std::unique_ptr<HomeModel> model_;
};

#endif // LTYY_HOME_CONTROLLER_H_