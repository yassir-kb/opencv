cmake_minimum_required(VERSION 3.22)
project(OpenCV)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.3")

find_package(OpenCV)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("/opt/homebrew/Cellar/qt@5/5.15.3/lib")

add_executable(OpenCV mainwindow.cpp mainwindow.h main.cpp erosion_dilation.cpp resizing.cpp lighten_darken.cpp panorama_stitching.cpp canny_edge_detection.cpp panorama_stitching.h resizing.h lighten_darken.h erosion_dilation.h canny_edge_detection.h)
target_link_libraries(OpenCV
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${OpenCV_LIBS}
        )