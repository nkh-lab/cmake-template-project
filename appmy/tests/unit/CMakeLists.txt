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

find_package(GTest REQUIRED)

file(GLOB SRC_FILES
    "*.cpp"
    "../../src/*.cpp"
    )

# Remove app main() from tests
list(FILTER SRC_FILES EXCLUDE REGEX ".*/appmy.cpp")

add_executable(${PROJECT_NAME}-unit-tests
    ${SRC_FILES}
    )

target_link_libraries(${PROJECT_NAME}-unit-tests
    PRIVATE GTest::Main
    PRIVATE gmock
    PRIVATE libmy-mock
    PRIVATE libutilsmy
    )

target_include_directories(${PROJECT_NAME}-unit-tests
    PRIVATE "../../src"
    )