cmake_minimum_required(VERSION 3.16)

project(Chap02)

find_package(VTK REQUIRED)
if (NOT VTK_FOUND)
  message("Skipping example: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif ()

add_executable(2.1_RenderCylinder 2.1_RenderCylinder.cpp)
target_link_libraries(2.1_RenderCylinder PRIVATE ${VTK_LIBRARIES})
vtk_module_autoinit(
  TARGETS 2.1_RenderCylinder
  MODULES ${VTK_LIBRARIES})

add_executable(2.2_RenderCylinder-Lights 2.2_RenderCylinder-Lights.cpp)
target_link_libraries(2.2_RenderCylinder-Lights PRIVATE ${VTK_LIBRARIES})
vtk_module_autoinit(
  TARGETS 2.2_RenderCylinder-Lights
  MODULES ${VTK_LIBRARIES})

add_executable(2.2_RenderCylinder-Camera 2.2_RenderCylinder-Camera.cpp)
target_link_libraries(2.2_RenderCylinder-Camera PRIVATE ${VTK_LIBRARIES})
vtk_module_autoinit(
  TARGETS 2.2_RenderCylinder-Camera
  MODULES ${VTK_LIBRARIES})

add_executable(2.2_TextureExample 2.2_TextureExample.cpp)
target_link_libraries(2.2_TextureExample PRIVATE ${VTK_LIBRARIES})
vtk_module_autoinit(
  TARGETS 2.2_TextureExample
  MODULES ${VTK_LIBRARIES})