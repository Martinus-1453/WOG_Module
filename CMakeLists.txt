cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(squirrel-template VERSION 0.1)

# exporting compile time variables into SquirrelTemplateConfig.h
include_directories(${CMAKE_CURRENT_BINARY_DIR})
string(TIMESTAMP COMPILE_TIME "%Y-%m-%d %H:%M:%S")
configure_file(SquirrelTemplateConfig.h.in SquirrelTemplateConfig.h)

option(INSTALL_AFTER_BUILD "Run cmake --install separately for every target after each build. By default this option is set to OFF" OFF)

set(GAME_PATH "" CACHE PATH "This option specifies the game location. It's only used for the installation step.")
set(SERVER_PATH "" CACHE PATH "This option specifies the server location. It's only used for the installation step.")

file(GLOB SRC
	"src/api/squirrel_api.h"
	"src/api/module_api.h"
	"src/api/module_api.cpp"

	"src/nonut/Class.h"
	"src/nonut/Class.cpp"
	"src/nonut/Function.h"
	"src/nonut/Property.h"
	"src/nonut/Constant.cpp"
	"src/nonut/Constant.h"

	"src/nonut/g2o/Draw.h"
	"src/nonut/g2o/Draw.cpp"
	"src/nonut/g2o/ClientFunctions.cpp"
	"src/nonut/g2o/ClientEventHandlers.h"
	"src/nonut/g2o/ClientEventHandlers.cpp"
	"src/nonut/g2o/ClientConstants.cpp"

	"src/wog/Init.h"

	"src/pch.h"
	"src/sqmain.cpp"
)

add_library(squirrel-template SHARED ${SRC})
target_precompile_headers(squirrel-template PRIVATE "src/pch.h")

target_include_directories(squirrel-template
	INTERFACE
		"include/"
	PRIVATE
		"src/"
)

add_subdirectory(dependencies)

if(DEFINED SHARED_LIBRARY_SUFFIX)
	set_target_properties(squirrel-template
			PROPERTIES 
				PREFIX ""
				SUFFIX ".${SHARED_LIBRARY_SUFFIX}${CMAKE_SHARED_LIBRARY_SUFFIX}"
	)
endif()

if (NOT ${GAME_PATH} STREQUAL "")
	install(TARGETS squirrel-template
			RUNTIME
			  DESTINATION ${GAME_PATH}
			  COMPONENT "clientModule"
	)

	if(INSTALL_AFTER_BUILD)
		add_custom_command(TARGET squirrel-template 
			POST_BUILD
				COMMAND ${CMAKE_COMMAND} --install ${CMAKE_CURRENT_BINARY_DIR} --component "clientModule"
		)
	endif()
endif()

if (NOT ${SERVER_PATH} STREQUAL "")
	install(TARGETS squirrel-template
			RUNTIME
			  DESTINATION ${SERVER_PATH}
			  COMPONENT "serverModule"
	)

	if(INSTALL_AFTER_BUILD)
		add_custom_command(TARGET squirrel-template 
			POST_BUILD
				COMMAND ${CMAKE_COMMAND} --install ${CMAKE_CURRENT_BINARY_DIR} --component "serverModule"
		)
	endif()
endif()
