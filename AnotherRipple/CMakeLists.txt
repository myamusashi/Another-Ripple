cmake_minimum_required(VERSION 3.16)
project(LibAnotherRipple LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Quick Gui Qml REQUIRED)

include(GNUInstallDirs)

if(NOT DEFINED QT_QML_OUTPUT_DIRECTORY)
    set(QT_QML_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/qml")
endif()

qt_add_qml_module(AnotherRipple
  URI AnotherRipple
  VERSION 1.0
  OUTPUT_DIRECTORY ${QT_QML_OUTPUT_DIRECTORY}/AnotherRipple
  SOURCES
    include/AnotherRipple.h

    include/AnotherRipple/framehandler.h
    include/AnotherRipple/AnotherRippleBase.h
    include/AnotherRipple/IconRipple.h
    include/AnotherRipple/ImageRipple.h
    include/AnotherRipple/ShapedRipple.h
    include/AnotherRipple/SimpleRipple.h

    src/framehandler.cpp
    src/AnotherRippleBase.cpp
    src/IconRipple.cpp
    src/ImageRipple.cpp
    src/ShapedRipple.cpp
    src/SimpleRipple.cpp
)

qt_query_qml_module(AnotherRipple
    URI module_uri
    PLUGIN_TARGET module_plugin_target
    TARGET_PATH module_target_path
    QMLDIR module_qmldir
    TYPEINFO module_typeinfo
)

set(INSTALL_QMLDIR "${CMAKE_INSTALL_LIBDIR}/qt-6/qml" CACHE STRING "QML install dir")
set(module_dir "${INSTALL_QMLDIR}/${module_target_path}")

install(TARGETS AnotherRipple LIBRARY DESTINATION "${module_dir}" RUNTIME DESTINATION "${module_dir}")
install(TARGETS "${module_plugin_target}" LIBRARY DESTINATION "${module_dir}" RUNTIME DESTINATION "${module_dir}")
install(FILES "${module_qmldir}" DESTINATION "${module_dir}")
install(FILES "${module_typeinfo}" DESTINATION "${module_dir}")

target_include_directories(AnotherRipple PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/AnotherRipple
)

target_link_libraries(AnotherRipple PRIVATE Qt6::Core Qt6::Quick Qt6::Gui)

target_compile_definitions(AnotherRipple PRIVATE AnotherRipple_LIBRARY)
