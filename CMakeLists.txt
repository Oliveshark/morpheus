cmake_minimum_required (VERSION 3.2.0)

SET(CMAKE_COLOR_MAKEFILE ON)

project(morpheus CXX)

set(morpheus_TITLE "Morpheus")
set(morpheus_MAJOR_VERSION 0)
set(morpheus_MINOR_VERSION 0)
set(morpheus_PATCH_VERSION 1)
set(morpheus_RELEASE_TYPE "(alfa)")

include(mk/cmake/FindSDL2.cmake)
include(mk/cmake/FindSDL2_image.cmake)
include(mk/cmake/FindCCache.cmake)
include(mk/cmake/Findcppcheck.cmake)

macro(set_option option value)
	set(${option} ${value} CACHE INTERNAL "" FORCE)
endmacro()

# Load ECS
set_option(ECS_TESTS_ENABLED off)
set_option(ECS_LINT_ENABLED off)
add_subdirectory(ECS)
set(ECS_INCLUDE_DIR "ECS/src")
set(ECS_LIBRARY "ecs")

# Load Box2D
set_option(BOX2D_INSTALL off)
set_option(BOX2D_INSTALL_DOC off)
set_option(BOX2D_BUILD_SHARED off)
set_option(BOX2D_BUILD_STATIC on)
set_option(BOX2D_BUILD_EXAMPLES off)
add_subdirectory(box2d/Box2D)
set(BOX2D_INCLUDE_DIR "box2d/Box2D/Box2D")
set(BOX2D_LIBRARY "Box2D")

configure_file(
	"${PROJECT_SOURCE_DIR}/src/Config.h.in"
	"${PROJECT_BINARY_DIR}/Config.h"
	)

include_directories(
	${PROJECT_BINARY_DIR}
	${SDL2_INCLUDE_DIR}
	${SDL2_IMAGE_INCLUDE_DIR}
	${ECS_INCLUDE_DIR}
	${BOX2D_INCLUDE_DIR}
	)

add_definitions(-std=c++17)
set(CMAKE_CXX_FLAGS_DEBUG
	"${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -fsanitize=address -fno-omit-frame-pointer -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wconversion -Wno-sign-conversion"
	)

add_executable(morpheus
	src/Main
	src/Texture
	src/Timer
	)

target_link_libraries(morpheus
	${SDL2_LIBRARY}
	${SDL2MAIN_LIBRARY}
	${SDL2_IMAGE_LIBRARY}
	${ECS_LIBRARY}
	${BOX2D_LIBRARY}
	)

# LINT:
if (CPPCHECK_FOUND)
	add_custom_target(lint
		COMMAND ${CPPCHECK_EXECUTABLE} --force --language=c++ --template=gcc --error-exitcode=1 --quiet --enable=warning,style,performance,portability,information,missingInclude src/
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
		COMMENT "Run cppcheck"
		)
endif (CPPCHECK_FOUND)

install(TARGETS morpheus DESTINATION bin)
