cmake_minimum_required(VERSION 3.27)
project(BookShop)

set(CMAKE_CXX_STANDARD 17)

add_executable(BookShop main.cpp
        Bancnote.cpp
        BancnoteValidator.h
        Book.cpp
        EntityValidator.h
        InvalidCodeException.cpp
        InvalidCodeException.h
        Service.cpp
        Tests.cpp
        UI.cpp)
