cmake_minimum_required(VERSION 3.10)
project(nimi_search LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(-Wall -Wextra -Wpedantic) # Enable all warnings

add_executable(nimi_search ${SRC_FILES})

target_sources(nimi_search PRIVATE
    src/main.cpp
    src/crawler.cpp
    )

target_include_directories(nimi_search PRIVATE 
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include
    )