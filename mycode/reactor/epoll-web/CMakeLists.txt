
cmake_minimum_required(VERSION 3.15)
project(test)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(EXECUTABLE_OUTPUT_PATH /mnt/d/fileswjf/MyCode/mycode/reactor/epoll-web/exe)
add_executable(app ${SRC})


