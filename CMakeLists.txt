cmake_minimum_required(VERSION 3.20)
project(SiADO2)

set(CMAKE_CXX_STANDARD 23)

add_executable(SiADO2 main.cpp fileUtil.h fileUtil.cpp phoneBookUtil.h phoneBookUtil.cpp)
