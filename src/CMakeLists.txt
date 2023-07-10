cmake_minimum_required(VERSION 3.1.0)

project(Calculator VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Charts REQUIRED)

add_executable(3D_Viewer
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    glview.cpp
    glview.h
    parser.c
    parser.h
    structs.h
)

target_link_libraries(Calculator Qt6::Widgets Qt6::Core)
target_link_libraries(Calculator Qt6::Charts Qt6::Core)