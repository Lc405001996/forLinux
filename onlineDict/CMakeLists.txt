cmake_minimum_required(VERSION 3.5.1)
project(forLinux C)

set(CMAKE_C_STANDARD 99)

#add_executable(ftos ftos.c)
#target_link_libraries(ftos sqlite3)

add_executable(ser ser.c)
add_executable(cli cli.c)