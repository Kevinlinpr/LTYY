cmake_minimum_required(VERSION 3.10)

project(LTYY)

add_subdirectory(third_party/wxWidgets-3.2.1)

add_executable(
    LTTY
    activity.h
    app.cc
    app.h
    beautician.h
    bitmap_btn_panel.cc
    bitmap_btn_panel.h
    consumption.h
    customer_frame.cc
    customer_frame.h
    customer.h
    frame_displayer.cc
    frame_displayer.h
    frame_event.h
    home_controller.cc
    home_controller.h
    home_frame.cc
    home_frame.h
    home_model.cc
    home_model.h
    main.cc
    menu_id.h
    order.h
    payment.h
    person.h
    preference.cc
    preference.h
    product.h
    project.h
    side_tab_switcher.cc
    side_tab_switcher.h
    social.h
)

target_link_libraries(LTTY wx::net wx::core wx::base)
set_target_properties(LTTY PROPERTIES
            CXX_STANDARD 17
            CXX_EXTENSIONS OFF
            )