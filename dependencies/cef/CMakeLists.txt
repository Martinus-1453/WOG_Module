cmake_minimum_required(VERSION 3.17)

project(CEF)

string(TOLOWER ${CMAKE_BUILD_TYPE} build_type)

add_library(CEF INTERFACE)

target_include_directories(CEF
	INTERFACE
		"./"
)

target_link_libraries(CEF 
	INTERFACE 
		"${CMAKE_CURRENT_SOURCE_DIR}/lib/libcef.lib"
		"${CMAKE_CURRENT_SOURCE_DIR}/lib/${build_type}/libcef_dll_wrapper.lib"
)