cmake_minimum_required(VERSION 3.0)
project(model_test)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_FLAGS_DEBUG "-g -pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

file(GLOB SOURCE_CXX "${CMAKE_SOURCE_DIR}/*.cpp" "${CMAKE_SOURCE_DIR}/../common/*.cpp")
file(GLOB SOURCE_C "${CMAKE_SOURCE_DIR}/*.c")
set(SOURCE ${SOURCE_CXX} ${SOURCE_C})

file(GLOB INCLUDE_SRC "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/../common")
include_directories(${INCLUDE_SRC})

if (WIN32)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mwindows")
elseif (APPLE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework Cocoa -framework IOKit -framework CoreVideo")
elseif (UNIX)
	link_libraries(X11 m dl Xxf86vm Xrandr Xi Xcursor Xinerama pthread)
endif ()

add_executable("model_test" ${SOURCE})