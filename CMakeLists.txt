cmake_minimum_required(VERSION 3.10)
project(para_solver)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}")

# Include directories
set(GUROBI_ROOT_DIR "/home/wangyuan@sribd.cn/Downloads/gurobi1100/linux64")
include_directories(${GUROBI_ROOT_DIR}/include)

# Library and link directories
link_directories(${GUROBI_ROOT_DIR}/lib)

# Test source for lll_reduction
set(sources src/main.cc ${GUROBI_ROOT_DIR}/include/gurobi_c++.h)

add_executable(${CMAKE_PROJECT_NAME} ${sources})
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${GUROBI_ROOT_DIR}/src/build/libgurobi_c++.a)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${GUROBI_ROOT_DIR}/lib/libgurobi110.so)
