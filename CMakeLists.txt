cmake_minimum_required(VERSION 2.8)

project(Durchfallmann)
set(Durchfallmann_VERSION_MAJOR	0)
set(Durchfallmann_VERSION_MINOR 1)

configure_file(
	"${PROJECT_SOURCE_DIR}/DurchfallmannConfig.hpp.in"
	"${PROJECT_BINARY_DIR}/DurchfallmannConfig.hpp"
)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(
	"${PROJECT_SOURCE_DIR}"
)

add_executable(
	durchfallmann
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/Durchfallmann.cpp
	${PROJECT_SOURCE_DIR}/Exception.cpp
)
target_link_libraries(durchfallmann sfml-graphics sfml-window sfml-system)
