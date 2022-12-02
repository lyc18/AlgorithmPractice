cmake_minimum_required(VERSION 3.22)
project(IntroductionAlgorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(IntroductionAlgorithms
        utils/iofunction.h
        src/02SortAndOrderStatistics/QuickSort.cpp)
