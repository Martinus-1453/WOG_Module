cmake_minimum_required(VERSION 3.17)

project(launcher
	VERSION 0.1.0.0
	DESCRIPTION "CEF Launcher"
)

file(GLOB_RECURSE CEF_LAUNCHER_SRC
	"CV8Handler.h"
	"CV8Handler.cpp"
	"CCefApp.h"
	"CCefApp.cpp"
	"main.cpp"
)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/VersionInfo.rc.in
	${CMAKE_CURRENT_BINARY_DIR}/VersionInfo.rc
	@ONLY
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CEF_LAUNCHER_SRC})

source_group("auto-generated/PCH"
	FILES
		${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}.dir/cmake_pch.hxx
		${CMAKE_CURRENT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${PROJECT_NAME}.dir/cmake_pch.cxx
)

add_executable(launcher WIN32 ${CEF_LAUNCHER_SRC})

target_include_directories(launcher
	PRIVATE
		"../dependencies/cef"
)

target_link_directories(launcher
	PRIVATE
		"../dependencies/cef/lib"
)

target_compile_definitions(launcher
	PRIVATE
		SERVER_VERSION=\"${PROJECT_VERSION}\"
		SERVER_DESCRIPTION=\"${PROJECT_DESCRIPTION}\"
)

set(CEF_LIBRARIES
	libcef
	debug debug/libcef_dll_wrapper
	optimized release/libcef_dll_wrapper
)

target_link_libraries(launcher ${CEF_LIBRARIES})
