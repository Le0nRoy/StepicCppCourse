cmake_minimum_required(VERSION 3.5)

project(StepicCppCourse LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(src /
    main.cpp /
    src/String.cpp /
    src/Cls.cpp /
    src/Utils.cpp
    src/Visitor.cpp /
    src/Rational.cpp src/ScopedPtr.cpp)

set(headers /
    src/Cls.h /
    src/String.h /
    src/Visitor.h /
    src/Rational.h /
    src/ScopedPtr.h /
    src/Utils.h /
    )

#enable_testing()
#add_test(NAME MyTest )

add_executable(${PROJECT_NAME}
               ${src}
               ${headers}
               )
