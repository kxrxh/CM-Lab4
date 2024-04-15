cmake_minimum_required(VERSION 3.5)

project(lab3_cpp VERSION 0.1 LANGUAGES CXX)

SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widget, Core, WebView, WebEngineWidgets)
find_package(Qt5 REQUIRED COMPONENTS Widgets Core WebView WebEngineWidgets)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCE_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB PROJECT_SOURCES ${SOURCE_DIR}/*.cpp ${SOURCE_HEADER_DIR}/*.hpp)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(lab3_cpp
        MANUAL_FINALIZATION
        resources.rcc
        ${PROJECT_SOURCES}
    )
else()  
    add_executable(lab3_cpp
        ${PROJECT_SOURCES}
    )
endif()

include_directories(include)
target_link_libraries(lab3_cpp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::WebView Qt${QT_VERSION_MAJOR}::WebEngineWidgets)

set_target_properties(lab3_cpp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS lab3_cpp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(lab3_cpp)
endif()