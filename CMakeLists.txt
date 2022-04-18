cmake_minimum_required(VERSION 3.21)
project(OOP_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(OOP_cpp main.cpp
        Lesson1/Lesson1.cpp Lesson1/Lesson1.h
        Lesson2/Lesson2.cpp Lesson2/Lesson2.h
        Lesson3/Lesson3.cpp Lesson3/Lesson3.h
        Blackjack/blackjack.cpp Blackjack/blackjack.h
        Lesson4/Lesson4.cpp Lesson4/Lesson4.h
        Lesson4/ArrayInt.cpp
        Lesson5/Lesson5.cpp Lesson5/Lesson5.h
        Lesson6/Lesson6.cpp Lesson6/Lesson6.h
        Lesson7/Lesson7.cpp Lesson7/Lesson7.h)
