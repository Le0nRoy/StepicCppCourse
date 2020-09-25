cmake_minimum_required(VERSION 3.5)

project(StepicCppCourse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(src /
    tests.cpp /
    src/String.cpp /
    src/Cls.cpp /
    src/Expression.cpp /
    src/visitor.cpp /
    )

set(headers /
    src/Cls.h /
    src/Expression.h /
    src/String.h /
    src/visitor.h /
    src/rational.h
    src/scoped_ptr.h
    )

#enable_testing()
#add_test(NAME MyTest )

add_executable(${PROJECT_NAME}
               ${src}
               ${headers}
               )
