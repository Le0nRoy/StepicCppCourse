cmake_minimum_required(VERSION 3.5)

project(StepicCppCourse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN_LIB_NAME ${PROJECT_NAME})
message("Configuring ${MAIN_LIB_NAME}...")

# Include block
# Compile block
set(src
    main.cpp
    src/Utils.cpp
    src/Cls.cpp
    src/String.cpp
    src/Visitor.cpp
    src/Rational.cpp
    src/ScopedPtr.cpp
    )
set(headers
    src/headers/Utils.h
    src/headers/Cls.h
    src/headers/String.h
    src/headers/Visitor.h
    src/headers/Rational.h
    src/headers/ScopedPtr.h
    )

add_library(${PROJECT_NAME} STATIC
            ${src}
            ${headers}
            )
#add_executable(${PROJECT_NAME}
#               ${src}
#               ${headers}
#               )

# Link block
# Test block
add_subdirectory(tests)

message("Finished configuring ${MAIN_LIB_NAME}!")
