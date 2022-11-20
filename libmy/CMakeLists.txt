#
# Copyright (C) 2022 https://github.com/nkh-lab
#
# This is free software. You can redistribute it and/or
# modify it under the terms of the GNU General Public License
# version 3 as published by the Free Software Foundation.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY.
#

cmake_minimum_required(VERSION 3.4.1)

project(libmy)

# Use it if your library name already starts with "lib" (to avoid "liblib" in naming)
set(CMAKE_SHARED_LIBRARY_PREFIX "")

# Overwrite with your own
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#option(${PROJECT_NAME}_BUILD_UTESTS "Build unit tests"      OFF)
#option(${PROJECT_NAME}_BUILD_CTESTS "Build component tests" OFF)

# Or overwrite from superproject
set(${PROJECT_NAME}_BUILD_UTESTS ${projectmy_BUILD_UTESTS})
set(${PROJECT_NAME}_BUILD_CTESTS ${projectmy_BUILD_CTESTS})

if(MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Defines
add_definitions(-DMY_DEFINE)
# Suppress warnings 
#add_compile_options(-Wno-deprecated-copy)

file(GLOB SRC_FILES "src/*.cpp")

add_library(${PROJECT_NAME} SHARED
    ${SRC_FILES}
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PRIVATE src
    )
    
#target_link_libraries(${PROJECT_NAME}
#    PUBLIC ...
#    PRIVATE ...
#    )

add_subdirectory(tests)