cmake_minimum_required(VERSION 3.5.1)
project(forLinux C)

set(CMAKE_C_STANDARD 99)
set(INC_DIR C:\\Users\\Lc\\Desktop\\ku\\include)
set(LINK_DIR C:\\Users\\Lc\\Desktop\\ku\\lib\\gcc)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})

add_subdirectory(onlineDict)