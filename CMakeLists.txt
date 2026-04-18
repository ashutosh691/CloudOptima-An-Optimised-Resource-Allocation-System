cmake_minimum_required(VERSION 3.19)
project(CloudOptima LANGUAGES CXX)

# 🔥 ADD Charts here
find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Charts)

qt_standard_project_setup()

qt_add_executable(CloudOptima
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    statsdialog.h
    statsdialog.cpp
    statsdialog.ui

    graphdialog.h
    graphdialog.cpp
    graphdialog.ui
    build/Qt_6_10_2_for_macOS-Debug/CloudOptima.app/Contents/MacOS/profiles.txt

)

# 🔥 LINK Charts here
target_link_libraries(CloudOptima
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Charts
)

include(GNUInstallDirs)

install(TARGETS CloudOptima
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET CloudOptima
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})
