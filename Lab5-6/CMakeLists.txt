cmake_minimum_required(VERSION 3.7)
project(Lab5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/Controller.cpp
        includes/Controller.h
        includes/DynamicVector.h
        main.cpp
        src/Movie.cpp
        includes/Movie.h
        src/Repository.cpp
        includes/Repository.h
        src/UI.cpp
        includes/UI.h src/Watchlist.cpp includes/Watchlist.h src/Tests.cpp includes/Tests.h src/Counter.cpp includes/Counter.h src/Validator.cpp includes/Validator.h)

add_executable(Lab5 ${SOURCE_FILES})