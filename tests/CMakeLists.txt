cmake_minimum_required(VERSION 3.5)

project(Google_tests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TEST_EXECUTABLE_NAME ${PROJECT_NAME})
message("Configuring ${TEST_EXECUTABLE_NAME}...")

enable_testing()

add_subdirectory(lib)

# Include block
set(INCLUDE_DIRS
    ${${MAIN_LIB_NAME}_SOURCE_DIR}/src
    ${gtest_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}
    )
include_directories(${INCLUDE_DIRS})

# Compile block
set(TEST_SRC
    ClsTests.cpp
    StringTests.cpp
    UtilsTests.cpp
    VisitorTests.cpp
    ExpressionTests.cpp
    RationalTests.cpp
    SharedPtrTests.cpp
    ArrayTests.cpp ArrayWithoutAssignmentTests.cpp)

add_executable(${TEST_EXECUTABLE_NAME}
               ${TEST_SRC}
               )

# Link block
set(LINK_LIBS
    ${MAIN_LIB_NAME}
    gtest
    gtest_main
    )

target_link_libraries(${TEST_EXECUTABLE_NAME}
                      ${LINK_LIBS}
                      )

message("Finished configuring ${TEST_EXECUTABLE_NAME}!")
