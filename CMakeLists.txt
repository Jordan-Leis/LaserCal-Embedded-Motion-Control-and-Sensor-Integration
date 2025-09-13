cmake_minimum_required(VERSION 3.16)
project(LaserCal LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 5.15 COMPONENTS Core Quick Sql REQUIRED)

add_executable(LaserCal
    src/main.cpp
    src/motion_controller.cpp
    src/sensor_simulator.cpp
    src/database_manager.cpp
    src/calibration_manager.cpp
    qml/qml.qrc
)

target_include_directories(LaserCal PRIVATE src)

target_link_libraries(LaserCal PRIVATE Qt5::Core Qt5::Quick Qt5::Sql)

set(QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/qml" CACHE STRING "" FORCE)
