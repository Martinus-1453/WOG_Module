cmake_minimum_required(VERSION 3.17)

project(Squirrel)

file(GLOB_RECURSE SRC
	"include/*.h"
)

add_library(Squirrel INTERFACE)
target_sources(Squirrel INTERFACE ${SRC})

target_include_directories(Squirrel
	INTERFACE
		"./"
		"include/"
)