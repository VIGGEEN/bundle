cmake_minimum_required(VERSION 3.13)
project(bundle)

set(CMAKE_CXX_STANDARD 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_library(bundle bundle.h bundle.cpp)
target_link_libraries(bundle PRIVATE Threads::Threads)