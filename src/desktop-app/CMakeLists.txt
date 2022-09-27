find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
    impl/App.cpp
    impl/MainWindow.ui
    impl/MainWindow.hpp
    impl/MainWindow.cpp
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(DesktopApp ${SOURCES})

target_link_libraries(DesktopApp PRIVATE TaskProcessor Qt6::Widgets)
