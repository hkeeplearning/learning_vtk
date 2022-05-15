cmake_minimum_required(VERSION 3.16)

project(LearningVTK)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake/")

include(learningvtkPrepare)

foreach(SUBDIR chap01 chap02)
    add_subdirectory(${SUBDIR})
endforeach()
