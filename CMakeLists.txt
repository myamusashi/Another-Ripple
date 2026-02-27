cmake_minimum_required(VERSION 3.16)

project(AnotherRipple LANGUAGES CXX)
set(PACKAGE_NAME AnotherRipple)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Quick Gui Qml REQUIRED)

add_subdirectory(
    ./AnotherRipple
)

add_subdirectory(
    ./test
)

