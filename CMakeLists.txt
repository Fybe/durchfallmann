cmake_minimum_required(VERSION 2.8)

project(Durchfallmann)
set(Durchfallmann_VERSION_MAJOR	0)
set(Durchfallmann_VERSION_MINOR 1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

configure_file(
	"${PROJECT_SOURCE_DIR}/DurchfallmannConfig.hpp.in"
	"${PROJECT_BINARY_DIR}/DurchfallmannConfig.hpp"
)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}"
	"${CMAKE_CACHEFILE_DIR}"
)

add_executable(
	durchfallmann
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/Exception.cpp
	${PROJECT_SOURCE_DIR}/Durchfallmann.cpp
	${PROJECT_SOURCE_DIR}/Scene.cpp
	${PROJECT_SOURCE_DIR}/MenuScene.cpp
	${PROJECT_SOURCE_DIR}/LevelScene.cpp
	${PROJECT_SOURCE_DIR}/HUD/Button.cpp
)
target_link_libraries(durchfallmann sfml-graphics sfml-window sfml-system)
