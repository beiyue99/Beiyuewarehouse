
cmake_minimum_required(VERSION 3.15)
project(test)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)

#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib2)
set(EXECUTABLE_OUTPUT_PATH /mnt/c/Users/北月/OneDrive/桌面/codeLinux/exe)
add_executable(app ${SRC})
#target_link_libraries(app calc)