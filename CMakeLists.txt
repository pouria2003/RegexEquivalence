cmake_minimum_required(VERSION 3.20)
project(Regex_equivalence)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Regex_equivalence
        DFA.cpp
        DFA.h
        main.cpp
        NFA.cpp
        NFA.h
        State.cpp
        State.h Transition.cpp Transition.h)
