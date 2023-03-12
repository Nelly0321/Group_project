find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Core)
find_package(Qt5 COMPONENTS Gui)
find_package(Qt5 COMPONENTS Widgets)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE
 opencv_core
 opencv_objdetect
 opencv_video
 opencv_videoio
 opencv_highgui
 Qt::Core
 Qt::Gui
 Qt::Widgets
)
