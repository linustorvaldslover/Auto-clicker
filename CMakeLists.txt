cmake_minimum_required(VERSION 3.12)
project(Auto_clicker)

set(CMAKE_CXX_STANDARD 23)

if (WIN32 OR WIN64)
    set(PLATFORM_SOURCES src/windows/main.cpp)
elseif (APPLE)
    set(PLATFORM_SOURCES src/mac/main.cpp)
elseif (UNIX)
    set(PLATFORM_SOURCES src/linux/main.cpp)
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

add_executable(Auto_clicker ${PLATFORM_SOURCES})


#add_executable(Auto_clicker
#    include/linux/include.cpp
#    include/ma
#    include/windows/include.cpp)
