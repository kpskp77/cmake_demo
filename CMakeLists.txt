cmake_minimum_required(VERSION 3.0)
project(demo_project)

# set default install prefix
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX
        ${PROJECT_BINARY_DIR}/install
        CACHE PATH "default install path" FORCE)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# force release build by default
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# trivial project to demonstrate multiple project organization
add_subdirectory(hello_world)
# library project to demonstrate how cmake manages the build process
add_subdirectory(lib_cat)
# main project to demonstrate how cmake manages the build process
add_subdirectory(main)
