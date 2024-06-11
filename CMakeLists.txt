cmake_minimum_required(VERSION 3.5)

project(qt_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Charts Multimedia MultimediaWidgets WebEngineWidgets)


set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/chart.cpp
    src/gyro_chart.cpp
    src/list_item.cpp
    src/player.cpp
    src/webview.cpp
)

set(HEADERS
    include/mainwindow.hpp
    include/chart.hpp
    include/gyro_chart.hpp
    include/list_item.hpp
    include/player.hpp
    include/webview.hpp
)

set(UIS
    ui/mainwindow.ui
    ui/list_item.ui
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UIS})

target_sources(${PROJECT_NAME} PRIVATE
    resources/resources.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt6::Widgets
    Qt6::Charts
    Qt6::Multimedia
    Qt6::MultimediaWidgets
    Qt6::WebEngineWidgets
)