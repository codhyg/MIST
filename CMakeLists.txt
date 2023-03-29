cmake_minimum_required(VERSION 3.5)

project(MIST VERSION 0.0.2)

CMAKE_POLICY(SET CMP0020 NEW)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Windows rc file section
#set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/resources/img/mist_icon.o")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

configure_file(config.h.in ../include/config.h)

# Project source directories and files
set(PROJECT_SOURCES
		src/main.cpp
)

# Add executable section
IF (UNIX)
		add_executable(MIST WIN32 ${PROJECT_SOURCES})
ELSE()
		add_executable(MIST WIN32 ${PROJECT_SOURCES} ${APP_ICON_RESOURCE_WINDOWS})
ENDIF()

set_property(TARGET MIST PROPERTY WIN32_EXECUTABLE true)
set_target_properties(MIST PROPERTIES
		WIN32_EXECUTABLE TRUE
)

IF(WIN32)
		set_target_properties(MIST PROPERTIES LINK_FLAGS "-mwindows")
ENDIF()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Unit testing section
option(ENABLE_TEST "Turn on to enable tests" OFF)

if (ENABLE_TEST)
		enable_testing()

		set(CATCH2_DIR ./test)
		add_library(Catch INTERFACE)
		target_include_directories(Catch INTERFACE ${CATCH2_DIR})

		add_subdirectory(./test)
endif()

target_include_directories(MIST PUBLIC ../include)
