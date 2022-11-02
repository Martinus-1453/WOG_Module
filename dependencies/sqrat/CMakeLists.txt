cmake_minimum_required(VERSION 3.17)

project(SqRat)

file(GLOB_RECURSE SRC
	"include/*.h"
)

add_library(SqRat INTERFACE)
target_sources(SqRat INTERFACE ${SRC})

target_include_directories(SqRat
	INTERFACE
		"include/"
)