cmake_minimum_required(VERSION 3.17)

project(sqlite3)

file(GLOB SRC
	"*.h"
	"*.c"
)

add_library(sqlite3 STATIC)
target_sources(sqlite3 PRIVATE ${SRC})

target_include_directories(sqlite3 PUBLIC ".")
target_compile_options(sqlite3 PRIVATE $<$<PLATFORM_ID:Linux>:-fPIC>)