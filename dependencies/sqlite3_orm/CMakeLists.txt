cmake_minimum_required(VERSION 3.17)

project(sqlite3_orm)

file(GLOB_RECURSE SRC
	"include/*.h"
)

add_library(sqlite3_orm INTERFACE)
target_sources(sqlite3_orm INTERFACE ${SRC})

target_include_directories(sqlite3_orm
	INTERFACE
		"./"
		"include/"
)