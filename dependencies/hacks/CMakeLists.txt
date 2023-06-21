cmake_minimum_required(VERSION 3.17)

project(Hacks)

file(GLOB SRC
	"include/*.h"
)

add_library(Hacks INTERFACE)
target_sources(Hacks INTERFACE ${SRC})

target_include_directories(Hacks
	INTERFACE
		"include/"
)