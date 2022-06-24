cmake_minimum_required(VERSION 3.0)
project(cpptrs)

set(target a.out)

include_directories(inc)
file(GLOB SOURCES "src/*.cpp")
# add_executable(${executable} ${SOURCES})


add_executable(a.out src/withboost.cc)

set_target_properties(${executable}
    PROPERTIES
    CXX_STANDARD 17
)
