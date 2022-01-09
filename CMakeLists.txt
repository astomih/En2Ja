cmake_minimum_required(VERSION 3.7)
project(En2Ja_utf8)


set(CMAKE_CXX_FLAGS "-std=c++20")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native -W2")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

file(GLOB SOURCE_FILES
	./src/*/*.cpp 
	./src/*.cpp
)

set(LIBRARIES
	nen
)

add_executable(En2Ja_utf8
	${SOURCE_FILES}
)
