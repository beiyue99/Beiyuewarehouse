cmake_minimum_required(VERSION 3.12)
project(AsyncServer)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 设置 Boost 的路径
set(BOOST_ROOT /usr)

# 查找 Boost 库的组件
find_package(Boost REQUIRED COMPONENTS system thread)

# 添加可执行文件和源文件
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/day06-AsyncServer/*.cpp)

add_executable(AsyncServer ${SOURCES})

# 包含头文件路径（包括其他目录）
target_include_directories(AsyncServer 
    PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/day06-AsyncServer 
    ${CMAKE_CURRENT_SOURCE_DIR}/other_directory
    # 添加其他目录路径...
)

# 包含 Boost 头文件路径
target_include_directories(AsyncServer PRIVATE ${Boost_INCLUDE_DIRS})

# 链接 Boost 库
target_link_libraries(AsyncServer PRIVATE ${Boost_LIBRARIES})
