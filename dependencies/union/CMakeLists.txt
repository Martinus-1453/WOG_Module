cmake_minimum_required(VERSION 3.17)

project(Union)

file(GLOB SRC
	"GothicAPI/zGothicAPI.h"
	"GothicAPI/Gothic_II_Addon/*.h"
	"GothicAPI/Gothic_II_Addon/*.cpp"
	"GothicAPI/Gothic_II_Addon/API/*.h"
	"GothicAPI/Gothic_UserAPI/*.inl"
)

add_library(Union INTERFACE)
target_sources(Union INTERFACE ${SRC})

target_include_directories(Union
	INTERFACE
		"./"
		"GothicAPI/"
		"GothicAPI/Gothic_UserAPI/"
)

target_compile_definitions(Union INTERFACE __G2A)