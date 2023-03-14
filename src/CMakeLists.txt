find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Core)
find_package(Qt5 COMPONENTS Gui)
find_package(Qt5 COMPONENTS Widgets)

add_executable(group_project main.cpp)

target_link_libraries(group_project PRIVATE
 opencv_core
 opencv_objdetect
 opencv_video
 opencv_videoio
 opencv_highgui
 Qt::Core
 Qt::Gui
 Qt::Widgets
)
