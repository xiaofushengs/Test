cmake_minimum_required(VERSION 3.10)
project(ReadPhoto)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置 OpenCV_DIR 路径
set(OpenCV_DIR "E:/opencv3.4/opencv/build/x64/MinGW/lib")
# 找到 OpenCV 包
find_package(OpenCV REQUIRED)

# 包含 OpenCV 头文件路径
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加可执行文件
add_executable(ReadPhoto read_photone.cpp)

# 链接 OpenCV 库
target_link_libraries(ReadPhoto ${OpenCV_LIBS})

