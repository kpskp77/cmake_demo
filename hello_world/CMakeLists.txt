cmake_minimum_required(VERSION 3.0)
project(hello_world)

add_executable(hello_world
    ${PROJECT_SOURCE_DIR}/main.cpp
    )

install(TARGETS hello_world
    RUNTIME DESTINATION "bin"
    )
