set(PROJECT_NAME ${CMAKE_PROJECT_NAME})

aux_source_directory(. SRC_LIST)

add_executable(${PROJECT_NAME}_run ${SRC_LIST})

add_library(${PROJECT_NAME}_lib STATIC ${SRC_LIST})

add_definitions("-Wall -g")

enable_testing()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
