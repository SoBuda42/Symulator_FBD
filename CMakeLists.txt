cmake_minimum_required(VERSION 3.10)
project(Symulator_FBD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

file(GLOB ZRODLA "*.cpp")
file(GLOB NAGLOWKI "*.h")
file(GLOB OKIENKA "*.ui")

add_executable(Symulator WIN32 ${ZRODLA} ${NAGLOWKI} ${OKIENKA})

target_link_libraries(Symulator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)