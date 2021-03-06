cmake_minimum_required(VERSION 3.0)
project(lib_ext)

# set default install prefix
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX
        ${PROJECT_SOURCE_DIR}/install
        CACHE PATH "default install path" FORCE)
endif()

# force release build by default
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# set version number
set(LIB_EXT_VERSION_MAJOR 1)
set(LIB_EXT_VERSION_MINOR 0)
set(LIB_EXT_VERSION_PATCH 0)

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
set(PUBLIC_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/include
    )
# private headers should be put in ${PROJECT_SOURCE_DIR/src
# ${PROJECT_BINARY_DIR} is for configure_file,
set(PRIVATE_HEADER_DIRS
    ${PROJECT_BINARY_DIR}
    ${SOURCE_DIR}
    )

################### build as shared library ###################
add_library(lib_ext_shared SHARED ${SOURCE_LIST})
target_include_directories(lib_ext_shared PUBLIC ${PUBLIC_HEADER_DIRS})
target_include_directories(lib_ext_shared PRIVATE ${PRIVATE_HEADER_DIRS})
# generate exported header for dll, compitable cross platform
include(GenerateExportHeader)
generate_export_header(lib_ext_shared
    EXPORT_FILE_NAME ${PROJECT_SOURCE_DIR}/include/lib_ext_EXPORTS.h
    STATIC_DEFINE LIB_EXT_BUILD_AS_STATIC
    )

################### build as static library ###################
add_library(lib_ext_static STATIC ${SOURCE_LIST})
target_include_directories(lib_ext_static PUBLIC ${PUBLIC_HEADER_DIRS})
target_include_directories(lib_ext_static PRIVATE ${PRIVATE_HEADER_DIRS})
# add compiler definitions to set correct macro for exported headers
# generated by shared libraray above,
# for compitability with static and dynamic mixed build
target_compile_definitions(lib_ext_static PUBLIC LIB_EXT_BUILD_AS_STATIC)

# install targets
# executable target will be installed in RUNTIME path
# shared library will be installed in RUNTIME path on DLL platform,
#       and will be installed in LIBRARY path on non-DLL platform
# static library will be installed in ARCHIVE path
install(TARGETS lib_ext_shared lib_ext_static
    RUNTIME DESTINATION "lib"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    )
# install public headers
install(DIRECTORY ${PUBLIC_HEADER_DIRS}
    DESTINATION "."
    )
