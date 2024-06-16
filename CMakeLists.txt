cmake_minimum_required(VERSION 3.5)

project(qt_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Charts)


set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/chart.cpp
    src/gyro_chart.cpp
    src/list_item.cpp
)

set(HEADERS
    include/mainwindow.hpp
    include/chart.hpp
    include/gyro_chart.hpp
    include/list_item.hpp
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
    Qt5::Widgets
    Qt5::Charts
)