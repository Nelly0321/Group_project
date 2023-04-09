cmake_minimum_required(VERSION 3.16)
project(filters LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS Core)
find_package(Qt5 COMPONENTS Gui)
find_package(Qt5 COMPONENTS Widgets)

find_program(CMAKE_CXX_CLANG_TIDY_EXECUTABLE NAMES clang-tidy)
if (NOT CMAKE_CXX_CLANG_TIDY_EXECUTABLE)
  message("clang-tidy not found")
else()
  message("clang-tidy found")
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif()

add_executable(filters
    mainwindow.cpp mainwindow.h
    Filter.cpp Filter.h
    Camera.cpp Camera.h
    Photos.cpp Photos.h
    main.cpp
)
set_target_properties(filters PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
target_link_libraries(filters PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
)