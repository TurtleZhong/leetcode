cmake_minimum_required(VERSION 3.9)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)
include_directories(${PROJECT_SOURCE_DIR}/array)
include_directories(${PROJECT_SOURCE_DIR}/binary_search)
include_directories(${PROJECT_SOURCE_DIR}/linked_list)
include_directories(${PROJECT_SOURCE_DIR}/string)

include_directories(${PROJECT_SOURCE_DIR}/include)


add_executable(561_array_partition1 array/561_array_partition1.cpp)
add_executable(766_Toeplitz_Matrix array/766_Toeplitz_Matrix.cpp)
add_executable(566_Reshape_the_Matrix array/566_Reshape_the_Matrix.cpp)
add_executable(485_Max_Consecutive_Ones array/485_Max_Consecutive_Ones.cpp)
add_executable(695_Max_Area_of_Island array/695_Max_Area_of_Island.cpp)
