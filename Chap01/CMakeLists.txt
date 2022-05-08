cmake_minimum_required(VERSION 3.16)

project(Chap01)

find_package(VTK REQUIRED)
if (NOT VTK_FOUND)
  message("Skipping example: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif ()

add_executable(1.3_TestVTKInstall 1.3_TestVTKInstall.cpp)
target_link_libraries(1.3_TestVTKInstall PRIVATE ${VTK_LIBRARIES})

vtk_module_autoinit(
  TARGETS 1.3_TestVTKInstall
  MODULES ${VTK_LIBRARIES})
