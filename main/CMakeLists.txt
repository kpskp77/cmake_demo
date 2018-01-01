cmake_minimum_required(VERSION 3.0)
project(main)

# set version number
set(MAIN_VERSION_MAJOR 1)
set(MAIN_VERSION_MINOR 0)
set(MAIN_VERSION_PATCH 0)

# config a header file to pass some of the CMake settings to
# the source code
configure_file(
    ${PROJECT_SOURCE_DIR}/configVersion.hpp.in
    ${PROJECT_BINARY_DIR}/configVersion.hpp
    )

# source file list is seperated from main CMakeLists, includes here
# ${SOURCE_DIR}/source.cmake should populate:
#       1. ${SOURCE_DIR} as source directory
#       2. ${SOURCE_LIST} as source list
include(${PROJECT_SOURCE_DIR}/source.cmake)

# general public headers should be put in ${PROJECT_SOURCE_DIR/include
set(PUBLIC_HEADER_DIR
    ${PROJECT_SOURCE_DIR}/include
    )
# private headers should be put in ${PROJECT_SOURCE_DIR/src
# ${PROJECT_BINARY_DIR} is for configure_file,
set(PRIVATE_HEADER_DIR
    ${PROJECT_BINARY_DIR}
    ${SOURCE_DIR}
    )

# external dynamic library, this target is not built by current project
add_library(ext_dll SHARED IMPORTED)
set(EXT_DLL_DIR ${CMAKE_SOURCE_DIR}/lib_ext/install)
set_target_properties(ext_dll PROPERTIES
    IMPORTED_IMPLIB ${EXT_DLL_DIR}/lib/lib_ext_shared.lib
    IMPORTED_LOCATION ${EXT_DLL_DIR}/lib/lib_ext_shared.dll
    INTERFACE_INCLUDE_DIRECTORIES ${EXT_DLL_DIR}/include
    )

# executable target with dynamic library
add_executable(main_dynamic ${SOURCE_LIST})
target_include_directories(main_dynamic PUBLIC ${PUBLIC_HEADER_DIR})
target_include_directories(main_dynamic PRIVATE ${PRIVATE_HEADER_DIR})
target_link_libraries(main_dynamic ext_dll lib_cat_shared)

# external static library, this target is not built by current project
add_library(ext_lib STATIC IMPORTED)
set(EXT_LIB_DIR ${CMAKE_SOURCE_DIR}/lib_ext/install)
set_target_properties(ext_lib PROPERTIES
    IMPORTED_LOCATION ${EXT_LIB_DIR}/lib/lib_ext_static.lib
    INTERFACE_INCLUDE_DIRECTORIES ${EXT_LIB_DIR}/include
    INTERFACE_COMPILE_DEFINITIONS LIB_EXT_BUILD_AS_STATIC
    )

# executable target with static library
add_executable(main_static ${SOURCE_LIST})
target_include_directories(main_static PUBLIC ${PUBLIC_HEADER_DIR})
target_include_directories(main_static PRIVATE ${PRIVATE_HEADER_DIR})
target_link_libraries(main_static ext_lib lib_cat_static)

install(TARGETS main_static main_dynamic
    RUNTIME DESTINATION "bin"
    )
install(FILES ${EXT_DLL_DIR}/lib/lib_ext_shared.dll
    DESTINATION "bin"
    )
