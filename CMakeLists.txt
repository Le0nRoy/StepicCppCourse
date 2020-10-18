cmake_minimum_required(VERSION 3.5)

project(StepicCppCourse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN_LIB_NAME ${PROJECT_NAME})
message("Configuring ${MAIN_LIB_NAME}...")

# Include block
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
include(FindEXPAT)
find_package(EXPAT REQUIRED)
include_directories(${EXPAT_INCLUDE_DIRS})

# Compile block
set(SRC
    main.cpp
    src/Utils.cpp
    src/Cls.cpp
    src/String.cpp
    src/Expression.cpp
    src/Rational.cpp
    src/ScopedPtr.cpp
    src/SharedPtr.cpp
    src/ICloneable.cpp
    src/BaseD1D2D3.cpp
    src/headers/ManBearPig.h
    src/examples/pthread_integration.cpp
    src/examples/xml_parse.cpp src/headers/Point.h)

set(HEADERS
    src/headers/Utils.h
    src/headers/Cls.h
    src/headers/String.h
    src/headers/Expression.h
    src/headers/Rational.h
    src/headers/ScopedPtr.h
    src/headers/SharedPtr.h
    src/headers/Array.h
    src/headers/ICloneable.h
    src/headers/TemplatedUtils.h
    src/headers/Any.h
    src/headers/SameType.h
    src/headers/BaseD1D2D3.h
    src/headers/ManBearPig.h
    src/headers/Point.h src/headers/Multimethod2.h)

add_library(${MAIN_LIB_NAME} STATIC
            ${SRC}
            ${HEADERS}
            )
#add_executable(${PROJECT_NAME}
#               ${SRC}
#               ${HEADERS}
#               )

# Link block
target_link_libraries(${MAIN_LIB_NAME} PRIVATE
                      Threads::Threads
                      ${EXPAT_LIBRARIES}
                      )

# Test block
add_subdirectory(tests)

message("Finished configuring ${MAIN_LIB_NAME}!")
