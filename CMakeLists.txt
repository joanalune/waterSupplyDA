cmake_minimum_required(VERSION 3.26)
project(waterSupplyDA)

set(CMAKE_CXX_STANDARD 17)

add_executable(waterSupplyDA main.cpp
        Headers/WaterSupply.h
        Sources/WaterSupply.cpp
        Headers/City.h
        Sources/City.cpp
        Headers/Reservoir.h
        Sources/Reservoir.cpp)
