cmake_minimum_required(VERSION 3.8)
project(quickSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ../sortUtils.c
        ../sortUtils.h
        ../../libs/random/random.c
        ../../libs/random/random.h
        quickSort.c
        quickSort.h
        testSort.c)

add_executable(quickSort ${SOURCE_FILES})