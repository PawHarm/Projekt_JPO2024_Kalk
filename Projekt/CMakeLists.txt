cmake_minimum_required(VERSION 3.10)
project(Projekt)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
    kalkulator.cpp
    kalkulator_bin.cpp
    kalkulator_float.cpp
    kalkulator_hex.cpp
    kalkulator_octa.cpp
    main.cpp
)


set(HEADER_FILES
    kalkulator.h
    kalkulator_bin.h
    kalkulator_float.h
    kalkulator_hex.h
    kalkulator_octa.h
)


add_library(ProjektLibrary ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(ProjektLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(Projekt ${SOURCE_FILES})


target_link_libraries(Projekt PRIVATE ProjektLibrary)
