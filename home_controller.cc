#include "home_controller.h"

HomeController::HomeController() : model_(new HomeModel()){}

HomeModel* HomeController::GetModel() {
    return model_.get();
}