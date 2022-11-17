set(PROJECT_NAME ${CMAKE_PROJECT_NAME})

aux_source_directory(. SRC_LIST)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(bigint ${SRC_LIST})

add_library(${PROJECT_NAME}_lib STATIC ${SRC_LIST})

add_definitions("-Wall -g")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
