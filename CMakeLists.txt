cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(LearningOpenGL)

add_definitions(-DGLEW_STATIC)
add_subdirectory(Libraries/glfw EXCLUDE_FROM_ALL)
add_subdirectory(Libraries/glew EXCLUDE_FROM_ALL)

file(GLOB_RECURSE SRC_FILES src/Source/*.cpp)
add_executable(LearningOpenGL src/main.cpp ${SRC_FILES})
target_include_directories(LearningOpenGL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/src/Headers)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(
  LearningOpenGL
  PRIVATE glfw
  PRIVATE libglew_static
)

target_include_directories(LearningOpenGL
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src
)
