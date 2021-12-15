cmake_minimum_required(VERSION 3.19)
project(JetsonJevoisPlayground)

set(CMAKE_PREFIX_PATH  "/home/jay/libtorch")

find_package(OpenCV REQUIRED)
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp opencv_operations.cpp opencv_operations.hpp pytorch_operations.cpp pytorch_operations.hpp)

add_executable(JetsonJevoisPlayground ${SOURCE_FILES})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(JetsonJevoisPlayground "${OpenCV_LIBRARIES}" "${TORCH_LIBRARIES}")
