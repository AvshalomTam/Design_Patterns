cmake_minimum_required(VERSION 3.9)
project(Thread_Pool_rec13)
find_package(Threads)

set(CMAKE_CXX_STANDARD 11)

add_executable(Thread_Pool_rec13
        README.md Task.cpp Task.h ThreadPool.cpp ThreadPool.h main.cpp)
target_link_libraries(Thread_Pool_rec13 ${CMAKE_THREAD_LIBS_INIT})
