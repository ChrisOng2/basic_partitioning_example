cmake_minimum_required(VERSION 3.30)
project(graphpartitioning_example)

set(CMAKE_CXX_STANDARD 20)

add_executable(graphpartitioning_example main.cpp
        MatrixStruct.h
        MatrixGen.h
        MatrixGen.cpp
        COOtoCSR.h
        COOtoCSR.cpp
        METISAdjncyFind.h
        METISAdjncyFind.cpp
        METISWrapper.h)

# /usr/include and /usr/lib/x86_64-linux-gnu are already on the default search paths
target_link_libraries(graphpartitioning_example PRIVATE metis)