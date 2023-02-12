set(PROJECT_NAME ${CMAKE_PROJECT_NAME})

add_executable(${PROJECT_NAME}_run main.cpp int2048.cpp)

add_definitions("-Wall -g")

enable_testing()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
